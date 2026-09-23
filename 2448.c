#include<stdio.h>

int BuscaBinaria(int x , int n , int v[]){
	int e , m , d;
	
	e = -1; d = n;
	
	while(e < d-1){
		m = (e + d)/2;
		
		if(v[m] < x){
			e = m;
		}else{
			d = m;
		}
	}
	return d;	
}


int main(void){
	int numcasas , numenco;
	
	scanf("%d" , &numcasas);
	scanf("%d" , &numenco);
	
	int casas[numcasas] , encomendas[numenco];
	
	for(int i = 0; i<numcasas; i++){
		scanf("%d" , &casas[i]);
	}
	
	for(int i =0; i<numenco; i++){
		scanf("%d" , &encomendas[i]);
	}
	
	
	int tempo = 0;
	int atual = 0;
	int aux = 0;
	
	for(int i = 0; i<numenco; i++){
		aux = BuscaBinaria(encomendas[i] , numcasas , casas);
		
		if(aux > atual){
			tempo += aux - atual;
		}else{
			tempo += atual - aux;
		}
		atual = aux;
	}
	
	printf("%d\n" ,tempo);
}
