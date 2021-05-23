#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;          
    struct node *nextAdress; 
}*head;

void newList(int n);
void newNodeAtBeginning(int data);
void readList();
int main()
{
    int n, data;
    printf("Please Enter the total number of nodes: ");
    scanf("%d", &n);
    newList(n);

    printf("\nData in the list \n");
    readList();

    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    newNodeAtBeginning(data);

    printf("\nData in the list \n");
    readList();

    return 0;
}

void newList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
      
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->nextAdress = NULL; 

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->nextAdress = NULL; 

                temp->nextAdress = newNode; 
                
                temp = temp->nextAdress; 
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void newNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->nextAdress = head; 

        head = newNode;          

        printf("THE DATA IS INSERTED SUCCESSFULLY IN THE NODE\n");
    }
}


void readList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->nextAdress;                 
        }
    }
}