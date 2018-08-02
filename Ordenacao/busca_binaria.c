#include <stdio.h>

int pos(int vetor[],int element,int esq, int dir, int mid)
{
	/*
	if(dir <= esq)
	{
		return -1;
	}
	*/
	if(vetor[mid] == element)
	{
		printf ("A posição que ele esta e: %d\n",mid);
		return 0;
	}
	if(element > vetor[mid])
	{
		esq = mid + 1;
		mid = (esq + dir)/2;
		pos(vetor,element,esq,dir,mid);
	}

	if(element < vetor[mid])
	{
		dir = mid - 1;
		mid = (esq + dir)/2;
		pos(vetor,element,esq,dir,mid);
	}
}
int main()
{
	int i, conf, element;
	int vetor[6]={1,2,3,4,5,6};

	scanf ("%d",&element);
	conf = pos(vetor,element,0,5,3);
	/*
	if(conf == -1)
	{
		printf ("Não existe esse numero procurado\n");
	}
	*/
	return 0;
}