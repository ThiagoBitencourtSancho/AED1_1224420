/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : THIAGO BITENCOURT SANCHO
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 30/08/2026
Objetivo    : Jogando Cartas Fora
Dificuldade : Implementar uso de filas
Uso de IA   : Me ajudou a entender Filas
-------------------------------------------------------------------------- */

#include<stdio.h>
#include<stdlib.h>


typedef struct Carta{
	int numero;
	struct Carta *proximo;
} Carta;

void inserir(int x , Carta **es , Carta **et){
	
	Carta *novo;
	novo = (Carta *) malloc(sizeof(Carta));
	novo->numero = x;
	novo->proximo = NULL;
	
	if(*et==NULL) *et = *es = novo;
	else{
		(*et)->proximo = novo;
		*et = novo;
	}
	
}


int remover(Carta **es , Carta **et){
	Carta *p;
	int x;
	
	p = *es;          
    x = p->numero;     
    *es = p->proximo;    
    free (p);         
    
    if (*es == NULL) {
        *et = NULL;   
    }
    
    return x;
}

int main(void){
	
	int n;
	
	while(scanf("%d" , &n) == 1 && n != 0){
		Carta *es , *et;
		es = et = NULL;
		for(int i = 1; i<=n; i++){
			inserir(i , &es , &et);
		}
		
		int descartadas[n];
		int contador_d = 0;
		
		while(es != et){
			descartadas[contador_d] = remover(&es , &et);
			
			int topo = remover(&es , &et);
			inserir(topo , &es , &et);
			contador_d++;
		}
		
		printf("Discarded cards:");
		
	    for (int i = 0; i < contador_d; i++) {
	        if (i == 0) {
	            printf(" %d", descartadas[i]);
	        } else {
	            printf(", %d" , descartadas[i]);
	        }
	    }
	    
	    printf("\n");
		
		if (es != NULL) {
	            printf("Remaining card: %d\n", es->numero);
	            remover(&es, &et); 
	    }
		
	} 
	
	
}
