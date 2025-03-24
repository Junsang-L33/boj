#include<bits/stdc++.h>
using namespace std;

int T;
string p;
int n;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for(int k=0; k<T; k++){
		deque<int> x;
		cin >> p;	
		
		cin >> n;
		
		if(n>0){		
			string input;
			cin >> input;
		

			for(char &c : input){
				if(c == '[' || c == ']'){
					c = ' ';	
				}	
			}	

			stringstream ss(input);
			string token;
			
			while(getline(ss, token, ',')){
				if(token.empty()){
					continue;	
				}
				x.push_back(stoi(token));	
			}
		}
		else{
			string dummy;
			cin>>dummy;	
		}
		
		bool isReversed = false;
		bool error = false;
		for(char cmd : p){
			if(cmd == 'R'){
				isReversed = !isReversed;	
			}	
			else if(cmd == 'D'){
				if(x.empty()){
					cout<<"error"<<'\n';
					error = true;
					break;	
				}
				if(!isReversed){
					x.pop_front();	
				}	
				else{
					x.pop_back();	
				}
			}
		}
		if(!x.empty()){
			cout<<'[';
		}
		if(!isReversed){
			for(int i=0; i<x.size(); i++){
				cout<<x[i];
				if(i + 1 != x.size()){
					cout<<',';	
				}	
			}	
		}
		else{	
			for(int i=x.size()-1; i>=0; i--){
				cout<<x[i];
				if(i!= 0){
					cout<<',';	
				}		
			}
		}	
		if(!x.empty()){
			cout<<']'<<'\n';	
		}	
	

		if(x.empty() && !error){
			cout<<'['<<']'<<'\n';	
		}
	}
	return 0;
}
