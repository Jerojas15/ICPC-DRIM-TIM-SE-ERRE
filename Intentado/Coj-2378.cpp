#include <bits/stdc++.h>

using namespace std;
typedef vector<long int> vli;

int main(){
  bool ended = false;
  long int a, b, temp;
  cin >> a;
  cin >> b;
  if(!b){
    cout << "danger\n";
    return 0;
  }
  vli list;
  a *= 10000000;
  while(b--){
    cin >> temp;
    list.push_back(temp);
  }
  sort(list.begin(),list.end());
  long int i = 0, j = list.size()-1;
  while(!ended){
    if(i >= j){
      ended = true;
      cout << "danger\n";
      return 0;
    }
    temp = list[i]+list[j];
    if(temp == a){
      ended = true;
      cout << "yes " << list[i] << " " << list[j] << "\n";
    }else{
      if(temp > a){
        j--;
      }else{
        if(temp<a){
          i++;
        }
      }
    }
  }
  return 0;
}
