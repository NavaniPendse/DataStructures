#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * front=NULL;
struct node * rear=NULL;

void enqueue(int value){
    struct node * ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    if((front==NULL)&&(rear==NULL)){
        front=rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    printf("Node is inserted\n");
}

void dequeue(){
    if(front==NULL){
        printf("\nUnderflow\n");
    }
    else{
        struct node * temp=front;
        int temp_data = front->data;
        front=front->next;
        free(temp);
        return temp_data;
    }
}

void display(){
    struct node * temp;
    if((front==NULL)&&(rear==NULL)){
        printf("Empty Queue");
    }
        else{
            printf("The queue is \n");
            temp=front;
            while(temp){
                printf("%d-->",temp->data);
                temp=temp->next;
            }
            printf("NULL\n");
        }
    
}

int main(){
    int choice, value;
    printf("\n Implementation of stack using linked list:\n");
    while(choice!=4){
        printf("1 - enqueue\n2 - dequeue\n3 - display\n4 - exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
            printf("\nEnter value:\n");
            scanf("%d", &value);
            enqueue(value);
            break;
            case 2:
            printf("Popped element is %d\n", dequeue());
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Error");
        }
    }
}

