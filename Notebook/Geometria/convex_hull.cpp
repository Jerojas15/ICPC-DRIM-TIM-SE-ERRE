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

	while(idx_u < n){
		upper[idx_u++] = lower[idx_l++];
	}
	return upper;
}
