#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;	
int main(){

	int i, j, max, min, cont, res, x;

	while(scanf("%i %i", &i, &j) != EOF){
		max = (i + j + (abs(i-j))) / 2;
		min = (i + j - (abs(i-j))) / 2;
		min--;
		res = 0;


		while(max > min){
			cont = 1;
			x = max;
			while(x != 1){
				if(x % 2 != 0){
					x *= 3;
					x++;
				}else{
					x /= 2;
				}
				cont++;
			}

			max--;
			res = (cont + res + (abs(cont-res))) / 2;
		}

		cout << i << " " << j << " " << res << endl;	
	}

	return 0;
}