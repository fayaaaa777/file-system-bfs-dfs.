#include <stdio.h>
#include <string.h>

#define MAX_NODES 50
#define NAME_LEN 100

char names[MAX_NODES][NAME_LEN];
int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int n;

int findNode(const char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

int bfs(int start, int target) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int found = 0;

    for (int i = 0; i < n; i++) visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%s ", names[current]);

        if (current == target) found = 1;

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\nBFS result: File %s.\n", found ? "FOUND" : "NOT FOUND");
    return found;
}

void dfsVisit(int current, int target, int *found) {
    visited[current] = 1;
    printf("%s ", names[current]);

    if (current == target) *found = 1;

    for (int i = 0; i < n; i++) {
        if (graph[current][i] && !visited[i]) {
            dfsVisit(i, target, found);
        }
    }
}

int dfs(int start, int target) {
    int found = 0;

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("DFS traversal: ");
    dfsVisit(start, target, &found);
    printf("\nDFS result: File %s.\n", found ? "FOUND" : "NOT FOUND");
    return found;
}

int main(void) {
    int edges, from, to;
    char startName[NAME_LEN], targetName[NAME_LEN];

    printf("File System Representation using BFS and DFS\n");
    printf("Enter number of nodes (1-%d): ", MAX_NODES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_NODES) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter name for node %d (no spaces): ", i);
        scanf("%99s", names[i]);
    }

    printf("Enter number of connections (edges): ");
    if (scanf("%d", &edges) != 1 || edges < 0 || edges > n * (n - 1)) {
        printf("Invalid number of edges.\n");
        return 1;
    }

    printf("Enter each connection using two node names (example: root docs):\n");
    for (int i = 0; i < edges; i++) {
        char first[NAME_LEN], second[NAME_LEN];
        printf("Edge %d: ", i + 1);
        scanf("%99s %99s", first, second);

        from = findNode(first);
        to = findNode(second);

        if (from == -1 || to == -1) {
            printf("Unknown node name. Please run the program again and enter valid names.\n");
            return 1;
        }

        /* File-system connections are treated as undirected for this graph activity. */
        graph[from][to] = 1;
        graph[to][from] = 1;
    }

    printf("Enter starting node: ");
    scanf("%99s", startName);
    printf("Enter file name to search for: ");
    scanf("%99s", targetName);

    int start = findNode(startName);
    int target = findNode(targetName);

    if (start == -1) {
        printf("Starting node '%s' does not exist.\n", startName);
        return 1;
    }

    if (target == -1) {
        printf("Target '%s' is not present in the list of nodes.\n", targetName);
        printf("BFS result: File NOT FOUND.\n");
        printf("DFS result: File NOT FOUND.\n");
        return 0;
    }

    printf("\n");
    bfs(start, target);
    dfs(start, target);

    return 0;
}
