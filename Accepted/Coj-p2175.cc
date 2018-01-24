#include <iostream>
using namespace std;
int Y[10000000];

int primos(int a){
	int aux = 3;
	if(a == 2){
		Y[a] = 1; 
		return 0;
	}
	if(!(a%2)){
		Y[a] = 2;
		return 0;
	}
	while(aux < a){
		if(!(a%aux)){
			Y[a] = 2;
			return 0;
		}
		aux++;
	}
	Y[a] = 1;
	return 0;
}

int calc(int B, int C){
	if(!Y[B])primos(B);
	if(!Y[C])primos(C);
	if(Y[B] == 1){
		if(Y[C] == 1){
			printf("%d %d\n",B,C);
			return 0;
		}else{
			return calc(B,C+1);
		}
		
	}else{
		return calc(B-1,C);
	}
	
	
	
}

int main() {
	int N, A;
	cin >> N;
	while(N--){
		cin >> A;
		calc(A, A);
		A = 0;}
	return 0;
}