#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> graph; //2차원 벡터
vector<bool> visited; //방문여부 기록
int virus_count = 0; //감염된 컴퓨터 수

void dfs(int node){
	visited[node] = true; //방문
	virus_count++; //감염된 컴퓨터 수 증가
	//인접노드 방문
	for(int i=0; i<graph[node].size(); i++){
		int neighbor = graph[node][i];
		if(!visited[neighbor]){
			dfs(neighbor);	
		}	
	}

}

int main(int argc, char* argv[]){
	int n, edge; //정점 수, 간선 수
	scanf("%d %d", &n, &edge);
	
	graph.resize(n+1);
	visited.resize(n+1, false); //모두 미방문 상태로 초기화

	for(int i=0; i<edge; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
//오름차순 정렬
	for(int i=1; i<=n; ++i){
		sort(graph[i].begin(), graph[i].end());	
	}
	
	dfs(1); //1번 컴퓨터에서 시작
	printf("%d\n", virus_count - 1);

	return 0;
}
