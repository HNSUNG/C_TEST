#include <stdio.h>
#include <stdbool.h>

#define INF 999999 // 무한대 값

#define MAX_VERTICES 100

int minKey(int key[], bool mstSet[], int vertexCount) {
    int min = INF, minIndex;
   int v;
	 for (v = 0; v < vertexCount; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertexCount) {
    printf("Edge \tWeight\n");
   int i;
	 for (i = 1; i < vertexCount; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertexCount) {
    int parent[MAX_VERTICES]; // 최소 비용 신장 트리의 부모 정점을 저장하는 배열
    int key[MAX_VERTICES]; // 각 정점의 키 값(가중치)을 저장하는 배열
    bool mstSet[MAX_VERTICES]; // 최소 비용 신장 트리에 포함된 정점인지 여부를 저장하는 배열

	int v;
    for (v = 0; v < vertexCount; v++) {
        key[v] = INF;
        mstSet[v] = false;
    }

    key[0] = 0; // 시작 정점의 키 값을 0으로 설정
    parent[0] = -1; // 시작 정점은 부모 정점이 없음
	
	int count;
    for (count = 0; count < vertexCount - 1; count++) {
        int u = minKey(key, mstSet, vertexCount);
        mstSet[u] = true; // 최소 비용 신장 트리에 포함

	int v;
        for (v = 0; v < vertexCount; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, vertexCount);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };
    int vertexCount = 5;

    primMST(graph, vertexCount);
}
