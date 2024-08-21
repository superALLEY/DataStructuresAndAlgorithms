#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* rear;
} queue;

void init_queue(queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(queue* q) {
    return (q->front == NULL);
}

void enqueue(queue* q, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->front->data;
    node* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

void merge(queue* q, queue* q1, queue* q2) {
    while (!is_empty(q1) && !is_empty(q2)) {
        if (q1->front->data < q2->front->data) {
            enqueue(q, dequeue(q1));
        }
        else {
            enqueue(q, dequeue(q2));
        }
    }

    while (!is_empty(q1)) {
        enqueue(q, dequeue(q1));
    }

    while (!is_empty(q2)) {
        enqueue(q, dequeue(q2));
    }
}

void merge_sort(queue* q) {
    if (is_empty(q) || q->front->next == NULL) {
        return;
    }

    queue q1, q2;
    init_queue(&q1);
    init_queue(&q2);

    int count = 0;
    node* current = q->front;

    while (current != NULL) {
        if (count % 2 == 0) {
            enqueue(&q1, current->data);
        }
        else {
            enqueue(&q2, current->data);
        }

        current = current->next;
        count++;
    }

    merge_sort(&q1);
    merge_sort(&q2);
    merge(q, &q1, &q2);
}

int main() {
    queue q;
    init_queue(&q);

    // Ajouter des éléments à la file
    enqueue(&q, 5);
    enqueue(&q, 9);
    enqueue(&q, 3);
    enqueue(&q, 7);
    enqueue(&q, 1);

    // Tri de la file
    merge_sort(&q);

    // Affichage des éléments triés
    printf("Les elements tries sont : ");
    while (!is_empty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    return 0;
}
