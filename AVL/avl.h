#ifndef AVL_H
#define AVL_H 
#include <stdlib.h>


typedef struct no {
    char *marca;
    int alturaAVL;
    struct no *esq;
    struct no *dir;
    int indice;
} No;

typedef No *arvoreAVL;




int alturaAVL(No *no);
int max(int a, int b);
No *rotacaoEsquerdaAVL(No *no);
No *rotacaoDireitaAVL(No *no);
No *rotacaoDuplaEsquerdaAVL(No *no);
No *rotacaoDuplaDireitaAVL(No *no);

arvoreAVL inserirAVL( arvoreAVL raiz, char *marca, int posicao);
No *removerAVL(No *no, char* marca);
void imprimir(No *no);
No *preorderAVL (No * raiz);
No *inorderAVL (No * raiz);
No *posorderAVL (No * raiz);

int maiorAVL(int a, int b);
	



#endif

