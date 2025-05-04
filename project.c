https://vjudge.net/contest/714232

//                                      ROAD TO HOSPITAL FASTLY FOR AN AMBULANCE

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 105

int n, m;
char a[MAX][MAX];
bool vis[MAX][MAX];
int parent[MAX][MAX]; // To store the previous direction
int dx[4] = {0, 0, -1, 1}; // Direction arrays for movement
int dy[4] = {1, -1, 0, 0};

// Movement directions as full words
char arr[4][10] = {"Right", "Left", "UP", "Down"};

// Structure to store a point (x, y) on the grid
typedef struct {
    int x, y;
} Point;

Point start, end_pos; // Start and end positions

// Function to check if the position is within bounds
bool check(int ci, int cj) {
    return ci >= 0 && cj >= 0 && ci < n && cj < m;
}

// Queue structure for BFS
typedef struct {
    Point data[MAX * MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Function to push an element into the queue
void push(Queue *q, Point p) {
    q->data[q->rear++] = p;
}

// Function to pop an element from the queue
Point pop(Queue *q) {
    return q->data[q->front++];
}

// BFS function to find the shortest path
void bfs() {
    Queue q;
    initQueue(&q);
    push(&q, start);
    vis[start.x][start.y] = true;

    while (!isEmpty(&q)) {
        Point p = pop(&q);

        // Checking all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int ci = p.x + dx[i];
            int cj = p.y + dy[i];

            // If within bounds, not visited, and not a wall ('#')
            if (check(ci, cj) && !vis[ci][cj] && a[ci][cj] != '#') {
                vis[ci][cj] = true;
                parent[ci][cj] = i; // Store the direction from which we arrived
                push(&q, (Point){ci, cj});

                // If we reach 'H', we stop BFS
                if (a[ci][cj] == 'H') {
                    end_pos = (Point){ci, cj};
                    return;
                }
            }
        }
    }
}

int main() {
    // Input grid dimensions
    //FILE *file = fopen("project.txt", "r");
    scanf("%d %d", &n, &m);

    // Read the grid and find the start ('S') and end ('H') positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'S') start = (Point){i, j};
            if (a[i][j] == 'H') end_pos = (Point){i, j};
        }
    }

    bfs(); // Call BFS to find the shortest path

    // If 'H' is not reachable
    if (!vis[end_pos.x][end_pos.y]) {
        printf("NO PATH FOUND\n");
        return 0;
    }

    // Extract the shortest path
    int path[MAX * MAX]; // Store direction indices
    int len = 0;
    Point cur = end_pos;

    while (!(cur.x == start.x && cur.y == start.y)) {
        int dir = parent[cur.x][cur.y];
        path[len++] = dir; // Store the direction index
        cur.x -= dx[dir]; // Move back to the previous position
        cur.y -= dy[dir];
    }

    // Print the path in reverse order with full words
    for (int i = 0; i < len ; i++) {
        printf("%s ", arr[path[i]]);
    }
    printf("\n");

    return 0;
}
