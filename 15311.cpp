#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cout << 2000 << '\n';
	//10^6 까지 요구함. 2000봉까지 올려놓을 수 있으니까, 1000봉은 약 1000개씩 넣고, 1000봉은 1개씩 넣으면
	//모든 경우에 성립함
	for(int i = 0; i<1000; i++){
		cout << 1 << ' ';	
	}
	for(int i = 0; i<1000; i++){
		cout << 1000 << ' ';
	}
	return 0;
}
