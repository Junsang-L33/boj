#include<bits/stdc++.h>
using namespace std;

int n, m;
int box[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;	
	queue<pair<int,int>> Q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> box[i][j];	
			if(box[i][j]==1){
				Q.push({i,j});	//start point
			}	
			if(box[i][j] == 0){ //unripe tomatoes
				dist[i][j] = -1;	
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
			if(dist[x][y] >= 0){ //if exist tomato in the box or empty box, value is 0
				continue;	
			}	
			dist[x][y] = dist[crr.first][crr.second] + 1;		
			Q.push({x,y});
		}
	}
	int max_value = 0;	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(dist[i][j] == -1){
				cout << -1;	//can not traverse all tomatoes
				return 0;
			}	
		max_value = max(max_value, dist[i][j]);
		}	
	}
	cout << max_value;


	return 0;
}
