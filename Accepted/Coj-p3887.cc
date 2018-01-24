
#include <iostream>
#include <stdio.h>
using namespace std;
int mat[105][105],aux[105][105][4];
int cont;
void solve(int x, int y, int r, int c){
	bool flag = true;
	int max = mat[x][y];
	for(int i = x+1;i<r;i++){//abajo
		if(aux[i][y][0] && mat[i][y]<max)break;
		if(mat[i][y]>=max){
			flag = false;
			break;
		}
	}
	if(flag)cont++;
	aux[x][y][0] = flag;
	flag = true;
	
	for(int i = x-1;i>=0;i--){//arriba
		if(aux[i][y][1] && mat[i][y]<max)break;
		if(mat[i][y]>=max){
			flag = false;
			break;
		}
	}
	if(flag)cont++;
	aux[x][y][1] = flag;
	flag = true;
	
	for(int j = y+1;j<c;j++){//der
		if(aux[x][j][2] && mat[x][j]<max)break;
		if(mat[x][j]>=max){
			flag = false;
			break;
		}
	}
	if(flag)cont++;
	aux[x][y][2] = flag;
	flag = true;
	for(int j = y-1;j>=0;j--){//izq
		if(aux[x][j][3] && mat[x][j]<max)break;
		if(mat[x][j]>=max){
			flag = false;
			break;
		}
	}
	if(flag)cont++;
	aux[x][y][3] = flag;
}

int main(int argc, char **argv)
{
	cont = 0;
	int r, c;
	scanf("%i %i",&r,&c);
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			scanf("%i",&mat[i][j]);
			aux[i][j][0] = 0;
			aux[i][j][1] = 0;
			aux[i][j][2] = 0;
			aux[i][j][3] = 0;
		}
	}
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			solve(i,j,r,c);
		}
	}
	cout << cont << endl;
	return 0;
}
