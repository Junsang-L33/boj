#include<stdio.h>
#include<stdlib.h>

typedef struct Spot{
	int x;
	int y;
}Spot;

void merge(Spot list[], int left, int mid, int right, Spot sorted[]){
	int i, j, k;
	i = left; j = mid + 1; k = left;
	
	while(i <= mid && j <= right){
		if(list[i].y < list[j].y || list[i].y == list[j].y && list[i].x < list[j].x){
			sorted[k++] = list[i++];	
		}	
		else{
			sorted[k++] = list[j++];	
		}	
	}
	while(i <= mid){
		sorted[k++] = list[i++];	
	}
	while(j <= right){
		sorted[k++] = list[j++];	
	}
	int l;
	for(l = left; l <= right; l++){
		list[l] = sorted[l];	
	}

}

void merge_sort(Spot list[], int left, int right, Spot sorted[]){
	int mid;
	if(left < right){
		mid = left + (right - left) /2;

		merge_sort(list, left, mid, sorted);
		merge_sort(list, mid+1, right, sorted);
		merge(list, left, mid, right, sorted);
	}
}

int main(int argc, char* argv[]){

	int n; //num of spot
	scanf("%d", &n);
	
	Spot *points = (Spot*)malloc(sizeof(Spot)*n);
	Spot *sorted = (Spot*)malloc(sizeof(Spot)*n);

	for(int i=0; i<n; i++){
		scanf("%d %d", &points[i].x, &points[i].y);	
	}	
	
	merge_sort(points, 0, n-1, sorted);

	for(int i=0; i<n; i++){
		printf("%d %d\n", points[i].x, points[i].y);	
	}
	
	free(points);
	free(sorted);

	return 0;
}
