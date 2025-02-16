#include<stdio.h>

int main(int argc, char* argv[]){
	int n;
	scanf("%d", &n);
	int dp[1001][10];

	for(int i=0; i<10; i++){
		dp[1][i] = 1;	
	}
	
	for(int i=2; i<n+1; i++){
		for(int j=0; j<10; j++){
			dp[i][j] = 0;
			for(int k=j; k<10; k++){
				dp[i][j] = (dp[i][j] + dp[i-1][k]) % 10007;
			}	
		}	
	}
	int result = 0;
	for(int i=0; i<10; i++){
		result = (result + dp[n][i]) % 10007;	
	}
	printf("%d", result);

	return 0;
}
