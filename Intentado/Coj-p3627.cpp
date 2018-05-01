#include <bits/stdc++.h>
using namespace std;

long long list[100005];

long long complete(int value){
  if(list[value])return list[value];
  if(value==1)return 1;
  list[value] = 4*complete(b);
}

int main(){
  for(int i = 0;i<10005;i++){
    list[i] = 0;
  }
  int a, b;
  cin >> a;
  while(a--){
    cin >> b;
    if(list[b]){
      cout << list[b] << "\n";
    }else{
      cout << complete(b) << "\n";
    }
  }

  return 0;
}
