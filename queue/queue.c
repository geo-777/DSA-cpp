#include <stdio.h>

#define MAX 10

int rear=-1, front=0;
int q[MAX];

int isEmpty(){
    return rear < front;
}

int isFull(){
    return rear==MAX-1;
}

int dequeue(){
    if(isEmpty()){
        printf("Underflow\n");
        return -1;
    }

    return q[front++];
}

void enqueue(int item){
    if(isFull()){
        printf("Overflow\n");
        return;
    }  
    q[++rear]=item;
}
