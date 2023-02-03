#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;

void insertAtHead(){
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value : ");
    scanf("%d",&item);

    if(head == NULL){
        ptr -> next = NULL;
        ptr -> prev = NULL;
        ptr -> data = item;
        head = ptr;
    }
    else{
        ptr -> data = item;
        ptr -> prev = NULL;
        ptr -> next = head;
        head = ptr;
    }
}

void insertAtLast(){

    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value : ");
    scanf("%d",&item);

    ptr -> data = item;

    if(head == NULL){
        ptr -> next = NULL;
        ptr -> prev = NULL;
        head = ptr;
    }
    else{
        temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = ptr;
        ptr -> prev = temp;
        ptr -> next = NULL;
    }
}

void insertAtIndex(){

    struct node *ptr, *temp;
    int item, loc;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the value : ");
    scanf("%d",&item);

    printf("Enter the location");
    scanf("%d", &loc);

    temp = head;
    for(int i=0; i<loc; i++){
        temp = temp -> next;
        if(temp == NULL){
            printf("Can't insert");
            return;
        }
        ptr -> data = item;
        ptr -> next = temp -> next;
        ptr -> prev = temp;
        temp -> next = ptr;
        temp -> next -> prev = ptr;
    }
}

void deleteFromHead(){
    struct node *ptr;

    if(head == NULL){
        printf("underflow");
    }
    else if(head -> next == NULL){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
    }
}

void deleteFromLast(){
    struct node *ptr;
    if(head == NULL){
        printf("Underflow");
    }
    else if(head -> next == NULL){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr -> next != NULL){
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
    }
}

void deleteSpecified(){

    struct node *ptr, *temp;
    int val;
    printf("\nEnter data after which the node is to be deleted ");
    scanf("%d",&val);

    ptr = head;
    while(ptr -> data != val){
        ptr = ptr -> next;
        if(ptr -> next == NULL){
            printf("can't delete\n");
        }
        else if(ptr -> next -> next == NULL){
            ptr -> next = NULL;
        }
        else{
            temp = ptr -> next;
            ptr -> next = temp -> next;
            temp -> next -> prev = ptr;
            free(temp);
        }
    }
}

void display(){
    struct node *ptr;
    printf("\nPrinting values\n");
    ptr = head;
    while(ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
}

int main(){

    insertAtHead();
    insertAtHead();
    insertAtHead();
    insertAtHead();
    insertAtHead();

    return 0;
}