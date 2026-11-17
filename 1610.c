#include <stdio.h>
#include <stdlib.h>

#define NAO_VISITADO 0
#define EM_PROCESSAMENTO 1
#define CONCLUIDO 2

typedef struct No {
    int destino;
    struct No *proximo;
} No;

void adicionar_aresta(No **adj, int origem, int destino) {
    No *novo = (No *) malloc(sizeof(No));
    novo->destino = destino;
    novo->proximo = adj[origem];
    adj[origem] = novo;
}

int detectar_ciclo_dfs(int documento_atual, No **adj, int *estado_visita) {
    estado_visita[documento_atual] = EM_PROCESSAMENTO;

    No *atual = adj[documento_atual];
    while (atual != NULL) {
        int vizinho = atual->destino;

        if (estado_visita[vizinho] == EM_PROCESSAMENTO) {
            return 1;
        }

        if (estado_visita[vizinho] == NAO_VISITADO) {
            if (detectar_ciclo_dfs(vizinho, adj, estado_visita)) {
                return 1;
            }
        }

        atual = atual->proximo;
    }

    estado_visita[documento_atual] = CONCLUIDO;
    return 0;
}

void liberar_grafo(No **adj, int total_documentos) {
    for (int i = 1; i <= total_documentos; i++) {
        No *atual = adj[i];
        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }
    free(adj);
}

int main(void) {
    int total_casos;
    if (scanf("%d", &total_casos) != 1) return 0;

    for (int caso_atual = 0; caso_atual < total_casos; caso_atual++) {
        int total_documentos, total_dependencias;
        scanf("%d %d", &total_documentos, &total_dependencias);

        No **adj = (No **) calloc(total_documentos + 1, sizeof(No *));

        int *estado_visita = (int *) calloc(total_documentos + 1, sizeof(int));

        for (int i = 0; i < total_dependencias; i++) {
            int documento_origem, documento_destino;
            scanf("%d %d", &documento_origem, &documento_destino);
            adicionar_aresta(adj, documento_origem, documento_destino);
        }

        int possui_ciclo = 0;

        for (int i = 1; i <= total_documentos; i++) {
            if (estado_visita[i] == NAO_VISITADO) {
                if (detectar_ciclo_dfs(i, adj, estado_visita)) {
                    possui_ciclo = 1;
                    break;
                }
            }
        }

        if (possui_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        liberar_grafo(adj, total_documentos);
        free(estado_visita);
    }

    return 0;
}
