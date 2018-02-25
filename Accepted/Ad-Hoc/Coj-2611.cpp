#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){
  int a, b,c,d, res = 0;
  cin >> a >> b;
  vi list;
  while(a--){
    cin >> c >> d;
    list.push_back((c-d));
  }
  sort(list.rbegin(), list.rend());
  for(int i = 0;i<list.size();i++){
    if(list[i]>0){
      res+=3;
    }else if(list[i] == 0){
      if(b){
        res+=3;
        b--;
      }else{
        res+=1;
      }
    }else{
      if(b>abs(list[i])){
        res+=3;
        b-= (abs(list[i])+1);
      }else if(b == abs(list[i])){
        res+=1;
        b = 0;
      }
    }
  }
  cout << res << "\n";
  return 0;
}
