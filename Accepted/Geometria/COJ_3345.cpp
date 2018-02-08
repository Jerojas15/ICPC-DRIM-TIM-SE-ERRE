//simulacion
//despiche de productos cruz, preguntarme en persona si quieren explicacion
//(esteban)

#include<bits/stdc++.h>
using namespace std;

const double PI = 3.141592653589793;
typedef complex<double> cd;
typedef vector<cd> vcd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

double cross(cd a, cd b){
	return real(a) * imag(b) - real(b) * imag(a);
}

int main(void){
	int t;
	cin>>t;
	while(t--){
		int tt, n, s, curr;
		double a;
		cin>>tt>>n>>s>>curr>>a;
		
		vcd points(n+1);
		vvvi left(n+1, vvi(n+1));
		points[0] = polar(1000.0, (a * PI) / 180);

		for(int i = 1; i <= n; i++){
			int b;
			double x,y;
			cin>>b>>x>>y;
			points[b] = cd(x,y);
		}
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <=n; j++){
				if(i == j) continue;
				for(int k = 0; k <=n; k++){
					if(((k == j) || (k == i)) || !k) continue;
					else if(cross(points[j] - points[i], points[k] - points[i]) > 0.0)
						left[i][j].push_back(k);
				}
				sort(left[i][j].begin(), left[i][j].end());
			}
		}
	
		cout<<tt<<' ';
		int last = 0;
		while(s--){
			int a = -1, b = -1;

			vi lefts = left[last][curr];
			for(int i = 0; i < lefts.size(); i++){
				vi tst = vi(lefts);
				tst.erase(tst.begin() + i);
				vi l = left[curr][lefts[i]];
				auto lst = lower_bound(l.begin(), l.end(), last);
				if((lst != l.end()) && (*lst == last)){
					l.erase(lst);
				}
				if(l == tst){
					a = lefts[i];
					break;
				}
			}
			
			lefts = left[curr][last];
			for(int i = 0; i < lefts.size(); i++){
				vi tst = vi(lefts);
				tst.erase(tst.begin() + i);
				vi l = left[curr][lefts[i]];
				auto lst = lower_bound(l.begin(), l.end(), last);
				if((lst != l.end()) && (*lst == last)){
					l.erase(lst);
				}

				if(l == tst){ 
					b = lefts[i];
					break;
				}
			}
		
			last = curr;
			if(a == -1){
				curr = b;
			}
			else if(b == -1){
				curr = a;
			}
			else{
				if(cross(points[a] - points[b], points[curr] - points[b]) > 0){
					curr = a;	
				}
				else{
					curr = b;
				}
			}

			cout<<curr<<' ';
		}

		cout<<'\n';
	}

	return 0;
}
