#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *esq;
    struct No *dir;
} No;

No *criar(char valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *criarArvore(char infixo[], char prefixo[], int inicial, int final, int *posicao) {
    if (inicial > final) {
        return NULL;
    }

    char raiz_valor = prefixo[(*posicao)++];
    No *novo = criar(raiz_valor);

    int aux = inicial;
    while (infixo[aux] != raiz_valor) {
        aux++;
    }

    novo->esq = criarArvore(infixo, prefixo, inicial, aux - 1, posicao);
    novo->dir = criarArvore(infixo, prefixo, aux + 1, final, posicao);

    return novo;
}

void posfixo(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    posfixo(raiz->esq);
    posfixo(raiz->dir);
    printf("%c", raiz->valor);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main(void) {
    char prefixo[30], infixo[30];

    while (scanf("%s %s", prefixo, infixo) == 2) {
        int posicao = 0;
        int tamanho = (int) strlen(prefixo);

        No *raiz = criarArvore(infixo, prefixo, 0, tamanho - 1, &posicao);

        posfixo(raiz);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
