#include<bits/stdc++.h>
using namespace std;
int main(){
  int a, c;
  string b,d;
  cin >> a;
  while(a--){
    cin >> b;
    if(b.length()>1){
      d = b.substr(b.length()-2, b.length());
      c = atoi(d.c_str());
    }else{
      c = b[0] - '0';
    }
    if(!(c % 4)){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
  return 0;
}
