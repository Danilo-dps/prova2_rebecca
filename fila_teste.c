#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <stdbool.h>
#include <string.h>
#define Maxfila 100
#define MAX_STRING_SIZE 40

typedef char elementoDaFila[MAX_STRING_SIZE];
elementoDaFila fila[Maxfila];

int frente, tras;

void imprimeFila(){
	int i;
	printf("\n");
	for(i=frente;i<=tras;i++){
		printf("%s ",fila[i]);
	}
}

void filaConstrutor(){
	frente = 0;
	tras = -1;
}

bool filaVazia(){
	if(frente > tras){
		return true;
	}else{
		return false;
	}
}

bool filaCheia(){
	if(tras == Maxfila-1){
		return true;
	}else{
		return false;
	}
}

void filaEnfileirar(char valor[MAX_STRING_SIZE]){
	if(filaCheia()){
		printf(" - Fila cheia!");
	}else{
		tras = tras + 1;
		strcpy(fila[tras], valor);
	}
}

void filaDesenfileirar(){
	if(filaVazia()){
		printf(" - Fila vazia!");
	}else{
		printf(" - Valor %s foi removido!", fila[frente]);
		strcpy(fila[frente], "");
		frente = frente + 1;
	}
}

void limparFila(){
	while(!filaVazia()){
		filaDesenfileirar();
	}
}

int main(){
	char valor[MAX_STRING_SIZE];
	int escolha;
	
	filaConstrutor();
	
	do {
		printf("\nEscolha\n");
		printf("[1] enfileirar, [2] desenfileirar, [3] limpar, [4] mostrar fila, [0] sair: ");
		scanf("%d", &escolha);
		
		switch(escolha)
		{
		  case 1 :   
			printf("Digite o valor a ser enfileirado: ");
			scanf("%s", valor);
			filaEnfileirar(valor);
			break;      
		  case 2 :   
			filaDesenfileirar();
			break;      
		  case 3 :   
			limparFila();  
			break;      
		  case 4 :   
			imprimeFila();  
			break;      
		  default:
			if (escolha != 0) {
				printf("Escolha inválida!\n");
			}
		}
	} while (escolha != 0);
	
	return 0;
}

