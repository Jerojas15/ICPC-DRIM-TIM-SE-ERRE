
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main(){
  int a, b;
  cin >> a >> b;
  char c[52][52];
  vi res(10,0);
  int pos = 0, found, aux, cont = 0;


  for(int i = 0;i<a;i++){
    for(int j = 0;j<b;j++){
      cin >> c[i][j];
    }
  }

  for(int j = b-1;j>=0;j--){
    found = 0;
    for(int i = 0;i<a;i++){
      if(c[i][j]>'0' && c[i][j]<='9'){
        aux = c[i][j]-48;
        if(res[aux] == 0){
          if(found == 0){
            pos++;
          }
          found=1;
          res[aux] = pos;
          cont++;
        }
      }
      if(cont == 9){
        break;
      }
    }
  }
  for(int i = 1;i<10;i++){
    cout << res[i] << "\n";
  }
  return 0;
}
