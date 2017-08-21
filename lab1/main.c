#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int maxCross_subvetor(int A[],int low,int high);
void max_subvetor(int A[],int low,int high);


int maxCross_subvetor(int A[],int low,int high)
{
    int soma = 0,leftSoma,rightSoma;
    int maxLeft,maxRight;
    int i,j,mid;
    mid = floor((high+low)/2);

    for (i = mid; i > low ; i-- )
    {
        soma = soma + A[i];
        if (soma > leftSoma)
        {
            leftSoma = soma;
            maxLeft = i;
        }
    }
    soma = 0;
    for (j = mid +1; j < high; j++)
    {
        soma = soma + A[j];
        if (soma > rightSoma)
        {
            rightSoma = soma;
            maxRight= j;
        }
    }
    return (maxLeft,maxRight,leftSoma + rightSoma);
}


void max_subvetor(int A[],int low,int high)
{
    int leftLow,leftHigh,leftSoma;
    int rightLow,rightHigh,rightSoma;
    int croosLow,crossHigh,crossSoma;
    int mid;

    if (high == low)
        return (low,high,A[low]);
    else
    {
        mid = floor((low + high)/2);
        (leftLow, leftHigh,leftSoma) = max_subvetor(A,low,mid);
        (rightLow,rightHigh,rightSoma) = max_subvetor(A,mid + 1, high);
        (crossLow,crossHigh,crossSoma) = maxCross_subvetor(A[low],mid,high);//----
        if ((leftSoma >= rightSoma) && (leftSoma >= crossSoma))
            return (leftLow,leftHigh,leftSoma);
        else if ((rightSoma >= leftSoma) && (rightSoma >= crossSoma))
            return (rightLow,rightHigh,rightSoma);
        else return (crossLow,crossHigh,crossSoma);
    }
}



int main()
{
    int N,taxa,i;
    int *vetor, receita,*lucro;

    scanf("%d",&N);
    scanf("%d",&taxa);
    for (i = 0; i < N; i++)
    {
        scanf("%d",&receita);
        if(i != 0)
        {
            vetor = (int*)realloc(vetor,(i+1)*sizeof(int));
            lucro = (int*)realloc(lucro,(i+1)*sizeof(int));
        }
        else
        {
            vetor = (int*)malloc(sizeof(int));
            lucro = (int*)malloc(sizeof(int));
        }
        vetor[i] = receita;
        lucro[i] = receita - taxa;
    }
    for(i = 0; i < N; i++)
        printf("taxa[%d] = %d\n",i,vetor[i]);
    for(i = 0; i < N; i++)
        printf("lucro[%d] = %d\n",i,lucro[i]);

    max_subvetor(vetor,0,N);


}
