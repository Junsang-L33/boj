#include<stdio.h>
#include<stdlib.h>
using namespace std;

int lower_bound(int* dp, int size, int target){
	int left = 0, right = size - 1;
	while(left <= right){
		int mid = left+(right-left)/2;
		if(dp[mid] >= target){
			right = mid - 1;
		}	
		else{
			left = mid + 1;	
		}	
	}

	return left;
}

int LIS_length(int* list, int size){
	int length = 0;

	int* dp = (int*)malloc(sizeof(int) * size);
	int* check = (int*)malloc(sizeof(int) * size);
	for(int i=0; i< size; i++){
		int pos = lower_bound(dp, length, list[i]);
		dp[pos] = list[i];
		check[i] = pos;
		if(pos == length){
			length++;	
		}	
	}
	int* ans = (int*)malloc(sizeof(int) * length);
	int crr_length = length - 1;

	for(int i=size-1; i>=0; i--){
		if(check[i] == crr_length){
			ans[crr_length] = list[i];
			crr_length--;
			if(crr_length < 0){
				break;	
			}	
		}	
	
	}
	printf("%d\n", length);
	for(int i=0; i<length; i++){
		printf("%d ", ans[i]);	
	}	
	free(dp);
	free(check);
	free(ans);

	return length;
}


int main(int argc, char* argv[]){
	int size ;
	scanf("%d", &size);

	int* list = (int*)malloc(sizeof(int)*size);
	for(int i=0; i<size; i++){
		scanf(" %d", &list[i]);	
	}
	int length;

	LIS_length(list, size);
	

	return 0;
}
