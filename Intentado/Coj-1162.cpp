#include <bits/stdc++.h>
using namespace std;

typedef vector< pair <int,int> > vpii;
typedef vector< int > vi;

int main(){
  int a;
  cin >> a;
  while(a--){
    int b, c,d,e,f;
    cin >> b >> c;
    vpii list;
    while(b--){
      cin >> d >> e >> f;
      list.push_back(make_pair(e,d));
    }
    sort(list.rbegin(), list.rend());
    int x;
    int temp;
    vi index;
    for(int i = 0;i<list.size();i++){
      index.push_back(list[i].second);

    }
    while(c--){
      cin >> x;
      for(int i = 0;i<index.size();i++){
        if(x == index[i]){
          if(i>0){
            cout << index[i-1] << " " << index.size()-i-1 << "\n";
          }else{
            cout << "0 " << index.size()-1 << "\n";
          }
        }
      }

    }
  }

  return 0;
}
