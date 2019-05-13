/*
* Faça um programa em C que crie uma árvore binária
* e implemente uma função que retorne a quantidade de folhas de uma árvore binária. 
*
* int folhas (Arv *);
*
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Arvore{
  int numero;
  struct Arvore* sad; // sad = sub arvore da direita
  struct Arvore* sae; // sae = sub arvore da esquerda
} Arvore;

Arvore* criacaoArvore(){
	  return NULL;
}

void inserirArvore(Arvore** a, int numero){
  
  if(*a == NULL)  {
    *a = (Arvore*)malloc(sizeof(Arvore)); 
    (*a)->sae = NULL; 
    (*a)->sad = NULL; 
    (*a)->numero = numero; 
  } else {
    if(numero < (*a)->numero) {
      inserirArvore(&(*a)->sae, numero);
    }
    if(numero > (*a)->numero) {
       inserirArvore(&(*a)->sad, numero);
    }
  }
}

int numFolhas(Arvore *raiz){
  if(raiz == NULL)
    return 0;
  else
    if(raiz->sae == raiz->sad)
      return 1;
   else
      return numFolhas(raiz->sae) + numFolhas(raiz->sad);
}

int main(){
  Arvore* a = criacaoArvore(); 
	
  //Criando e testando se os Nós foram criados com sucesso
  /*inserirArvore(&a, 0); 
  printf("Arvore = %d\n",a->numero);
  inserirArvore(&a, 1); 
  printf("Arvore = %d\n",a->sad->numero);
  inserirArvore(&a, 2); 
  printf("Arvore = %d\n",a->sad->sad->numero);
  inserirArvore(&a, 3);    
  printf("Arvore = %d\n",a->sad->sad->sad->numero);
  printf("%d\n",a->numero);*/
		
  //Testando outra quantidade de folhas	
  inserirArvore(&a, 9); 
  inserirArvore(&a, 6); 
  inserirArvore(&a, 3); 
  inserirArvore(&a, 5);
  inserirArvore(&a, 7);
  inserirArvore(&a, 8); 
  inserirArvore(&a, 10); 
  printf("Quantidade de Folhas: %d",numFolhas(a));
}
