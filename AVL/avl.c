#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int alturaAVL(No *no) {
    if(no == NULL) {
		return 0;
	}
	return 1 + maiorAVL(alturaAVL(no->dir), alturaAVL(no->esq));
    }


int maiorAVL(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

No *rotacaoEsquerdaAVL(No *no) {
    No *aux = no->dir;
    no->dir = aux->esq;
    aux->esq = no;
    no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
    aux->alturaAVL = max(alturaAVL(aux->dir), no->alturaAVL) + 1;
    return aux;
}

No *rotacaoDireitaAVL(No *no) {
    No *aux = no->esq;
    no->esq = aux->dir;
    aux->dir = no;
    no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
    aux->alturaAVL = max(alturaAVL(aux->esq), no->alturaAVL) + 1;
    return aux;
}

No *rotacaoDuplaEsquerdaAVL(No *no) {
    no->dir = rotacaoDireitaAVL(no->dir);
    return rotacaoEsquerdaAVL(no);
}

No *rotacaoDuplaDireitaAVL(No *no) {
    no->esq = rotacaoEsquerdaAVL(no->esq);
    return rotacaoDireitaAVL(no);
}

arvoreAVL inserirAVL(arvoreAVL raiz, char *marca, int posicao) {
    if (raiz == NULL) {

        arvoreAVL no = (No*) malloc(sizeof (No));
        no->marca = marca;
        no->indice = posicao;
        no->alturaAVL = 0;
        no->esq = NULL;
        no->dir = NULL;
        raiz = no;
       
    } else if (strcmp(marca , raiz->marca)<0) {
        raiz->esq = inserirAVL(raiz->esq, marca, posicao);
        if (alturaAVL((raiz)->esq) - alturaAVL((raiz)->dir) == 2) {
            if (strcmp(marca , raiz->esq->marca)<0) {
                raiz = rotacaoDireitaAVL(raiz);
            } else {
                raiz = rotacaoDuplaDireitaAVL(raiz);
            }
        }
    } else if (strcmp(marca , (raiz)->marca)>0) {
        raiz->dir = inserirAVL(raiz->dir, marca, posicao);
        if (alturaAVL(raiz->dir) - alturaAVL(raiz->esq) == 2) {
            if (strcmp(marca , raiz->dir->marca)>0) {
                raiz = rotacaoEsquerdaAVL(raiz);
            } else {
                raiz = rotacaoDuplaEsquerdaAVL(raiz);
            }
        }
}
    (raiz)->alturaAVL = max(alturaAVL(raiz->esq), alturaAVL(raiz->dir) + 1);
    return raiz;

    
}



No *removerAVL(No *no, char* marca) {
    if (no == NULL) {
        return NULL;
    } else if (strcmp(marca , no->marca)<0) {
        no->esq = removerAVL(no->esq, marca);
    } else if (strcmp (marca , no->marca)>0) {
        no->dir = removerAVL(no->dir, marca);
    } else {
        if (no->esq == NULL && no->dir == NULL) {
            free(no);
            no = NULL;
        } else if (no->esq == NULL) {
            No *aux = no;
            no = no->dir;
            free(aux);
        } else if (no->dir == NULL) {
            No *aux = no;
            no = no->esq;
            free(aux);
        } else {
            No *aux = no->esq;
            while (aux->dir != NULL) {
                aux = aux->dir;
            }
            strcpy(no->marca , aux->marca);
            aux->marca = marca;
            no->esq = removerAVL(no->esq, marca);
        }
    }
    if (no != NULL) {
        no->alturaAVL = max(alturaAVL(no->esq), alturaAVL(no->dir)) + 1;
        if (alturaAVL(no->esq) - alturaAVL(no->dir) == 2) {
            if (alturaAVL(no->esq->esq) - alturaAVL(no->esq->dir) == 1) {
                no = rotacaoDireitaAVL(no);
            } else {
                no = rotacaoDuplaDireitaAVL(no);
            }
        } else if (alturaAVL(no->dir) - alturaAVL(no->esq) == 2) {
            if (alturaAVL(no->dir->dir) - alturaAVL(no->dir->esq) == 1) {
                no = rotacaoEsquerdaAVL(no);
            } else {
                no = rotacaoDuplaEsquerdaAVL(no);
            }
        }
    }
    return no;
}

void imprimir(No *no) {
    if (no != NULL) {
        imprimir(no->esq);
        printf("%s ", no->marca);
        imprimir(no->dir);
    }
}

No *preorderAVL (No * raiz)
{

  if (raiz != NULL)
    {
      printf ("%s ", raiz->marca);
      preorderAVL (raiz->esq);
      preorderAVL (raiz->dir);
    }
}

No*inorderAVL (No* raiz)
{

  if (raiz != NULL)
    {
      inorderAVL (raiz->esq);
      printf ("%s ", raiz->marca);
      inorderAVL (raiz->dir);
    }

}


No *posorderAVL (No * raiz)
{

  if (raiz != NULL)
    {
      posorderAVL (raiz->esq);
      posorderAVL (raiz->dir);
      printf ("%s ", raiz->marca);
    }
}