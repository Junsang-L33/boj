#include<bits/stdc++.h>
using namespace std;

int n, k;
int dist[100002];

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>k;

	fill(dist, dist+100001, -1);
	dist[n] = 0;	//start point

	queue<int> Q;
	Q.push(n);

	while(dist[k] == -1){ //searching while unvisited
		int crr = Q.front();
		Q.pop();
		for(int next : {crr-1, crr+1, crr * 2}){
			if(next < 0 || next > 100000){
				continue;	
			}	
			if(dist[next] != -1){ //if visited
				continue;	
			}	
			dist[next] = dist[crr]+1;
			Q.push(next);
		}	
	}

	cout << dist[k];


	return 0;
}
