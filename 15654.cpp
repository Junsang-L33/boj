#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<int> ans;
bool isUsed[8];

void dfs(int depth){
	if(depth == m){ 
		for(int x : ans){
			cout << x << ' ';	
		}	
		cout<<'\n';	
		return;
	}
	
	for(int i=0; i<n; i++){
		if(isUsed[i]){ //used check
			continue;	
		}	
		ans.push_back(v[i]); //add num	
		isUsed[i] = true; //used
		
		dfs(depth + 1); //recursive call

		ans.pop_back();  //return state
		isUsed[i] = false;
	}
	return;
}


int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for(int i=0; i<n; i++){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);	
	}
	
	sort(v.begin(), v.end());	

	dfs(0);

	return 0;
}
