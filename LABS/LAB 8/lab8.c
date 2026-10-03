#include <stdio.h>

#define WINDOW_LEN 5
#define MAX_ITEMS  100000

typedef struct {
    int q[MAX_ITEMS];
    int head;
    int tail;
} Deque;

static int weight_history[MAX_ITEMS];
static int total_readings = 0;
static Deque dq = { .head = 0, .tail = -1 };

static inline int is_empty(void) {
    return dq.tail < dq.head;
}

void addPackageWeight(int current_weight) {
    int current_idx = total_readings;
    weight_history[current_idx] = current_weight;
    total_readings++;

    // Evict items from the rear that cannot be the minimum
    while (!is_empty() && weight_history[dq.q[dq.tail]] >= current_weight) {
        dq.tail--;
    }
    dq.q[++dq.tail] = current_idx;

    // Evict the front item if it expired out of the window
    while (dq.q[dq.head] <= current_idx - WINDOW_LEN) {
        dq.head++;
    }

    int active_min = weight_history[dq.q[dq.head]];
    printf("Package: %2d kg | Min (last %d sec): %2d kg\n", current_weight, WINDOW_LEN, active_min);
}

int main(void) {
    int conveyor_feed[] = {10, 4, 8, 3, 7, 9, 2, 6, 5, 1};
    int total_samples = sizeof(conveyor_feed) / sizeof(conveyor_feed[0]);

    for (int i = 0; i < total_samples; i++) {
        addPackageWeight(conveyor_feed[i]);
    }

    return 0;
}