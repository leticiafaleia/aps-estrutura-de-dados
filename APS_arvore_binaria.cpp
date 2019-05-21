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

Arvore* inserirArvore(Arvore* a, int numero){
  if(a == NULL)  {
    a = (Arvore*) malloc(sizeof(Arvore)); 
    a->sae = NULL; 
    a->sad = NULL; 
    a->numero = numero;
  } else {
    if(numero <= a->numero) {
      a->sae = inserirArvore(a->sae, numero);
    }
    if(numero > a->numero) {
       a->sad = inserirArvore(a->sad, numero);
    }
  }
  return a;
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
  a = inserirArvore(a, 0); 
  printf("Arvore = %d\n",a->numero);
  a = inserirArvore(a, 0); 
  printf("Arvore = %d\n",a->sae->numero);
  printf("Arvore = %d\n",a->numero); //a raiz continua a mesma
  
  a = inserirArvore(a, 3); 
  printf("Arvore = %d\n",a->sad->numero);
  a = inserirArvore(a, 4);    
  printf("Arvore = %d\n",a->sad->sad->numero);
  printf("%d",numFolhas(a));	
  
  //Testando outra quantidade de folhas	
  /*a = inserirArvore(a, 9);
  printf("Arvore = %d\n",a->numero);
  a = inserirArvore(a, 6); 
  printf("Arvore = %d\n",a->sae->numero);
  a = inserirArvore(a, 3); 
  printf("Arvore = %d\n",a->sae->sae->numero);
  a = inserirArvore(a, 5);
  printf("Arvore = %d\n",a->sae->sae->sad->numero);
  a = inserirArvore(a, 7);
  printf("Arvore = %d\n",a->sae->sad->numero);
  a = inserirArvore(a, 8); 
  printf("Arvore = %d\n",a->sae->sad->sad->numero);
  a = inserirArvore(a, 10); 
  printf("Arvore = %d\n",a->sad->numero);
  printf("Quantidade de Folhas: %d",numFolhas(a));*/
}
