#include<bits/stdc++.h>
using namespace std;

int n, m;
int maze[102][102];
bool vis[502][502];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0 ,0};

int main(int argc, char* argv[]){
	cin.tie(0);	
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &maze[i][j]);	
		}	
	}

	queue<pair<int,int>> Q;
	vis[0][0] = 1;	
	Q.push({0,0});
	while(!Q.empty()){
		pair<int,int> crr = Q.front();
		Q.pop();
		for(int i=0; i<4; i++){	
		int x = crr.first + dx[i];
		int y = crr.second + dy[i];
		
		if(x < 0 || x >= n || y < 0 || y >= m){
			continue;	
		}
		if(vis[x][y] || !maze[x][y]){
			continue;	
		}	
		vis[x][y] = 1;	
		maze[x][y] = maze[crr.first][crr.second]+1;	
		Q.push({x,y});	
		}	
	}

	cout << maze[n-1][m-1];	





	return 0;
}
