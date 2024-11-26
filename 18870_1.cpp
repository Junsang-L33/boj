#include<stdio.h>
#include<stdlib.h>
using namespace std;

void merge(int** arr, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = (int*)malloc(sizeof(int)*n1);
	int* R = (int*)malloc(sizeof(int)*n2);

	for(int i=0; i<n1; i++){
		L[i] = *arr[left + i];
	}
	for(int i=0; i<n2; i++){
		R[i] = *arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			*arr[k++] = L[i++];	
		}	
		else{
			*arr[k++] = R[j++];	
		}	
	}	
	
	while(i<n1){
		*arr[k++] = L[i++];	
	}
	while(j<n2){
		*arr[k++] = R[j++];	
	}
	free(L);
	free(R);	
}

void merge_sort(int** arr, int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;	
		
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		
		merge(arr, left, mid, right);	
	}
}

int main(int argc, char* argv[]){
	int n; //N개의 좌표를 입력받음
	scanf("%d", &n);
	
	int** pos = (int**)malloc(sizeof(int*) * n);
	for(int i=0; i<n; i++){
		pos[i] = (int*)malloc(sizeof(int));	
	}

	int** original = (int**)malloc(sizeof(int*) * n); //원래 배열을 유지해서 인덱스 뽑기위한 배열
	for(int i=0; i<n; i++){
		original[i] = (int*)malloc(sizeof(int));	
	}

	for(int i=0; i<n; i++){
		scanf(" %d", pos[i]);	
	}
	
	for(int i=0; i<n; i++){
		*original[i] = *pos[i];	
	}	

	merge_sort(pos, 0, n-1);
	
	int* xz = (int*)malloc(sizeof(int)*n);//중복된 숫자를 제거해서 저장할 배열
	xz[0] = *pos[0];
	int index = 1;
	for(int i=1; i<n; i++){
		if(*pos[i] != *pos[i-1]){
			xz[index++] = *pos[i];	
		}	
	}	

	for(int i=0; i<n; i++){
		for(int j=0; j<index; j++){
			if(xz[j] == *original[i]){
				printf("%d ", j);	
				break;	
			}	
		}	
	}
	for(int i=0; i<n; i++){
		free(pos[i]);
		free(original[i]);	
	}
	free(pos);
	free(original);
	free(xz);
	return 0;
}
