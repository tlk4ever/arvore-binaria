/*
 ============================================================================
 Name        : arvore_binaria.c
 Author      : Thiago Brito
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct arv TArv;
struct arv{
	char dado;
	TArv *esq;
	TArv *dir;
};

TArv* criaVAzia(){
	return NULL;
}

TArv* criarNo(char ch, TArv *esq, TArv *dir){
	TArv *aux = (TArv*) malloc(sizeof(TArv));
	aux->dado = ch;
	aux->esq = esq;
	aux->dir = dir;
	return aux;
}

TArv* insereArv(TArv *arv, char ch){
	if(arv==NULL){
		arv = criarNo(ch,criaVAzia(),criaVAzia());
	}else{
		if(arv->dado > ch){
			arv->esq = insereArv(arv->esq,ch);
		}else{
			arv->dir = insereArv(arv->dir,ch);
		}
	}
	return arv;
}

void imprimeArv(TArv *arv){

	if(arv !=NULL){
		printf("(");
		printf("%c",arv->dado);//pre ordem raiz antes
		imprimeArv(arv->esq);
		//printf("%c",arv->dado); ordem crescente
		imprimeArv(arv->dir);
		//printf("%c",arv->dado);//pos ordem raiz depois
		printf(")");
	}else{
		printf("(_)");
	}

	/*printf("%c",arv->dado);
	if(arv->esq!=NULL){
		imprimeArv(arv->esq);
	}else{
		printf("(_)");
	}
	if(arv->dir!=NULL){
		imprimeArv(arv->dir);
	}else{
		printf("(_)");
	}*/


}
int pertence(TArv *arv, char ch){
	return arv!=NULL && (arv->dado==ch || pertence(arv->esq,ch) || pertence(arv->dir,ch));
}
TArv* busca(TArv *arv, char ch){
	if(arv==NULL) return arv;

	if(arv->dado==ch) return arv;
	TArv *aux;
	aux = busca(arv->esq,ch);
	if(aux==NULL){
		aux = busca(arv->dir,ch);
	}
	return aux;
}

int main(void) {
	TArv *arvx = criaVAzia();

	arvx = insereArv(arvx,'M');

	arvx = insereArv(arvx,'R');
	arvx = insereArv(arvx,'H');

	arvx = insereArv(arvx,'O');
	arvx = insereArv(arvx,'K');
	arvx = insereArv(arvx,'T');
	arvx = insereArv(arvx,'E');

	arvx = insereArv(arvx,'L');
	arvx = insereArv(arvx,'G');
	arvx = insereArv(arvx,'N');
	arvx = insereArv(arvx,'C');

	arvx = insereArv(arvx,'D');
	arvx = insereArv(arvx,'A');
	/*arvx = criarNo('M',
			criarNo('H',
					criarNo('E',
							criarNo('C',
									criarNo('A',
											criaVAzia(),
											criaVAzia()
											),
									criarNo('D',
											criaVAzia(),
											criaVAzia()
											)
									),
							criarNo('G',
									criaVAzia(),
									criaVAzia()
									)
							),
					criarNo('K',
							criaVAzia(),
							criarNo('L',
									criaVAzia(),
									criaVAzia())
							)
					),
			criarNo('R',
					criarNo('O',
							criarNo('N',
									criaVAzia(),
									criaVAzia()
									),
							criaVAzia()
							),
					criarNo('T',
							criaVAzia(),
							criaVAzia()
							)
					)
			);*/
	//printf("%p\n",arvx);
	imprimeArv(arvx);
	printf("\n(M(H(E(C(A(_)(_))(D(_)(_)))(G(_)(_)))(K(_)(L(_)(_))))(R(O(N(_)(_))(_))(T(_)(_))))");
	return EXIT_SUCCESS;
}
