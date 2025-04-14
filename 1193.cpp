#include<bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x;
	cin >> x;

	int line = 1;
	while(x > line){
		x = x - line;
		line++;	
	}

	int nume, deno;
	if(line % 2 == 0){
		nume = x;
		deno = line - x + 1;	
	}
	else{
		nume = line - x + 1;
		deno = x;
	}

	cout << nume << '/' << deno << '\n';

	return 0;
}
