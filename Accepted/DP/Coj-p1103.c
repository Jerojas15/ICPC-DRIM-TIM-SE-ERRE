#include <stdio.h>
#include <stdlib.h>
int **ma;
int v[5];
int m(int p, int i){

	
	if(p == 0){return 1;}
	if(p < 0 || i == -1){return 0;}
	if(ma[p][i]){
		return ma[p][i];
	}
	ma[p][i] = m(p-v[i],i)+m(p,i-1);
	return ma[p][i];
}

int main(){
	v[0] = 1;
	v[1] = 5;
	v[2] = 10;
	v[3] = 25;
	v[4] = 50;
	
	int i, p, res;
	ma=(int**)calloc(8000,sizeof(int*));
	for(i=0; i<8000; i++)  {
		ma[i]=(int*)calloc(5,sizeof(int));
	}
	while(scanf("%i", &p) != EOF){
		res = m(p, 4);
		printf("%i\n", res);
	}
	return 0;
}