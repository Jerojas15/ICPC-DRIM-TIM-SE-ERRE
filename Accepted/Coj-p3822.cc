#include <bits/stdc++.h>
using namespace std;

vector<bool> criba;

unsigned gcd(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

vector<bool> set_criba(int n){
	vector<bool> v;
	int j;
	for(int i = 0;i<=n;i++){
		v.push_back(true);
	}	
	v[0] = 0;
	v[1] = 0;
	for(int i = 2;i<=n;i++){
		for(j=i*i;j<n;j+=i){
			v[j] = false;
		}
	}
	return v;
}

int main(){
	int a;
	cin >> a;
	criba =vector<bool>(set_criba(a+5));
	int aux = a,res = 0;
	while(aux>1){
		if(criba[gcd(a,aux)]){
			res++;
		}
		aux--;
	}
	cout << res << "\n";
	return 0;
}