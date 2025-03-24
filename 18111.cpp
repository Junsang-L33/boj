#include<bits/stdc++.h>
using namespace std;

int block;
int n, m;
int ground[502][502];

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> block;

	int minH = 256;
	int maxH = 0;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> ground[i][j];	
			minH = min(minH, ground[i][j]);
			maxH = max(maxH, ground[i][j]);	
		}	
	}

	int result_time = 1e9;
	int result_height = 0;

	for(int h = minH; h<= maxH; h++){
		int time = 0;
		int inventory = block;

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int diff = ground[i][j] - h;
				if(diff > 0){ //remove block
					time += 2 * diff;
					inventory += diff;	
				}		
				else if(diff < 0 ){
					time += -1 * diff;
					inventory += diff;	
				}	
			}	
		}	
	
		if(inventory >= 0){
			if(time < result_time || (time == result_time && h > result_height)){
				result_time = time;
				result_height = h;	
			}	
		}	
	}

	cout << result_time << ' ' << result_height;



	return 0;
}
