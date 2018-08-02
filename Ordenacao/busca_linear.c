#include <stdio.h>

int main(){
	int vetor[6]={1,2,6,4,5,3};
	int i;

	for(i=0;i<6;i++)
	{
		if(vetor[i] == 6)
		{
			printf ("%d\n",i);
			break;
		}
	}
	return 0;
}