#include <bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c,d;
  cin >> a;
  while(a--){
    bool temp = false;
    cin >> b >> c >> d;
    if(c>b)cout << "No\n";
    else if(c == b || d == b)cout << "Yes\n";
    else{
      for(int i = c;i<d;i++){
        double aux = (double)b/(double)i;
        int res = aux;
        if(aux == res){
          cout << "Yes\n";
          temp = true;
          break;

        }
      }
      if(!temp)cout << "No\n";
    }
  }


  return 0;
}
