//Sort elements of array in ascending order using insertion sort
#include<stdio.h>
int main()
{
	int n,ar[1000],i,d,t;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("Enter %d integers  ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	for(i=1;i<=n-1;i++)
	{
		d=i;
		while(d>0 && ar[d-1]>ar[d])
		{
			t=ar[d];
			ar[d]=ar[d-1];
			ar[d-1]=t;
			d--;
		}
	}
	printf("Sorted list in ascending order\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d  ",ar[i]);
	}
	return 0;
}
