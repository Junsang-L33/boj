#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<pair<int, int>> mat(n+1);
	for(int i=1; i<=n; i++){
		cin >> mat[i].first >> mat[i].second;	
	}
	
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

	for(int len = 2; len <= n; len++){
		for(int i=1; i+len - 1<=n; i++){
			int j = i + len - 1;
			dp[i][j] = INT_MAX;	

			for(int k = i; k<j; k++){
				int cost = dp[i][k] + dp[k+1][j] + mat[i].first * mat[k].second * mat[j].second;	
				dp[i][j] = min(dp[i][j], cost);	
			}
		}	
	}

	cout << dp[1][n] << '\n';

	return 0;
}
