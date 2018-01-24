#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int w,h,ax,ay,bx,by;
	cin>>w>>h>>ax>>ay>>bx>>by;
	if(ax == bx){
		cout<<0<<" "<<ay<<" "<<w<<" "<<by<<"\n";
		return 0;
	}else{
		cout<<ax<<" "<<0<<" "<<bx<<" "<<h<<"\n";
		return 0;
	}
	return 0;
}