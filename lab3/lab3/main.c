#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char *a, char *b);
void permutar(char *aux , int ind, int k, int vet2[], int vet3[], int tam);

int main()
{
    int n,m,i,x,y,j=0;
    int *vet,*vet2,*vet3;
    char *aux =(char*)malloc (sizeof(char)*100);
    scanf("%d %d",&n,&m);

    vet = (int*) calloc (n,sizeof(int));
    vet2 = (int*)malloc(sizeof(int)*m);
    vet3 = (int*)malloc(sizeof(int)*m);

    for(i = 0; i < m; i++)
    {
        scanf("%d %d",&x,&y);

        vet2[i] = x - 1;
        vet3[i] = y - 1;
        vet[x - 1] = 1;
    }
    aux[0]='\0';

    for(i = 0; i < n; i++)
    {
        if(vet[i]==0)
        {
            aux[j]=(char)i + '0';
            j++;
        }
    }
    aux[strlen(aux)-1]='\0';
    permutar(aux, 0, n - m, vet2, vet3, n);

    return 0;
}

void troca(char *a, char *b)
{
    char aux = *a;
    *a = *b;
    *b = aux;
}


void permutar(char *aux, int ind, int k, int vet2[], int vet3[], int tam)
{
    int i,j,flag, str ,a;

    if(ind == k)
    {
        str = 0;
        for(i = 0; i < tam; i++)
        {
            flag = 0;
            for(j = 0; j < tam - k; j++)
            {
                if(i == vet3[j])
                {
                    printf("%d ",vet2[j] + 1);
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
             //   printf("aux[str] = %c ----  %d\n",aux[str],(int)aux[str]);
             //   printf("aux[str] - '0' = %c ----  %d\n",aux[str] - '0',(int)aux[str] - '0');
                a = (int)((char)aux[str] - '0') + 1 ;
               // if (a == -47)
               //     a = 8;
                printf("%d ",a);
                str++;
            }
        }
        printf("\n");
    }
    else
    {
        for(i = ind; i < k; i++)
        {
            troca(&aux[i], &aux[ind]);
            permutar(aux, ind + 1, k,vet2, vet3, tam);
        }
    }
}
