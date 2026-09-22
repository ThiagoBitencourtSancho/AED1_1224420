#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Insere (int y, celula **es, celula **et) {
    celula *nova = (celula *) malloc(sizeof(celula));
    if (nova == NULL) {
        exit(1);
    }
    nova->valor = y;
    nova->seg = NULL;
    
    if (*et == NULL) {
        *et = *es = nova;
    } else {
        (*et)->seg = nova;
        *et = nova;
    }
}

int Remove (celula **es, celula **et) {
    celula *p = *es;
    int x = p->valor;
    
    *es = p->seg;
    free(p);
    
    if (*es == NULL) {
        *et = NULL;
    }
    
    return x;
}

int main(void) {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        celula *s = NULL;
        celula *t = NULL;
        
        for (int i = 1; i <= n; i++) {
            Insere(i, &s, &t);
        }
        
        int descartadas[55];
        int d_count = 0;
        
        while (s != NULL && s != t) {
            descartadas[d_count++] = Remove(&s, &t);
            int mover = Remove(&s, &t);
            Insere(mover, &s, &t);
        }
        
        printf("Discarded cards:");
        for (int i = 0; i < d_count; i++) {
            if (i == 0) {
                printf(" %d", descartadas[i]);
            } else {
                printf(", %d", descartadas[i]);
            }
        }
        printf("\n");
        
        if (s != NULL) {
            printf("Remaining card: %d\n", s->valor);
            Remove(&s, &t);
        }
    }
    
    return 0;
}
