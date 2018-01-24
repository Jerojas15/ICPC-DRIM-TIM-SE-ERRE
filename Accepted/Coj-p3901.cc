#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long int x1,x2,y1,y2;
	long int z1,z2,w1,w2;
	long int pos1,pos2;
	long int aux,aux2,aux3,aux4,aux5,aux6;
	vector<int> v;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> z1 >> w1 >> z2 >> w2;
	cin >> pos1 >> pos2;
	v.push_back(x1);
	v.push_back(y1);
	v.push_back(x2);
	v.push_back(y2);
	v.push_back(z1);
	v.push_back(w1);
	v.push_back(z2);
	v.push_back(w2);
	sort(v.begin(),v.end());
	x1 += v[0];y1+= v[0];x2+= v[0];y2+= v[0];z1+= v[0];w1+= v[0];z2+= v[0];w2+= v[0];
	aux = w1-y1;//altura abajo
	aux2 = x2-x1;//largo abajo/arriba
	aux3 = z1-x1;//largo izq
	aux4 = y2-y1;//altura izq/der
	aux5 = y2-w2;//altura arriba
	aux6 = x2-z2;//largo der
	if(aux2>=pos1 && aux>=pos2)cout << "Yes\n";//abajo
	else if(aux3>=pos1 && aux4>=pos2)cout << "Yes\n";//izq
	else if(aux2>=pos1 && aux5>=pos2)cout << "Yes\n";//arriba
	else if(aux6>=pos1 && aux4>=pos2)cout << "Yes\n";//derecha
	else{cout << "No\n";}
	return 0;
}