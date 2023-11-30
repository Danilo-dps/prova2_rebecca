#include <stdio.h>
#include <stdlib.h>

struct no {
    int chave;
    struct no *esquerda, *direita;
};

struct no *novoNo(int item) {
    struct no *temp = (struct no *)malloc(sizeof(struct no));
    temp->chave = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

struct no* inserir(struct no* no, int chave) {
    if (no == NULL) return novoNo(chave);

    if (chave < no->chave)
        no->esquerda = inserir(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = inserir(no->direita, chave);   

    return no;
}

void emOrdem(struct no *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d \n", raiz->chave);
        emOrdem(raiz->direita);
    }
}

int main() {
    struct no *raiz = NULL;
    int chaves[] = {34, 12, 7, 3, 9, 34, 54, 1, 6, 42, 78, 77, 24, 10};
    int n = sizeof(chaves)/sizeof(chaves[0]);
	
	int i;
    for (i=0; i<n; i++)
        raiz = inserir(raiz, chaves[i]);

    emOrdem(raiz);

    return 0;
}


