#include <stdio.h>

void troca(int *a, int *b)
{
	int u = 0;

	u = *b;
	*b = *a;
	*a = u;

	return ;
}

void selection_sort (int S[],int n)
{
	int i,j,min;

	for(i = 0; i < n; i++)
	{
		min = i;
		for(j = i + 1;j < n; j++)
		{
			if (S[j] < S [min])
			{
				min = j;
			}
			// swap == troca.
			troca(&S[i], &S[min]);
		}
	}
	return ;
}
int main ()
{
	int S[10]={5,4,3,2,1,7,8,9,6};
	int i;

	selection_sort(S,10);
	for(i = 0; i < 10; i++)
	{
		printf ("%d ",S[i]);
	}
	printf ("\n\n");
	return 0;
}