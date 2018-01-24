#include <stdio.h>

int main(){
	int a, b, c;
	scanf("%i %i", &a, &b);
	while(a != 0 && b != 0){
		if(a < b){
			c = 0;
		}else if(a == b){
			c = 1;
			a = 0;
		}else{
			c = a/b;
			a = a-b*c;
		}
		printf("%i %i / %i \n", c, a, b);
		scanf("%i %i", &a, &b);
	}

	return 0;
}