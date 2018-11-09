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
	int idx = 0, idxo = 0, n = points.size();
	vc hull(n+1);
	sort(points.begin(), points.end(), compare_complex);

	for(int i = 0; i<n; i++){
		//change <= to < if including collinear points
		while((idx > 1) && 
		  (cross_product(points[i] - hull[idx-2],
		  hull[idx-1] - hull[idx-2]) <= 0)){
			idx--;
		}
		hull[idx++] = points[i];
	}
	idxo = idx;
	for(int i = n-1; i+1; i--){
		while((idx > idxo) && 
		  (cross_product(points[i] - hull[idx-2],
		  hull[idx-1] - hull[idx-2]) <= 0)){
			idx--;
		}
		hull[idx++] = points[i];
	}

	hull.resize(idx-1);
	return hull;
}
