#include <stdio.h>
#include <string.h>

int main(){
	int i, j = 0;
	char s[30], t[30];
	while(scanf("%s %s", s, t) != EOF){
		for (i = 0; i < strlen(t); i++)
		{
			if(t[i] == s[j]){
				j++;
			}
		}
		if(j == strlen(s)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		j = 0;
	}


	return 0;
}