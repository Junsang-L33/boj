#include<bits/stdc++.h>
using namespace std;

int N,M,V;
vector<int> adj[1002];
bool visited[1002];

void dfs(int V){
	visited[V] = true;
	cout << V << ' ';	
	for(int i=0; i<adj[V].size(); i++){
		int next = adj[V][i];
		if(!visited[next]){
			dfs(next);	
		}	
	}
}

void bfs(int V){
	queue<int> Q;
	Q.push(V);
	visited[V] = true;

	while(!Q.empty()){
		int crr = Q.front();
		Q.pop();
		cout << crr << ' ';
		for(int i=0; i<adj[crr].size(); i++){
			int next = adj[crr][i];
			if(!visited[next]){
				visited[next] = true;
				Q.push(next);	
			}	
		}	
	}
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;

	for(int i=0; i<M; i++){
		int a,b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);	
	}

	for(int i=1; i<=N; i++){
		sort(adj[i].begin(), adj[i].end());	
	}

	fill(visited, visited+N+1, false);
	dfs(V);
	cout<<'\n';

	fill(visited, visited+N+1, false);
	bfs(V);

	return 0;
}
