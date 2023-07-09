#include<stdio.h>
#include<stdlib.h>
typedef struct SLL sll; 
struct SLL
{
    int data;
    sll *next;
}*head=NULL;
int count=0,key;
void insert(int pos)
{
    sll *newnode,*temp=head,*prev;
    if(1>pos || pos>count+1)
    {
        printf("Position does not exist - Cannot insert into SLL\n");
        return;
    }
    newnode=(sll*)malloc(sizeof(sll));
    scanf("%d",&newnode->data);
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        newnode->next=temp;
        prev->next=newnode;
    }
    count++;
}
void del(int pos)
{
    sll *temp=head,*prev;
    if(1>pos || count<pos)
    {
        printf("Position does not exist  - Cannot delete from SLL\n");
        return;
    }
    if(pos==1)
    {
        printf("\nDeleted element from SLL is %d",head->data);
        head=head->next;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("\nDeleted element from SLL is %d",temp->data);
        prev->next=temp->next;
    }
    count--;
}
void display()
{
    sll *temp=head;
    if(head==NULL)
        printf("\nEmpty SLL - Cannot display\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
}
void search()
{
    sll *temp=head;
    scanf("%d",&key);
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("%d is found in SLL\n",key);
            return;
        }
        temp=temp->next;
    }
    printf("%d is not found in SLL\n",key);
}
void nodecount()
{
    sll *temp=head;
    key=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        key++;
    }
    printf("No of nodes in SLL = %d\n",key);
}
void rvsedsply(sll *temp)
{
    if(temp!=NULL)
    {
        rvsedsply(temp->next);
        printf("%d ",temp->data);
    }
}
int main()
{
    int pos,ch;
    while(1)
    {
       scanf("%d",&ch);
       switch(ch)
       {
            case 1: scanf("%d",&pos);
                   insert(pos);
                   break;
            case 2: scanf("%d",&pos);
                    del(pos);
                    break;
            case 3: printf("\n"); 
                    display();
                    break;
            case 4: search();
                    break;
            case 5: nodecount();
                    break;
            case 6: rvsedsply(head);
                    break;
            case 7: exit(0);
            default:printf("invalid choice\n");
       }
    }
}