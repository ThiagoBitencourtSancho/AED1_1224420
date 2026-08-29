/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : THIAGO BITENCOURT SANCHO
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 29/08/2026
Objetivo    : MAIOR E POSICAO
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include<stdio.h>

int main(void){
	int maior;
	int posicao = 1;
	scanf("%d" , &maior);
	int atual;
	for (int cont = 2; cont<=100; cont++){
		scanf("%d" , &atual);
		if(atual > maior){
			maior=atual;
			posicao = cont;	
		} 
	}
	printf("%d\n",  maior);
	printf("%d\n" , posicao);
	return 0;
}
