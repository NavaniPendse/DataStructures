// program for inserting nodes at end of the link list

//create a link list with 5 diff values (12,22,30,44,50)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//create a node structure
struct node{
    int data;
    struct node *next;
    // *next is a node type of pointer as it is pointing to the next node
};


struct node *head=NULL;


void insertatbegin(int d){

    //create a node
    struct node *lk = (struct node*)malloc(sizeof(struct node));
    
    //put value into link
    lk->data=d;

    //point it to old first node
    lk->next=head;

    //point old first node to new first node
    head=lk;

}


void printList(){
    struct node *p=head;
    printf("\n[");
    
    //start form beginning
    while(p!= NULL){
        printf(" %d", p->data);
        printf(" ,%d,  ", p->next);
        p=p->next;
        
    }
    printf("]");

    
}

void printReverse(struct node* head)
{
    // Base case 
    if (head == NULL)
       return;
 
    // print the list after head node
    printReverse(head->next);
 
    // After everything else is printed, print head
    printf("%d  ", head->data);
    //printing memory locations
    printf("%d  ", head->next);
}


void main(){
    int k=0;

    //putting values into the link list
    insertatbegin(12);
    insertatbegin(22);
    insertatbegin(30);


    
    //printing the list in direct and reverse order
    
    //reverse
    printf("\nReverse Linked list is: \n [");
    printReverse(head);
    printf("]\n");

    //direct
    printf("\nLinked list is: ");
    printList();


}