#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<string, int> msi;

vi ds;
vi dsLen;
msi mymap;


void ds_create(int n){
	
}

int ds_union(int a, int b){
	int parent, auxParent;
	
	if (!ds[a] && !ds[b]) {
		ds[a] = a;
		ds[b] = a;
		dsLen[a] = 1;
		parent = a;
	}
	else if (!ds[a]) {
		parent = ds[b];
		while(parent != ds[parent])parent = ds[parent];
		ds[a] = parent;
		dsLen[parent] += 1;
	}
	else if (!ds[b]) {
		parent = ds[a];
		while(parent != ds[parent])parent = ds[parent];
		ds[b] = parent;
		dsLen[parent] += 1;
	}
	else {
		parent = ds[a];
		auxParent = ds[b];
		while(parent != ds[parent])parent = ds[parent];
		while(auxParent != ds[auxParent])auxParent = ds[auxParent];
		
		if (parent != auxParent) {
			ds[auxParent] = parent;
			dsLen[parent] += dsLen[auxParent] + 1;
		}
	}
	return dsLen[parent];
}

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, res, cont;
	string a, b;
	cin >> t;
	while(t--){
		cin >> n;
		
		ds = vi(100005);
		dsLen = vi(100005);
		
		//ds_create(n);
		cont = 1;
		while(n--){
	  		cin >> a >> b;
	  		if(!mymap[a]){
	  			mymap[a] = cont++;
	  		}
	  		if(!mymap[b]){
	  			mymap[b] = cont++;
	  		}
	  		res = ds_union(mymap[a],mymap[b]);
	  		cout << res + 1 << "\n";
		}
	}

	return 0;
}
