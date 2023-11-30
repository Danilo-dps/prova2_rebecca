#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no {
    char chave;
    struct no *esquerda, *direita;
};

struct no *novoNo(char item) {
    struct no *temp = (struct no *)malloc(sizeof(struct no));
    temp->chave = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

int main() {
		setlocale (LC_ALL, "Portuguese");
    struct no *raiz = novoNo('-');
    raiz->esquerda = novoNo('*');
    raiz->direita = novoNo('+');
    raiz->esquerda->esquerda = novoNo('+');
    raiz->esquerda->direita = novoNo('2');
    raiz->direita->esquerda = novoNo('/');
    raiz->direita->direita = novoNo('+');
    raiz->esquerda->esquerda->esquerda = novoNo('A');
    raiz->esquerda->esquerda->direita = novoNo('B');
    raiz->direita->esquerda->esquerda = novoNo('4');
    raiz->direita->esquerda->direita = novoNo('3');
    raiz->direita->direita->esquerda = novoNo('C');
    raiz->direita->direita->direita = novoNo('D');
    
    struct no *raiz2 = novoNo('-');
    raiz->esquerda = novoNo('+');
    raiz->direita = novoNo('*');
    raiz->esquerda->esquerda = novoNo('/');
    raiz->esquerda->direita = novoNo('*');
    raiz->direita->esquerda = novoNo('C');
    raiz->direita->direita = novoNo('3');
    raiz->esquerda->esquerda->esquerda = novoNo('A');
    raiz->esquerda->esquerda->direita = novoNo('2');
    raiz->esquerda->direita->esquerda = novoNo('B');
    raiz->esquerda->direita->direita = novoNo('3');

    return 0;
}

