#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

	int matriz[100][100];
	int x; 
	int y;
	
int caminos(int i, int j){
	int caminox[4]={0,0,1,-1}; 
	int caminoy[4]={1,-1,0, 0};
    int res = 0;
    for(int c = 0; c < 4; c++){
       int posx = i + caminox[c];
       int posy = j + caminoy[c];
       if(posx>=0 && posy>=0 && posx < x && posy < y && matriz[posx][posy] < matriz[i][j]){
           res = max(res, 1 + caminos(posx, posy));
       }
    }
    return res;	
}

int pruebas(int x, int y){
	int sol = 0;
	for(int i = 0; i < x; i++ ){
		for(int j = 0; j < y; j++){
			sol = max(sol, caminos(i,j));
		}
	}
	sol++;
	return sol;
}

int main(){
	int cont;
	string name;

	cin>>cont;
	while(cont--){
		cin>>name;
		cin>>x>>y;
		for(int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				cin>>matriz[i][j];
			}
		}
		
		int res = 0;
		res = pruebas(x, y);
		cout<<name<<": "<<res<<endl; 
	}
	return 0;
}

