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

int minValor(struct no* no) { 
    struct no* atual = no; 
  
    while (atual && atual->esquerda != NULL) 
        atual = atual->esquerda; 
  
    return(atual->chave); 
} 

int maxValor(struct no* no) { 
    struct no* atual = no; 
  
    while (atual && atual->direita != NULL) 
        atual = atual->direita; 
  
    return(atual->chave); 
} 

int main() {
	setlocale (LC_ALL, "Portuguese");
    struct no *raiz = NULL;
    int chaves[] = {34, 12, 7, 3, 9, 34, 54, 1, 6, 42, 78, 77, 24, 10};
    int n = sizeof(chaves)/sizeof(chaves[0]);
	
	int i;
    for (i=0; i<n; i++)
        raiz = inserir(raiz, chaves[i]);

    printf("O menor valor da árvore é %d\n", minValor(raiz));
    printf("O maior valor da árvore é %d", maxValor(raiz));

    return 0;
}

