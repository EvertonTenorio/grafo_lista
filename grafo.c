#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void inicializar (grafo *g, int tamanho) {
	int i,j;
	g->v = tamanho;
	g->lista = (lista **) malloc(sizeof(lista) * tamanho);
	g->mapa = (char *) malloc(sizeof(char) * tamanho);

	for(i =0; i < tamanho; i++) {
		g->lista[i] = malloc(sizeof(lista));
		g->mapa[i] = '\0';
	}
}

void adicionarVertice(grafo *g, char vertice){
	int i;

	for(i = 0; i < g->v; i++){
		if(g->mapa[i] == '\0'){
			g->mapa[i] = vertice;
			g->lista[i]->v = vertice;
			g->lista[i]->prox = NULL;
			break;
		}
	}
}

void adicionarAresta(grafo *g, char v1, char v2){
	int indV1= -1, indV2 = -1, i;

	if(v1 == v2 || (v1 == '0' && v2 == '0')){
		printf("aresta invalida\n");
		return;
	}

	for(i = 0; i < g->v; i++){
		if(g->mapa[i] == v1){
			indV1 = i;
			break;
		}
	}

	for(i = 0; i < g->v; i++){
		if(g->mapa[i] == v2){
			indV2 = i;
			break;
		}
	}
	if (indV1 != -1 && indV2 != -1) {
		lista* l1 = (lista*) malloc(sizeof(lista));
	  l1->v = v2;
	  l1->prox = NULL;

	  lista* aux1 = g->lista[indV1];

	  while (1) {
	    if(aux1->prox == NULL){
	      aux1->prox = l1;
	      break;
	    }
			aux1 = aux1->prox;
		}
		lista* l2 = (lista*) malloc(sizeof(lista));
	  l2->v = v1;
		l2->prox = NULL;
		lista* aux2 = g->lista[indV2];

		while (1) {
			if(aux2->prox == NULL){
		     aux2->prox = l2;
		     break;
			}
			aux2 = aux2->prox;
		}
	}
}

void imprimir(grafo *g) {
		int i;

		for(i = 0; i < g->v; i++){
			lista* l = g->lista[i];
			while (l != NULL) {
				printf("%c->", l->v);
				l = l->prox;
			}
			printf("NULL\n");
		}
}
