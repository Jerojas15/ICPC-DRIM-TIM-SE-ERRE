#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a;
  while(a--){
    long long cont = 1;
    cin >> b;
    for(int i=2;i<=b/2;i++){
      if(!(b%i)){
        cont+=i;
      }
    }
    if(cont<b){
      cout << "deficient\n";
    }else if(cont == b){
      cout << "perfect\n";
    }else{
      cout << "abundant\n";
    }
  }
  return 0;
}
