/*
 * Implementa��o de grafos dirigidos utilizando lista de adjac�ncias.
 */

#include <stdlib.h>

typedef struct no {
  int v; /* V�rtice */
  struct no* prox;
} No;

typedef struct grafo {
  int n;      /* N�mero de n�s */
  No** lista;
} Grafo;


void cria_grafo(Grafo* g, int n)  {
  g->lista = calloc(n, sizeof(No*));
  g->n = n;
}

void destroi(Grafo *g) {
  int i;
  for (i = 0; i < g->n; i++) {
    No* l = g->lista[i];
    while (l) {
      No *r = l;
      l = l->prox;
      free(r);
    }
  }
  free(g->lista);
}


void adiciona_aresta(Grafo *g, int v1, int v2) {
  No **ap_l = &g->lista[v1];
  while (*ap_l != NULL &&
	 (*ap_l)->v < v2)
    ap_l = &(*ap_l)->prox;
  if (*ap_l == NULL || (*ap_l)->v != v2) {
    No* n = malloc(sizeof(No));
    n->v = v2;
    n->prox = *ap_l;
    *ap_l = n;
  }
}

int existe_aresta(Grafo *g, int v1, int v2) {
  No *l = g->lista[v1];
  while (l != NULL && l->v < v2)
    l = l->prox;
  if (l != NULL && l->v == v2)
    return 1;
  return 0;
}

void remove_aresta(Grafo *g, int v1, int v2) {
  No **ap_l = &g->lista[v1];
  while (*ap_l != NULL &&
	 (*ap_l)->v < v2)
    ap_l = &(*ap_l)->prox;
  if (*ap_l != NULL && (*ap_l)->v == v2) {
    No* r = *ap_l;
    *ap_l = (*ap_l)->prox;
    free(r);
  }
}

/* Deve imprimir grafos no seguinte formato:

  Grafo dirigido

    0 ----> 1 --->2
    ^       ^
    |       |
    4 <-----3<----5

    E = {<0,1>,<1,2><3,1>,<4,0>,<5,3>}

*/

void imprime_grafo(Grafo *g) {
}

int main() {
  Grafo g;
  int n,a,b,i;
  scanf("%d",&n);
  cria_grafo(&g, n);
  for(i = 0; i < n ; i++)
  {
    scanf("%d %d",&a,&b);
    adiciona_aresta(&g,a,b);
  }

  return 0;
}

