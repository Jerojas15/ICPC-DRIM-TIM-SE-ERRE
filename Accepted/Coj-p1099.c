int main(){
	int a, b , c,d,e,f;
	while(1){
		scanf("%i %i %i",&d, &e , &f);
		if(d == 0){break;}
		if((d>e)&&(d>f)){
 			c = d; a = e; b = f;
  		}else if((e>d)&&(e>f)){
 			c = e;  a = d; b = f; 
  		}else{
 			c = f; a = d; b = e;
 		}
		if(((a*a) + (b*b)) == c*c){
			printf("right\n");
		}else{
			printf("wrong\n");
		}
	}
	return 0;
}
