#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data; //Data of the node
  struct node *nextAdress; //Address of the next node 
}
*stnode;

void newNodeList(int n);//Function to create the list
void readNodeList();        //Function to display the list of nodes

int main()
{
    int n;
    printf("\n\n Welcome in Linked List: Create and display Singly Linked List: \n");
    printf("----------------------------\n");
    printf(" Please enter the number of nodes : ");
    scanf("%d",&n);
    newNodeList(n);
    printf("\n Data Entered in the List: \n");
    readNodeList();
    return 0;
}

void newNodeList(int n){
 struct node *fnNode, *temp;
 {
     /* data */
     int data, i;
     stnode = (struct node *)malloc(sizeof(struct node));
     if(stnode == NULL) //Check wheter the fnnode is NULL and if so no memory allocation
     {
         printf(" Memory can not be allocated.");  
     }
     else
     {
        //Reads data for the node through keyboard
        printf(" Input data for node 1 : ");
        scanf("%d", &data);     
        stnode->data=data; 
        stnode->nextAdress = NULL;// Links the address field to NULL
        temp = stnode; 
        //Creating n nodes and adding to linked list
        for(i=2;i<=data; i++) 
        {
            fnNode=(struct  node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &data);

                fnNode->data = data; //Links the num field of fnNode with data
                fnNode->nextAdress = NULL; //Links previous node i.e tmp to the fnNode
                temp->nextAdress = fnNode;
                temp = temp->nextAdress;
            }
        }
     }    
 }; 
}

 void readNodeList()
 {
    struct node *temp;
    if(stnode == NULL)
    {
        printf(" List is empty");
    }
    else
    {
        temp = stnode;
        while (temp !=NULL)
        {
            printf(" Data = %d\n", temp->data);//Print the data of current node
            temp = temp->nextAdress;//advances the position of current node
        }
        
    }
    
 }