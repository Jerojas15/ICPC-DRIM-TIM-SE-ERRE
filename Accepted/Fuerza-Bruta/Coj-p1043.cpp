#include <iostream>
using namespace std;

int main() {
	int n, x, cont;
	cin >> n;
	while(n--){
		cin >> x;
		cont = 0;
		while(x){
			if(x & 1) cout << cont << " ";
			cont++;
			x>>=1;
		}
		cout << endl;
	}
	return 0;
}
