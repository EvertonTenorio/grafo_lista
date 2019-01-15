#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc, int* argv) {
	grafo g;
	int tamanho, arestas,i;
	scanf("%d\n", &tamanho);
	scanf("%d\n", &arestas);

	inicializar(&g, tamanho);

	char v;
	for(i = 0; i < tamanho; i++){
		scanf("%c\n", &v);
		adicionarVertice(&g, v);
	}
	imprimir(&g);
	printf("\n");

	char a[2];
	for(i = 0; i < arestas; i++){
		scanf("%s\n", a);
		adicionarAresta(&g, a[0], a[1]);
	}
	 imprimir(&g);
}
