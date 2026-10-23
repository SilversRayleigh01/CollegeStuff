#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

#define DEBUG 0


void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
    ptr_graph->n_vertices_ = n_vertices;
    ptr_graph->n_edges_ = n_edges;
    for (int i = 0; i < ptr_graph->n_vertices_; ++i)
    {
        for (int j = 0; j < ptr_graph->n_vertices_; ++j)
        {
            ptr_graph->adj_mat_[i][j] = 0;
        }
    }
}


void add_edge(graph_t *ptr_graph, int from, int to)
{
    if (DEBUG)
        printf("Adding an edge %d - %d\n", from, to);
    ptr_graph->adj_mat_[from][to] = 1;
    ptr_graph->adj_mat_[to][from] = 1;
}


void dfs_recursive(int n, int a[][MAXSIZE], int visited[], int u)
{
    visited[u] = 1;
    printf("visited %d \n", u);
    for (int i = 0; i < n; ++i)
    {
        if (a[u][i] && !visited[i])
        {
            dfs_recursive(n, a, visited, i);
        }
    }
}


void dfs(graph_t *ptr_graph, int u)
{
    int visited[MAXSIZE];
    for (int i = 0; i < ptr_graph->n_vertices_; ++i)
        visited[i] = 0;
    dfs_recursive(ptr_graph->n_vertices_, ptr_graph->adj_mat_, visited, u);
    printf("\n");
}


static void dfs_silent(int n, int a[][MAXSIZE], int visited[], int u)
{
    visited[u] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[u][i] && !visited[i])
        {
            dfs_silent(n, a, visited, i);
        }
    }
}


void disp(graph_t *ptr_graph)
{
    printf("    ");
    for (int j = 0; j < ptr_graph->n_vertices_; ++j)
    {
        printf("%c  ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < ptr_graph->n_vertices_; ++i)
    {
        printf("%c   ", 'A' + i);
        for (int j = 0; j < ptr_graph->n_vertices_; ++j)
        {
            printf("%d  ", ptr_graph->adj_mat_[i][j]);
        }
        printf("\n");
    }
}


void deinit_graph(graph_t *ptr_graph)
{
    ptr_graph->n_vertices_ = 0;
    ptr_graph->n_edges_ = 0;
}


int degree(graph_t *g, int v)
{
    int deg = 0;
    for (int j = 0; j < g->n_vertices_; ++j)
    {
        if (g->adj_mat_[v][j])
        {
            deg++;
        }
    }
    return deg;
}


int count_edges(graph_t *g)
{
    int edges = 0;
    for (int i = 0; i < g->n_vertices_; ++i)
    {
        for (int j = i + 1; j < g->n_vertices_; ++j)
        {
            if (g->adj_mat_[i][j])
            {
                edges++;
            }
        }
    }
    return edges;
}


int is_connected(graph_t *g)
{
    if (g->n_vertices_ <= 1)
        return 1;

    int visited[MAXSIZE] = {0};
    dfs_silent(g->n_vertices_, g->adj_mat_, visited, 0);

    for (int i = 0; i < g->n_vertices_; ++i)
    {
        if (!visited[i])
        {
            return 0;
        }
    }
    return 1;
}


int check_eulerian(graph_t *g)
{
    if (count_edges(g) == 0)
        return 0;

    
    int start_node = -1;
    for (int i = 0; i < g->n_vertices_; ++i)
    {
        if (degree(g, i) > 0)
        {
            start_node = i;
            break;
        }
    }

    if (start_node == -1)
        return 0;

    
    int visited[MAXSIZE] = {0};
    dfs_silent(g->n_vertices_, g->adj_mat_, visited, start_node);

    for (int i = 0; i < g->n_vertices_; ++i)
    {
        if (degree(g, i) > 0 && !visited[i])
        {
            return 0;
        }
    }

    
    int odd_count = 0;
    for (int i = 0; i < g->n_vertices_; ++i)
    {
        if (degree(g, i) % 2 != 0)
        {
            odd_count++;
        }
    }

    if (odd_count == 0)
        return 2;
    if (odd_count == 2)
        return 1;
    return 0;
}


int check_star(graph_t *g)
{
    int n = g->n_vertices_;
    if (n < 3)
        return -1;

    int hub = -1;
    int hub_count = 0;
    int leaf_count = 0;

    for (int i = 0; i < n; ++i)
    {
        int d = degree(g, i);
        if (d == n - 1)
        {
            hub = i;
            hub_count++;
        }
        else if (d == 1)
        {
            leaf_count++;
        }
    }

    if (hub_count == 1 && leaf_count == n - 1)
    {
        return hub;
    }

    return -1;
}


topology_t identify_topology(graph_t *g)
{
    int n = g->n_vertices_;
    if (n < 2 || !is_connected(g))
    {
        return NOT_NETWORK;
    }

    int edges = count_edges(g);

    
    if (n >= 3)
    {
        int is_ring = 1;
        for (int i = 0; i < n; ++i)
        {
            if (degree(g, i) != 2)
            {
                is_ring = 0;
                break;
            }
        }
        if (is_ring)
            return RING;
    }

   
    if (edges == n - 1)
    {
        int deg1 = 0;
        int deg2 = 0;
        for (int i = 0; i < n; ++i)
        {
            int d = degree(g, i);
            if (d == 1)
                deg1++;
            else if (d == 2)
                deg2++;
        }
        if (deg1 == 2 && deg2 == n - 2)
        {
            return BUS;
        }
    }

    
    if (check_star(g) != -1)
    {
        return STAR;
    }

   
    int is_full_mesh = 1;
    for (int i = 0; i < n; ++i)
    {
        if (degree(g, i) != n - 1)
        {
            is_full_mesh = 0;
            break;
        }
    }
    if (is_full_mesh)
    {
        return FULL_MESH;
    }

    
    if (edges == n - 1)
    {
        return TREE;
    }

    
    return HYBRID;
}


const char *topology_name(topology_t t)
{
    switch (t)
    {
        case RING:        return "Ring";
        case BUS:         return "Bus";
        case STAR:        return "Star";
        case FULL_MESH:   return "Full Mesh";
        case TREE:        return "Tree";
        case HYBRID:      return "Hybrid";
        case NOT_NETWORK: return "Not a network";
        default:          return "Unknown";
    }
}
