#include<bits/stdc++.h>
using namespace std;

long long dp[101];

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; 
	cin >> T;
	int N[T];

	for(int i=0; i<T; i++){
		cin >> N[i];	
	}

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	int maxx = 0;

	for(int i=0; i<T; i++){
		maxx = max(maxx, N[i]);	
	}	

	for(int i=4; i<=maxx; i++){
		dp[i] = dp[i-3] + dp[i-2];
	}
	
	for(int i=0; i<T; i++){
		cout << dp[N[i]] << '\n';
	}


	return 0;
}
