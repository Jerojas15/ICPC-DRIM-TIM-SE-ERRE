#include <bits/stdc++.h>

using namespace std;

int main(){
  int a;
  cin >> a;
  int size = a;
  int b[a][4];
  bool c[a];
  int cont = 0;
  int xMax, xMin, yMax, yMin;
  int result = 0;

  while(a--){
    cin >> b[cont][0] >> b[cont][1] >> b[cont][2] >> b[cont][3];
    b[cont][0] += 100001;
    b[cont][1] += 100001;
    b[cont][2] += 100001;
    b[cont][3] += 100001;
    c[cont] = false;
    cont++;

  }


  for(int i = 0;i<size;i++){
    cout << "+"<< (b[i][2]-b[i][0]) << " " << (b[i][1]-b[i][3]) << endl;
    result+=((b[i][2]-b[i][0])*(b[i][1]-b[i][3]));

    for(int j = i+1;j<size;j++){
      cout << "*"<< (b[j][2]-b[j][0]) << " " << (b[j][1]-b[j][3]) << endl;
      xMax = min(b[i][2], b[j][2]);
      xMin = max(b[i][0], b[j][0]);
      yMax = min(b[i][1], b[j][1]);
      yMin = max(b[i][3], b[j][3]);

      cout << "/"<< (xMax)<<" "<<(xMin) << " " << (yMax)<<" "<<(yMin) << endl;
      if (xMax >= xMin || yMax >= yMin) {

      }else{
          if(!c[j]){
          cout << "-"<< (xMax-xMin) << " " << (yMax-yMin) << endl;
          result -= ((xMax-xMin)*(yMax-yMin));
        }
        c[j] = true;}
        

    }
  }
  cout << result << "\n";

  return 0;
}
