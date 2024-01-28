#include <stdio.h>
#include "bst.h"
#include<string.h>


void inicializarBST(arvoreBST * raiz) {
	 *raiz = NULL;
}


arvoreBST inserirBST (arvoreBST raiz, char* codigo, int indice)
{ 
  

  if (raiz == NULL)
    {
      arvoreBST no = (arvoreBST) malloc (sizeof (arvoreBST));
      no->codigo = (char*)malloc(sizeof(codigo));
      
      strcpy(no->codigo,codigo);
      no->indice = indice;
      no->dir = NULL;
      no->esq = NULL;
      return no;
    }
  else
    {
      if (strcmp(codigo , raiz->codigo) > 0) 
	{
	  raiz->dir = inserirBST (raiz->dir, codigo, indice);

	}
      else
	{
	  raiz->esq = inserirBST (raiz->esq, codigo, indice);
	}
      return raiz;
    }

  return raiz;
}


void preorderBST (arvoreBST raiz)
{

  if (raiz != NULL)
    {
      printf ("%s ", raiz->codigo);
      preorderBST (raiz->esq);
      preorderBST (raiz->dir);
    }
}

void inorderBST (arvoreBST raiz)
{

  if (raiz != NULL)
    {
      inorderBST (raiz->esq);
      printf ("%s ", raiz->codigo);  
      inorderBST (raiz->dir);
    }

}


void posorderBST (arvoreBST raiz)
{

  if (raiz != NULL)
    {
      posorderBST (raiz->esq);
      posorderBST (raiz->dir);
      printf ("%s ", raiz->codigo);
    }
}

char *menorElementoBST (arvoreBST raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->esq == NULL)
    {
      return raiz->codigo;
    }

  return menorElementoBST (raiz->esq);
}

int maiorBST(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int alturaBST(arvoreBST raiz){
  if(raiz == NULL) {
		return 0;
	}
	return 1 + maiorBST(alturaBST(raiz->dir), alturaBST(raiz->esq));
}

char *maiorElementoBST (arvoreBST raiz)
{
  if (raiz == NULL)
    {
      return NULL;
    }

  if (raiz->dir == NULL)
    {
      return raiz->codigo;
    }

  return maiorElementoBST (raiz->dir);
}





arvoreBST removerBST (arvoreBST raiz, char* codigo)
{

  if (raiz == NULL)
    {
      return raiz;
    }

  if (strcmp(codigo,raiz->codigo)==0)
    {
      if (raiz->dir == NULL && raiz->esq == NULL)
	{
	  free (raiz);
	  return NULL;
	}
      if (raiz->dir == NULL && raiz->esq != NULL)
	{
	  arvoreBST aux = raiz->esq;
	  free (raiz);
	  return aux;
	}
      if (raiz->esq == NULL && raiz->dir != NULL)
	{
	  arvoreBST aux = raiz->dir;
	  free (raiz);
	  return aux;
	}
      strcpy(raiz->codigo, maiorElementoBST(raiz->esq));
      raiz->esq = removerBST (raiz->esq, raiz->codigo);


    }

  if (strcmp(codigo , raiz->codigo) > 0)
    {
      raiz->dir = removerBST (raiz->dir, codigo);
    }

  if (strcmp(codigo , raiz->codigo) < 0)
    {
      raiz->esq = removerBST (raiz->esq, codigo);
    }

  return raiz;

}

