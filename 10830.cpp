#include<bits/stdc++.h>
using namespace std;

long long matrix[5][5];
long long I[5][5];
long long tmp[5][5];

void mul(long long A[5][5], long long B[5][5], long long C[5][5], int n){

	for(int i = 0; i < n; i++) {
  	for(int j = 0; j < n; j++) {
    	tmp[i][j] = 0;
     }
  }
	for(int i=0; i<n; i++){
		for(int k = 0; k<n; k++){	
			for(int j=0; j<n; j++){
				tmp[i][j] = (tmp[i][j] + A[i][k] * B[k][j])%1000;	
			}	
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			C[i][j] = tmp[i][j];	
		}	
	}
}

void matrixPow(long long exp, int size){
	static long long base[5][5];
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			base[i][j] = matrix[i][j];
		}	
	}

	while(exp > 0){
		if(exp & 1){
			mul(I, base, I, size);	
		}	
		mul(base, base, base, size);	
		exp = exp >> 1;	
	}
}

int main(int argc, char* argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int size;
	long long exp;
	cin >> size >> exp;	
	
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cin >> matrix[i][j];	
			I[i][j] = (i == j ? 1 : 0);
		}	
	}

	matrixPow(exp, size);

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout << I[i][j] << ' ';	
		}	
		cout<<'\n';
	}

	return 0;
}
