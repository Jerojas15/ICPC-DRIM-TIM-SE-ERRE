//se parte en upper y lower, se ordenan los puntos por x
//entran al upper si estan arriba de la linea que separa el upper 
//del lower, igual al lower

#include<bits/stdc++.h>
using namespace std;

typedef complex<long> c;
typedef vector<c> vc;

bool compare_complex(c a, c b){
	pair<long,long> aa(real(a),imag(a));
	pair<long,long> bb(real(b),imag(b));
	return aa < bb;
}

long cross_product(c a, c b){
	return real(a) * imag(b) - real(b) * imag(a);
}

vc convex_hull(vc points){
	int idx_u = 0, idx_l = 0, n = points.size();
	vc upper(n), lower(n);
	sort(points.begin(), points.end(), compare_complex);

	for(int i = 0; i<n; i++){
		//change <= to < if including collinear points
		while((idx_u > 1) && 
		  (cross_product(points[n-1] - points[0],
		  upper[idx_u-1] - points[0]) < 0)){
			idx_u--;
		}
		upper[idx_u++] = points[i];
	}
	for(int i = n-1; i+1; i--){
		while((idx_l > 1) && 
		  (cross_product(points[n-1] - points[0],
		  lower[idx_l-1] - points[0]) >= 0)){
			idx_l--;
		}
		lower[idx_l++] = points[i];
	}
	idx_u--;
	idx_l--;

	int size = idx_u+idx_l;
	idx_l = 0;
	while(idx_u < size){
		upper[idx_u++] = lower[idx_l++];
	}
	upper.resize(size);
	return upper;
}

int main(void){
	int n;
	while(cin>>n){
		vc points(n);
		for(auto &i: points){
			long x,y;
			cin>>x>>y;
			i = c(x,y);
		}
	
		vc r = convex_hull(points);
		cout<<r.size()<<'\n';
		for(auto i:r){
			cout<<real(i)<<' '<<imag(i)<<'\n';
		}
	}
}
