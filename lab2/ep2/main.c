#include <stdio.h>
#include <stdlib.h>

 typedef struct
    {
        int tam;
        int *conteudo;
    } conjunto;

void heap_sort(long vet[], long tam)
{
    int i = tam/2, pai, filho, t;

    for (;;)
    {
        if (i > 0)
        {
            i--;
            t = vet[i];
        }
        else
        {
            tam--;
            if (tam == 0)
                return;
            t = vet[tam];
            vet[tam] = vet[0];
        }

        pai = i;
        filho = i*2 + 1;

        while (filho < tam)
        {
            if ((filho + 1 < tam)  &&  (vet[filho + 1] > vet[filho]))
                filho++;
            if (vet[filho] > t)
            {
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai*2 + 1;
            }
            else
                break;
        }
        vet[pai] = t;
    }
}

int main()
{
    int k,i,x,y,tam,num;
    scanf("%d %d",&k,&i);

    conjunto *vetor=(conjunto*)malloc(k * sizeof*(conjunto*));

    for(x = 0 ; x < k; x++)
    {
        scanf("%d",&vetor[x].tam);
        vetor[x].conteudo[x] = (int*)malloc(vetor.tam * sizeof(int*));
        for (y = 0; y < vetor.tam; y++)
                scanf("%d",&vetor.conteudo[x][y]);
    }

    for (x = 0;x < k;x++)
    {
        for(y = 0;y < tam;y++)
        printf("%d ",v[x][y]);
        printf("\n");
    }

    return 0;
}
