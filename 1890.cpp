#include<bits/stdc++.h>

int main(int argc, char* argv[]){
	
	int N;
	scanf("%d", &N);

	long long arr[N][N];
	long long dp[N][N];

	//init
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			dp[i][j] = 0;	
		}	
	}

	dp[0][0] = 1;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%lld", &arr[i][j]);	
		}	
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] > 0 && dp[i][j] > 0){
				if(arr[i][j] + i < N){
					dp[i+arr[i][j]][j] += dp[i][j];
				}	
				if(arr[i][j] + j < N){
					dp[i][j+arr[i][j]] += dp[i][j];	
				}	
			}
		}	
	}

	printf("%lld", dp[N-1][N-1]);


	return 0;
}
