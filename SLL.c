#include <stdio.h>
#include <stdlib.h>

struct linkedlist{
    int data;
    struct linkedlist* next;
};

typedef struct linkedlist node;

node *head = NULL;

void createlist(int n);
void display();
void insert_beg();
void insert_pos();
void insert_last();
void delete_beg();
void delete_pos();
void delete_last();

int main()
{
    int n,d;

     while(1){
     printf("1 : createList 2 : display 3 : insertBeginning 4 : insertPosition 5 : insertLast 6 : deleteBeginning 7 : deletePosition 8 : deleteLast 9 : exit\n");
      printf("Enter choice : ");
    scanf("%d" , &d);
    switch(d)
    {
        case 1 : printf("Enter the number of nodes in list : ");
                 scanf("%d" , &n); 
                 createlist(n);
                 break;
        case 2 : display();
                 break;
        case 3 : insert_beg();
                break;
        case 4 : insert_pos();
                break;
        case 5 : insert_last();
                    break;
        case 6 : delete_beg();
                break;
        case 7 : delete_pos();
                    break;
        case 8 : delete_last();
                    break;
        case 9 : exit(0);

    }
         
       }

}
node *getNode()
{
    node *newnode = (node*)malloc(sizeof (node));
    printf("Enter value\n");
    scanf("%d",&(newnode->data));
    newnode->next = NULL;
    return newnode;
}
void createlist(int n)
{
    node *newnode;
    node *temp;

    for(int i = 0 ; i < n ; i++)
    {
        newnode = getNode();

        if(head == NULL)
        {
            head = newnode;
        }
        else
        { 
           temp = head;
           while( temp -> next != NULL )
           {
                 temp = temp->next;
           }
         temp->next = newnode;

        }
    }
}

void display()
{
    node *temp;

    if( head == NULL )
    {
        printf(" No data found in the list.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp -> data);  
            temp = temp -> next;                 
        }
    }
} 
void insert_beg()
{
    node *newnode;
    newnode = getNode();
    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode -> next = head;
        head = newnode;
    }
}
void insert_pos()
{
   node *temp,*newnode;
   int pos,i = 0;
    printf("Enter pos to insert node : \n");
   scanf( "%d" , &pos);

   temp = head;
   newnode = getNode();

   if(head == NULL)
   {
    head = newnode;
   }
else{
   while(i < pos - 1)
   {
    temp = temp->next;
    i=i+1;
   }

   newnode -> next = temp -> next;
   temp -> next = newnode;

  }
}

void insert_last()
{
    node* temp;
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    node *newnode = getNode();
    temp -> next = newnode;
} 

void delete_beg()
{
    node *temp = head;
    head = temp->next;
    free(temp);
    printf("node deleted\n");
}
void delete_pos()
{
    node *temp,*prev;
    prev = head;
    temp = head -> next;
    int pos, i = 0 ;
    scanf("%d" , &pos);
    if(head == NULL)
    {
        printf("No nodes present for deletion \n");
    }
    else
    {
        while(i < pos-1)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = temp -> next;
        free(temp);
    }
    printf("node deleted\n");
}

void delete_last()
{
    node *temp,*prev;
    temp = head;
    prev = head;
    if(head == NULL)
    {
        printf("list is empty");

    }
    else
{
    while(temp -> next  != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = NULL;
    free(temp);
}
    printf("node deleted\n");
}
