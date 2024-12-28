#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(int argc, char* argv[]){

	int n;
	scanf("%d", &n);

	for(int i = n/5; i>=0; i--){
		int a = n - (i*5);
		if(a%3 == 0){
			int j = a/3;
			printf("%d", i+j);
			return 0;	
		}	
	
	}	

	printf("-1");
	

	return 0;
}
