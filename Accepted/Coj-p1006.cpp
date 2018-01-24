#include <iostream>
#include <stdlib.h>

using namespace std;


string desencrypt(string a){

    if (a.size() == 0) {
        return "";}
    
    if(a.size() == 1){
        if(isalpha(a[0])){
                switch (a[0]) {
                case 'a':
                    a[0] = 'z';
                    break;
                case 'A':
                    a[0] = 'Z';
                    break;
                default:
                    a[0] -= 1;
            }
            }
        return a;
    }
    int left=(a.size()-1)/2;

    return desencrypt(a.substr(1,left))+desencrypt(a.substr(0,1))+desencrypt(a.substr((left)+1,a.size()-left-1));
    
}
int main() {
    string linea;
    while(getline(cin,linea)){
        cout<<desencrypt(linea)<<'\n';
    }

        
    return 0;
}