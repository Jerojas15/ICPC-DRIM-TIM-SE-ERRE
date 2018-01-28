#include <stdio.h>

int N, small, large, len, aux;
int dirX[]	= {0,1,1,1,0,-1,-1,-1};
int dirY[] = {-1,-1,0,1,1,1,0,-1};

char mat[101][101];

int min(int a, int b){
	return a<b? a:b;
}

int max(int a, int b){
	return a>b? a:b;
}

int ff(int i, int j, char c1, char c2){
	
	if(i < 0 || j < 0 || i >= N || j >= N) return 0;
	if(mat[i][j] != c1) return 0;
	mat[i][j] = c2;
	int ans = 1;
	for(int d = 0; d < 8; d++){
		ans += ff(i + dirX[d], j + dirY[d], c1, c2);
	}
	return ans;
}

main(){
	
	scanf("%d", &N);
	
	while(N != 0){
		
		small = 10000000;
		large = -10000000;
		len = 0;
		
		for(int i = 0; i < N; i++){
				scanf("%s", mat[i]);
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				
				aux = ff(i, j, 'l', '_');
				if(aux){
					len++;
					small = min(small, aux);
					large = max(large, aux);
				}
			}
		}
		small = small>N*N? 0:small;
		large = large<0? 0:large;
		printf("%d %d %d\n", len, small, large);
		scanf("%d", &N);
	}
	
	
	return 0;
}

