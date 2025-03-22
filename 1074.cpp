#include<bits/stdc++.h>
using namespace std;

int N, r, c;

int recur(int n,int x,int y){
	if(n == 0){
		return 0;	
	}
	int center = (1<<(n-1));
	
	if(r < x + center && c < y + center){
		return recur(n-1, x, y);	
	}
	if(r < x + center && c >= y + center){
		return center * center + recur(n-1, x, y + center);	
	}
	if(r >= x + center && c < y + center){
		return 2 * center * center + recur(n-1, x + center , y);	
	}
	return 3 * center * center + recur(n-1, x + center, y + center);
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin>>N>>r>>c;

	cout<<recur(N,0,0);

	return 0;
}
