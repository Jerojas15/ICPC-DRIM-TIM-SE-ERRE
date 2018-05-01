#include <bits/stdc++.h>
using namespace std;

typedef pair<char, string> pcs;
typedef pair<int, pcs> pics;
typedef pair<int, pics> piis;
typedef pair<int, piis> piiis;

priority_queue<piiis> pq;
int main(){

	int g, s, b;
	string str;

	cin >> str;
	while (str.compare("#")) {
		if(!str.compare("@")){
			while(!pq.empty()){
				cout << pq.top().second.second.second.second << "\n";
				pq.pop();
			}
			cout << "@\n";
		}else{

			cin >> g >> s >> b;
			pq.push(piiis(g,piis(s,pics(b, pcs(-str[0], str)))));
		}
		cin >> str;
	}
	while(!pq.empty()){
		cout << pq.top().second.second.second.second << "\n";
		pq.pop();
	}
	return 0;
}
