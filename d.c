#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node *prev;
int n;
struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;

void insert1();
void insert2();
void insert3();
void traversebeg();
void delete();

int count=0;
void main()
{
  int ch;
  h=NULL;
  temp=temp1=NULL;
  do
   {
     printf("\n 1-insert at beginning");
     printf("\n 2-insert at end");
     printf("\n 3-insert at position");
     printf("\n 4-delete from a position");
     printf("\n 5-display from begining");
     printf("\n 6-exit");
     printf("\n ENTER YOUR CHOICE ");
     scanf("%d",&ch);
       switch(ch)
         {
  case 1:
   	  insert1();
  break;
  case 2:
  insert2();
  break;
    case 3:
  insert3();
  break;
  case 4:
  delete();
    break;
  case 5:
  traversebeg();
   	  break;
  case 6:
  break;
  default:
              printf("\n wrong choice menu");
          }
      }while(ch!=6);
 }

void create()
 {
   int data;
   temp=(struct node*) malloc (1*sizeof(struct node));
   temp->prev=NULL;
   temp->next=NULL;
   printf("\n enter value of node:");
   scanf("%d",&data);
   temp->n=data;
   count++;
 }

void insert1()
 {
   if(h==NULL)
     {
create();
h=temp;
temp1=h;
     }
   else
      {	
create();
temp->next=h;
h->prev=temp;
h=temp;
      }
  }

void insert2()
 {
   if(h==NULL)
     {
create();
h=temp;
temp1=h;
      }
   else
     {
       create();
       temp1->next=temp;
       temp->prev=temp1;
       temp1=temp; 
     }
 }

void insert3()
 {
   int pos,i=2;
   printf("\n enter the position to be inserted:");
   scanf("%d",&pos);
   temp2=h;
     if((pos<1)||(pos>=count+1))
       {
         printf("\n position out of range to insert:");
         return;
       }
    if((h==NULL)&&(pos!=1))
      {
        printf("\nempty list cannot insert other than 1st position");
        return;
      }
     if ((h==NULL)&&(pos==1))
        {
         create();
h=temp;
temp1=h;
        return;
       }
     else
       {
         while(i<pos)
           {
             temp2=temp2->next;
             i++;
            }
    create();
    temp->prev=temp2;
    temp->next=temp2->next;
    temp2->next->prev=temp;
    temp2->next=temp;
    }
  }

void delete()
  {
    int i=1,pos;
    printf("\n enter position to be deleted:");
    scanf("%d",&pos);
    temp2=h;
    if((pos<1)||(pos>=count+1))
      {
printf("\n error:position out of range to delete:");
        return;
       }
    if(h==NULL)
{
 printf("\n error:empty list no elements to delete");
          return;
        }
    else
{
 while(i<pos)
   {
     temp2=temp2->next;
              i++;
             }
           if(i==1)
            {
if(temp2->next==NULL)
{
             printf("\n node deleted from list");
             free(temp2);
             temp2=h=NULL;
             return;
           }
         }
if (temp->next==NULL)
   {
      temp2->prev->next=NULL;
      free(temp2);
      printf("\n node deleted from the list");
      return;
    }
temp2->next->prev=temp2->prev;
 if(i!=1)
temp2->prev->next=temp->next;
if(i==1)
 h=temp2->next;
 printf("\n node deleted");
 free(temp2);
 }
count--;
}

void traversebeg()
 {
   temp2=h;
   if(temp2==NULL)
    {
      printf("list is empty to display\n");
      return;
     }
   printf("\n linked list elements from beginning:\n");
   while (temp2->next!=NULL)
{
printf("\t%d",temp2->n);
temp2=temp2->next;
}
printf("\t%d",temp2->n);
}
