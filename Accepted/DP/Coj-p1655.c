#include <stdio.h>
#include <string.h>

int main() {
	char A[100000];
	char B[100000];
	int i = 0, j = 0;
	int x, y;
	scanf("%s", A);
	while(scanf("%s", B) != EOF){
		i = 0;
		x = strlen(A);
		y = strlen(B);
		for(j = 0;j < y;j++){
			if(B[j] == A[i]){
				i++;
			}
		}
		if(i == x)
			printf("Yes\n");
		else
			printf("No\n");
		scanf("%s", A);
	}
	return 0;
}