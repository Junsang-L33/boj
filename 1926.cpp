#include<bits/stdc++.h>
using namespace std;

int n, m;
int paper[502][502];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool vis[502][502];

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n>>m;	 
		for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >>paper[i][j];	
		}	
	}
	int picnum=0;
	int max_size = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){	
			if(vis[i][j]==1 || paper[i][j]==0){
				continue;	
			}	
			picnum++;	
			queue<pair<int,int>> Q;
			vis[i][j] = 1;
			Q.push({i,j});

			int picsize = 0;
			while(!Q.empty()){
				picsize++;		
				pair<int,int> crr = Q.front();
				Q.pop();

				for(int k=0; k<4; k++){
					int x = crr.first + dx[k];
					int y = crr.second + dy[k];	
			
					if(x < 0 || x >= n || y < 0 || y >= m){
						continue;
					}	
					if(vis[x][y] == 1 || paper[x][y] == 0){
						continue;	
					}	
					vis[x][y] = 1;
					Q.push({x,y});	
				}
			}
			max_size = max(max_size, picsize);	
		}
	}
	cout<<picnum<<"\n"<<max_size;	
	return 0;
}
