#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 100000

typedef struct dna
{
    int maior_seq;
    int maior_seqM;
} dna;

void imprimeMatrizMaiorSeq(dna **matriz, int dim);
void imprimeMatrizSeqMut(dna **matriz, int dim);
int max(int a, int b);
int lps_mutante(dna **matriz,int *vetorM, char * dna, int dim);


int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int lps_mutante(dna **matriz,int *vetorM,char *seq_dna, int dim)
{
    int i,j;

    int len = 2;


    while(len <= dim)
    {
        for( i = 0, j = len - 1 + i; j < dim; i++, j++)
        {
            if(seq_dna[i] == seq_dna[j] && len == 2)
            {
                if((vetorM[i] == 1) && (vetorM[j] == 1))
                {
                    matriz[i][j].maior_seqM = matriz[i][j-1].maior_seqM + 1;
                    matriz[i][j].maior_seq = 2;
                }
                else
                {
                    if(matriz[i][j - 1].maior_seqM > matriz[i + 1][j].maior_seqM)
                    {
                        matriz[i][j].maior_seqM = matriz[i][j - 1].maior_seqM;
                        matriz[i][j].maior_seq = 2;
                    }
                    else
                    {
                        matriz[i][j].maior_seqM = matriz[i + 1][j].maior_seqM;
                        matriz[i][j].maior_seq = 2;
                    }
                }
            }
            else
            {
                if(seq_dna[i] != seq_dna[j])
                {
                    if((vetorM[i] == 1) && (vetorM[j] == 1))
                    {
                        matriz[i][j].maior_seqM = matriz[i][j - 1].maior_seqM;
                        matriz[i][j].maior_seq = max(matriz[i][j - 1].maior_seq,matriz[i + 1][j].maior_seq);
                    }
                    else
                    {
                        if(matriz[i][j - 1].maior_seqM > matriz[i + 1][j].maior_seqM)
                        {
                            matriz[i][j].maior_seqM = matriz[i][j - 1].maior_seqM;
                            matriz[i][j].maior_seq = matriz[i][j - 1].maior_seq;
                        }
                        else
                        {
                            matriz[i][j].maior_seqM = matriz[i + 1][j].maior_seqM;
                            matriz[i][j].maior_seq = matriz[i + 1][j].maior_seq;
                        }
                    }
                }
                else
                {
                    if((vetorM[i] == 1) && (vetorM[j] == 1))
                    {
                        matriz[i][j].maior_seqM = matriz[i][j-1].maior_seqM + 1;
                        matriz[i][j].maior_seq = matriz[i + 1][j - 1].maior_seq + 2;
                    }
                    else
                    {
                        if(matriz[i][j - 1].maior_seqM > matriz[i + 1][j].maior_seqM)
                        {
                            matriz[i][j].maior_seqM = matriz[i][j - 1].maior_seqM;
                            matriz[i][j].maior_seq = matriz[i][j - 1].maior_seq;
                        }
                        else
                        {
                            matriz[i][j].maior_seqM = matriz[i + 1][j].maior_seqM;
                            matriz[i][j].maior_seq = matriz[i + 1][j].maior_seq;
                        }
                    }
                }
            }
        }
        len++;
    }

//    imprimeMatrizMaiorSeq(matriz,dim);
//    printf("\n\n");
//    imprimeMatrizSeqMut(matriz,dim);

    return matriz[0][dim - 1].maior_seq;

}

void imprimeMatrizMaiorSeq(dna **matriz, int dim)
{
    int i,j;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            printf ("%d ",matriz[i][j].maior_seq);
        }
        printf ("\n");
    }
}

void imprimeMatrizSeqMut(dna **matriz, int dim)
{
    int i,j;
    for (i = 0; i < dim; i++)
    {
        for (j = 0; j < dim; j++)
        {
            printf ("%d ",matriz[i][j].maior_seqM);
        }
        printf ("\n");
    }
}

int main()
{
    char *seq_dna;
    dna **matriz;
    int *vetorM;
    int i,n,mut,dim;

    seq_dna = (char*) malloc (TAM*sizeof(char));
    fgets(seq_dna, TAM, stdin);

    dim = strlen(seq_dna)-1;
 //   printf("dna tam= %d\n",dim);

    matriz = (dna**) calloc (dim, sizeof(dna *));
    for ( i = 0; i < dim; i++ )
        matriz[i] = (dna*) calloc (dim, sizeof(dna));

    for(i = 0; i < dim; i++)
        matriz[i][i].maior_seq = 1;

    vetorM = (int*)calloc(dim,sizeof(int));

//    printf("==============\n");
//    printf ("\n\n");
//    imprimeMatrizMaiorSeq(matriz,dim);
//    printf ("\n\n");
//    imprimeMatrizSeqMut(matriz,dim);


    scanf("%d",&n);


    for (i = 0; i < n ; i++)
    {
        scanf("%d",&mut);
        vetorM[mut-1] = 1;
        matriz[mut-1][mut-1].maior_seqM = 1;
    }

    printf("%d",lps_mutante(matriz,vetorM,seq_dna,dim));

    return 0;
}
