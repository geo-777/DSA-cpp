#include <stdio.h>
#include <stdlib.h>

struct State {
    int a,b,c;
    struct State* parent;
};

struct QueueNode {
    struct State* state;
    struct QueueNode* next;
};

struct Queue{
    struct QueueNode* front,*rear;
};

struct State* createNewState(int a,int b, int c,struct State* parent) {
    struct State* newState = (struct State*) malloc(sizeof(struct State));
    newState->a=a;
    newState->b=b;
    newState->c=c;
    newState->parent=parent;
    return newState;
}

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q,struct State *state){
    struct  QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->state = state;
    temp->next = NULL;

    if(q->rear==NULL){
        q->rear = q->front = temp;
        return;
    }
    q->rear->next = temp;
    q->rear=temp;
}

struct State* dequeue(struct Queue *q) {
    if(isEmpty(q)) return NULL;
    struct QueueNode* temp = q->front;

}