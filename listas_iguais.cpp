#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
	int info;
	no *prox;
}no;

no *L1 = NULL;
no *L2 = NULL;

no* cria_no(int valor){
	no *aux;
	aux = (no*) malloc(sizeof(no));
	aux->info = valor;
	aux->prox = NULL;
	return aux;	
}

adicionar_L1(int valor){
	no *pt,*aux;
	aux = cria_no(valor);
	if(L1==NULL){
		L1 = aux;	
	}
	else{
		pt = L1;
		while(pt->prox!=NULL){
			pt=pt->prox;
		}
		pt->prox = aux;
	}
}

adicionar_L2(int valor){
	no *pt,*aux;
	aux = cria_no(valor);
	if(L2==NULL){
		L2 = aux;	
	}
	else{
		pt = L2;
		while(pt->prox!=NULL){
			pt=pt->prox;
		}
		pt->prox = aux;
	}
}

exibir_lista(no* L){
	no *aux;
	aux = L;
	printf("\n----Exibindo Lista----\n");
	while(aux!=NULL){
		printf("Info: %d\n",aux->info);
		//printf("Pr�x: %p\n",aux->prox);
		aux = aux->prox;
	}
	printf("\n");
}

listas_iguais(){
	no *aux1,*aux2;
	aux1 = L1;
	aux2 = L2;
	while(aux1!=NULL&&aux2!=NULL){
		if(aux1->info==aux2->info){
			aux1 = aux1->prox;
			aux2 = aux2->prox;
		}
		else{
			printf("As listas n�o s�o iguais.");
			break;
		}
	}
	if(aux1==NULL&&aux2==NULL){
		printf("As listas s�o iguais.");
	}
}

int main(){
	int i,valor;
	
	setlocale(LC_ALL, "Portuguese");//habilita a acentua��o para o portugu�s
	
	//criando lsita 1
	for(i=0;i<3;i++){
	printf("Digite um valor para a lista1.");
	scanf("%d",&valor);
	adicionar_L1(valor);
	}
	
	exibir_lista(L1);
	
	//criando lsita 2
	for(i=0;i<3;i++){
	printf("Digite um valor para a lista2.");
	scanf("%d",&valor);
	adicionar_L2(valor);
	}
		
	exibir_lista(L2);
	
	//Testando se s�o iguais
	listas_iguais();
}
