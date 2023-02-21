#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x){
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = x;
    ptr -> next = NULL;

    if(rear == NULL){
        front = rear = ptr;
        rear -> next = front;
    }
    else{
        rear -> next = ptr;
        rear = ptr;
        rear -> next = front;
    }
}

void dequeue() {
    struct node *ptr = front;
    if(front == NULL && rear == NULL){
        printf("underflow");
    }
    else if(front == rear){
        front = rear = NULL;
        free(ptr);
    }
    else{
        front = front -> next;
        rear -> next = front;
        free(ptr);
    }
}

int peek() {
    if(front == NULL && rear == NULL){
        printf("Empty Queue");
    }
    else{
        printf("the front ele is %d", front->data);
    }
}

void display() {
    struct node *ptr = front;
    if(front == NULL && rear == NULL){
        printf("Empty Queue");
    }
    else{
        while(ptr -> next != front){
            printf("%d ->", ptr->data);
            ptr = ptr->next;
        }
    }
}
