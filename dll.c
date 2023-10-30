#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global pointer to the head of the doubly linked list
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to insert a node at a specified position in the list
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position. Insertion failed.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    struct Node* current = head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position. Insertion failed.\n");
        return;
    }
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete a node from the list
void deleteNode(int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("Node with data %d not found. Deletion failed.\n", data);
}

// Function to traverse and print the list forward
void printForward() {
    struct Node* current = head;
    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to traverse and print the list backward
void printBackward() {
    struct Node* current = head;
    if (current == NULL) {
        printf("Doubly Linked List (Backward): NULL\n");
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    printf("Doubly Linked List (Backward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);

    printForward();
    printBackward();

    deleteNode(20);
    deleteNode(40);

    printForward();
    printBackward();

    return 0;
}
