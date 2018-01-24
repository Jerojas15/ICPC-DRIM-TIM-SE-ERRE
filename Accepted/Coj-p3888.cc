#include <iostream>
#include <math.h>
using namespace std;

int res;

int foo(float i, float j, float x, float y){
    if(i < x || j < y) return -1;
    int cont = 0;
    while(i > x || j > y){
        
        if(i>x){
            i /= 2;
            cont++;
        }
        if(j>y){
            j /= 2;
            cont++;
        }
    }
    return cont;
}

int main(){
    
    float a, b, c, d;
    int aux1, aux2;
    
    cin >> a >> b;
    cin >> c >> d;
    aux1 = foo(a,b,c,d);
    aux2 = foo(a,b,d,c);
    
    res = min((aux1 == -1)? aux2 : aux1, (aux2 == -1)? aux1 : aux2);
    
    cout << res << endl;
    return 0;
}