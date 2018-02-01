//izi, sacar la altura de un isoceles a partir de la base y ua linea paralela
//luego el area del cono

#include <bits/stdc++.h>
using namespace std;

const double pi = acos(0)*2.0;

int main(void){
	int t;
	double r, R, h, V, res, bucket;
	cin>>t;
	while(t--){
		cin>>r>>R>>h>>V;
		
		if(r>R){
			double tmp = r;
			r = R;
			R = tmp;
		}

		if(r == R){
			bucket = pi * R * R * h;	
		}
		else{
			double l = h / (R/r - 1.0);
			bucket = (pi * R * R * (h + l)) / 3.0;
			bucket -= (pi * r * r * l) / 3.0;

		}
		res = V / bucket;
		cout<<ceil(res) * 2<<'\n';

	}

	return 0;
}
