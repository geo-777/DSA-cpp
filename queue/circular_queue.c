#include <stdio.h>

#define MAX 5

int q[MAX], rear=-1, front=-1;

void enqueue(int item){
    if(front==-1 && rear==-1){
        front=rear=0;
        q[rear]=item;
    }else if((rear + 1)%MAX == front){
        return;
    }else{
        rear=(rear+1)%MAX;
        q[rear]=item;
    }
}

int dequeue() {
    int item;
    if(front==-1 && rear==-1){
        return -1;
    } else if (front==rear){
        item=q[front];
        front=rear=-1;
    }
    else{
        item=q[front];
        front=(front+1)%MAX;
    }
    return item;
}