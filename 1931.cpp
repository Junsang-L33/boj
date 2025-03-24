#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> meet;

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		meet.push_back({a,b});
	}

	sort(meet.begin(), meet.end(), [](pair<int,int> a , pair<int, int> b){
		if(a.second == b.second){
			return a.first < b.first;	
		}
		return a.second < b.second;		
	});	

	int count = 0;
	int endtime = 0;

	for(int i=0; i<n; i++){
		if(meet[i].first >= endtime){ //the start time of the next meeting must be 
																	//greater than or equal to the end time of the previous meeting
																	//in order to avoid overlaaping	
			count++;
			endtime = meet[i].second;	
		}	
	}

	cout << count;

	return 0;
}
