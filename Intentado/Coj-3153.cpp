#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){
  int a, b, c, temp;
  cin >> a >> b >> c;
  vi list(a);
  while(c--){
    cin >> temp;
    list[temp] = 1;
  }
  for(int i = 1;i<a;i++){
    for(int j = 1;;j+=i){
      if(list[j%a]){
        break;
      }
      if((j%a) == b){
        cout << i << "\n";
        return 0;
      }
    }
  }

  return 0;
}
