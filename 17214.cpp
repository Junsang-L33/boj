#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	
	map<int,int> poly;

	int i=0;
	while(i < s.size()){
		if(s[i] == '0'){
			cout<<'W';
			return 0;	
		}	
		int sign = 1;
		//1 == +, -1 == -	
		if(s[i]	== '+'){
			sign = 1;
			i++;
		}
		else if(s[i] == '-'){
			sign = -1;
			i++;	
		}	
	
		int coef = 0;
		while(i < s.size() && isdigit(s[i])){
			coef = coef * 10 + (s[i] - '0');
			i++;		
		}		
		
		int degree = 0;
		while(i < s.size() && s[i] == 'x'){
			degree++;
			i++;	
		}

		poly[degree] += sign * coef;	
	}
	
	for(auto it = poly.rbegin(); it != poly.rend(); ++it){
		if(abs(it->second) != 1 && abs(it->second/(it->first + 1)) != 1 ){
			cout << it->second/(it->first + 1);
		}
		if(it->second/(it->first+1) == -1){
			cout<<'-';	
		}
		for(int j = 0; j<it->first + 1; j++){
			cout << 'x';	
		}		
		if(next(it) != poly.rend()){
			if(next(it)->second > 0){
			cout<<'+';	
			}
			
			else{}
		}	
	}
	cout<<"+W";
	return 0;
}
