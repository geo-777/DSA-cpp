#include <stdio.h>

#define MAX 100

int top=-1, stack[MAX];

int isFull() {
    return top + 1 == MAX;
}
int isEmpty() {
    return top==-1;
}

void push(int val) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = val;
}



int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack[top--];
}

int main() {

    return 0;
}