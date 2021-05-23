//Deletion in a singly linked list of integers at beginning.

#include <stdio.h>
#include <stdlib.h>
struct  node {
    int data;   //Data
    struct node*next; //Address
}* head;

void createList(int n);
void deleteFirstNode();
void displayList();

int main()
{
    int n, choice;
    /*
      Create a singly linked list of n nodes
    */
    printf("Total number of nodes? ");
    scanf("%d", &n);
    createList(n);

    printf("\n Data in the list \n");
    displayList();

    printf("\nTo delete first node press 1: ");
    scanf("%d", &choice);

    //Delete first node from list
    if(choice == 1) {
        deleteFirstNode();

        printf("\nFinal Data in the list \n");

        displayList();

        return 0;
    }
}
/*
   Create a list of n nodes
*/
void createList(int n)
{
    struct  node *newNode, * temp;
    int data, i;
    head=(struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL){
                printf("Unable to allocate memory.");
                break;
            }
            else 
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                
                newNode->data=data;
                newNode->next = NULL;

                temp->next=newNode;
                temp=temp->next;
            }
        }
        printf("LIST CREATED SUCCESSFULLY\n");
    }
}

void deleteFirstNode()
{
    struct node *toDelete;
    if(head == NULL)
    {
        printf("Empty List.");
    }
    else
    {
        toDelete = head;
        head =head->next;

        printf("\nData deleted = %d\n", toDelete->data);
        free(toDelete);
        printf("FIRST NODE FROM LIST DELETED SUCCESSFULLY\n");
    }
}

void displayList()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;
        }
    }
}
