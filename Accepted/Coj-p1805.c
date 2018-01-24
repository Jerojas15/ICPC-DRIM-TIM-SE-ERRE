#include <stdio.h>

int main(){
	long int A = 0, B = 0, R;
	scanf("%li %li", &A, &B);
	R = (A+B)+(A-B)+(B+A)+(B-A);
	printf("%li\n", R);
	return 0;
}