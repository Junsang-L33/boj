#include<bits/stdc++.h>
using namespace std;

int arr[10];
int n, m;
bool isused[10];

void backtrace(int k, int l){
	if(k == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << ' ';
		}	
		cout<<"\n";
		return;	
	}
		
	for(int i=l; i<=n; i++){
			arr[k] = i;
			backtrace(k+1, i+1);
		
	}
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	backtrace(0, 1);
	return 0;
}
