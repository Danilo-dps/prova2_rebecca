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

int avaliar(struct no* raiz) {
    if (raiz == NULL)
        return 0;

    if (raiz->esquerda == NULL && raiz->direita == NULL)
        return raiz->chave - '0';

    int esquerda = avaliar(raiz->esquerda);
    int direita = avaliar(raiz->direita);

    if (raiz->chave == '+')
        return esquerda + direita;

    if (raiz->chave == '-')
        return esquerda - direita;

    if (raiz->chave == '*')
        return esquerda * direita;

    return esquerda / direita;
}

int main() {
	setlocale (LC_ALL, "Portuguese");
	
	int a, b, c;
	printf("Digite 3 números:\n");
	scanf("%d%d%d", &a, &b, &c);
	
    struct no *raiz = novoNo('-');
    raiz->esquerda = novoNo('+');
    raiz->direita = novoNo('*');
    raiz->esquerda->esquerda = novoNo('/');
    raiz->esquerda->direita = novoNo('*');
    raiz->direita->esquerda = novoNo('c');
    raiz->direita->direita = novoNo('3');
    raiz->esquerda->esquerda->esquerda = novoNo('a');
    raiz->esquerda->esquerda->direita = novoNo('2');
    raiz->esquerda->direita->esquerda = novoNo('b');
    raiz->esquerda->direita->direita = novoNo('3');

    printf("O resultado da expressão é %d", avaliar(raiz));

    return 0;
}

