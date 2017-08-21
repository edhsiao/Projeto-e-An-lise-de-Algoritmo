#include <stdio.h>
#include <stdlib.h>

void dfs(int i);
void dfs1(int i);

    int n,i,j,k ,cont;
    int a,b;
    int *indicado,**matAdj,*visitado,*aux1;

int main()
{

    scanf("%d",&n);

    indicado = (int*)calloc(n,sizeof(int));

    visitado = (int*)calloc(n,sizeof(int));

    aux1= (int*)calloc(n,sizeof(int));

    matAdj = (int **) calloc (n,sizeof(int *));
    for ( i = 0; i < n+1; i++ )
        matAdj[i] = (int*) calloc (n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d %d",&a,&b);
        indicado[a - 1]++;
        indicado[b - 1]++;
        matAdj[a - 1][b - 1] = 1;
    //    matAdj[b - 1][a - 1] = 1;
    }


    printf("\n");

    for(i = 0; i < n;i++)
        printf("%d ",indicado[i]);

     printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("\n");
        for(j = 0; j < n; j++)
            printf ("%d ",matAdj[i][j]);
    }

    printf("\n-----------------\n");

  //  for (i = 0; i < n ; i ++)
 //   {
    cont =0;
    dfs1(0,visitado);
    printf("\ncont  = %d\n",cont);
 //   }

//    for(i = 0;i < n; i++)
//    {
//     //   if(aux[i] == 0)
//            dfs(i);
//        printf("------\n");
//    }
//
//     for(i = 0;i < n; i++)
//        printf("%d ",aux[i]);
//
//    printf("\n");

//    for(i = 0;i < n; i++)
//    {
//        if(aux[i] == 0)
//            dfs1(i);
//        printf("\n");
//        printf("\n--imprime aux1--\n");
//            for(k = 0;k < n; k++)
//                printf("%d ",aux1[k]);
//
//        printf("\n\n********************************\n\n");
//    }
}
//void dfs(int i)
//{
//    int j;
//    aux[i]=1;
//    for(j = 0;j < n;j++)
//       if(!aux[j] && matAdj[i][j] == 1)
//            dfs(j);
//}

void dfs1(int i,int *visitado )
{
    int j;
    if(visitado[i])
        if(i==0)
        return;
    visitado[i]=1;
    printf("%d ",i+1);
    aux1[i] = 1;

    for(j = 0;j < n;j++)
       if(!aux1[j] && matAdj[i][j] == 1)
            dfs1(j,visitado);
    visitado = 0;
}

//dfs(adj,node,visited):
//  if (visited[node]):
//    if (node == start):
//      "found a path"
//    return;
//  visited[node]=YES;
//  for child in adj[node]:
//    dfs(adj,child,visited)
//  visited[node]=NO;
//Call the above function with the start node:
//
//visited = {}
//dfs(adj,start,visited)

//
//void dfs(int **mat,int *vet) {
//    int i;
//    for (i = 0 ; i < n ; i++)
//    if (vet[i])
//        printf("vet[%d] = %d", i vet[i]);
//    vet[i] = 1;
//    for (i=0; i < n; i++)
//        if (adj[a][b])
//            dfs(i);
//}

//    #include <stdio.h>
//    #include <stdlib.h>
//
//
//
//    void dfs(int i);
//
//    int n,i,j,flag ;
//    int a,b;
//    int **matAdj,*aux;
//
//    int main()
//    {
//        scanf("%d",&n);
//
//        aux = (int*)calloc(n,sizeof(int));
//
//        matAdj = (int **) calloc (n,sizeof(int *));
//        for ( i = 0; i < n+1; i++ )
//            matAdj[i] = (int*) calloc (n, sizeof(int));
//
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d %d",&a,&b);
//            matAdj[a - 1][b - 1] = 1;
//        }
//
//
//        dfs(0);
//
//    }
//    void dfs(int i)
//    {
//        int j;
//        printf("%d ",i+1);
//        aux[i]=1;
//
//        for(j = 0;j < n;j++)
//           if(!aux[j] && matAdj[i][j] == 1)
//                dfs(j);
//    }
