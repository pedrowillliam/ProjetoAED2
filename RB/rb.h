#ifndef RB_H
#define RB_H

#include <stdlib.h>

enum cor { VERMELHO, PRETO, DUPLO_PRETO };

typedef struct noarvoreRB {
	char* info;
	enum cor cor;
	struct noarvoreRB *esq, *dir, *pai;
    int indice;
} noarvoreRB;

typedef noarvoreRB* arvoreRB;

void init_arvoreRB(arvoreRB* raiz);
void inserir(arvoreRB* raiz, char* info, int indice);
void remover(arvoreRB* raiz, arvoreRB* raiz_relativa, char* info);

void correcao(arvoreRB* raiz, arvoreRB no);
void reajustar(arvoreRB *raiz, arvoreRB no);
void rotacao_simples_esq(arvoreRB* raiz, arvoreRB no);
void rotacao_simples_dir(arvoreRB* raiz, arvoreRB no);
void rotacao_dupla_dir(arvoreRB* raiz, arvoreRB no);
void rotacao_dupla_esq(arvoreRB* raiz, arvoreRB no);
void preorder(arvoreRB raiz);
void inorder(arvoreRB raiz);
void posorder(arvoreRB raiz);
void imprimir_elemento(arvoreRB no);

int altura(arvoreRB raiz);
int maior(int a, int b);
arvoreRB maior_elemento (arvoreRB raiz);


enum cor cor(arvoreRB no);
int eh_raiz(arvoreRB no);
int eh_esq(arvoreRB no);
arvoreRB irmao(arvoreRB no);
arvoreRB tio(arvoreRB no);


#endif