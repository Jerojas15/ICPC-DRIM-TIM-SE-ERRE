#include<bits/stdc++.h>
using namespace std;

typedef complex<double> cd;

const double PI = 3.141592653589793;

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		cd a,b;
		double i1,i2,i3,i4,h;
		scanf("%lf %lf %lf %lf %lf", &i1, &i2, &i3, &i4, &h);
		a = cd(i1,i2);
		b = cd(i3,i4);

		cd r = polar(h, arg(b-a));
		r *= polar(1.0, PI/2.0);

		cd halfp = a + (b-a)*0.5;

		r += halfp;

		printf("%.3lf %.3lf\n", real(r), imag(r));
	}

	return 0;
}
