#ifndef TABELA_H
#define TABELA_H
#include "../BST/bst.h"
#include "../AVL/avl.h"
#include "../RB/rb.h"
#include <stdlib.h>
#include <stdio_ext.h>


typedef struct roupa{
    char* codigo;
    char* categoria;
    char* marca;
    char* tamanho;
    float preco;
}dado;

typedef struct tabela{
    FILE* arquivo_dados;
    arvoreBST indice_bst;
    arvoreAVL indice_avl;
    arvoreRB indice_rb;
    
}tabela;

int inicializarTabela(tabela *tab);

void finalizar (tabela *tab);

void adicionarRoupa(tabela *tab, dado *roupa);


void carregar_arquivo_BST(char *nome, arvoreBST* a);
void salvar_arquivo_BST(char *nome, arvoreBST a);
void salvar_auxiliar_BST(arvoreBST raiz, FILE *arq);


void imprimirRoupa(int indice, tabela *tab);


void carregar_arquivo_BST(char *nome, arvoreBST* a);
void salvar_arquivo_BST(char *nome, arvoreBST a);
void salvar_auxiliar_BST(arvoreBST raiz, FILE *arq);
void imprimir_elemento_BST(arvoreBST raiz, tabela * tab);

void listarTodos(tabela *tab);

void carregar_arquivo_AVL(char* nome, arvoreAVL* a);
void salvar_arquivo_AVL(char* nome, No* a);
void salvar_auxiliar_AVL(No* raiz, FILE* arq);
void imprimir_elemento_AVL(No* raiz, tabela* tab);


void carregar_arquivo_RB(char* nome, arvoreRB* a);
void salvar_arquivo_RB(char* nome, noarvoreRB* a);
void salvar_auxiliar_RB(noarvoreRB* raiz, FILE* arq);
void imprimir_elemento_RB(noarvoreRB* raiz, tabela* tab);


void removerRoupaIndiceBST(tabela *tab, char* codigo);

void removerRoupaIndiceAVL(tabela *tab, char* marca);

void removerRoupaPeloIndiceRB(tabela *tab, char* categoria);


void procurarRoupaIndiceRB(tabela *tab, char* categoria);





void imprimir_elementoRB(tabela *tab, noarvoreRB *raiz);


void procurarRoupaIndiceBST(tabela *tab, char* codigo);

void imprimir_elementoBST(tabela* tab, arvoreBST no);

void procurarRoupaIndiceAVL(tabela *tab, char* marca);

void imprimir_elementoAVL(tabela* tab, No* no);


dado * ler_dados();

void tirar_enter(char *string);


#endif