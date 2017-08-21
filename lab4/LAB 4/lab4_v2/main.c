#include<stdio.h>
#include<stdlib.h>
#include<string.h>




void imprimeMatriz(int **matriz, int len)
{
    int i,j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            printf ("%d ",matriz[i][j]);
        }
        printf ("\n");
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void lps(char *dna, int len)
{
    int i,j;
    int matriz[len][len];
    for (i = 0; i < len; i++)
        for (j = 0; j < len; j++)
        matriz[i][j] = 0;


    for(i = 0; i < len; i++)
        matriz[i][i] = 1;

    int result = 2;

        printf("\nENTRANDO WHILE\n");
    while(result <= len)
    {
        for( i = 0, j = result - 1 + i; j < len; i++, j++)
        {
            if(dna[i] == dna[j] && result == 2)
                matriz[i][j] = 2;
            else if(dna[i] != dna[j])
                matriz[i][j] = max(matriz[i][j - 1], matriz[i + 1][j]);
            else
                matriz[i][j] = matriz[i + 1][j - 1] + 2;
        }
        result++;
    }
    printf("\nSAIU WHILE\n");
    printf("\n\n");
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
        {
            printf ("%d ",matriz[i][j]);
        }
        printf ("\n");
    }

    printf("\n\t%d\n", matriz[0][len - 1]);
}

int main()
{
    char dna[]="GATTACA";
   // int *vetorM;
    int i,n,mut,len;
  //  dna = (char*) malloc (5000*sizeof(char));
 //   fgets(dna, 5000, stdin);
    len = strlen(dna);
    printf("len dna = %d\n",len);
    scanf("%d",&n);

//    vetorM = (int*) calloc (len, sizeof(int));
//
//    for (i = 0; i < n ; i++)
//    {
//        scanf("%d",&mut);
//        vetorM[mut] = 1;
//    }

    lps(dna,len);

    return 0;
}
