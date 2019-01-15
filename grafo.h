#ifndef GRAFO_H
#define GRAFO_H

typedef struct lista{
	char v;
	struct lista* prox;
} lista;

typedef struct grafo {
	int v;
	char *mapa;
	lista **lista;
} grafo;

void inicializar (grafo *g, int tamanho);

void imprimir(grafo *g);

void adicionarAresta(grafo *g, char v1, char v2);

void adicionarVertice(grafo *g, char v);

#endif
