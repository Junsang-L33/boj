#include<stdio.h>

void draw(int x, int y, int size){
	if((x/size)%3 == 1 && (y/size)%3 == 1){ //you have to find rule. center is empty
		printf(" ");
	}
	else{
		if(size/3 == 0){ //why if(size/3 == 0) print"*"? line 17 recursively size/3.
											 //because if size/3 is not used , the fractal structure will not be formed
											 //if n=9, (3,3)(3,4)(3,5) (4,3)(4,4)(4,5) (5,3)(5,4)(5,5) also have to empty
											 //(4,4) (this spot is one of the center spots. just test case) is (4/9) % 3 == 0
											 //this does not satisfy the condition
											 //if do size/3, size is 9 -> 3
											 //Then (4/3)%3 == 1. it works!
			printf("*");	 //this comment is for people who cannot understand, like me (it is so hard to understand)
		}	
		else{
			draw(x, y, size/3);	
		}	
	}	
}	

int main(int argc, char* argv[]){

	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			draw(i, j, n);	
		}	
		printf("\n");
	}
	return 0;
}
