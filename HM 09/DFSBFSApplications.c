#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front, rear;
int n;

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int i, v;
    front = 0;
    rear = -1;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int i, j, start, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    while (1) {
        printf("\n1. DFS");
        printf("\n2. BFS");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (i = 0; i < n; i++)
                visited[i] = 0;

            printf("Enter starting vertex: ");
            scanf("%d", &start);

            printf("DFS Traversal: ");
            DFS(start);
            printf("\n");
            break;

        case 2:
            printf("Enter starting vertex: ");
            scanf("%d", &start);

            printf("BFS Traversal: ");
            BFS(start);
            printf("\n");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
