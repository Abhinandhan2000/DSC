#define size 50
#include<stdio.h>
#include<ctype.h>
int s[size];
int top=size-1;
int push(int ele)
{
	s[++top]=ele;
}
int pop()
{
	return(s[top--]);
}
int main()
{
	char pofx[50],ch;
	int i=0,op1,op2;
	printf("Enter postfix expression  \n");
	scanf("%s",pofx);
	while((ch=pofx[i++])!='\0')
	{
		if(isdigit(ch))
		{
			push(ch-'0');
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':
				push(op1+op2);
				break;
				case '-':
				push(op1-op2);
				break;
				case '*':
				push(op1*op2);
				break;
				case '/':
				push(op1/op2);
				break;
			}

		}
	}
	printf("Given postfix expression %s \n",pofx);
	printf("Result after evaluation %d \n",s[top]);
}