#include <bits/stdc++.h>
using namespace std;

int main(void){
	int r=0,c=0,W,H,w,h;
	cin >> W >> H >> w >> h;

	int t;
	while(W>-1){
		W-=w;
		c++;
	}
	while(H>-1){
		H-=h;
		r++;
	}
	r>>=1;
	c>>=1;
	cout << r*c << "\n";
	

	return 0;
}