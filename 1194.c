#include<stdio.h>
#include<stdlib.h>

typedef struct No {
	char valor;
	struct No *esq;
	struct No *dir;
} No;



No *criar(char valor){
	No *novo;
	novo = (No *) malloc(sizeof(No));
	novo->valor = valor;
	novo->dir = novo->esq = NULL;
	return novo;
}


No *montarArvore(char pref[] , char inf[] ,int inicio , int fim , int *pos){
	if(inicio >fim){
		return NULL;
	}
	
	char raiz = pref[(*pos)++];
	
	No *novo = criar(raiz);
	
	
	int aux = inicio;
	
	while(inf[aux]!= raiz){
		aux++;
	}
	
	novo->esq = montarArvore(pref , inf , inicio , aux-1 , pos);
	novo->dir = montarArvore(pref , inf , aux+1 , fim , pos);
	return novo;
}


void mostrarEDR(No *raiz){
	if(raiz == NULL){
		return;
	}
	
	mostrarEDR(raiz->esq);
	mostrarEDR(raiz->dir);
	printf("%c" , raiz->valor);
}



int main(void){
	int casos;
	scanf("%d\n" , &casos);
	
	while(casos--){
		int nos;
	
		scanf("%d", &nos);
		
		char pref[nos] , inf[nos];
		
		scanf("%s %s" , pref , inf);
		
		int pos = 0;
		
		No *raiz = montarArvore(pref , inf , 0 , nos-1 , &pos);
		
		mostrarEDR(raiz);
		printf("\n");
		
	}
	 
}
