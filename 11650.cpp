#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comparePairs(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first == b.first){
		return a.second < b.second;	
	}
	return a.first < b.first;
}

int main(int argc, char* argv[]){
	int N;
	cin >> N;

	vector<pair<int, int>> point(N);

	for(int i=0; i<N; ++i){
		cin >> point[i].first >> point[i].second;	
	}
	sort(point.begin(), point.end(), comparePairs);

	for(const auto &p : point){
		cout << p.first << " "<< p.second << "\n";	
	}
							
	return 0;				
}
