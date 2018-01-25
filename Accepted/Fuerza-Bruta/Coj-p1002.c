#include <stdio.h>

int min(int a,int b){ return a>b?b:a;}

int main(){
	int k;
	int T, N, i, j, fin = 1;
	scanf("%i", &T);
	while(T-->=1){
		scanf("%i", &N);
		char aux[N];
		int X[N][N], A[N][N];
		for(i = 0;i<N;i++){
			scanf("%s", aux);
			for(j = 0;j<N;j++){
				if(aux[j] == '#'){
					X[i][j] = 0;
				}else{X[i][j] = 1;}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if(i == 0|| j ==0){
					A[i][j] = X[i][j];
				}else{
					if(X[i][j] == 0){
						A[i][j] = 0;
					}else{
						A[i][j] = 1+min(min(A[i-1][j], A[i][j-1]) , A[i-1][j-1]);

					}
				}
				if(A[i][j]> fin){
					fin = A[i][j];
				}
			}
		}
		printf("%i\n", fin);
		fin = 0;
	}
	
	return 0;
}