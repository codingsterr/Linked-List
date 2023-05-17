#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp,*start,*p,*q;
typedef struct node NODE;

void insertAtFirstSLL(int ele)
{
    temp=(NODE *)malloc(sizeof (NODE*));
    temp->data=ele;
    if(start==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
    }
    start=temp;
}


void insertAtLastSLL(int ele)
{
    temp=(NODE *)malloc(sizeof (NODE*));
    temp->data=ele;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            p=p->next;
        }
            p->next=temp;
    }
}


void deleteAtFirstSLL()
{
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        p=start;
        start=start->next;
        free(p);
    }
}


void deleteAtLastSLL()
{
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        p=start;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
            if(start==p)
            {
                start=NULL;
            }    
            else
            {
                q->next=NULL;
            }
            free(p);
    }
}


void traversalSLL()
{
    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
     p=start;
     while(p->next!=NULL)
     {
        printf("\n%d",p->data);
        p=p->next;
     }
    } 
}


void searchingSLL(int ele)
{
    int i=1,flag=0;
    p=start;
    while(p->next!=NULL)
    {
        if(p->data==ele)
         {
            flag=1;
            break;
         }
         i++;
         p=p->next;
    }
    if(flag==1)
    {
        printf("Element found at %d position",i);
    }
    else
    {
        printf("Element not found ");
    }
}


int main()
{
    start=NULL;
    int n,choice;
    do
    {
       printf("\n----------MENU----------");
       printf("\n1.Insert At First");
       printf("\n2.Insert At Last");
       printf("\n3.Delete At First");
       printf("\n4.Delete At Last");
       printf("\n5.Traversal");
       printf("\n6.Search");
       printf("\n------------------------");
       printf("\nEnter your choice ");
       scanf("\n%d",&choice);
     switch(choice)
    {
        case 1:printf("\nEnter the value of the element ");
               scanf("\n%d",&n);
               insertAtFirstSLL(n);
               break;

        case 2:printf("\nEnter the value of the element ");
               scanf("\n%d",&n);
               insertAtLastSLL(n); ;
                break;

        case 3: deleteAtFirstSLL();
                break;

        case 4: deleteAtlastSLL(); 
                break;             

        case 5: printf("\nEnter the value of the element ");
                scanf("\n%d",&n);
                searchingSLL(n);      
                break;     

        case 6: traversalSLL();
                break;        

        case 7: break;      

        default: printf("Invalid Choice ");  
    }
    }while(choice!=7);

     return 0;
}