#include <stdio.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES]; // 방문 여부를 저장하는 배열

typedef struct {
    int count; // 정점의 개수
    int matrix[MAX_VERTICES][MAX_VERTICES]; // 인접 행렬
} Graph;

void initGraph(Graph* graph, int count) {
    graph->count = count;
	int i; 
   for (i = 0; i < count; i++) {
        int j;
		for (j = 0; j < count; j++) {
            graph->matrix[i][j] = 0; // 인접 행렬 초기화
        }
    }
}

void addEdge(Graph* graph, int start, int end) {
    graph->matrix[start][end] = 1; // 간선 추가
    graph->matrix[end][start] = 1; // (무방향 그래프인 경우) 반대 방향 간선 추가
}

void dfs(Graph* graph, int v) {
    visited[v] = 1; // 정점 v를 방문한 것으로 표시
    printf("%d ", v); // 정점 v 출력

    int i;
	for (i = 0; i < graph->count; i++) {
        if (graph->matrix[v][i] && !visited[i]) { // 정점 v와 연결된 인접 정점 중에서 방문하지 않은 정점 찾기
			   dfs(graph, i); // 해당 정점을 시작점으로 재귀 호출
        }
    }
}

int main() {
    Graph graph;
    int vertexCount = 7; // 정점의 개수

    initGraph(&graph, vertexCount);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 2, 6);

    int startVertex = 0; // 시작 정점

    printf("DFS traversal: \n");
    dfs(&graph, startVertex);
	printf("\n");
    return 0;
}

