#include <stdio.h>
#include <stdlib.h>



void busca_par(int i);

int n,i,j;
int a,b;
int **matAdj,*aux;

int main()
{
    scanf("%d",&n);

    aux = (int*)calloc(n,sizeof(int));

    matAdj = (int **) calloc (n,sizeof(int *));
    for ( i = 0; i < n+1; i++ )
        matAdj[i] = (int*) calloc (n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        scanf("%d %d",&a,&b);
        matAdj[a - 1][b - 1] = 1;
    }

    for(i = 0 ; i < n ;i++)
    busca_par(i);

}
void busca_par(int i)
{
    int j;
    printf("%d ",i+1);
    aux[i]=1;

    for(j = 0;j < n;j++)
       if(!aux[j] && matAdj[i][j] == 1)
            busca_par(j);
}


