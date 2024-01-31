#include <stdio.h>
#include <stdlib.h>
#include "Tabela/tabela.c" 


int main() {
	tabela tab;
	int opcao;
	
	printf("Inicializando tabela...\n");

    inicializarTabela(&tab);

    printf("Tabela inicializada com sucesso!\n");

	printf("Digite a opcao desejada:\n");
	printf("1 - Adicionar Roupa\n");
	printf("2 - Remover Roupa pelo codigo\n");
	printf("3 - Remover Roupa pela marca \n");
	printf("4 - Remover Roupa pelo tamanho\n");
	printf("5 - inordem BST \n");
	printf("6 - inordem AVL\n");
	printf("7 - inordem RB\n");
	printf("8 - Buscar Roupa por codigo\n");
	printf("9 - Buscar Roupa por marca\n");
	printf("10 - Buscar Roupa por tamanho\n");
	printf("11 - listar todos\n"); 
    printf("99 - Sair\n");

    while(1) {
		scanf("%d", &opcao);

		switch(opcao) {
				int valor;
				case 1:	
						
						adicionarRoupa(&tab, ler_dados());
						puts("Roupa adicionada com sucesso!");
						break;
        }
    }
}