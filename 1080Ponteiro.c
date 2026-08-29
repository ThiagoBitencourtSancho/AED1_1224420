/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : THIAGO BITENCOURT SANCHO
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 29/08/2026
Objetivo    : MAIOR E POSICAO
Dificuldade : aplicar listas encadeadas
Uso de IA   : 
-------------------------------------------------------------------------- */
#include<stdio.h>
#include<stdlib.h>


typedef struct Numeros {
	int valor;
	struct Numeros *prox;
} Numeros;


void inserir(int x , Numeros *p ){
	Numeros *novo;
	
	novo = (Numeros *) malloc(sizeof(Numeros));
	
	novo->valor = x;
	novo->prox = p->prox;
	p->prox = novo;
}


int main(void){
		
	Numeros *lista;
	lista = (Numeros *) malloc(sizeof(Numeros));
	lista->prox = NULL;
	
	int entrada = 0;
	for(int cont = 1;cont<=100; cont++){
		scanf("%d" , &entrada);
		inserir(entrada , lista);
	}
	
	Numeros *atual = lista->prox;

	int maior;

	maior = atual->valor;
	
	int cont = 1;
	int posicao = 1;
	
	while(atual != NULL){
		
		if(atual->valor > maior){
			maior = atual->valor;
			posicao = cont;
		}
		
		cont++;
		atual = atual->prox;
	}
	printf("%d\n" , maior);
	printf("%d\n" , 100 - posicao + 1);
	
	atual = lista->prox;
    while (atual != NULL) {
        Numeros *aux = atual->prox;
        free(atual);
        atual = aux;
    }
    
    free(lista);
	
}
