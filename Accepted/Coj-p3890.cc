#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long int n;
	cin >> n;
	long long int res = 0;
	long long int l = 1,t = 1;
	for(l = 1, t =1;n>=0;t+=4*l,l++){
		n-=t;
		res++;
	}
	cout <<res-1<< "\n";
    return 0;
}