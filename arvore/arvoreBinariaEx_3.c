#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int altura(struct no* no) {
    if (no == NULL)
        return 0;
    else {
        int alturaEsquerda = altura(no->esquerda);
        int alturaDireita = altura(no->direita);

        if (alturaEsquerda > alturaDireita)
            return(alturaEsquerda + 1);
        else return(alturaDireita + 1);
    }
}

int main() {
			setlocale (LC_ALL, "Portuguese");
    struct no *raiz = NULL;
    int chaves[] = {34, 12, 7, 3, 9, 34, 54, 1, 6, 42, 78, 77, 24, 10};
    int n = sizeof(chaves)/sizeof(chaves[0]);
	
	int i;
    for (i=0; i<n; i++)
        raiz = inserir(raiz, chaves[i]);

    printf("Altura da árvore é :%d", altura(raiz));

    return 0;
}

