#include "rb.h"
#include <stdio.h>
#include <string.h>

arvoreRB no_null;

void init_arvoreRB(arvoreRB *raiz) {
	*raiz = NULL;
    no_null = (arvoreRB) malloc(sizeof(arvoreRB));
	no_null->cor = DUPLO_PRETO;
	no_null->info = NULL;
    no_null->esq = no_null->dir = NULL;
}

void inserir(arvoreRB* raiz, char* info, int indice) {

    



    arvoreRB cont = *raiz, pai = NULL, no;


    while (cont != NULL) {
        pai = cont;
        
        if (strcmp(info , cont->info) > 0)
            cont = cont->dir;
        else
            cont = cont->esq;
    }

    no = (arvoreRB) malloc(sizeof(noarvoreRB));
    no->info = (char*) malloc(sizeof(char) * (strlen(info) + 1));

    strcpy(no->info , info);

    no->esq = no->dir = NULL;
    no->cor = VERMELHO;
    no->pai = pai;
    no->indice = indice;


    if(eh_raiz(no)) {
        no->cor = PRETO;
        *raiz = no;

    } else {
        if (strcmp(info , no->pai->info) > 0) 
            no->pai->dir = no;

        else
            no->pai->esq = no;
    }
    correcao(raiz, no);


}

void correcao(arvoreRB* raiz, arvoreRB no) {

    while(cor(no->pai) == VERMELHO && cor(no) == VERMELHO){
        if(cor(tio(no)) == VERMELHO) {
            no->pai->cor = tio(no)->cor = PRETO;
            no->pai->pai->cor = VERMELHO;
            no = no->pai->pai;
            continue;
        } else {
            if(eh_esq(no) && eh_esq(no->pai)) {
                no->pai->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                rotacao_simples_dir(raiz, no->pai->pai);
                continue;
            }
            if(!eh_esq(no) && !eh_esq(no->pai)) {
                no->pai->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                rotacao_simples_esq(raiz, no->pai->pai);
                continue;
            }
            if(eh_esq(no) && !eh_esq(no->pai)) {
                no->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                rotacao_dupla_esq(raiz, no->pai->pai);
                continue;
            }
            if(!eh_esq(no) && eh_esq(no->pai)) {
                no->cor = PRETO;
                no->pai->pai->cor = VERMELHO;
                rotacao_dupla_dir(raiz, no->pai->pai);
                continue;
            }
        }
    }
    (*raiz)->cor = PRETO;
}

void rotacao_simples_esq(arvoreRB* raiz, arvoreRB no) {
	arvoreRB u = no->dir,
		t2 = u->esq;
    int ehesq = eh_esq(no);

    no->dir = t2;
	
    	
    if(t2 != NULL)
		t2->pai = no;
    
    u->esq = no;
	u->pai = no->pai;
    no->pai = u;

	if(eh_raiz(u))
		*raiz = u;
	else {
		if(ehesq)
			u->pai->esq = u;
		else
		    u->pai->dir = u;
	}
}

void rotacao_simples_dir(arvoreRB* raiz, arvoreRB no) {
	arvoreRB u = no->esq,
		t2 = u->dir;
    int ehesq = eh_esq(no);

    no->esq = t2;
	u->dir = no;
    
    if(t2 != NULL)
		t2->pai = no;
	u->pai = no->pai;
    no->pai = u;

	if(eh_raiz(u))
		*raiz = u;
	else {
		if(ehesq)
			u->pai->esq = u;
		else
		    u->pai->dir = u;
	}
}

void rotacao_dupla_esq(arvoreRB* raiz, arvoreRB no) {
	rotacao_simples_dir(raiz, no->dir);
	rotacao_simples_esq(raiz, no);
}

void rotacao_dupla_dir(arvoreRB* raiz, arvoreRB no) {
	rotacao_simples_esq(raiz, no->esq);
	rotacao_simples_dir(raiz, no);
}

int maior(int a, int b) {
    return a > b ? a : b;
}

int altura(arvoreRB raiz) {
	if (raiz == NULL){
		return 0;
	} else {
		int aesq = altura(raiz->esq) + 1, adir = altura(raiz->dir) + 1;
		return aesq > adir ? aesq : adir;
	}
}

int eh_raiz(arvoreRB no) {
    return no->pai == NULL;
}

int eh_esq(arvoreRB no) {
	return (!eh_raiz(no) && no->pai->esq == no);
}

enum cor cor(arvoreRB no) {
    return no == NULL ? PRETO : no->cor;
}

arvoreRB irmao(arvoreRB no) {
    return eh_esq(no) ? no->pai->dir : no->pai->esq;
}

arvoreRB tio(arvoreRB no) {
    return irmao(no->pai);
}

void imprimir_elemento(arvoreRB no) {
	switch(no->cor){
		case PRETO:
			printf("[%s] -> ", no->info);
			break;
		case VERMELHO:
			printf("\x1b[31m[%s]\x1b[0m  -> ", no->info);
			break;
		case DUPLO_PRETO:
			printf("\x1b[32m[%s]\x1b[0m  -> ", no->info);
			break;
	}
}

void remover(arvoreRB *raiz, arvoreRB *raiz_relativa, char* info) {
	arvoreRB cont = *raiz_relativa;

	while(cont != NULL) {
		if(strcmp(info , cont->info) == 0) {

            if(cont->esq != NULL && cont->dir != NULL) { 
    			strcpy(cont->info , (maior_elemento(cont->esq))->info);
	    		remover(raiz, &cont->esq, cont->info);
                break;
            }
            arvoreRB aux;
			if(cont->esq == NULL && cont->dir != NULL) {
				aux = cont->dir;
                if(aux->esq != NULL)
                    aux->esq->pai = cont;
                if(aux->dir != NULL)
                    aux->dir->pai = cont;
                strcpy(cont->info , aux->info);
                cont->esq = aux->esq;
                cont->dir = aux->dir;
                free(aux);
				break;
			}

			if(cont->esq != NULL && cont->dir == NULL) {
				aux = cont->esq;
                if(aux->esq != NULL)
                    aux->esq->pai = cont;
                if(aux->dir != NULL)
                    aux->dir->pai = cont;
                strcpy(cont->info , aux->info);
                cont->esq = aux->esq;
                cont->dir = aux->dir;
                free(aux);
				break;
			}

			if(cont->esq == NULL && cont->dir == NULL) {			
				if(eh_raiz(cont)) {
					*raiz = NULL;
					break;
				}
				if(cont->cor == VERMELHO) {
                    if(eh_esq(cont))
						cont->pai->esq = NULL;
					else
						cont->pai->dir = NULL;
                    free(cont);
                    cont = NULL;
					break;
				} else {
				    no_null->pai = cont->pai;
                    if(eh_esq(cont))
                        cont->pai->esq = no_null;
                    else
                        cont->pai->dir = no_null;
                    reajustar(raiz, no_null);
				    break;
				}
			}
		}	
		if(strcmp(info , cont->info) > 0) 
			cont = cont->dir;
		else 
			cont = cont->esq;
	}
}

void reajustar(arvoreRB *raiz, arvoreRB no){
	if(eh_raiz(no)) {
        printf("\nCASO 1\n");
		no->cor = PRETO;
        if(no == no_null)
            *raiz = NULL;
		return;
	}
    
	if(cor(no->pai) == PRETO &&
	   cor(irmao(no)) == VERMELHO &&
	   cor(irmao(no)->dir) == PRETO &&
	   cor(irmao(no)->esq) == PRETO) {
        printf("\nCASO 2\n");
		if(eh_esq(no))
			rotacao_simples_esq(raiz, no->pai);
		else
			rotacao_simples_dir(raiz, no->pai);	
		no->pai->pai->cor = PRETO;
		no->pai->cor = VERMELHO;
        reajustar(raiz, no);
		return;
	}
	

    if(cor(irmao(no)) == PRETO) {

        if(cor(no->pai) == PRETO
        && cor(irmao(no)->dir) == PRETO
        && cor(irmao(no)->esq) == PRETO) {
            printf("\nCASO 3\n");
            no->pai->cor = DUPLO_PRETO;
            irmao(no)->cor = VERMELHO;
            if(eh_esq(no))
                no->pai->esq = NULL;
            else
                no->pai->dir = NULL;
            reajustar(raiz, no->pai);
            no->pai = NULL;
            return;
	    }

        if(cor(no->pai) == VERMELHO
        && cor(irmao(no)->dir) == PRETO
        && cor(irmao(no)->esq) == PRETO) {
            printf("\nCASO 4\n");
            irmao(no)->cor = VERMELHO;
            no->pai->cor = PRETO;
            if(eh_esq(no))
                no->pai->esq = NULL;
            else
                no->pai->dir = NULL;
            no->pai = NULL;
            return;
        }

        if(eh_esq(no)){
            if(cor(irmao(no)->esq) == VERMELHO && cor(irmao(no)->dir) == PRETO){
                printf("\nCASO 5A\n");
                irmao(no)->cor = VERMELHO;
                irmao(no)->esq->cor = PRETO;
                rotacao_simples_dir(raiz, irmao(no));
                reajustar(raiz, no);
                return;
            }

            if(cor(irmao(no)->dir) == VERMELHO){
                printf("\nCASO 6A\n");
                irmao(no)->cor = no->pai->cor;
                irmao(no)->dir->cor = PRETO;
                no->pai->cor = PRETO;
                rotacao_simples_esq(raiz, no->pai);
                no->pai->esq = NULL;
                no->pai = NULL;
                return;
            }
        } else {
            if(cor(irmao(no)->dir) == VERMELHO && cor(irmao(no)->esq) == PRETO) {
                printf("\nCASO 5B\n");
                irmao(no)->cor = VERMELHO;
                irmao(no)->dir->cor = PRETO;
                rotacao_simples_esq(raiz, irmao(no));
                reajustar(raiz, no);
                return;
            }

            if(cor(irmao(no)->esq) == VERMELHO){
                printf("\nCASO 6B\n");
                irmao(no)->cor = no->pai->cor;
                irmao(no)->esq->cor = PRETO;
                no->pai->cor = PRETO;
                rotacao_simples_dir(raiz, no->pai);
                no->pai->dir = NULL;
                no->pai = NULL;
                return;
            }
        }

    }
}

void preorder (arvoreRB raiz) {
  if (raiz != NULL) {
      imprimir_elemento(raiz);
      preorder (raiz->esq);
      preorder (raiz->dir);
    }
}

void inorder (arvoreRB raiz) {
  if (raiz != NULL) {
      inorder (raiz->esq);
      imprimir_elemento(raiz);
      inorder (raiz->dir);
    }
}

void posorder (arvoreRB raiz) {
  if (raiz != NULL) {
      posorder (raiz->esq);
      posorder (raiz->dir);
      imprimir_elemento(raiz);
    }
}

arvoreRB maior_elemento(arvoreRB raiz) {
  if (raiz == NULL)
    return NULL;

  if (raiz->dir == NULL)
    return raiz;

  return maior_elemento (raiz->dir);
}

