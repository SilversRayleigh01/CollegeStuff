#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    int time_for_completion;
    int time_allotted;
} Job;

Job set_job(int id, int burst_time) {
    Job j;
    j.id = id;
    j.time_for_completion = burst_time;
    j.time_allotted = 0;
    return j;
}

void display_job(Job j) {
    printf("Job %d: Total=%d, Allotted=%d\n", j.id, j.time_for_completion, j.time_allotted);
}

typedef struct Node {
    Job job;
    struct Node *prev;
    struct Node *next;
} Node;

Node* create_list() {
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = header;
    header->prev = header;
    return header;
}

Node* insert_before(Node *curr, Job j) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->job = j;
    new_node->next = curr;
    new_node->prev = curr->prev;
    curr->prev->next = new_node;
    curr->prev = new_node;
    return new_node;
}

Node* remove_at(Node *curr, Node *header) {
    if (curr == header) return header;
    Node *next_node = curr->next;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    return (next_node == header) ? header->next : next_node;
}

void display_list(Node *header) {
    if (header->next == header) {
        printf("List is empty\n");
        return;
    }
    Node *curr = header->next;
    while (curr != header) {
        display_job(curr->job);
        curr = curr->next;
    }
}

Node* process_job(Node *curr, Node *header, int time_slice) {
    if (header->next == header) {
        printf("No jobs to process\n");
        return header;
    }
    if (curr == header) curr = header->next;

    curr->job.time_allotted += time_slice;
    printf("Processed Job %d (+%d). Allotted: %d/%d\n", 
           curr->job.id, time_slice, curr->job.time_allotted, curr->job.time_for_completion);

    if (curr->job.time_allotted >= curr->job.time_for_completion) {
        printf("Job %d completed and removed.\n", curr->job.id);
        curr = remove_at(curr, header);
    } else {
        curr = curr->next;
        if (curr == header) curr = header->next;
    }
    return curr;
}

int main() {
    Node *header = create_list();
    Node *curr = header;
    int choice, id = 1, time_slice = 2;

    while (1) {
        printf("\n1. Add Job (before current)\n2. Remove Job (at current)\n3. Process Job\n4. Display Queue\n5. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            int burst;
            printf("Enter burst time: ");
            scanf("%d", &burst);
            Job j = set_job(id++, burst);
            curr = insert_before(curr, j);
            printf("Job %d inserted.\n", j.id);
        } else if (choice == 2) {
            if (header->next == header) {
                printf("Queue is empty.\n");
            } else {
                if (curr == header) curr = header->next;
                printf("Removing Job %d at current position.\n", curr->job.id);
                curr = remove_at(curr, header);
            }
        } else if (choice == 3) {
            curr = process_job(curr, header, time_slice);
        } else if (choice == 4) {
            display_list(header);
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}