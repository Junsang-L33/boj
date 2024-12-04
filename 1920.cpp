#include<stdio.h>
#include<stdlib.h>
using namespace std;

void merge(int* arr, int left, int mid, int right){
	int left_size = mid - left + 1;
	int right_size = right - mid ;

	int* L = (int*)malloc(sizeof(int)*left_size);
	int* R = (int*)malloc(sizeof(int)*right_size);
	
	for(int i=0; i<left_size; i++){
		L[i] = arr[left + i];	
	}
	for(int j=0; j<right_size; j++){
		R[j] = arr[mid + 1 + j];	
	}

	int left_index = 0, right_index = 0, k = left;
	while(left_index < left_size && right_index < right_size){
		if(L[left_index] <= R[right_index]){
			arr[k++] = L[left_index++];	
		}	
		else{
			arr[k++] = R[right_index++];	
		}	
	}
		while(left_index < left_size){
			arr[k++] = L[left_index++];	
		}	
		while(right_index < right_size){
			arr[k++] = R[right_index++];	
		}
	
	free(R);
	free(L);
}


void merge_sort(int* arr, int left, int right){
	if(left < right){
		int mid = left + (right - left) / 2;
			
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);	
	
		merge(arr, left, mid, right);	
	}
}

int binary_search(int* arr, int size, int target){
	int left = 0;
	int right = size - 1;

	while(left <= right){
		int mid = left + (right - left) / 2;	
		if(arr[mid] == target){
			return 1;	
		}	
		else if(arr[mid] < target){
			left = mid + 1;	
		}
		else{
			right = mid - 1;	
		}
	}
	
	return 0;
}

int main(int argc, char* argv[]){
	int base_size;
	int* base = (int*)malloc(sizeof(int) * base_size);

	scanf("%d", &base_size);
	for(int i=0; i<base_size; i++){
		scanf(" %d", &base[i]);	
	}
	
	int arr_size;
	scanf(" %d", &arr_size);
	
	int* arr = (int*)malloc(sizeof(int) * arr_size);
	for(int i=0; i<arr_size; i++){
		scanf(" %d", &arr[i]);	
	}

	merge_sort(base, 0, base_size - 1);

	for(int i=0; i<arr_size; i++){		
		if(binary_search(base, base_size, arr[i])){
			printf("1\n");	
		}
		else{
			printf("0\n");	
		}
	}	
	return 0;
}
