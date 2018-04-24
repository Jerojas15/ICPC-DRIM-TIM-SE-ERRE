#include <bits/stdc++.h>
using namespace std;


typedef vector<long long> vi;

vi arr;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long t, n, q, len, a, b;

	cin >> t;
	while(t--){
		cin >> n >> q;
		arr.clear();
		for (int i = 0; i < n; i++){
			cin >> a;
			arr.push_back(a);
			if(i > 0){
				arr[i] += arr[i-1];
			}
		}
		while(q--){
			cin >> a >> b;
			if(a){
				cout << arr[b] - arr[a-1] << "\n";
			} else{
				cout << arr[b] << "\n";
			}
		}
		if (t > 0)
			cout << "\n";
	}

	return 0;
}
