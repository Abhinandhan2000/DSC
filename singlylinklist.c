#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void ins_b();
void ins_e();
void ins_p();
void del_b();
void del_e();
void del_p();
struct node
{
	int data;
	struct node*next;
};
struct node*first=NULL;
int main()
{
	int choice;
	while(1)
	{
		printf("\n Singly Linked List operations:\n");
		printf("\nMenu\n");
		printf("\n-----------\n");
		printf("\n1.Create");
		printf("\n2.Display");
		printf("\n3.Insert at beginning");
		printf("\n4.Insert at end");
		printf("\n5.Insert at specific position");
		printf("\n6.Delete at beginning");
		printf("\n7.Delete at end");
		printf("\n8.Delete at specific position");
		printf("\n9.Exit");
		printf("\nEnter choice\t");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			create();
			break;
			case 2:
			display();
			break;
			case 3:
			ins_b();
			break;
			case 4:
			ins_e();
			break;
			case 5:
			ins_p();
			break;
			case 6:
			del_b();
			break;
			case 7:
			del_e();
			break;
			case 8:
			del_p();
			break;
			case 9:
			exit(0);
			break;
			default:
			printf("\nWrong Choice");break;
		}
	}
	return 0;
}
void create()
{
	struct node*temp,*ptr;
	temp=(struct node*) malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOut of memory space");
		exit(0);
	} 
	printf("\nEnter data value for node\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		ptr=first;
		while(ptr->next !=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void display()
{
	struct node*ptr;
	if(first==NULL)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		ptr=first;
		printf("\nThe list elements are:\n");
		while(ptr !=NULL)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
	}
}
void ins_b()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOut of memory space");
		return;
	} 
	printf("Enter data value for node:\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		temp->next=first;
		first=temp;
	}
}
void ins_e()
{
	struct node*temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOut of memory space");
		return;
	} 
	printf("Enter data value for node:\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		ptr=first;
		while(ptr->next !=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}
void ins_p()
{
	struct node*ptr,*temp;
	int i,pos;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("\nOut of memory space");
		return;
	} 
	printf("\nEnter position for node to be inserted:\t");
	scanf("%d",&pos);
	printf("Enter data value for node:\t");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(pos==0)
	{
		temp->next=first;
		first=temp;
	}
	else
	{
		for(i=0,ptr=first;i<pos-1;i++)
		{
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("\nPosition not found");
				return;
			}
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}
void del_b()
{
	struct node*ptr;
	if(ptr==NULL)
	{
		printf("\nList is empty:");
		return;
	}
	else
	{
		ptr=first;
		first=first->next;
		printf("Deleted element is %d\t",ptr->data);
		free(ptr);
	}
}
void del_e()
{
	struct node*temp,*ptr;
	if(ptr==NULL)
	{
		printf("\nList is empty:");
		exit(0);
	}
	else if(first->next==NULL)
	{
		ptr=first;
		first=NULL;
		printf("Deleted element is %d\t",ptr->data);
		free(ptr);
	}
	else
	{
		ptr=first;
		while(ptr->next !=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		printf("Deleted element is %d\t",ptr->data);
		free(ptr);
	}
}
void del_p()
{
	struct node*temp,*ptr;
	int i,pos;
	if(first==NULL)
	{
		printf("\nList is empty:");
		exit(0);
	}
	else
	{
		printf("\nEnter position of node to be deleted\t");
		scanf("%d",&pos);
		if(pos==0)
		{
			ptr=first;
			first=first->next;
			printf("Deleted element is %d\t",ptr->data);
			free(ptr);
		}
		else
		{
			ptr=first;
			for(i=0;i<pos;i++)
			{
				temp=ptr;
				ptr=ptr->next;
				if(ptr==NULL)
				{
					printf("\nPosition not found\n");
					return;
				}
			}
			temp->next=ptr->next;
			printf("\nDeleted element is %d\t",ptr->data);
		}

	}

}