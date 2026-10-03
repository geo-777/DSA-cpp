
#include <stdio.h>

#define MAX 100
#define INF 9999

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct Node {
    int x, y;
};

struct Node queue[MAX * MAX];
int front = 0, rear = -1;

void enqueue(int x, int y) {
    queue[++rear] = (struct Node){x, y};
}

struct Node dequeue() {
    return queue[front++];
}

int isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    int maze[MAX][MAX], dist[MAX][MAX];
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maze[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = INF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == -1) {
                enqueue(i, j);
                dist[i][j] = 0;
            }
        }
    }

    while (front <= rear) {
        struct Node cur = dequeue();

        for (int k = 0; k < 4; k++) {
            int x = cur.x + dr[k];
            int y = cur.y + dc[k];

            if (isValid(x, y, n, m) &&
                maze[x][y] == 0 &&
                dist[x][y] > dist[cur.x][cur.y] + 1) {

                dist[x][y] = dist[cur.x][cur.y] + 1;
                enqueue(x, y);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 999)
                printf("# ");
            else if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}

