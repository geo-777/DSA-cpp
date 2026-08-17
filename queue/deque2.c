//deque using circular arrays

#include<stdio.h>
#define MAX 5

int front=-1,rear=-1;
int q[MAX];

int isFull(){
    return (rear + 1)%MAX == front;
}
int isEmpty(){
    return rear==-1;
}
void insertFront(int item){
    if(isFull())return;

    if(isEmpty()){
        front=rear=0;
    }else{
        front = (front-1)%MAX;
    }
    q[front]=item;
}

void insertBack(int item){
    if(isFull())return;

    if(isEmpty()){
        front=rear=0;
    }else{
        rear = (rear+1)%MAX;
    }
    q[rear]=item;
}

int deleteFront(){
    if(isEmpty())return -1;

    int item=q[front];

    if(front==rear){
        front=rear=-1;
    }else{
        front=(front+1)%MAX;
    }
}

int deleteRear(){
    if(isEmpty())return -1;

    int item=q[rear];

    if(front==rear){
        front=rear=-1;
    }else{
        rear=(rear-1)%MAX;
    }
}