#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>> graph; //2차원 벡터. 인접리스트표현
vector<int> visit_order; //정점의 방문순서를 기록

void bfs(int start){
	queue<int> q;
	int order = 1; //첫방문순서는 1부터

	q.push(start);
	visit_order[start] = order++; //순서기록

	while(!q.empty()){
		int crr = q.front();
		q.pop();
//crr의 모든 인접노드 순회
		for(int i=0; i<graph[crr].size(); i++){
			int neighbor = graph[crr][i];	
	//아직 방문하지 않았으면
			if(visit_order[neighbor] == 0){
				visit_order[neighbor] = order++;
				q.push(neighbor);	 //큐에추가
			}
		}	
	}
}

int main(int argc, char* argv[]){
	int n, edge, start; //정점수, 간선수, 시작정점
	scanf("%d %d %d", &n, &edge, &start);

	graph.resize(n+1); //1번부터 사용하기때문에 n+1로 크기 할당
	visit_order.resize(n+1, 0); //모든정점 0으로 초기화

	for(int i=0; i<edge; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v); // u->v 간선 추가
		graph[v].push_back(u); // v->u 간선 추가	
	}

	for(int i=0; i<=n; ++i){
		sort(graph[i].begin(), graph[i].end());	 //오름차순 정렬
	}
	
	bfs(start);

	for(int i=1; i<=n; ++i){
		printf("%d\n", visit_order[i]);	
	}

	return 0;
}
