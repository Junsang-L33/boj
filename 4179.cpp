#include<bits/stdc++.h>
using namespace std;

string maze[1002];
int n, m;
int Fire[1002][1002];
int Jhoon[1002][1002];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=0; i<n; i++){
		cin >> maze[i];	
	}
	
	for(int i=0; i<n; i++){
		fill(Fire[i], Fire[i]+m, -1);	
		fill(Jhoon[i], Jhoon[i]+m, -1);	
	}


	queue<pair<int,int>> Q1;
	queue<pair<int,int>> Q2;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(maze[i][j] == 'F'){
				Q1.push({i,j});
				Fire[i][j] = 0;	
			}	
			if(maze[i][j] == 'J'){
				Q2.push({i,j});
				Jhoon[i][j] = 0;	
			}	
		}	
	}
	
	while(!Q1.empty()){
		pair<int,int> crr = Q1.front();
		Q1.pop();

		for(int i=0; i<4; i++){
			int x = crr.first + dx[i];
			int y = crr.second + dy[i];	
			
			if(x < 0 || x >= n || y < 0 || y >= m){
				continue;	
			}		
			if(Fire[x][y] >= 0 || maze[x][y] == '#'){
				continue;	
			}	
			
			Fire[x][y] = Fire[crr.first][crr.second] + 1;		
			Q1.push({x,y});
		}	
	}
	
	while(!Q2.empty()){
		pair<int,int> crr = Q2.front();
		Q2.pop();	
		for(int i=0; i<4; i++){
			int x = crr.first + dx[i];
			int y = crr.second + dy[i];	
			
			if(x < 0 || x >= n || y < 0 || y >= m){
				cout << Jhoon[crr.first][crr.second] +1;
				return 0;	
			}
		
			if(maze[x][y] == '#' || Jhoon[x][y] >= 0 ){
				continue;	
			}
			if(Fire[x][y] != -1 && Jhoon[crr.first][crr.second]+1 >= Fire[x][y]){
				continue;	
			}
			
			Jhoon[x][y] = Jhoon[crr.first][crr.second] + 1;		
			Q2.push({x,y});	
		}		
	}
	cout << "IMPOSSIBLE";
	


	return 0;
}
