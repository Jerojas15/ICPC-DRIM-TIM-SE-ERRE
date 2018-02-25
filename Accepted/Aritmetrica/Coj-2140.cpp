//Se preprocesa un arreglo con los 8000 valores posibles
//el arreglo se llena:
//5^x y despues 5^x + [cada posicion del areglo hasta llegar a 5^x], donde se pone 5^x+1
//Ej: 5(5^1) -> 25(5^2) -> 30(5^2 + 5) -> 125(5^3) -> 130(5^3 + 5) -> 150(5^3 + 25) -> 155(5^3 + 30) -> 625(5^4)
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
  vi list;
  int cont = 0;
  int last = 0;
  int lastPow = 1;
  int index = 0;
  for(int i = 0;i<8000;i++){
    if(cont == index){
      list.push_back(pow(5,lastPow));
      lastPow++;
      last = list[i];
      index = i;
      cont = 0;
    }else{
      list.push_back(last+list[cont]);
      cont++;
    }

  }


  int a,b;
  cin >> a;
  while(a--){
    cin >> b;
    cout << list[b-1]<<"\n";
  }
}
