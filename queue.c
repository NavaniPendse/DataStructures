#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->items[queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    int dequeuedItem;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; 
    }
    dequeuedItem = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return dequeuedItem;
}

int search(struct Queue* queue, int value) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot search.\n");
        return 0; 
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        if (queue->items[i] == value) {
            return 1; 
        }
    }
    return 0; 
    }

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);

    display(&myQueue);

    int elementToSearch = 20;
    if (search(&myQueue, elementToSearch)) {
        printf("%d found in the queue.\n", elementToSearch);
    } else {
        printf("%d not found in the queue.\n", elementToSearch);
    }

    int dequeuedItem = dequeue(&myQueue);
    if (dequeuedItem != -1) {
        printf("Dequeued item: %d\n", dequeuedItem);
    }

    display(&myQueue);

    return 0;
}