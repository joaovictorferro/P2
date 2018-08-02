#include <stdio.h>

void quick(int *v,int begin, int end)
{
	int right = end -1;
	int left = begin;
	int mid = (begin + end) / 2;
	int pivo = v[mid];
	int aux = 0;

	while(left <= right)
	{
		while(v[left] < pivo && left < end )
		{ 
			left++;
		}

		while(v[right] > pivo && right > begin )
		{ 
			right--;
		}

		if (right >= left)
		{
			aux = v[left];
			v[left] = v[right];
			v[right] = aux;	
			
			left ++;
			right --;
		}
	}
	
	if (begin < right)
		{
			quick(v,begin,right +1);
		}
		
		if (end > left)
		{
			quick(v, left, end);
		}
	
}

int main()
{
	int i;
	int v[10]={5,4,3,2,1,7,7,8,9,1};
	
	quick(v,0,10);
	
	for(i = 0; i < 10; i++)
	{
		printf ("%d ",v[i]);
	}
	printf ("\n\n");
	
	return 0;
}