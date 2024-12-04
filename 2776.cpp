#include<stdio.h>
#include<stdlib.h>
using namespace std;

void merge(int* arr, int left, int mid, int right){
	int left_size = mid - left + 1;
	int right_size = right - mid;

	int* L = (int*)malloc(sizeof(int) * left_size);
	int* R = (int*)malloc(sizeof(int) * right_size);

	for(int i=0; i<left_size; i++){
		L[i] = arr[left + i];	
	}
	for(int j=0; j<right_size; j++){
		R[j] = arr[mid + 1 + j];	
	}
	
	int left_index =0, right_index = 0, k = left;	

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
		int mid = left + (right - left) /2;

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
	int test_case;
	scanf("%d", &test_case);

	while(test_case > 0){

		int note1_size;
		scanf("%d", &note1_size);
	
		int* note1 = (int*)malloc(sizeof(int) * note1_size);
		for(int i = 0; i<note1_size; i++){
			scanf(" %d", &note1[i]);	
		}
	
		int note2_size;
		scanf("%d", &note2_size);
	
		int* note2 = (int*)malloc(sizeof(int) * note2_size);
		for(int i = 0; i<note2_size; i++){
			scanf(" %d", &note2[i]);	
		}
	
		merge_sort(note1, 0, note1_size - 1);
		
		for(int i=0; i<note2_size; i++){	
			if(binary_search(note1, note1_size, note2[i])){
				printf("1\n");	
			}
			else{
				printf("0\n");	
			}
		}
		
		free(note1);
		free(note2);

		test_case--;	
	}


	return 0;
}
