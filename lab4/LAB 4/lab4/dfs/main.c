#include <stdio.h>
#include <stdlib.h>

typedef struct combinacao{
    int vertice;
    struct combinacao *amigo;
}par;

par **p;

int n,conta,*aux;

void ListtaAdj();
void ImprimeListaAjd(int n);
void dfs(par **p,int x);
void dfsR(par **p, int v);

int main()
{
    int  i;
    p = (par **)malloc(n*sizeof(par*));
    scanf("%d",&n);
    aux = (int*)calloc(n,sizeof(int));

    for(i = 1;i <= n;i++){
        p[i] = (par *)malloc(sizeof(par));
        p[i]->amigo=NULL;
    }
    ListaAdj();
    ImprimeListaAjd(n);

    dfs(p,0);

    return 0;
}

void dfs(par **p,int x)
{
   int i;
   conta = 0;
   for (i = 0; i < p[x]->vertice; i++)
      aux[i] = -1;
   for (i = 0; i < p[x]->vertice; i++)
      if (aux[i] == -1)
         dfsR( p[x], i);
}
void dfsR(par **p, int v)
{
   par *a;
   aux[v] = conta++;
   for (a = p->combinacao[v]; a != NULL; a = a->next)
      if (aux[a->w] == -1)
         dfsR( p, a->w);
}



void ListaAdj()
{
    int v1,v2,i;
    par *aux;

    for (i= 0;i < n ; i++)
     {
        scanf("%d %d",&v1,&v2);
        aux = (par *)malloc(sizeof(par));
        aux->vertice = v2;
        aux->amigo = p[v1]->amigo;
        p[v1]->amigo = aux;

    }
}

void ImprimeListaAjd(int nv)
{
    int i;
    par *aux;

    for(i=1; i<=nv; i++){
        aux = p[i]->amigo;
        printf("    p[%d]  ",i);
        while(aux != NULL){
            printf("  -->%d", aux->vertice);
            aux = aux->amigo;
        }
        printf("\n");
    }
    printf("\n");

}
