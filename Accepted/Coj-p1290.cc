#include <bits/stdc++.h>
using namespace std;

map<int, long int> memo;

long int max(int a, long int b){
	return a>b?a:b;
}

unsigned int solve(long int a){
	if(memo[a])return memo[a];
	if(!a)return 0;
	return memo[a] = max(a,solve(a/2)+solve(a/3)+solve(a/4));
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int x = 10,y;
	memo[1] = 1;
	while(x--){
		cin >> y;
		cout << solve(y)<<"\n";
	}
    return 0;
}