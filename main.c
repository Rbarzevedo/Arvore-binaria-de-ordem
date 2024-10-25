#include <stdlib.h>
#include <stdio.h>

struct NO{
	int info;
	struct NO *esq;
	struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin() {
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
	if(raiz!=NULL) {
		*raiz = NULL;
	}
	return raiz;
}

int insere_ArvBin(ArvBin* raiz,  int valor) {
	if(raiz == NULL) {
		return 0;
	}

	struct NO* novo;
	novo = (struct NO*) malloc(sizeof(struct NO));
	if(novo == NULL) {
		return 0;
	}
	novo->info = valor;
	novo->dir = NULL;
	novo->esq = NULL;

	if(*raiz == NULL) {
		*raiz = novo;
	} else {
		struct NO* atual = *raiz;
		struct NO* ant = NULL;
		while(atual!=NULL) {
			ant = atual;
			if(valor == atual->info) {
				free(novo);
				return 0;
			}

			if(valor>atual->info) {
				atual= atual->dir;
			} else {
				atual= atual->esq;
			}
		}
		if(valor>ant->info) {
			ant->dir =novo;
		} else {
			ant->esq =novo;
		}
	}

	return 1;
}

void libera_NO(struct NO* no){
    if (no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

void preOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\t", (*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\t", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin* raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\t", (*raiz)->info);
    }
}


int main()
{
	ArvBin* raiz = cria_ArvBin();
	int dados[8] = {50, 100, 30, 20, 40, 45, 35, 37};
	for(int i = 0; i<8; i++) {
		insere_ArvBin(raiz, dados[i]);
	}
    
    printf("\nPré-Ordem:\n");
    preOrdem_ArvBin(raiz);
    printf("\nEm-Ordem:\n");
    emOrdem_ArvBin(raiz);
    printf("\nPós-Ordem:\n");
    posOrdem_ArvBin(raiz);
	return 0;
}