#include <bits/stdc++.h>

using namespace std;

int main(){
  int a;
  vector<int> list;
  cin >> a;
  int cont = 0;
  while(a--){
        bool ended = true;
        int b,c,d, sum;
        cin >> b >> c >> d;
        int dif = 1;
        int less, more, total;
        while(ended){
              list.clear();
              cont = 0;
              less = b-(dif*2);
              total = d;
              while(total>0){
                    list.push_back(less);
                    total-=less;
                    less+=dif;
                    cont++;

              }
              if(!total){
                    ended = false;
                    cout << cont << "\n";
                    for(int i = 0;i<cont;i++){
                      cout << list[i] << " ";
                    }
                    cout << "\n";
              }
              dif++;
        }
  }
  return 0;
}
