#include<stdio.h>

int dfs(int adj[100][100] , int visitados[] , int atual, int vertices ){
	visitados[atual] = 1;
	
	int aux = 0;
	for(int viz = 0; viz<  vertices; viz++){
		if(adj[atual][viz] == 1 && visitados[viz]!=1){
			
			aux += 1 + dfs(adj , visitados , viz , vertices);
		}
	}
	return aux;
}



int main(void){
	int casos;
	
	scanf("%d" , &casos);
	
	while(casos--){
		int inicio;
		scanf("%d" , &inicio);
		
		int vertices , arestas;
		scanf("%d %d" , &vertices , &arestas);
		
		int adj[100][100] = {0};
		
		int x , y;
		
		int visitados[100] = {0};
		
		for(int cont = 0; cont < arestas; cont++){
			scanf("%d %d" , &x , &y);
			
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		
		printf("%d" , dfs(adj , visitados , inicio , vertices)*2);
		printf("\n");
	}
		
}
