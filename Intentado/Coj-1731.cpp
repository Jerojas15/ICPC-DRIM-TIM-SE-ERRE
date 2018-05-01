#include <bits/stdc++.h>
using namespace std;


int main(){
  int a;
  long long b,first, second;
  cin >> a;
  while(a--){
    long long xMin = 0, yMin = 0, minArea;
    cin >> b;
    b = ceil((float)b/5);

    for(int i = 1;i<=sqrt(b);i++){
      first = ceil((float)(b)/i);
      second = i;

      first*=10;
      first+=2;

      second*=44;
      second+=4;

      if(minArea > (first*second) || !xMin){
        xMin = first;
        yMin = second;
        minArea = xMin*yMin;
      }else{
        if(minArea == (first*second) && abs(first-second)<=abs(xMin-yMin)){
          xMin = first;
          yMin = second;
          minArea = xMin*yMin;
        }

      }
      first = i;
      second = ceil((float)(b)/i);

      first*=10;
      first+=2;

      second*=44;
      second+=4;

      if(minArea > (first* second) || !xMin){
        xMin = first;
        yMin = second;
        minArea = xMin*yMin;
      }else{
        if(minArea == (first*second) && abs(first-second)<=abs(xMin-yMin)){
          xMin = first;
          yMin = second;
          minArea = xMin*yMin;
        }

      }
    }
    cout << ((yMin>xMin)?yMin:xMin) << " X " << ((yMin<xMin)?yMin:xMin) << " = " << minArea << "\n";
  }
  return 0;
}
