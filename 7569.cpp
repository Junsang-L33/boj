#include<bits/stdc++.h>
using namespace std;

int m, n, h;
int box[102][102][102];
int dist[102][102][102];
int dx[6] = {0, 0, 0, 0, -1, 1}; //위 아래 상 하 좌 우 
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	queue<tuple<int,int,int>> Q;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				cin >> box[i][j][k];	
				if(box[i][j][k] == 1){
					Q.push(make_tuple(i,j,k));	//i == height j == row k == column
				}
				else if(box[i][j][k] == 0){
					dist[i][j][k] = -1;	
				}
				else{
					dist[i][j][k] = -2;	
				}	
			}	
		}	
	}
	
	while(!Q.empty()){
		tuple<int,int,int> crr = Q.front();	
		Q.pop();

		for(int i=0; i<6; i++){
			int x = get<1>(crr) + dx[i];
			int y = get<2>(crr) + dy[i];
			int z = get<0>(crr) + dz[i];
			if(x < 0 || x >= n || y < 0 || y >= m || z < 0 || z >= h){
				continue;	
			}	
			if(dist[z][x][y] != -1){
				continue;	
			}	
			dist[z][x][y] = dist[get<0>(crr)][get<1>(crr)][get<2>(crr)] + 1;	
			Q.push(make_tuple(z,x,y));	
			}
			
	}
	int max_value = 0;
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(dist[i][j][k] == -1){
					cout<<-1;
					return 0;	
				}
				if(dist[i][j][k] > max_value){	
					max_value = max(max_value, dist[i][j][k]);	
				}
			}	
		}	
	}
	cout << max_value;


	return 0;
}
