#include<stdio.h>
#define max 10
int top1,top2,arr[max],b1,b2;
void push();
void pop();
void display();
void main()
{
	int ch;
	top1=b1=-1;top2=b2=(max-1)/2;
	do
	{
		printf("1:Push\n2:Pop\n3:Display\n4:Exit\nchoice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			break;
			case 2:pop();
			break;
			case 3:display();
			break;
			case 4:printf("Program exited\n");
			break;
			default:printf("Wrong Choice\n");
			break;

		}
	}
	while(ch!=4);
}
void push()
{
	int x,ch;
	printf("Enter a number\n");
	scanf("%d",&x);
	printf("Press 1 to push in stack 1 and press 2 for stack 2:\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(top1==b2)
		{
			printf("Stack overflow\n");
			return;
		}
		else
		{
			arr[++top1]=x;
		}
	}
	if(ch==2)
	{
		if(top2==max-1)
		{
			printf("Stack overflow\n");
			return;
		}
		else
		{
			arr[++top2]=x;
		}
	}
}
void pop()
{
	int y,ch;
	printf("\nPress 1 to pop from stack 1 and Press 2 for stack 2:\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(top1==-1)
		{
			printf("Stack underflow\n");
			return;
		}
		y=arr[top1];
		arr[top1--]=0;
	}
	else
	{
		if(top2==b2)
		{
			printf("stack underflow\n");
			return;
		}
		y=arr[top2];
		arr[top2--]=0;
	}
	printf("\nelement %d is successfully popped from stack\n",y);
	return;

}
void display()
{
	int i;
	if(top1==-1)
	{
		printf("Stack 1 is empty\n");
	}
	else
	{
		printf("Element of stack 1 are:\n");
		for(i=0;i<=top1;i++)
		{
			printf("%d\n",arr[i]);
		}
	}
	if(top2==b2)
	{
		printf("stack 2 is empty\n");
	}
	else
	{
		printf("Elements of stack 2 are:\n");
		for(i=b2+1;i<=top2;i++)
		{
			printf("%d\n",arr[i]);
		}

	}
	return;
}