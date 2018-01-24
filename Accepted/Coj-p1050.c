#include <stdio.h>

int mcd(int a, int b){
  int r;
  r=a%b;
    while(r>0)
    {
              a=b;
              b=r;
              r=a%b;
    }
    return b;
}

int main()
{
    int N, i, a, cont = 0;
    scanf("%i", &N);
    for(i = 1;i<N;i++){
      a = mcd(N, i);
      if(a == 1){
        cont++;
      }
    }
    printf("%i\n", cont);
    return 0;
}