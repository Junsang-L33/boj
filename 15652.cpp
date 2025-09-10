#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];

void run(int d, int s){
	if(d == m){
		for(int i=0; i<m; i++){
			cout<<arr[i]<<' ';	
		}	
		cout<<'\n';	
		return;
	}
	for(int i = s; i<=n; i++){
		arr[d] = i;	
		run(d+1, i);
	}
}


int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	run(0, 1);




	return 0;
}
