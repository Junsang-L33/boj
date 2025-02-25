#include<bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){

	int N, M;
	scanf("%d %d", &N, &M);
	
	int arr[N+1][M+1];
	int dp[N+1][M+1];

	//init
	for(int i=0; i<N+1; i++){
		for(int j=0; j<M+1; j++){
			dp[i][j] = 0;	
		}	
	}

	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			scanf("%d", &arr[i][j]);		
		}	
	}
	
	for(int i=1; i<N+1; i++){
		for(int j=1; j<M+1; j++){
			dp[i][j] = arr[i][j] + max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
		}	
	}
	
	printf("%d", dp[N][M]);	



	return 0;
}
