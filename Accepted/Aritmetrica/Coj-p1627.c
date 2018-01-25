# include <stdio.h>

int main(){
	int T, N, res = 0;
	scanf("%i", &T);
	while(T-->0){
		scanf("%i", &N);
		while(N!=0){
			res += N/5;
			N = N/5;
		}
		printf("%i\n", res);
		res = 0;
	}
	return 0;
}