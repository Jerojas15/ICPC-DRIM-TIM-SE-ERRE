#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include <stdio.h>
#define pb push_back

using namespace std;

int T,X2,X1,Y;
vector<int> primos;

int prueba(int X)
{
  if(X==0)return 0;
  vector<bool> inclusion;
  int S=primos.size();
  inclusion.resize(S);

  int sum=0;
  int mul=1;
  for(int i=1;i<=S;i++){
    inclusion.clear();inclusion.resize(S);
    for(int j=0;j<i;j++)inclusion[S-j-1]=true;

    do{
      long long N=1;
      for(int i=0;i<S;i++)if(inclusion[i])N*=primos[i];
      sum+=(mul*(X/N));
    }while(next_permutation(inclusion.begin(),inclusion.end()));
    mul*=-1;
  }
  return sum;
}

bool revisar(int X)
{
  for(int i=0;i<primos.size();i++)
    if(X%primos[i]==0)return false;
  return true;
}

void factores(int Y)
{
  if(Y%2==0){
    primos.pb(2);
    Y/=2;
    while(Y%2==0){
        Y/=2;
    }
  }

  for(int i=3;i*i<=Y;i+=2){
    if(Y%i==0){
      primos.pb(i);
      Y/=i;
      while(Y%i==0){
          Y/=i;
      }
    }
  }
  if(Y!=1)primos.pb(Y);
}

int main()
{
  scanf("%d",&T);
  while(T--){
    scanf("%d %d %d",&Y,&X1,&X2);
    if(X1>X2)swap(X1,X2);
    Y=Y>0?Y:-Y;
    if(Y==0)assert(false);
    primos.clear();
    factores(Y);
    int s1=1,s2=1;
    if(Y==1){
        printf("%d\n",s2*X2-s1*X1+1);
    }
    else if(X1>0 and X2>0){
        printf("%d\n",(X2-prueba(X2))-(X1-prueba(X1))+revisar(X1));
    }
    else if(X1==0 and X2>0){
        printf("%d\n",(X2-prueba(X2)));
    }
    else if(X1==0 and X2==0){
        printf("%d\n",0);
    }
    else if(X1<0 and X2>0){
        X1=-X1;
        printf("%d\n",(X2-prueba(X2))+(X1-prueba(X1)));
    }
    else if(X1<0 and X2==0){
        X1=-X1;
        printf("%d\n",(X1-prueba(X1)));
    }
    else if(X1<0 and X2<0){
        X1=-X1;X2=-X2;
        printf("%d\n",(X1-prueba(X1))-(X2-prueba(X2))+revisar(X2));
    }
  }
}
