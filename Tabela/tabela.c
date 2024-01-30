#include "tabela.h" 
#include "../BST/bst.c"
#include "../AVL/avl.c"
#include "../RB/rb.c"
#include <stdio.h>
#include <string.h>

int inicializarTabela(tabela *tab) {
	inicializarBST(&tab->indice_bst);	
	tab->arquivo_dados = fopen("dados.dat", "a+");
	carregar_arquivo_BST("indicesBST.dat", &tab->indice_bst);
	carregar_arquivo_AVL("indicesAVL.dat", &tab->indice_avl);
	carregar_arquivo_RB("indicesRB.dat", &tab->indice_rb);
	if(tab->arquivo_dados != NULL)
		return 1;
	else
		return 0;
}

void finalizar (tabela *tab) {
	fclose(tab->arquivo_dados);
	salvar_arquivo_BST("indicesBST.dat", tab->indice_bst);
	salvar_arquivo_AVL("indicesAVL.dat", tab->indice_avl);
	salvar_arquivo_RB("indicesRB.dat", tab->indice_rb);	
}


void adicionarRoupa(tabela *tab, dado *roupa){
	
    int posicaoNovoRegistro;
    if(tab->arquivo_dados != NULL) {
			
			fseek(tab->arquivo_dados, 0L, SEEK_END);
			posicaoNovoRegistro = ftell(tab->arquivo_dados);
			
            dado * novo = (dado *) malloc(sizeof(dado));
			novo->codigo = roupa->codigo;
			
			tab->indice_bst = inserirBST(tab->indice_bst, roupa->codigo, posicaoNovoRegistro);

			novo->codigo = roupa->codigo;

			tab->indice_avl = inserirAVL(tab->indice_avl, roupa->marca, posicaoNovoRegistro);

			novo->tamanho = roupa->tamanho;

			inserir(&tab->indice_rb, roupa->tamanho, posicaoNovoRegistro);
			


			fprintf(tab->arquivo_dados, "%s|%s|%s|%s|%f\n", roupa->codigo,roupa->categoria,roupa->marca,roupa->tamanho,roupa->preco);
			
    }
}