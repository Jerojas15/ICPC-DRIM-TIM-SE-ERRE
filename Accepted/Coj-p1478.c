#include <stdio.h>
#include <string.h>
char S[500], T[500];
int gap = 1;

int mat[500][500];

int min(int a, int b){return a<=b?a:b;}

int f(char a, char b){
	return a==b?0:1;
}

int al(int n, int m){
	if(n==-1 ||m ==-1){return(n+m+2)*gap;}
	if(mat[n][m]){return mat[n][m];}
	mat[n][m] = min(min(f(S[n],T[m])+al(n-1,m-1),gap + al(n,m-1)), gap+al(n-1,m));
	return mat[n][m];
}


int main(){
	
	scanf("%s", S);
	scanf("%s", T);
	printf("%i\n", al(strlen(S)-1, strlen(T)-1));
	return 0;
}