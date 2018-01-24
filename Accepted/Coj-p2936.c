#include <stdio.h>

int main(){
	int n, m;
	long long int a, b, c, d;
	
	while(scanf("%d %d", &n, &m) != EOF){
		a = n*(n-1)/2;
		b = m*(m-1)/2;
		c = a*m + b*n;
		d = a*b;
		printf("Triangles: %lld\n", c);
		printf("Quadrilaterals: %lld\n", d);
		printf("\n");
	}	

	return 0;
}
