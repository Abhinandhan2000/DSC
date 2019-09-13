//TO perform matrix operations on arrays
#include<stdio.h>
int main(void)
{
	int m,n,a[20][20],b[20][20],i,j,sum[20][20],sub[20][20],opt,tr[20][20],opt1,ch,e,f;
	printf("enter no. of rows in matrix1  ");
	scanf("%d",&m);
	printf("enter no. of columns in matrix1  ");
	scanf("%d",&n);
	printf("Enter elements of matrix 1 ");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter no. of rows in matrix2 ");
	scanf("%d",&e);
	printf("enter no. of columns in matrix2 ");
	scanf("%d",&f);
	printf("Enter elements of matrix2 ");
	for(i=0;i<e;i++)
	{
		for(j=0;j<f;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	do
	{
		if(m==e && n==f)
		{printf("Enter 1 for add or sub of matrix\n");
		}
		if(n==e)
		{
			printf("enter 2 for multiplication of matrices\n");
			printf("enter 3 for transpose of matrix1\n"); 
		}
		else if(m!=n && n==e)
		{ 
			printf("Enter 2 for multiplication of matrices\n");
			printf("Enter 3 for transpose of matrix1\n");
		}
		else
		{
			printf("enter 3 for transpose of matrix1\n");
		}
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					sum[i][j]=a[i][j]+b[i][j];
					sub[i][j]=a[i][j]-b[i][j];
				}
			}
			printf("enter 1-add\nenter 2-sub\n");
			scanf("%d",&opt);
			switch (opt)
			{
				case 1:
				printf("Resultant matrix \n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%3d",sum[i][j]);

					}printf("\n");
				}
				break;
				case 2:
				printf("Resultant matrix \n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<n;j++)
					{
						printf("%3d",sub[i][j]);
					}printf("\n");
				}
				break;
			}
			case 2:
			printf("Resultant matrix \n");
			int k;
			for(i=0;i<m;i++)
			{
				for(j=0;j<f;j++)
				{
					sum[i][j]=0;
					for(k=0;k<m;k++)
					{
						sum[i][j]+=a[i][k]*b[k][j];
					}printf("%3d",sum[i][j]);

				}printf("\n");
			}break;
			case 3:
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					tr[j][i]=a[i][j];
				}
			}
			printf("Resultant matrix \n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					printf("%3d",tr[i][j]);
				}printf("\n");
			}break;

		}


	}while(ch>0);
}