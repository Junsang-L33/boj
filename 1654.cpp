#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char* argv[]){
	int already_have;
	int need_rope;
	scanf(" %d %d", &already_have, &need_rope);

	vector<long long> length(already_have);
	long long max_length =0;

	for(int i=0; i<already_have; i++){
		scanf(" %lld", &length[i]);
		if(length[i] > max_length){
			max_length = length[i];		
		}	
	}
	
	long long low = 1;
	long long high = max_length;
	long long good_length = 0;
	
	while(low <= high){ //탐색이 유효할때까지만 loop돎
		long long mid = (low + high) /2;	
		long long count =  0; //한번 할때마다 초기화 시켜줘야함
		
		for( int i=0; i< already_have; i++){
			count += length[i] / mid;	
		}
		
		if(count >= need_rope){
			good_length = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;	
		}
	}

	printf("%lld", good_length);

	return 0;
}
