#include <iostream>
#include <math.h>

using namespace std;

int main(){
	long long int N,A,B, suma, i;
	cin >> N;
	while(N--){
		suma = 0;
		cin >> A >> B;
		for (i = A; i <= B; i++)
		{
			suma+= (A*(A+1)*(A+2));
			A++;
		}
		suma = suma % 100;
		cout << suma << endl;

	}

	return 0;
}