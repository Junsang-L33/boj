#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void input_voca(char** voca, int n){

	for(int i=0; i<n; i++){
		scanf(" %s", voca[i]);
	}	

}

void merge(char** voca, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;

	char** L = (char**)malloc(n1 * sizeof(char*));
	char** R = (char**)malloc(n2 * sizeof(char*));

	for(int i=0; i<n1; i++){
		L[i] = voca[left + i];	
	}
	for(int i=0; i<n2; i++){
		R[i] = voca[mid + 1 + i];	
	}
	
	int i=0, j=0, k=left;

	while(i < n1 && j < n2){
		if(strlen(L[i]) < strlen(R[j]) || (strlen(L[i]) == strlen(R[j]) &&
			 strcmp(L[i], R[j]) <= 0 )){
			voca[k++] = L[i++];
			}	
		else{
			voca[k++] = R[j++];
		}	
	}
	
	while(i<n1){
		voca[k++] = L[i++];
	}
	while(j<n2){
		voca[k++] = R[j++];
	}
	free(L);
	free(R);

}

void merge_sort(char** voca, int left, int right){
	if(left<right){
		int mid = left + (right - left) / 2;	
		
		merge_sort(voca, left, mid);
		merge_sort(voca, mid+1, right);

		merge(voca, left, mid, right);
	}

}

int main(int argc, char* agv[]){
	int n;//number of voca
	scanf("%d",&n);
	char** voca = (char**)malloc(sizeof(char*) * n);
	for(int i=0; i<n; i++){
		voca[i] = (char*)malloc(sizeof(char) * 51);	
	}
	input_voca(voca, n);
	
	merge_sort(voca, 0, n-1);

	printf("%s\n", voca[0]);
	for(int i=1; i<n; i++){
		if(strcmp(voca[i] ,voca[i-1]) != 0){
			printf("%s\n", voca[i]);	
		}	
	}
	
	for(int i=0; i<n; i++){
		free(voca[i]);	
	}
	free(voca);
	return 0;
}
