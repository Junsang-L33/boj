#include<bits/stdc++.h>
using namespace std;

int coin[11];

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	for(int i=0; i<N; i++){
		cin >> coin[i];	
	}
	int num = 0;

	for(int i=N-1; i >= 0; i--){
		if(K < coin[i]){
			continue;	
		}	
		if(K == 0){
			break;	
		}	
		num += K / coin[i];
		K = K % coin[i];
	}

	cout << num;

	return 0;
}
