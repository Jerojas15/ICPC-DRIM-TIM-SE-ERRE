#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	int r, c, q, a, b, s, e, res;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> r >> c >> q;
	
	vvi imat = vvi(r, vi(c));
	vvi rmat = vvi(r, vi(c));
	
	
	for(int i = 0; i < r; i++) {
		for(int j =0; j < c; j++) {
			cin >> a;
			if(a<0) a = 0;
			imat[i][j] = a;
			if (!i && !j) rmat[i][j] = a;
			else if (!i) rmat[i][j] = rmat[i][j-1] + a;
			else if (!j) rmat[i][j] = rmat[i-1][j] + a;
			else rmat[i][j] = rmat[i-1][j] + rmat[i][j-1] - rmat[i-1][j-1] + a;
			
		}
	}
	
	while(q--){
		cin >> a >> b >> s >> e;
		a--; b--; s--; e--;
		res = rmat[s][e];
		if (a) res -= rmat[a-1][e];
		if (b) res -= rmat[s][b-1];
		if (a && b) res += rmat[a-1][b-1];
		cout << res << "\n";
	}
	
	return 0;
}
