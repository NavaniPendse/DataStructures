//program for creation of stack & push and pop functions
#include<stdio.h>
#include <stdlib.h>
#define MAX 10

int count=0;

struct stack{
    int item[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s){
    s->top=-1;
}

int isFull(st *s){
    if(s->top==MAX-1)
        return 1;
    else
        return 0;
}

//check if stack is empty
int isEmpty(st *s){
    if(s->top==-1)
        return 1;
    else
        return 0;
}

void push(st *s, int newitem){
    if (isFull(s)){
        printf("Stack Full\n");
    }
    else{
        s->top++;
        s->item[s->top]=newitem;
    }
    count++;
}

void pop(st *s){
    if(isEmpty(s)){
        printf("\nStack Empty\n");
    }
    else{
        printf("Item popped=%d",s->item[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}

void printStack(st *s){
    printf("Stack: ");
    for(int i=0;i<count;i++){
        printf(" [%d]",s->item[i]);
    }
    printf("\n");
}

void search(st *s){
    int key=0;
    int i=0;
    int flag=0;
    printf("Enter data to find: ");
    scanf("%d", &key);
    //for(i=0;i<count;i++){
        // if(s->item[i]==key){
        //     flag=1;
        // }
    //}
    while(s->item[i]!=key){
        i++;
    }

    //if(flag==1){
        printf("%d value found at %d position\n", key, i);
    //}
    // else{
    //     printf("Value not found");
    // }
}

int main(){
    st *s =(st *)malloc(sizeof(st));
    createEmptyStack(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    printStack(s);
    search(s);
    pop(s);
    pop(s);
    printf("\nAfter popping out\n");
    printStack(s);
}