//Simulacion, maximo mcm(s,c) ciclos

#include<bits/stdc++.h>
using namespace std;

int mod(int a, int b){
	if(a > 0) return a%b;
	else return (b+a)%b;
}

int main(void){
	int s,c,p,l;
	int cas = 1;
	cin>>s>>c>>p>>l;
	while(s){
		int lcm = (s * c) / __gcd(s,c) ;
		int i = 0;
		int is = 0, ic =  0;
		int flag = 0;
		while(i < lcm){
			if((is == p) && (ic == l)){
				flag = 1;
				break;
			}
			
			is--;
			ic--;
			is = mod(is, s);
			ic = mod(ic, c);

			i++;
		}
		cout<<"Case "<<cas<<": ";	
		if(flag){
			cout<<i/s<<' '<<i%s<<'/'<<s<<'\n';	
		}
		else cout<<"Never\n";
		
		cas++;
		cin>>s>>c>>p>>l;
	}

	return 0;
}
