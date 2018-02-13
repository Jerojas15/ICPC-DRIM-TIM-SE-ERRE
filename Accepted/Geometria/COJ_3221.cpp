/*quasi-rotating calipers
 se ordenan los puntos de disparo, para cada uno
 se saca el target mas a la izquierda y mas a la derecha
 y el punto hacia el que dispara tiene que estar entre ellos
 inicialmente se encuentran los lados en una busqueda lineal
 luego se derian de los anteriores ya que los puntos de disparo
 estan ordenados
 O(nlog(n) + mlog(m)) por los ordenamientos, el resto lineal
 para buscar entre los targets eficientemente sacar el 
 convex hull, ya que tienen que estar clockwise para que
 el los de la izquierda y derecha se puedan sacar de los 
 anteriores
 */

#include<bits/stdc++.h>
using namespace std;

typedef complex<long> c;
typedef vector<c> vc;
typedef pair<c,c> pc;
typedef pair<pc,int> p;
typedef vector<p> vp;

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

bool cmp(pc a, pc b){
	if(compare_complex(a.first,b.first)) return 1;
	else if(!compare_complex(b.first,a.first)){
		if(compare_complex(a.second,b.second)) return 1;
		else return 0;
	}
	else return 0;
}

bool cm(p a, p b){
	if(cmp(a.first,b.first)) return 1;	
	else if(!cmp(b.first,a.first)){
		if(a.second < b.second) return 1;
		else return 0;
	}
	else return 0;
}

int main(void){
	int n,m;
	cin>>n>>m;

	vc targets(n);
	vp line(m);

	for(auto &i: targets){
		long x,y;
		cin>>x>>y;
		i = c(x,y);
	}

	targets = convex_hull(targets);
	n = targets.size();
	for(int i = 0; i < m; i++){
		long x,y,z,w;
		cin>>x>>y>>z>>w;
		line[i] = p(pc(c(x,y),c(z,w)), i );
	}
	
	sort(line.begin(),line.end(),cm);

	//iteration order
	bool inv = 0;
	if(cross_product(line[1].first.first - line[0].first.first,
	  targets[0]-line[0].first.first) > 0) 
		inv = 1;


	int left = 0,right = 0;

	c curr = inv?(line[m-1].first.first):(line[0].first.first);
	for(int i = 1; i < n-1; i++){
		if((cross_product(targets[i]-curr,targets[i+1]-curr) <=0)
		&& (cross_product(targets[i]-curr,targets[i-1]-curr) <=0)){
			left = i;
			break;
		}
				
	}
	//check corners
	if(!left){
		if((cross_product(targets[n-1]-curr,targets[0] - curr) <=0) 
		&& (cross_product(targets[n-1]-curr,targets[n-2]-curr) <=0))
			left = n-1;
		else
			left = 0;
	} 
	for(int i = 1; i < n-1; i++){
		if((cross_product(targets[i]-curr,targets[i+1]-curr) >=0)
		&& (cross_product(targets[i]-curr,targets[i-1]-curr) >=0)){
			right = i;
			break;
		}
				
	}
	if(!right){
		if((cross_product(targets[n-1]-curr,targets[0] - curr) >=0) 
		&& (cross_product(targets[n-1]-curr,targets[n-2]-curr) >=0))
			right = n-1;
		else
			right = 0;
	} 

	int it = inv?-1:1;
	vector<bool> res(m);
	for(int i = inv?(m-1):0; (i < m) && (i > -1); i += it){
		curr = line[i].first.first;
		c target = line[i].first.second;
		int next = (left + 1) % n;
		while(cross_product(targets[left] - curr, targets[next] - curr) > 0){
			left = next;
			next = (left+1)%n;
		}
		next = (right+1) % n;
		while(cross_product(targets[right] - curr, targets[next] - curr) < 0){
			right = next;
			next = (right+1)%n;
		}
		
		if((cross_product(targets[left]-curr, target-curr) <=0)
		&&(cross_product(targets[right]-curr, target-curr) >=0))
			res[line[i].second] = 1;
	}

	for(auto i:res){
		if(i) cout<<"YES\n";
		else cout<<"NO\n";
	}


	return 0;
}
