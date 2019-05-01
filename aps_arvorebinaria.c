#include <stdio.h>
#include <stdlib.h>


typedef struct arvore{
  int numero;
  struct arvore* sad; // sad = sub arvore da direita
  struct arvore* sae; // sae = sub arvore da esquerda
} arvore;

int criacaoArvore(){
	  return NULL;
}

int arvoreVazia(arvore* a)
  return t == NULL;
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

int folhasArvore(Arvore *a){
	if(a == null)
		return 0;
	else
		if(a->sae == a-> sad)
			return 1;
		else
			return folhasArvore(a->sae) + folhasArvore(a->sad);
}

int main(){
  Arvore* a = criarArvore(); 
  
  inserirArvore(&a, 0); 
  inserirArvore(&a, 1); 
  inserirArvore(&a, 2); 
  inserirArvore(&a, 3);    
}

int numFolhas(ARVORE *raiz){
  if(raiz == null)
    return 0;
  else
    if(raiz->esq == raiz->dir)
      return 1;
   else
      return numFolhas(raiz->esq) + numFolhas(raiz->dir);
