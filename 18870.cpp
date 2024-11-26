#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

void merge(int* arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(sizeof(int) * n1);
    int* R = (int*)malloc(sizeof(int) * n2);

    for(int i = 0; i < n1; i++){
    	L[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
      R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
    	if(L[i] <= R[j]){
        	arr[k++] = L[i++];
      }
			else{
          arr[k++] = R[j++];
      }
    }

    while(i < n1){
    	arr[k++] = L[i++];
    }
    while(j < n2){
      arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void merge_sort(int* arr, int left, int right){
    if(left < right){
    	int mid = left + (right - left) / 2;

      merge_sort(arr, left, mid);
      merge_sort(arr, mid + 1, right);

      merge(arr, left, mid, right);
    }
}

int main(int argc, char* argv[]){
    int n;
    scanf("%d", &n);

    int* original = (int*)malloc(sizeof(int) * n);
    int* sorted = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
      scanf("%d", &original[i]);
      sorted[i] = original[i];
    }

    merge_sort(sorted, 0, n - 1);

    map<int, int> compression;
    int index = 0;

    for(int i = 0; i < n; i++){
      if(compression.find(sorted[i]) == compression.end()){
      	compression[sorted[i]] = index++;
      }
    }

    for(int i = 0; i < n; i++){
      printf("%d ", compression[original[i]]);
    }
    printf("\n");

    free(original);
    free(sorted);

    return 0;
}
