#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct Edge{
	int u;
  int	v;
  int	weight;
}Edge;
//오름차순 정렬을 위한 비교함수
int compareEdges(Edge a, Edge b){
	return a.weight < b.weight; //a가 b보다 가중치가 작으면 1반환
}

int findParent(int node, vector<int> &parent){
	if(parent[node] != node){//루트가 아닐때
		parent[node] = findParent(parent[node], parent);//부모찾음
	}
	return parent[node];
}

void unionNodes(int u, int v, vector<int> &parent, vector<int> &rank){
	int rootU = findParent(u, parent); //u의 root찾음
	int rootV = findParent(v, parent); //v의 root찾음

	if(rootU != rootV){ //두 노드의 root가 다르면
			//높이가 더 높은 트리에 병합
		if(rank[rootU] > rank[rootV]){
			parent[rootV] = rootU;	
		}	
		else if(rank[rootU] < rank[rootV]){
			parent[rootU] = rootV;	
		}	
		else{ //높이가 같으면
			parent[rootV] = rootU; //rootU에 rootV를 붙이고 U의 높이 1증가시킴 
			rank[rootU]++;	
		}	
	}
}

int kruskalMST(int V, vector<Edge> &edges){
		//가중치 오름차순 정렬
	sort(edges.begin(), edges.end(), compareEdges);

	vector<int> parent(V+1); //부모배열
	vector<int> rank(V+1, 0); //높이배열 0으로 초기화

	for(int i=0; i<=V; ++i){
		parent[i] = i;	//자신으로 초기화 
	}
	
	int mstWeight = 0; //MST가중치 합
	for(int i=0; i< edges.size(); ++i){
		Edge edge = edges[i];
		//사이클이 없으면 (부모가 같으면 사이클발생한거)
		if(findParent(edge.u, parent) != findParent(edge.v, parent)){
			mstWeight += edge.weight;
			unionNodes(edge.u, edge.v, parent, rank);	 //두개 같은부모로 병합
		}	
	}
	return mstWeight;
}


int main(int argc, char* argv[]){
	int V, E;
	scanf("%d %d", &V, &E);

	vector<Edge> edges(E);
	for(int i=0; i<E; ++i){
		scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);	
	}
	
	int result = kruskalMST(V, edges);
	printf("%d\n", result);

		return 0;
}
