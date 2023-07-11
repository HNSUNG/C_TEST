#include <stdio.h>
#include <stdbool.h>

#define INF 999999 // 무한대 값

#define MAX_VERTICES 100

int minDistance(int dist[], bool sptSet[], int vertexCount) {
    int min = INF, minIndex;
	int v;
    for (v = 0; v < vertexCount; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int dist[], int vertexCount) {
    printf("Vertex \tDistance from Source\n");
   int v;
	 for (v = 0; v < vertexCount; v++) {
        printf("%d \t%d\n", v, dist[v]);
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int startVertex, int vertexCount) {
    int dist[MAX_VERTICES]; // 시작 정점으로부터의 최단 거리를 저장하는 배열
    bool sptSet[MAX_VERTICES]; // 최단 경로가 확정된 정점인지 여부를 저장하는 배열

   int v;
	 for (v = 0; v < vertexCount; v++) {
        dist[v] = INF;
        sptSet[v] = false;
    }

    dist[startVertex] = 0; // 시작 정점의 거리는 0

	int count;
    for (count = 0; count < vertexCount - 1; count++) {
        int u = minDistance(dist, sptSet, vertexCount);
        sptSet[u] = true;

	int v;
        for (v = 0; v < vertexCount; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, vertexCount);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };
    int startVertex = 0;
    int vertexCount = 9;

    dijkstra(graph, startVertex, vertexCount);

    return 0;
}

