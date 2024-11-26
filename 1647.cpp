#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Edge{
	int u;
	int v;
	int weight;
}Edge;
//가중치 비교후 b가 a보다 크면 1반환
int compare(Edge a, Edge b){
	return a.weight < b.weight;
}
//부모 찾는 함수
int findParent(int node, vector<int> &parent){
	if(parent[node] != node){
		parent[node] = findParent(parent[node], parent);	
	}
	return parent[node];
}
//트리의 높이비교해서 작은걸 큰쪽으로 병합시키는 함수
void unionNodes(int u, int v, vector<int> &parent, vector<int> &rank){
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
//크루스칼 알고리즘
int kruskal(int V, vector<Edge> &edges){
	
	sort(edges.begin(), edges.end(), compare);//오름차순으로 정렬
	//compare함수 가서 1이 반환되면 앞으로 오도록 정렬. 0반환되면 뒤로정렬

	vector<int> parent(V+1);
	vector<int> rank(V+1, 0);

	for(int i=1; i<= V; ++i){
		parent[i] = i;	
	}

	int mstWeight =0;
	int maxEdgeWeight = 0; //마지막에 지울 간선의 가중치 (가중치가 가장큰거)

	for(int i=0; i< edges.size(); ++i){
		Edge edge = edges[i];	

		if(findParent(edge.u, parent) != findParent(edge.v, parent)){
			mstWeight += edge.weight;
			maxEdgeWeight = edge.weight; //계속 for문 돌면서 바뀌다가 맨마지막(가중치가 가장큰거) 로 설정됨	
			unionNodes(edge.u, edge.v, parent, rank);	
		}
	}
	mstWeight = mstWeight - maxEdgeWeight; //가장 가중치가 큰 간선을 끊어서 두개의 마을로 분할
	return mstWeight;
}

int main(int argc, char* argv[]){
	int V, E;
	scanf("%d %d", &V, &E);

	vector<Edge> edges(E);
	
	for(int i=0; i<E; ++i){
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
	}
	
	int result = kruskal(V, edges);

	printf("%d\n", result);

	return 0;
}
