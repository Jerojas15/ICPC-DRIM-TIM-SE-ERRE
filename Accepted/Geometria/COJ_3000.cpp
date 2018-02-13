//ecuacion de lineas 
//si A es vector en la direccion del primer angulo
//y B en la direccion del segundo
//las lineas son a + A y b + B;

#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
double const PI = acos(0) * 2;

int main(void){
 	int t;
	cin>>t;
	while(t--){
		cd a,b;
		double x,y,ana,anb;
		cin>>x>>y>>ana;
		a = cd(x,y);
		cin>>x>>y>>anb;
		b = cd(x,y);
		ana = 360 - ana;
		anb = 360 - anb;
		ana += 90.0;
		anb += 90.0;
		if(ana >= 360.0) ana -= 360.0;
		if(anb >= 360.0) anb -= 360.0;

		double c, e;
		cd B,D;
		B = (polar(1.0,(ana*PI)/180)) * cd(0.0,1.0);
		c = B.real() * a.real() + B.imag() * a.imag();

		D = (polar(1.0,(anb*PI)/180)) * cd(0.0,1.0);
		e = D.real() * b.real() + D.imag() * b.imag();

		double d = B.real() * D.imag() - D.real() * B.imag();

		//cout<<(c * D.imag() - e * B.imag()) / d<<' '<<(e*B.real() - c * D.real()) / d<<'\n';
		printf("%.4lf %.4lf\n",(c * D.imag() - e * B.imag()) / d, (e*B.real() - c * D.real()) / d);
	}
 }
