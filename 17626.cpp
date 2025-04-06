#include<bits/stdc++.h>
using namespace std;

int dp[50001];

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	
	dp[0] = 0;
	int n;

	cin >> n;
	
	for(int i=1; i<= n; i++){
		dp[i] = dp[i-1] + 1;		//worst case (1^2 init)
		for(int j=1; j*j<=i; j++){
			dp[i] = min(dp[i], dp[i-j*j] + 1);	
		} 	
	}

	cout << dp[n];

	return 0;
}
