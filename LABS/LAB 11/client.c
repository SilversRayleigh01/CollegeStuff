#include <stdio.h>
#include "graph.h"

static void run_test(const char *title, int n_vertices, int edges[][2], int n_edges)
{
    graph_t g;
    init_graph(&g, n_vertices, n_edges);

    for (int i = 0; i < n_edges; ++i)
    {
        add_edge(&g, edges[i][0], edges[i][1]);
    }

    printf("==== %s ====\n", title);
    disp(&g);

    int euler = check_eulerian(&g);
    if (euler == 2)
    {
        printf("Eulerian check   : Euler circuit exists\n");
    }
    else if (euler == 1)
    {
        printf("Eulerian check   : Euler path exists\n");
    }
    else
    {
        printf("Eulerian check   : Not Eulerian\n");
    }

    int hub = check_star(&g);
    if (hub != -1)
    {
        printf("Star check       : Star, hub = %c\n", 'A' + hub);
    }
    else
    {
        printf("Star check       : Not a star\n");
    }

    topology_t top = identify_topology(&g);
    printf("Network topology : %s\n\n", topology_name(top));

    deinit_graph(&g);
}

int main(void)
{
    int e1[][2] = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4},
        {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}
    };
    run_test("Handout Graph (8 vertices, 11 edges)", 8, e1, 11);

    int e2[][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}
    };
    run_test("Cycle of 5 Vertices", 5, e2, 5);

    int e3[][2] = {
        {0, 1}, {1, 2}, {2, 3}
    };
    run_test("Path of 4 Vertices", 4, e3, 3);

    int e4[][2] = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}
    };
    run_test("Star with 1 Hub and 5 Leaves", 6, e4, 5);

    int e5[][2] = {
        {0, 1}, {0, 2}, {0, 3}, {0, 4},
        {1, 2}, {1, 3}, {1, 4},
        {2, 3}, {2, 4},
        {3, 4}
    };
    run_test("Complete Graph K5", 5, e5, 10);

    int e6[][2] = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}
    };
    run_test("Binary Tree (7 vertices)", 7, e6, 6);

    int e7[][2] = {
        {0, 1}, {1, 2}, {2, 0},
        {0, 3}, {3, 4}, {4, 0}
    };
    run_test("Bow-tie Graph", 5, e7, 6);

    int e8[][2] = {
        {0, 1}, {2, 3}
    };
    run_test("Disconnected Graph (4 vertices)", 4, e8, 2);

    return 0;
}
