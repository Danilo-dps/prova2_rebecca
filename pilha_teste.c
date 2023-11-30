#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Maxpilha 30

void imprimeVetor(int vet[Maxpilha]){
	int i;
	printf("\n");
	for(i=0;i<Maxpilha; i++){
		printf(" %d ", vet[i]);
	}
}

void pilhaPush(int pilha[Maxpilha], int valor, int *topo){
	if(*topo == Maxpilha-1){
		printf("Pilha cheia");
	}else{
		*topo = *topo + 1;
		pilha[*topo] = valor;
	}	
}

void pilhaPop(int pilha[Maxpilha], int *topo){
	if(*topo == -1){
		printf("Pilha vazia");
	}else{
		printf("Valor removido: %d ", pilha[*topo]);
		pilha[*topo] = 0;
		*topo = *topo - 1;
	}
}

void limparPilha(int pilha[Maxpilha], int *topo){
    int i;
    for(i = 0; i <= *topo; i++){
        pilha[i] = 0;
    }
    *topo = -1;
}

int main(){
	int pilha[Maxpilha];
	int topo = -1; //topo da pilha
	int escolha;
	int valor;
	
	do {
		printf("Escolha\n");
		printf("[1] empilhar, [2] desempilhar, [3] limpar, [4] mostrar pilha e [0] sair: ");
		scanf("%d", &escolha);
		
		switch(escolha)
		{
		  case 1 :   
			printf("Digite o valor a ser empilhado: ");
			scanf("%d", &valor);
			pilhaPush(pilha, valor, &topo);
			break;      
		  case 2 :   
			pilhaPop(pilha, &topo);
			break;      
		  case 3 :   
			limparPilha(pilha, &topo);  
			break;      
		  case 4 :   
			imprimeVetor(pilha);  
			break;      
		  default:
			if (escolha != 0) {
				printf("Escolha inválida!\n");
			}
		}
	} while (escolha != 0);
	
	return 0;
}

