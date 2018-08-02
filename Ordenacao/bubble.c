#include <stdio.h>

void troca(int *a, int *b)
{
	int u;

	u = *b;
	*b = *a;
	*a = u;
}

void bubble(int v[], int size)
{
	int i,j;
	for(j = 1; j <= size; j++)
	{
		for(i = 0; i < size - 1; i++)
		{
			if (v[i] > v[i+1])
			{
				troca(&v[i],&v[i+1]);
			}
		}
	}
}

int main()
{
	int i;
	int v[10]={9,6,7,8,4,3,2,0,1,5};
	bubble(v,10);
	for (i = 0; i < 10; i++)
	{
		printf ("%d ",v[i]);
	}
	printf ("\n\n");
return 0;	
}