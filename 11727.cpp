#include<stdio.h>

using namespace std;

int main(int argc, char* argv[]){
	int n;
	scanf("%d", &n);
	int dp[1001];

	dp[1] = 1;
	dp[2] = 3;

	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1] + dp[i-2] *2) %10007;	
	}
	
	printf("%d", dp[n]);

	return 0;
}
