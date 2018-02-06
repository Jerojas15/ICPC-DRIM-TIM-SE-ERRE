//diametro del convex hull usando rotating calipers

#include <bits/stdc++.h>
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

double distance(c a, c b){
	complex<double> aa(real(a), imag(a)), bb(real(b), imag(b));
	aa /= 64.0;
	bb /= 64.0;
	return 64.0*abs(aa-bb);
}

double angle(c a){
	return arg(complex<double>(real(a),imag(a)));
}

double diameter(vc points){
	double res;

	//idx point to top+1 (next idx to push) 
	int idx_u = 0, idx_l = 0, n = points.size();
	vc upper(n), lower(n);
	sort(points.begin(), points.end(), compare_complex);

	for(int i = 0; i<n; i++){
		//change <= to < if including collinear points
		while((idx_u > 1) && 
		  (cross_product(points[i] - upper[idx_u-2], upper[idx_u-1] - upper[idx_u-2]) <= 0)){
			idx_u--;
		}
		upper[idx_u++] = points[i];
	}
	for(int i = n-1; i+1; i--){
		while((idx_l > 1) && 
		  (cross_product(points[i] - lower[idx_l-2], lower[idx_l-1] - lower[idx_l-2]) <= 0)){
			idx_l--;
		}
		lower[idx_l++] = points[i];
	}
	idx_u--;
	idx_l--;

	int j = idx_u;
	int size = idx_u+idx_l;
	idx_l = 0;
	while(idx_u < size){
		upper[idx_u++] = lower[idx_l++];
	}
	upper.resize(size);

	int i = 0, k = 0;
	while(k < size){
		//upper[i] and upper[j] are a pair
		res = max(res, distance(upper[i],upper[j]));	
		k++;

		if( cross_product(upper[(j+1) % size] - upper[j], upper[(i+1) % size] - upper[i]) < 0){
			i++;		
		}
		else if( cross_product(upper[(j+1) % size] - upper[j] , upper[(i+1) % size] - upper[i]) == 0 ){
			//upper[i] and upper[j+1]
			//uppper[i+1] and upper[j]
			//are a pair;
			res = max(res, distance(upper[i], upper[(j+1) % size]));
			res = max(res, distance(upper[(i+1) % size], upper[j]));
			
			i++;
			j++;
			k++;
		}
		else{
			j++;
		}
		i %= size;
		j %= size;
	}
	
	return res;
}

int main(void){
	int n, m;
	long x,y;
	cin>>n>>m;
	n+=m;
	vc points(n);
	for(int i = 0; i<n; i++){
		cin>>x>>y;
		points[i] = c(x,y);
	}

	switch(n){
		case 1:
			printf("0.0000");
		case 2:
			printf("%.4lf", distance(points[0],points[1]));
		default:
			printf("%.4lf", diameter(points));
	}

	return 0;
}
