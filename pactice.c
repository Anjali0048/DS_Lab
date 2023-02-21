#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;;

void insertAtHead() {

    int item;
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node data : ");
    scanf("%d", &item);
    ptr -> data = item;
    ptr -> next = head;
    head = ptr;
}

void insertAtLast() {

    int item;
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node data : ");
    scanf("%d", &item);
    ptr -> data = item;

    if(head == NULL){
        ptr -> next = NULL;
        head = ptr;
    }
    else{
        temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = ptr;
        ptr -> next = NULL;
    }
}

void randomInsert() {
    
}