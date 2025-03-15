#include<bits/stdc++.h>
using namespace std;

int arr[10];
int n, m;

void bt(int k){
	if(k == m){
		for(int i=0; i<m; i++){
		cout<< arr[i] <<' ';	
		}
		cout << "\n";
		return;
	}

	for(int i=1; i<=n; i++){
			arr[k] = i;
			bt(k+1);
	}
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	bt(0);
	return 0;
}
