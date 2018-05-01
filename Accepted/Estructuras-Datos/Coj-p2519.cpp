#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

stack<int> stk;
queue<int> q;
priority_queue<pii> pq;


int main(){

	int n, x, y, z;
	string s;

	cin >> n;
	getline(cin, s);

	while (n--){

		getline(cin, s);
		istringstream ss(s);
		while (ss >> s) {

			if (!s.compare("+")){
				y = stk.top(); stk.pop();
				x = stk.top(); stk.pop();
				stk.push(x + y);
				y = q.front(); q.pop();
				x = q.front(); q.pop();
				q.push(x + y);
				y = pq.top().second; pq.pop();
				x = pq.top().second; pq.pop();
				z = x + y;
				pq.push(pii(-z, z));
			} else if (!s.compare("-")){
				y = stk.top(); stk.pop();
				x = stk.top(); stk.pop();
				stk.push(x - y);
				y = q.front(); q.pop();
				x = q.front(); q.pop();
				q.push(x - y);
				y = pq.top().second; pq.pop();
				x = pq.top().second; pq.pop();
				z = x - y;
				pq.push(pii(-z, z));
			}else if (!s.compare("*")){
				y = stk.top(); stk.pop();
				x = stk.top(); stk.pop();
				stk.push(x * y);
				y = q.front(); q.pop();
				x = q.front(); q.pop();
				q.push(x * y);
				y = pq.top().second; pq.pop();
				x = pq.top().second; pq.pop();
				z = x * y;
				pq.push(pii(-z, z));
			} else {
				x = stoi(s);
				stk.push(x);
				q.push(x);
				pq.push(pii(-x, x));
			}
		}
		cout << stk.top() << " " << q.front() << " " << pq.top().second << "\n";
		stk.pop();
		q.pop();
		pq.pop();
	}

	return 0;
}
