#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vli;

int main(){
  vli list(1000000000,0);
  long long int a  = 0;
  int i = 0,last = 0;
  list[0] = 0;
  for(i = 1;i<44721;i++){
    a+=i;
    double temp = sqrt(a+1);
    if(!((int)temp - temp)){
      list[a+1] = list[last]+1;
      for(int i = last;i<a+1;i++){
        list[i] = list[last];
      }
      last = a+1;
    }
  }
  int x, y;
  int cont = 1;
  cin >> x >> y;
  while(x&&y){
    cout << "Case " << cont << ": " << (list[y-1]-list[x]) << "\n";
    cont++;
    cin >> x >> y;
  }
  return 0;
}
