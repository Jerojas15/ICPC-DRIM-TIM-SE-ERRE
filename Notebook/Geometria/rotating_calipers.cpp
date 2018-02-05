//used here to find diameter
double calipers(vc points){
	//get upper and lower convex hulls
	//upper[size_u] = lower[0] and viceversa
	vc upper,lower;
	int size_u, size_l;

	int i = 0, j = 0;
	while((i < size_u) || (j < size_l)){
		//upper[i] and lower[j] are opposed;
		res = max(res, distance(upper[i],lower[j]));	

		if(i == size_u){
			j++;
		}
		else if( j = size_l){
			i++;
		}
		else if( angle(lower[j+1] - lower[j]) > 
		  angle(upper[i+1] - upper[i])){
			i++;		
		}
		else if( angle(lower[j+1] - lower[j]) == 
		  angle(upper[i+1] - upper[i])){
			//upper[i] and lower[j+1]
			//uppper[i+1] and lower[j]
			//are opposed;
			res = max(res, distance(upper[i], lower[j+1]));
			res = max(res, distance(upper[i+1], lower[j]));

			i++;
			j++;
		}
		//possibli replaces previous 2 statements, needs proof
		/*else if(cross_product(lower[j] - lower[j+1], 
		 * upper[i+1] - upper[i]) > 0 ){
			i++;	
		}*/
		else{
			j++;
		}

	}
}
