#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);//desincroniza con C (printf y scanf)
 	cin.tie(0); // (Hasta que el buffer estE lleno o hasta que termine el proc)
	int a, b, c;
	string s;
	
	cin >> a;
	
	while(a--){
		
		cin >> s;
		b = s.length();
		c = 0;
		
		for(int i = 0; i < b; i++){
			
			c = ((c * 2) +(s[i]-'0')) % 3;
			
		}
		if(c) cout << "NO" << endl;
		else cout << "YES" << endl;
		
	}
	
	return 0;
}
