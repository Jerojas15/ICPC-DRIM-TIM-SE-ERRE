#include <bits/stdc++.h>
using namespace std;
typedef complex<double> ci;

const double PI = acos(0) * 2.0;

int main(void){
	double res, r;
	double x,y;
	ci a,b,c;

	cin>>x>>y;
	a = ci(x,y);
	cin>>x>>y;
	b = ci(x,y);
	cin>>x>>y>>r;
	c = ci(x,y);

	ci ab = b-a;
	ci ca = a-c;
	//quadratic equation
	double A,B,C;
	A = real(ab) * real(ab) + imag(ab) * imag(ab);
	B = 2.0 * real(ab) * real(ca) + 2.0 * imag(ab) * imag(ca);
	C = real(ca) * real(ca) + imag(ca) * imag(ca) - r * r;

	double delta = B * B - 4.0 * A * C;
	if(delta > 0.0){
		double t1, t2;
		delta = sqrt(delta);
		t1 = (-B + delta) / (2.0 * A);
		t2 = (-B - delta) / (2.0 * A);

		if((t1 < 0.0) || (t1 > 1.0)) res = abs(b-a); 
		else if((t2 < 0.0) || (t2 > 1.0)) res = abs(b-a); 
		else{
			ci i1 = a + t1 * (b-a);
			ci i2 = a + t2 * (b-a);
			double theta = arg(i1-c) - arg(i2-c);

			if(theta < 0) theta = 2.0*PI + theta;

			double circ = min(theta * r, (2*PI - theta) * r);

			res = abs(b-a) - abs(i2-i1) + circ;
		}
	}
	else{
		res = abs(b-a);;
	}	

	printf("%.3lf",res);
	

	return 0;
}
