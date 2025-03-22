#include<bits/stdc++.h>
using namespace std;

int dp[102];

int fibo(int n){
	if(n == 0 || n == 1){
		return dp[n];	
	}
	else if(dp[n] == 0){
		dp[n] = fibo(n-1) + fibo(n-2);	
	}	
	return dp[n];
} 

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin>>T;
	
	dp[0] = 0;
	dp[1] = 1;	

	int n;

	for(int i=0; i<T; i++){
		cin >> n;
		if(n == 0){
			cout<< "1 0" << '\n';	
		}
		else{
			cout << fibo(n-1) << ' ' << fibo(n) << '\n';
		}	
	}

	return 0;
}
