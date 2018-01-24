#include <stdio.h>
#include <string.h>

int main(){
	int T, i, suma = 0;
	char N[1000];
	scanf("%i", &T);
	while(T-->0){
		suma = 0;
		scanf("%s", N);
		for(i = 0; i< strlen(N);i++){			
			suma += (N[i]-48);
		}

		if((N[i-1]-48)%2 == 0){
			if(suma%3 == 0){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			printf("NO\n");
		}
	}
	return 0;
}