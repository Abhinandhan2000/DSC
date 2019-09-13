#include<stdio.h>
void quicksort(int[10],int,int);
int main()
{
	int x[20],si,i;
	printf("Enter size of array ");
	scanf("%d",&si);
	printf("Enter %d elements ",si);
	for(i=0;i<si;i++)
	{
		scanf("%d",&x[i]);
	}
	quicksort(x,0,si-1);
	printf("Sorted elements ");
	for(i=0;i<si;i++)
	{
		printf("%d",x[i]);
	}
	return 0;
}
void quicksort(int x[10],int first,int last)
{
	int pivot,j,t,i;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
	}
	while(i<j)
	{
		while(x[i]<=x[pivot]&&i<last)
		{
			i++;
		}
		while(x[j]>x[pivot])
		{
			j--;

		}
		if(i<j)
		{
			t=x[i];
			x[i]=x[j];
			x[j]=t;

		}

	}
	t=x[pivot];
	x[pivot]=x[j];
	x[j]=t;
	quicksort(x,first,j-1);
	quicksort(x,j+1,last);
}