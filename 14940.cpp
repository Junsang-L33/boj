#include<bits/stdc++.h>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	queue<pair<int,int>> Q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>board[i][j];
			dist[i][j] = -1;
			if(board[i][j] == 0){
				dist[i][j] = 0;	
			}	
			if(board[i][j] == 2){
				dist[i][j] = 0;
				Q.push({i,j});	
			}	
		}	
	}

	while(!Q.empty()){
		pair<int,int> crr = Q.front();
		Q.pop();

		for(int i=0; i<4; i++){
			int x = crr.first + dx[i];
			int y = crr.second + dy[i];

			if(x < 0 || x >= n || y < 0 || y >= m){
				continue;	
			}
			if(dist[x][y] != -1 || board[x][y] == 0){
				continue;	
			}	
			
			dist[x][y] = dist[crr.first][crr.second]+1;
			Q.push({x,y});	
		}		
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout << dist[i][j] << ' ';	
		}	
		cout<<'\n';	
	}


	return 0;
}
