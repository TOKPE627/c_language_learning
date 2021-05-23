 //Deletion in a singly linked list of integers at end.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          // Data
    struct node *next; // Address 
}*head;

void createNodeList(int n);
void deleteLastNode();
void displayList();


int main()
{
    int n, choice;

    printf("Total number of nodes: ");
    scanf("%d", &n);
    createNodeList(n);

    printf("\nData in the list \n");
    displayList();

    printf("\nTo delete last node press 1: ");
    scanf("%d", &choice);

    if(choice == 1)
        deleteLastNode();

    printf("\nData in the list \n");
    displayList();

    return 0;
}


void createNodeList(int n)
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
        head->next = NULL; 

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

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("LIST CREATED SUCCESSFULLY\n");
    }
}


void deleteLastNode()
{
    struct node *elementToDelete, *lastNode;
    if(head == NULL)
    {
        printf("Empty list.");
    }
    else
    {
        elementToDelete = head;
        lastNode = head;

        while(elementToDelete->next != NULL)
        {
            lastNode = elementToDelete;
            elementToDelete = elementToDelete->next;
        }
        if(elementToDelete == head)
        {
            head = NULL;
        }
        else
        {
            lastNode->next = NULL;
        }
        free(elementToDelete);
        printf("LAST NODE DELETED SUCCESSFULLY\n");
    }
}

void displayList()
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
            temp = temp->next;                
        }
    }
}