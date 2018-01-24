#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int N, cont, cont2, len, i;
	char c[102];
	cin >> N;
	while(N--){
		cont = 0;
		cont2 = 0;
		scanf("%s", c);
		len = strlen(c);
		for(i = 0;i<len;i++){
			if(c[i] > 96)
				cont++;
			else
				cont2++;

		}
		if (cont == cont2)
			cout << "SI\n";
		else
			cout << "NO\n";

	}




	return 0;
}