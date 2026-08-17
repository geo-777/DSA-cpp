#include <stdio.h>

#define MAX_SIZE 5

int A[MAX_SIZE];
int front = -1;
int rear = -1;


// Insert at rear end
void insertRear(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("OVERFLOW\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = rear + 1;
    }

    A[rear] = item;
}


// Insert at front end
void insertFront(int item) {
    if (front == 0) {
        printf("OVERFLOW\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        front = front - 1;
    }

    A[front] = item;
}


// Delete from front end
int deleteFront() {
    if (front == -1 || rear == -1) {
        printf("UNDERFLOW\n");
        return -1;
    }

    int item = A[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = front + 1;
    }

    return item;
}


// Delete from rear end
int deleteRear() {
    if (front == -1 || rear == -1) {
        printf("UNDERFLOW\n");
        return -1;
    }

    int item = A[rear];

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = rear - 1;
    }

    return item;
}


// Display deque
void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
}