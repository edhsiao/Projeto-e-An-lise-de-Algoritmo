#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    int *amigos;
    int **combinacao;
} par;

void dfs(par p1);
void dfsR(par p2, int x);

int n,cont;
int *aux;
//int **combinacao,*amigos;
par p;


int main()
{
    int i,j;
    int a,b;
    scanf("%d",&p.n);

    aux = (int*)calloc(p.n+1,sizeof(int));

    p.amigos = (int*)calloc(p.n+1,sizeof(int));

    p.combinacao = (int **) calloc (p.n+1,sizeof(int *));

    for ( i = 0; i < p.n; i++ )
        p.combinacao[i] = (int*) calloc (p.n+1, sizeof(int));

    for (i = 0; i < p.n; i++)
    {
        scanf("%d %d",&a,&b);
        p.amigos[a-1]++;
        p.amigos[b-1]++;
        p.combinacao[a - 1][b - 1] = 1;
     //   p.combinacao[b - 1][a - 1] = 1;
    }
    printf("p.n = %d\n",p.n);

    printf("\np.amigos = ");
    for (i = 0 ; i < p.n ; i++)
        printf("%d ",p.amigos[i]);

    printf("\n");
    for (i = 0 ; i < p.n ; i++)
    {
        printf("\n");
        for (j = 0 ; j < p.n ; j++)
            printf("%d ",p.combinacao[i][j]);
    }

    dfs(p);
    printf("\n\n");
    for (i = 0 ; i < p.n ; i++)
    {
        printf("%d ",p.amigos[i]);
    }

}

void dfs(par p1)
{
    int i;
    cont = 0;
    for (i = 0; i < p1.n; i++)
        p1.amigos[i] = -1;
    for (i = 0; i < p1.n; i++)
        if (p1.amigos[i] == -1)
            dfsR(p1,i);
}
void dfsR(par p2, int x)
{
    int j;
    p2.amigos[x] = cont++;
    for (j = 0; j < p2.n; j++)
        if (p2.combinacao[x][j] != 0 && p2.amigos[j] == -1)
            dfsR( p2, j);
}



//    void dfs(int i)
//    {
//        int j;
//        printf("%d ",i+1);
//        amigos[i]=1;
//
//        for(j = 0;j < n;j++)
//           if(!amigos[j] && combinacao[i][j] == 1)
//                dfs(j);
//    }


//#include <stdio.h>
//#include <stdlib.h>
//
//enum boolean {
//    true = 1, false = 0
//};
//typedef  enum boolean  bool;
//
//void retira (int **mat,int *vet,int a,int n) {
//    int i;
//    for (i=1;i<n+1;i++) {
//        if (mat[a][i] == 1) {
//            mat[a][i] = 0; // retira da lista de amizade na matriz.
//            mat[i][a] = 0; // retira da lista de amizade na matriz.
//            vet[a] = 0; //nao podera ir na festa entao nao "tera nenhum amigo"
//            vet[i]--; //retira 1 amigo de seus numero de amigos.
//        }
//    }
//}
//
//int main()
//{
//    int n,p,k,i,a,b,resultado=0;
//    bool continua = true;
//    scanf("%d %d %d",&n,&p,&k);
//    int *vet;
//    int **mat;
//
//    vet = (int *)calloc(n+1,sizeof(int));
//
//    mat = (int **) calloc (n+1, sizeof(int *));
//    if (mat == NULL) {
//        printf ("** Erro: Memoria Insuficiente **");
//        return (NULL);
//    }
//  /* aloca as colunas da matriz */
//    for ( i = 0; i < n+1; i++ ) {
//        mat[i] = (int*) calloc (n+1, sizeof(int));
//        if (mat[i] == NULL) {
//            printf ("** Erro: Memoria Insuficiente **");
//            return (NULL);
//        }
//    }
//
//    for (i=0 ; i < p ; i++) {
//        scanf("%d %d",&a,&b);
//        vet[a]++;
//        vet[b]++;
//        mat[a][b] = 1;
//        mat[b][a] = 1;
//    }
//
//    /*for (i=0;i<n+1;i++) {
//        printf("\n");
//        for(j=0;j<n+1;j++)
//            printf ("%d ",mat[i][j]);
//    }*/ //Preenchimento da matriz esta OK
//
//    while(continua) {
//        continua = false;
//        for (i=1;i<n+1;i++){
//            if (vet[i] < k && vet[i] > 0) { // Esse cara não pode ir para a festa e pode afetar outros que poderiam.
//                retira(mat,vet,i,n);//Entao se o cara nao vai pra festa logo remover todas as amizades dele e zerar o vetor de amizades.
//                continua = true;
//            }
//        }
//    }
//
//    for (i=1;i<n+1;i++) {
//        if (vet[i] >= k) {
//            resultado++;
//            //printf("vet[%d] = %d\n",i,vet[i]);
//        }
//    }
//    printf("%d",resultado);
//
//    return 0;
//}
