#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *esq;
    struct no *dir;
} no;

no* insere(no* r, int val) {
    if (r == NULL) {
        no* novo = (no*) malloc(sizeof(no));
        novo->v = val;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (val < r->v) {
        r->esq = insere(r->esq, val);
    } else {
        r->dir = insere(r->dir, val);
    }
    return r;
}

void preOrdem(no* r, int *primeiro) {
    if (r != NULL) {
        if (*primeiro) {
            printf("%d", r->v);
            *primeiro = 0;
        } else {
            printf(" %d", r->v);
        }
        preOrdem(r->esq, primeiro);
        preOrdem(r->dir, primeiro);
    }
}

void emOrdem(no* r, int *primeiro) {
    if (r != NULL) {
        emOrdem(r->esq, primeiro);
        if (*primeiro) {
            printf("%d", r->v);
            *primeiro = 0;
        } else {
            printf(" %d", r->v);
        }
        emOrdem(r->dir, primeiro);
    }
}

void posOrdem(no* r, int *primeiro) {
    if (r != NULL) {
        posOrdem(r->esq, primeiro);
        posOrdem(r->dir, primeiro);
        if (*primeiro) {
            printf("%d", r->v);
            *primeiro = 0;
        } else {
            printf(" %d", r->v);
        }
    }
}

void libera(no* r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    int c;
    if (scanf("%d", &c) != 1) return 0;
    
    for (int k = 1; k <= c; k++) {
        int n;
        scanf("%d", &n);
        no* raiz = NULL;
        
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            raiz = insere(raiz, val);
        }
        
        printf("Case %d:\n", k);
        
        int primeiro = 1;
        printf("Pre.: ");
        preOrdem(raiz, &primeiro);
        printf("\n");
        
        primeiro = 1;
        printf("In..: ");
        emOrdem(raiz, &primeiro);
        printf("\n");
        
        primeiro = 1;
        printf("Post: ");
        posOrdem(raiz, &primeiro);
        printf("\n\n"); 
        libera(raiz);
    }
    
    return 0;
}
