#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

/* Check if queue is empty */
int isEmpty() {
    return front == NULL;
}

/* Insert an element */
void enqueue(int value) {
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d\n", value);
}

/* Remove an element */
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    printf("Deleted %d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

/* Display the front element */
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

/* Display all elements */
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

/* Free remaining nodes */
void freeQueue() {
    while (front != NULL) {
        struct Node *temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;
}

/* Main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                freeQueue();
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}