#include<stdio.h>

int main(int argc, char* argv[]){

		int n;
		scanf("%d", &n);

		int dp[101][12];
		for(int i=1; i<n+1; i++){
			for(int j=0; j<13; j++){
				dp[i][j] = 0;	
			}	
		}

		for(int i=2; i<11; i++){
			dp[1][i] = 1;	
		}	
		dp[1][0] = 0;
		dp[1][1] = 0;
		dp[1][11] = 0;
	
		for(int i=2; i<n+1; i++){
			for(int j=1; j<11; j++){
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;	
			}	
		}

	int sum = 0;
	for(int i=1; i<11; i++){
		sum = (sum + dp[n][i]) % 1000000000;	
	}
	
	printf("%d", sum);

	return 0;
}
