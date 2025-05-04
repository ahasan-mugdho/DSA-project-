//                                      MAP TO REACH DESTINATION

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 105 // Maximum grid size

// Global variables
int n, m;                      // Grid dimensions
char a[MAX][MAX];              // Grid representation
bool vis[MAX][MAX];            // Visited matrix for BFS
int parent[MAX][MAX];          // To store the direction we came from
int dx[4] = {0, 0, -1, 1};     // Movement in x-axis (Right, Left, Up, Down)
int dy[4] = {1, -1, 0, 0};     // Movement in y-axis
char arr[4][10] = {"Right", "Left", "UP", "Down"}; // Direction names

// Structure to hold a point (x, y) in the grid
typedef struct {
    int x, y;
} Point;

Point start, end_pos; // Start and Destination points

// Function to check if the point is within grid bounds
bool check(int ci, int cj) {
    return ci >= 0 && cj >= 0 && ci < n && cj < m;
}

// Queue structure for BFS
typedef struct {
    Point data[MAX * MAX];
    int front, rear;
} Queue;

// Initialize the queue
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is empty
bool isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Add element to the queue
void push(Queue *q, Point p) {
    q->data[q->rear++] = p;
}

// Remove element from the queue
Point pop(Queue *q) {
    return q->data[q->front++];
}

// Perform BFS to find the shortest path from 'S' to 'D'
void bfs() {
    Queue q;
    initQueue(&q);
    push(&q, start);
    vis[start.x][start.y] = true;

    // Explore the grid in 4 directions
    while (!isEmpty(&q)) {
        Point p = pop(&q);

        for (int i = 0; i < 4; i++) {
            int ci = p.x + dx[i];
            int cj = p.y + dy[i];

            // Check valid, unvisited, and not blocked
            if (check(ci, cj) && !vis[ci][cj] && a[ci][cj] != '#') {
                vis[ci][cj] = true;
                parent[ci][cj] = i; // Store direction index
                push(&q, (Point){ci, cj});

                // Stop if we reached the destination 'D'
                if (a[ci][cj] == 'D') {
                    end_pos = (Point){ci, cj};
                    return;
                }
            }
        }
    }
}

int main() {
    // Input grid size
    scanf("%d %d", &n, &m);

    // Input grid characters and locate 'S' and 'D'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'S') start = (Point){i, j};
            if (a[i][j] == 'D') end_pos = (Point){i, j};
        }
    }

    // Run BFS to find shortest path
    bfs();

    // If destination was not reached
    if (!vis[end_pos.x][end_pos.y]) {
        printf("\nNO PATH FOUND\n");
        return 0;
    }

    // Reconstruct path from destination back to start
    int path[MAX * MAX];
    int len = 0;
    Point cur = end_pos;

    while (!(cur.x == start.x && cur.y == start.y)) {
        int dir = parent[cur.x][cur.y];
        path[len++] = dir;
        cur.x -= dx[dir];
        cur.y -= dy[dir];
    }

    // Print the path in reverse with direction arrows
    printf("\nPath: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%s", arr[path[i]]);
        if (i != 0) printf(" -> "); // Add arrow between directions
    }

    // Print directional guide for user clarity
    printf("\n\n");
    printf("                            UP\n");
    printf("                            ^\n");
    printf("                            |\n");
    printf("           LEFT    <-    direction   ->   RIGHT\n");
    printf("                            |\n");
    printf("                            v\n");
    printf("                          DOWN\n");

    return 0;
}


/*5 7
S . . # . . .
# # . # . # .
. . . . . # D
# . # # . . .
. . . . # . .
*/
