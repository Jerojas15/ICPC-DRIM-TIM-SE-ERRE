#include<bits/stdc++.h>
using namespace std;

typedef complex<long> c;
typedef vector<c> vc;
typedef vector<int> vi;

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
		  (cross_product(points[i] - upper[idx_u-2],
		  upper[idx_u-1] - upper[idx_u-2]) <= 0)){
			idx_u--;
		}
		upper[idx_u++] = points[i];
	}
	for(int i = n-1; i+1; i--){
		while((idx_l > 1) && 
		  (cross_product(points[i] - lower[idx_l-2],
		  lower[idx_l-1] - lower[idx_l-2]) <= 0)){
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
	int t;
	cin>>t;
	while(t--){
		int n,a,b;
		double p,q,r,ix,iy;
		cin>>p>>q>>n;
	
		vc v(n);

		for(int i = 0; i < n; i++){
			cin>>ix>>iy;
			v[i] = c(ix,iy);
		}

		vc ch = convex_hull(v);

		int i = -1;
		while(v[++i] != ch[0]);
			
		rotate(v.begin(), v.begin()+i, v.end()); 

		a = 0;
		int j;
		b = ch.size();
		
		for(i = 0, j = 0; i < ch.size(); i++,j++){
			if(ch[i] != v[j]){
				a++;
				b--;
				while((++j < n) && (ch[i] != v[j]));
			}	
		}
		if(j < n){
			a++;
			b--;
		}

		r = -a*p+b*q;
		if(r<0)cout<<"0\n";
		else cout<<r<<'\n';;
		
	}

	return 0;
}

