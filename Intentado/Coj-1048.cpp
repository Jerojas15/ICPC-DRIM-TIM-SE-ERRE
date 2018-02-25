#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c[1001];

    c[0] = 1;

    for(int i = 0;i<100;i++){
      for(int j = 1;j<i;j++){
        for(int k = 1;k<j;k++){
          if(__gcd(__gcd(i,j),k) == 1){
            c[i] +=3;
          }
        }
      }
    }

    cout << "ya"<<endl;
    cin >> a;
    while(a--){
      cin >> b;
      cout << c[b] << "\n";
    }

    return 0;
}
