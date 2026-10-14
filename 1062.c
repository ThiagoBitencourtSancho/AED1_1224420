#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int numero;
    struct cel *prox;
} cel;

void empilhar(int x, cel *pilha) {
    cel *nova = (cel *) malloc(sizeof(cel));
    if (nova == NULL) exit(1);
    nova->numero = x;
    nova->prox = pilha->prox;
    pilha->prox = nova;
}

int desempilhar(cel *pilha) {
    cel *remover = pilha->prox;
    int x = remover->numero;
    pilha->prox = remover->prox;
    free(remover);
    return x;
}

void limparPilha(cel *p) {
    while (p->prox != NULL) {
        desempilhar(p);
    }
}

int main(void) {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        cel *vagoes = (cel *) malloc(sizeof(cel));
        vagoes->prox = NULL;

        cel *pilha = (cel *) malloc(sizeof(cel));
        pilha->prox = NULL;

        while (1) {
            int primeiro;
            scanf("%d", &primeiro);

            if (primeiro == 0) {
                printf("\n");
                break;
            }

            int ordem[n];
            ordem[0] = primeiro;
            for (int i = 1; i < n; i++) {
                scanf("%d", &ordem[i]);
            }

            limparPilha(vagoes);
            limparPilha(pilha);

            for (int j = n; j >= 1; j--) {
                empilhar(j, vagoes);
            }

            int possivel = 1;

            for (int i = 0; i < n; i++) {
                int atual = ordem[i];

                while ((pilha->prox == NULL || pilha->prox->numero != atual) && vagoes->prox != NULL) {
                    empilhar(desempilhar(vagoes), pilha);
                }

                if (pilha->prox != NULL && pilha->prox->numero == atual) {
                    desempilhar(pilha);
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }

        limparPilha(vagoes);
        limparPilha(pilha);
        free(vagoes);
        free(pilha);
    }

    return 0;
}
