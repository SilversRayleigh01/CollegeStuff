#include <stdio.h>
#include <stdlib.h>

/* =========================================================================
 * Step 1: Callbacks & Functional Concepts (Map, Filter, Reduce)
 * ========================================================================= */

void map(const int *src, int *dest, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++) {
        dest[i] = fn(src[i]);
    }
}

int filter(const int *src, int *dest, int n, int (*pred)(int)) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (pred(src[i])) {
            dest[count++] = src[i];
        }
    }
    return count;
}

int reduce(const int *arr, int n, int (*reducer)(int acc, int val), int init) {
    int acc = init;
    for (int i = 0; i < n; i++) {
        acc = reducer(acc, arr[i]);
    }
    return acc;
}

// Sample helper callbacks for Step 1 demo
static int square(int x)            { return x * x; }
static int is_even(int x)           { return x % 2 == 0; }
static int add(int acc, int val)    { return acc + val; }

void demonstrate_step_1(void) {
    printf("--- Step 1: Callbacks (Map, Filter, Reduce) ---\n");
    int data[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int transformed[6];

    map(data, transformed, n, square);
    printf("Map (x^2)    : ");
    for (int i = 0; i < n; i++) printf("%d ", transformed[i]);
    printf("\n");

    int filtered[6];
    int filtered_count = filter(data, filtered, n, is_even);
    printf("Filter (even): ");
    for (int i = 0; i < filtered_count; i++) printf("%d ", filtered[i]);
    printf("\n");

    int sum = reduce(data, n, add, 0);
    printf("Reduce (sum) : %d\n\n", sum);
}

/* =========================================================================
 * Step 2: Flexible Heap via Function Pointer Callbacks
 * ========================================================================= */

typedef int (*cmp_func_t)(int a, int b);

typedef struct {
    int *data;
    int size;
    int capacity;
    cmp_func_t cmp; // Returns > 0 if 'a' has higher priority than 'b'
} Heap;

int max_heap_cmp(int a, int b) {
    return (a > b) - (a < b);
}

int min_heap_cmp(int a, int b) {
    return (a < b) - (a > b);
}

Heap* heap_create(int capacity, cmp_func_t cmp) {
    Heap *h = (Heap *)malloc(sizeof(Heap));
    h->data = (int *)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    h->cmp = cmp;
    return h;
}

static void heap_swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapify_up(Heap *h, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (h->cmp(h->data[idx], h->data[parent]) > 0) {
            heap_swap(&h->data[idx], &h->data[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

static void heapify_down(Heap *h, int idx) {
    int best = idx;
    while (1) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < h->size && h->cmp(h->data[left], h->data[best]) > 0) {
            best = left;
        }
        if (right < h->size && h->cmp(h->data[right], h->data[best]) > 0) {
            best = right;
        }

        if (best != idx) {
            heap_swap(&h->data[idx], &h->data[best]);
            idx = best;
        } else {
            break;
        }
    }
}

void heap_push(Heap *h, int val) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (int *)realloc(h->data, sizeof(int) * h->capacity);
    }
    h->data[h->size] = val;
    heapify_up(h, h->size);
    h->size++;
}

int heap_pop(Heap *h) {
    if (h->size <= 0) return 0;
    int root = h->data[0];
    h->size--;
    if (h->size > 0) {
        h->data[0] = h->data[h->size];
        heapify_down(h, 0);
    }
    return root;
}

int heap_peek(const Heap *h) {
    return h->data[0];
}

int heap_size(const Heap *h) {
    return h->size;
}

void heap_free(Heap *h) {
    if (h) {
        free(h->data);
        free(h);
    }
}

/* =========================================================================
 * Step 3: Running Median Tracker
 * ========================================================================= */

typedef struct {
    Heap *left_half;  // Max-Heap: smaller half[cite: 1]
    Heap *right_half; // Min-Heap: larger half[cite: 1]
} MedianFinder;

MedianFinder* median_finder_create(int initial_cap) {
    MedianFinder *mf = (MedianFinder *)malloc(sizeof(MedianFinder));
    mf->left_half = heap_create(initial_cap, max_heap_cmp);
    mf->right_half = heap_create(initial_cap, min_heap_cmp);
    return mf;
}

void median_finder_insert(MedianFinder *mf, int x) {
    // 1. Insert[cite: 1]
    if (heap_size(mf->left_half) == 0 || x <= heap_peek(mf->left_half)) {
        heap_push(mf->left_half, x);
    } else {
        heap_push(mf->right_half, x);
    }

    // 2. Balance[cite: 1]
    if (heap_size(mf->left_half) > heap_size(mf->right_half) + 1) {
        heap_push(mf->right_half, heap_pop(mf->left_half));
    } else if (heap_size(mf->right_half) > heap_size(mf->left_half)) {
        heap_push(mf->left_half, heap_pop(mf->right_half));
    }
}

double median_finder_query(const MedianFinder *mf) {
    int total = heap_size(mf->left_half) + heap_size(mf->right_half);

    // 3. Query Median[cite: 1]
    if (total % 2 == 0) {
        return (heap_peek(mf->left_half) + heap_peek(mf->right_half)) / 2.0;
    }
    if (heap_size(mf->left_half) > heap_size(mf->right_half)) {
        return (double)heap_peek(mf->left_half);
    }
    return (double)heap_peek(mf->right_half);
}

void median_finder_free(MedianFinder *mf) {
    if (mf) {
        heap_free(mf->left_half);
        heap_free(mf->right_half);
        free(mf);
    }
}

/* =========================================================================
 * Main: Element Insertion & Median Output
 * ========================================================================= */

int main(void) {
    demonstrate_step_1();

    int n;
    printf("--- Running Median ---\n");
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    MedianFinder *mf = median_finder_create(n > 16 ? n : 16);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) break;

        median_finder_insert(mf, x);
        printf("Inserted: %d, Current Median: %.2f\n", x, median_finder_query(mf));
    }

    median_finder_free(mf);
    return 0;
}