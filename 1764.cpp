#include<bits/stdc++.h>
using namespace std;

int N,M;
set<string> neverHeard;
vector<string> result;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string name;
	cin>>N>>M;

	for(int i=0; i<N; i++){
		cin>>name;
		neverHeard.insert(name);	
	}

	for(int i=0; i<M; i++){
		cin >> name;

		if(neverHeard.find(name) != neverHeard.end()){
			result.push_back(name);	
		}	
	}

	sort(result.begin(), result.end());

	cout<<result.size()<<'\n';

	for(auto& s : result){
		cout<<s<<'\n';	
	}

	return 0;
}
