#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insertAtHead(){

    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the node data : ");  
    scanf("%d",&item);  
    ptr -> data = item;
    ptr -> next = head;
    head = ptr;

}

void insertAtLast(){

    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the node data : ");  
    scanf("%d",&item);  
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

void randomInsert(){

    struct node *ptr, *temp;
    int item, loc;
    ptr = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the node data : ");  
    scanf("%d",&item);  
    ptr -> data = item;

    printf("\nEnter the location after which you want to insert ");  
    scanf("\n%d",&loc);  
    temp = head;  

    for(int i=0; i<loc; i++){
        temp = temp -> next;
        if(temp == NULL){
            printf("can't insert\n");
            return;
        }
    }
    ptr -> next = temp -> next;
    temp -> next = ptr;
    printf("\nNode inserted");
}

void deleteFromHead(){
    struct node *ptr;
    
    if(head == NULL){
        printf("List is empty");
    }
    else{
        ptr = head;
        head = ptr -> next;
        free(ptr);
    }
}

void deleteFromEnd(){
    struct node *ptr, *prevptr;
    if(head == NULL){
        printf("List is empty");
    }
    else if(head -> next == NULL){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr -> next != NULL){
            prevptr = ptr;
            ptr = ptr -> next;
        }
        prevptr -> next = NULL;
        free(ptr);
    }
}

void deleteRandom(){
    struct node *ptr, *prevptr;
    int loc;
    printf("\nEnter location of the node to be deleted : ");
    scanf("%d",&loc);
    
    ptr = head;
    for(int i=0; i<loc; i++){
        prevptr = ptr;
        ptr = ptr -> next;

        if(ptr == NULL){
            printf("Can't delete");
            return;
        }
    }
    prevptr -> next = ptr -> next;
    free(ptr);
}

void search(){
    struct node *ptr;
    int item, i=0, flag;
    ptr = head;
    
    printf("Enter item which you want to search : ");
    scanf("%d",&item);

    while(ptr != NULL){
        if(ptr -> data == item){
            printf("item found at ;oc %d", i+1);
            flag = 0;
        }
        else{
            flag = 1;
        }
        i++;
        ptr = ptr -> next;
    }
    if(flag == 1){
        printf("item not found");
    }
}

void display(){
    struct node *ptr;
    ptr = head;

    if(ptr == NULL){
        printf("\nnothing to print");  
    }
    while(ptr != NULL){
        printf("%d -> ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("NULL");
}



int main(){

    insertAtHead();
    insertAtHead();
    insertAtHead();
    insertAtHead();

    insertAtLast();
    insertAtLast();
    insertAtLast();

    // randomInsert();

    display();

    deleteFromHead();
    deleteFromEnd();
    deleteRandom();

    display();


    return 0;
}
