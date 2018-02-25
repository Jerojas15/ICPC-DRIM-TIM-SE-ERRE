#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin >> a;
  while(a--){
    cin >> b >> c;
    if(((b-1)*c+(c-1)*b)%2){
      cout << "First\n";
    }else{
      cout << "Second\n";
    }
  }
  return 0;
}
