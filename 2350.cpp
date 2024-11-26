#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

typedef struct Edge{
    int u, v, weight;
}Edge;

typedef struct Route{
    int u, v; //출발지와 도착지
}Route;

int compare(Edge a, Edge b){
    return a.weight > b.weight;
}

int findParent(int node, int parent[]){
    if(parent[node] != node){
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionNodes(int u, int v, int parent[], int rank[]){
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if(rootU != rootV){
        if(rank[rootU] > rank[rootV]){
            parent[rootV] = rootU;
        }
        else if(rank[rootU] < rank[rootV]){
            parent[rootU] = rootV;
        }
        else{
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// BFS로 두 노드 간 최대 가중치 찾기
int bfs(int start, int end, pair<int, int> graph[][100], int graphSize[], int N){
    int visited[N + 1] = {0};
    queue<pair<int, int>> q;
    q.push(pair<int, int>(start, INT_MAX)); //시작노드 큐에추가. 가중치 INT_MAX로 초기화
    visited[start] = 1; //방문플래그 1

    while(!q.empty()){
        int node = q.front().first; //노드번호
        int crrMaxWeight = q.front().second; // 현재 최대 가중치
        q.pop();

        if(node == end){ // 도착하면 최대 가중치 리턴  
            return crrMaxWeight;
        }

        for(int i = 0; i < graphSize[node]; i++){
            int nextNode = graph[node][i].first; // 이웃노드 
            int edgeWeight = graph[node][i].second; // 현재 간선 가중치

            if(!visited[nextNode]){ // 이웃노드 방문X면 
                visited[nextNode] = 1;

                int newWeight;
                if(crrMaxWeight < edgeWeight){
                    newWeight = crrMaxWeight;
                }
                else{
                    newWeight = edgeWeight;
                }

                q.push(pair<int, int>(nextNode, newWeight)); // 이웃노드, 최대가중치 -> 큐에추가
            }
        }
    }
    return -1; // 경로가 없는 경우
}

void kruskal(int N, vector<Edge> &edges, pair<int, int> graph[][100], int graphSize[]){
    int parent[N + 1];
    int rank[N + 1] = {0};

    for(int i = 1; i <= N; ++i){
        parent[i] = i;
        graphSize[i] = 0; // 초기화
    }

    sort(edges.begin(), edges.end(), compare);
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if(findParent(u, parent) != findParent(v, parent)){
            unionNodes(u, v, parent, rank);
            graph[u][graphSize[u]++] = pair<int, int>(v, weight);
            graph[v][graphSize[v]++] = pair<int, int>(u, weight);
        }
    }
}

int main(int argc, char* argv[]){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vector<Edge> edges(M);
    Route routes[K];
    pair<int, int> graph[N + 1][100]; // 그래프 연결 정보 저장, 최대 100개
    int graphSize[N + 1] = {0}; // 각 노드의 연결된 간선 수

    for(int i = 0; i < M; ++i){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    for(int i = 0; i < K; ++i){
        scanf("%d %d", &routes[i].u, &routes[i].v);
    }

    kruskal(N, edges, graph, graphSize);

    // 각 노선에 대해 BFS로 최대 가중치 찾기
    for(int i = 0; i < K; ++i){
        int start = routes[i].u; // 시작노드 
        int end = routes[i].v; // 도착노드 
        int maxWeight = bfs(start, end, graph, graphSize, N); // 최대가중치 
        printf("%d\n", maxWeight);  // 결과출력 
    }

    return 0;
}

