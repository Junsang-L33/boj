#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long N;
	long long M;
	cin >> N >> M;

	long long tensplace = N/10;
	long long onesplace = N%10;
	long long tmp=1;
	long long ans = 0;

	if(tensplace > 0){
	
		for(int i=9; i>0; i--){
			tmp = tmp * i;	
		}
			tmp %= 10;			
			ans = tensplace * tmp;	
	}

	else{
		for(int i=onesplace; i>0; i--){
			tmp = tmp * i;  	
		}	
		ans = tmp;	
	}
	
	cout<<ans%7;


	return 0;
}
