#include<bits/stdc++.h>
using namespace std;

int n;
bool check1[35];
bool check2[35];
bool check3[35];
int cnt = 0;

void check(int x){
	if(x == n){
		cnt++;
		return;	
	}
	
	for(int y=0; y<n; y++){
		if(check1[y] || check2[x+y] || check3[x-y+n-1]){
			continue;	
		}
		check1[y] = 1;
		check2[x+y] = 1;
		check3[x-y+n-1] = 1;
		check(x+1);

		check1[y] = 0;
		check2[x+y] = 0;
		check3[x-y+n-1] = 0;
	}	
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	check(0);	

	cout << cnt;

	return 0;
}
