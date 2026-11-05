#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Check if queue is full */
int isFull() {
    return rear == MAX - 1;
}

/* Check if queue is empty */
int isEmpty() {
    return front == -1 || front > rear;
}

/* Insert an element */
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

/* Remove an element */
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

/* Display the front element */
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

/* Display all elements */
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

/* Main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Array ---\n");
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

/* Check if queue is full */
int isFull() {
    return rear == MAX - 1;
}

/* Check if queue is empty */
int isEmpty() {
    return front == -1 || front > rear;
}

/* Insert an element */
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

/* Remove an element */
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

/* Display the front element */
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

/* Display all elements */
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

/* Main function */
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Using Array ---\n");
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}