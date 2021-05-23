#include<stdio.h>  
#include<stdlib.h> 

struct node{
    int data;
    struct node *link;
};

int main() {
    struct node *head=NULL;
    head = malloc(sizeof(struct node));
    head->data=45;
    head->link = NULL;

    /*head = malloc(sizeof(struct node));
    head->data=98;
    head->link=NULL;*/

    /*
    METHOD 1
    struct node *current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    struct node *current2= malloc(sizeof(struct node));
    current2->data=3;
    current2->link=NULL;
    current->link=current2;

    printf("%d \n",head->data);
    printf("%d \n",current->data);
    printf("%d",current2->data);*/

    struct node *current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link=current;

    current = malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link = current;

    /*printf("%d\n",head);
    printf("%d \n",head->data);
    printf("%d\n",current);
    printf("%d\n",current->data);
    printf("%d\n", head->link);
    printf("%d\n",current->data);*/

    //count_of_nodes(head);
    
    int count = 0;
    if(head == NULL)
       printf("Linked List is empty");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr !=NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d",count);
    return 0;
}

count_of_nodes(struct node *head){
    int count = 0;
    if(head == NULL)
       printf("Linked List is empty");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr !=NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("%d",count);
}




