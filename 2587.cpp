#include<stdio.h>
#include<stdlib.h>
using namespace std;

void input_num(int** num){
	for(int i=0; i<5; i++){
		scanf(" %d", num[i]);	
	}
}

void insertion_sort(int** num){
	int i, j, key;

	for(i=1; i<5; i++){
		key = *num[i];
		for(j = i - 1; j>=0 && *num[j] > key; j--){
			*num[j+1] = *num[j];	
			}	
		*num[j+1] = key;	
	}
}

int main(int argc, char* argv[]){
	//5개의 자연수가 주어짐(자연수 < 100 && 자연수%10 == 0)
	int** num = (int**)malloc(sizeof(int*) * 5);
	for(int i = 0; i<5; i++){
		num[i] = (int*)malloc(sizeof(int));	
	}

	input_num(num);
	int sum = 0;
	int	avg;
	for(int i=0; i<5; i++){
		sum += *num[i];		
	}
	avg = sum / 5;

	printf("%d\n", avg);
	
	insertion_sort(num);	
	//5개로 자연수의 개수가 정해져있으므로 중간값 인덱스는 2
	printf("%d\n", *num[2]);
	return 0;
}
