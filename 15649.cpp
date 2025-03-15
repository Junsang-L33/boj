#include<bits/stdc++.h>
using namespace std;

int arr[10];
int m, n;
bool isused[10];

void backtrace(int k){
	
	if(k == m){
		for(int i=0; i<m; i++){
			cout << arr[i] << ' ';	
		}	
		cout<<"\n";	
		return;
	}

	for(int i=1; i<=n; i++){
		if(!isused[i]){
			arr[k] = i;
			isused[i] = 1;
			backtrace(k+1);
			isused[i] = 0;	
		}				
	}	
}


int main(int argc, char* argv[]){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	//1~N까지 자연수중
	//중복없이 M개를 고른수열

	backtrace(0);	




	return 0;
}
