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

void adicionarCarro(tabela *tab, dado *carro);






#endif