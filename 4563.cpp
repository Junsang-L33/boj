#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	while(1){
		int a;
		cin>>a;
		if(a == 0){
			return 0;	
		}	
	
		long long a2 =1LL* a * a;
		int cnt = 0;

		for(long long k=1; k*k <= a2; k++){
			if(a2 % k != 0){
				continue;	
		}	
		
			long long d1 = k;  // C - B
			long long d2 = a2 / k; // C + B

			if((d2-d1) % 2 != 0){
				continue;	
			}	
			long long b = (d2 - d1) / 2;
			if(b>a){
				cnt++;	
			}	
			
		}	
			
		cout<<cnt<<'\n';	
		
		}	
		return 0;
}
