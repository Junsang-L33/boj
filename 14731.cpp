#include<bits/stdc++.h>
using namespace std;

int c[100002];
int k[100002];
queue<pair<long long,int>> result;
long long ans;

long long power(long long base, int exp){
	long long res = 1;
	while(exp > 0){
		if(exp % 2 == 1){
			res = (res * base) % 1000000007;	
		}	
		base = (base * base) % 1000000007;
		exp /= 2;
	}
	return res;
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> c[i] >> k[i];
	}
	
	for(int i=0; i<n; i++){
		if(k[i] > 0){
			result.push({(1LL * c[i]*k[i])%1000000007 ,k[i] - 1 });	
		}
	}
	
	while(!result.empty()){
		pair<long long,int>crr = result.front();
		//계수, 차수	
		if(crr.second < 0){
			result.pop();
			continue;	
		}	
		
		long long t = (1LL * crr.first * power(2, crr.second)) % 1000000007;	
		ans = (ans + t) % 1000000007;	
			
		result.pop();	
	}	
	
	cout << ans;



	return 0;
}
