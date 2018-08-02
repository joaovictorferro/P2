#include <stdio.h>

void is_par(int (*f)(int x))
{
int i,sum=0;
int vetor[5]={1,2,3,4,5};

for(i=0;i<5;i++)
{
	sum += (*f)(vetor[i]);
}
printf ("Total: %d\n\n",sum);

return ;
}

int par(int x)
{
	if(x%2 == 0)
	{
		printf ("Par: %d\n",x);
		return x;
	}
	return 0;
}

int impar(int x)
{
	if(x%2 != 0)
	{
		printf ("Impar: %d\n",x);
		return x;
	}
	return 0;
}

int main()
{
	is_par(par);
	is_par(impar);

	//integral(impar, 2, 3);

return 0;
}