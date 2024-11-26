#include<stdio.h>
#define BASE 31
#define MOD 1234567891

int charToASCII(char c){
	
	return c - 'a' + 1;
}

int main(int argc, char* argv[]){
	int length;
	char input[51]; //최대 문자열 입력수가 50으로 고정되어있음
	
	scanf(" %d", &length);
	scanf(" %s", input);	

	long long hash_value = 0;
	long long base_power = 1;

	for(int i=0; i<length; i++){
		int charASCII = charToASCII(input[i]);	
		hash_value = (hash_value + (charASCII * base_power) % MOD) % MOD;
		base_power = (base_power * BASE) % MOD;
	}
	
	printf("%lld\n", hash_value);

	return 0;
}
