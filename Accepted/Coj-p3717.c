#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int T;
	scanf("%d",&T);
	int arr[T];
	int *bit = calloc(T,sizeof(int));
	for(int i = 0; i < T; i++)scanf("%d",&arr[i]);
	for(int i = T-1; i >= 0; i--){
		if(i+arr[i] == T-1){
			bit[i] = 1;
		}else if(i+arr[i] < T && bit[i+arr[i]+1]){
			bit[i] = 1;
		}else{
			bit[i] = 0;
		}
	}
	for(int i = 0; i < T; i++){
		if(bit[i]){
			printf("%d\n",i);
		}
	}
	printf("%d\n",T);
	
	return 0;
}