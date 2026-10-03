#include <stdio.h>
#include <stdlib.h>

#define MAX 11

typedef struct State {
    int a, b, c;
    struct State *parent;
} State;

typedef struct Node {
    State *state;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

State *createState(int a, int b, int c, State *parent) {
    State *s = malloc(sizeof(State));
    s->a = a;
    s->b = b;
    s->c = c;
    s->parent = parent;
    return s;
}

void enqueue(Queue *q, State *s) {
    Node *n = malloc(sizeof(Node));
    n->state = s;
    n->next = NULL;

    if (q->rear)
        q->rear->next = n;
    else
        q->front = n;

    q->rear = n;
}

State *dequeue(Queue *q) {
    if (!q->front)
        return NULL;

    Node *n = q->front;
    State *s = n->state;

    q->front = n->next;
    if (!q->front)
        q->rear = NULL;

    free(n);
    return s;
}

void printPath(State *s) {
    if (!s)
        return;

    printPath(s->parent);
    printf("(%d, %d, %d)\n", s->a, s->b, s->c);
}

void addState(Queue *q, int a, int b, int c, State *parent,
              int visited[MAX][MAX][MAX]) {
    if (!visited[a][b][c]) {
        visited[a][b][c] = 1;
        enqueue(q, createState(a, b, c, parent));
    }
}

void pour(State *s, Queue *q, int visited[MAX][MAX][MAX]) {
    int amount[] = {s->a, s->b, s->c};
    int capacity[] = {10, 7, 4};

    for (int from = 0; from < 3; from++) {
        for (int to = 0; to < 3; to++) {
            if (from == to || amount[from] == 0)
                continue;

            int poured = amount[from];

            if (amount[to] + poured > capacity[to])
                poured = capacity[to] - amount[to];

            if (poured == 0)
                continue;

            int next[3] = {amount[0], amount[1], amount[2]};

            next[from] -= poured;
            next[to] += poured;

            addState(q, next[0], next[1], next[2], s, visited);
        }
    }
}

int main() {
    Queue q = {NULL, NULL};
    int visited[MAX][MAX][MAX] = {0};

    State *start = createState(0, 7, 4, NULL);
    enqueue(&q, start);
    visited[0][7][4] = 1;

    while (q.front) {
        State *curr = dequeue(&q);

        if (curr->b == 2 || curr->c == 2) {
            printf("Solution path:\n");
            printPath(curr);
            return 0;
        }

        pour(curr, &q, visited);
    }

    printf("No solution found.\n");
    return 0;
}