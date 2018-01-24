#include <bits/stdc++.h>
using namespace std;

double max(double a, double b){
	return a>b?a:b;
}
double min(double a, double b){
	return a<b?a:b;
}

double solve(double x, double y){
	double max = 0;
	if(x*3<=y){
		max = x;
	}
	if(x/2<=y && x/2>max){
		max = x/2;
	}
	if(y/3<=x && y/3>max){
		max = y/3;
	}
	return max;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double a, b;
	double c;
	cin >> a >> b;
	c = solve(min(a, b),max(a,b));
	printf("%lf\n",c);
	return 0;
}


