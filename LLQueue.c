#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front;
struct node *rear;

void insert(){
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("enter value : ");
    scanf("%d",&item);
    ptr -> data = item;

    if(front == NULL){
        front = ptr;
        rear = ptr;
        front -> next = NULL;
        rear -> next = NULL;
    }
    else{
        rear -> next = ptr;
        rear = ptr;
        rear -> next = NULL;
    }
}

void delete(){
    struct node *ptr;
    
    if(front == NULL){
        printf("Underflow");
        return;
    }
    else{
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}

void display(){
    struct node *ptr;
    ptr = front;
    if(front == NULL){
        printf("Empty queue");
    }
    else{
        printf("Printing values\n");
        while(ptr != NULL){
            printf("%d -> ", ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main(){

    insert();
    insert();
    insert();
    insert();

    delete();
    display();


    return 0;
}