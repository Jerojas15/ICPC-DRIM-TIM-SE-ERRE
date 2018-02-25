#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int main(){
  int a,b, cont, temp, index;
  cin >> a;
  while(a--){
    temp = 1;
    cin >> b;
    vi list(b,0);
    int i = 0;
    while(temp<=b){
      index = temp;
      while(index){
        if(!list[i%b]){
          index--;
        }
        i++;
      }
      while(list[i%b]){
        i++;
      }
      list[i%b] = temp;
      temp++;
    }
    for(int i = 0;i<b;i++){
      cout << list[i] << " ";
    }cout << "\n";
  }


  return 0;
}
