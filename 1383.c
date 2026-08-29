/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : THIAGO BITENCOURT SANCHO
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383  
Data        : 29/08/2026
Objetivo    : SODOKU
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */

#include<stdio.h>

int main(void){
	
	int rep;
	
	scanf("%d" , &rep);
	
	for(int cont = 1; cont<=rep; cont++){
		int matriz[9][9];
	
		int ver = 1;
		
		for(int linha = 0; linha < 9; linha++){
			
			int soma = 0;
			int produto = 1;
			
			for(int coluna = 0; coluna < 9; coluna++){
				scanf("%d" , &matriz[linha][coluna]);
				
				soma += matriz[linha][coluna];
				produto = produto * matriz[linha][coluna];
			}
			
			if(!(soma == 45 && produto == 362880)){
				ver = 0;
			}
		}
		
		
		for(int coluna = 0; coluna < 9; coluna++){
			
			int soma = 0;
			int produto = 1;
			for(int linha = 0; linha < 9; linha++){
				soma += matriz[linha][coluna];
				produto = produto * matriz[linha][coluna];
			}
			
			if(!(soma == 45 && produto == 362880)){
				ver = 0;
			}
		}
		
		
		
		for(int linhaQua = 0; linhaQua <= 6; linhaQua+=3){
			for(int colunaQua = 0; colunaQua <= 6; colunaQua +=3){
				int soma = 0;
				int produto = 1;
				
				for(int linha = linhaQua; linha <= linhaQua + 2; linha++){
					for(int coluna = colunaQua; coluna<= colunaQua+2; coluna++){
						soma += matriz[linha][coluna];
						produto = produto * matriz[linha][coluna];			
					}
				}
				
				if(!(soma == 45 && produto == 362880)){
					ver = 0;
				}
			
			}
		}
		
		if(ver == 1){
			printf("Instancia %d\n" , cont);
			printf("SIM\n\n");
		}else{
			printf("Instancia %d\n" , cont);
			printf("NAO\n\n");
		}	
	}
	
}
