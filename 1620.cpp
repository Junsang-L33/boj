#include<bits/stdc++.h>
using namespace std;

int N, M;
map<int, string> KtoV;
map<string, int> VtoK;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>M>>N;

	for(int i=1; i<=M; i++){
		string value;
		cin>>value;

		KtoV[i] = value;
		VtoK[value] = i;	
	}	

		string problem[N+2];
	for(int i=1; i<=N; i++){
		cin >> problem[i];	

		if(isdigit(problem[i][0])){
			int num = stoi(problem[i]);
			cout<<KtoV[num]<<'\n';	
		}	
		else{
			cout<<VtoK[problem[i]]<<'\n';	
		}	
	}


	return 0;
}
