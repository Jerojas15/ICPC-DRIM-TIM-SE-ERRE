#include <bits/stdc++.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
typedef double T;

const T EPS = 1e-12;

struct PT {
	T x, y;
	PT(){}
	PT(T x, T y) : x(x), y(y) {}
	bool operator< (const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
	bool operator== (const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
	PT operator - (const PT &p) const { return PT(x-p.x,y-p.y);}
};

T cross(PT p, PT q) { return p.x * q.y - p.y * q.x;}
T dot (PT p, PT q) { return p.x*q.x+p.y*q.y;}
T dist2 (PT p, PT q){return dot(p-q,p-q);} 

bool LinesParallel(PT a,PT b, PT c,PT d){
	return fabs(cross(b - a, c - d)) < EPS;
}

bool LinesCollinear(PT a,PT b, PT c,PT d){
		return LinesParallel(a,b,c,d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d,c-a)) < EPS;
}

bool SegmentsIntersect(PT a,PT b, PT c,PT d){
	if(LinesCollinear(a,b,c,d)){
		if( dist2(a,c) < EPS || dist2(a,d) < EPS || dist2(b,c) < EPS || dist2(b,d) < EPS) return true;
		if(dot(c-a,c-b) > 0 && dot(d-a, d-b) > 0 && dot(c - b, d - b) > 0 ) return false;
		return true;
	}
	if (cross ( d - a, b - a) * cross ( c-a, b -a) > 0) return false;
	if (cross ( a - c, d - c) * cross ( b-c, d -c) > 0) return false;
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int s,k,w;
	//segment seg;
	
	PT paux1,paux2,kid1,kid2;
	pair<PT,PT> pppaux;
	vector<PT> kids;
	vector<pair<PT,PT> > walls;
	cin>>s>>k>>w;
	int veo[k];
	for(int i = 0; i < k; i++){
		veo[i] = 0;
		cin>>paux1.x;
		cin>>paux1.y;
		kids.push_back(paux1);
	}
	for(int i = 0; i < w; i++){
		
		cin>>paux1.x;
		cin>>paux1.y;
		
		cin>>paux2.x;
		cin>>paux2.y;
		
		pppaux.first = paux1;
		pppaux.second = paux2;
		
		walls.push_back(pppaux);
	}
	bool pega;
	for(int i = 0; i < s; i ++){
		kid1=kids[i];		
		for(int j = i+1; j < k; j ++){
			pega = false;
			kid2=kids[j];
			for(int h = 0; h < w; h ++){
				if(SegmentsIntersect(kid1,kid2,walls[h].first, walls[h].second)){
					pega = true;
					break;
				}
			}
			if(!pega){
				veo[i]++;
				if(j < s)veo[j]++;
			}
		}
	}
	for(int i = 0; i < s; i ++){
		cout<<veo[i]<<"\n";
	}
	return 0; 
}