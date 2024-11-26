#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

int input_num(){
	int num;
	scanf("%d", &num);

	return num;
}

int* input_sequence(int size){
	int* sequence = (int*)malloc(sizeof(int) * size);	
	int i = 0;
	for(i = 0; i < size; i++){
		scanf("%d", &sequence[i]);	
	}
	return sequence;
}

void stack_sequence(int* sequence, int size){
	stack<int> s;
	queue<char> q;

	int number = 1; //size까지 1씩 증가하는 값 (스택에 들어가는값)
	int index = 0;

	while(index < size){ 
		if(!s.empty() && s.top() > sequence[index]){
			printf("NO\n");
			return;	
		}
	
		if(!s.empty() && s.top() == sequence[index]){ //스택이 비어있지않거나 s.top이 수열값과 동일한경우
			s.pop();
			q.push('-');	
			index++;	
		}	
		else if(number <= size){ //
			s.push(number);
			q.push('+');	
			number++;
		}	
	}
	while(!q.empty()){
		printf("%c\n", q.front());
		q.pop();
	}
}

int main(int argc, char* argv[]){
	int size = input_num();  //입력받을 수의 개수 저장
	int* sequence = input_sequence(size);
	stack_sequence(sequence, size);		
	free(sequence);

	return 0;
}
