#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void push(){
    int data;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value : ");
    scanf("%d",&data);

    if(head == NULL){
        ptr -> data = data;
        ptr -> next = NULL;
        head = ptr;
    }
    else{
        ptr -> data = data;
        ptr -> next = head;
        head = ptr;
    }
}

void pop(){
    int item;
    struct node *ptr;
    if(head == NULL){
        printf("Underflow");
    }
    else{
        item = head -> data;
        ptr = head;
        head = head -> next;
        free(ptr);
    }
}

void display(){
    struct node *ptr;
    ptr = head;

    if(ptr == NULL){
        printf("Stack is empty");
    }
    else{
        printf("printing stack elements\n");
        while(ptr != NULL){
            printf("%d -> ",ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main(){
    push();
    push();
    push();
    push();

    pop();
    display();

    return 0;
}