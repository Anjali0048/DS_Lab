#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insertAtHead(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the node data : ");  
    scanf("%d",&item);  

    ptr -> data = item;
    if(head == NULL){
        head = ptr;
        ptr -> next = head;
    }
    else{
        temp = head;
        while(temp -> next != head){
            temp  = temp -> next;
        }
        ptr -> next = head;
        temp -> next = ptr;
        head = ptr;
    }

}

void insertAtLast(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the node data : ");  
    scanf("%d",&item);  

    ptr -> data = item;

    if(head == NULL){
        head = ptr;
        ptr -> next = head;
    }
    else{
        temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = ptr;
        ptr -> next = head;
    }
}

void deleteFromHead(){
    struct node *ptr;
    
    if(head == NULL){
        printf("underflow");
    }
    else if(head -> next == head){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr -> next != head){
            ptr = ptr -> next;
        }
        ptr -> next = head -> next;
        free(head);
        head = ptr -> next;
    }
}

void deleteFromLast(){
    struct node *ptr, *preptr;

    if(head == NULL){
        printf("underflow");
    }
    else if(head -> next == head){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr -> next != head){
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
    }
}

void search(){
    struct node *ptr;
    int item, i=0, flag=1;
    ptr = head;
    
    printf("\nEnter the item to search : ");  
    scanf("%d",&item);

    if(head -> data == item){
        printf("item found at location %d ",i+1);
        flag = 0;
    }
    else{
        while(ptr -> next != head){
            if(ptr -> data == item){
                printf("item found at location %d ",i+1);
                flag = 0;
                break;
            }
            else{
                flag = 1;
            }
            i++;
            ptr = ptr -> next;
        }
    }
    if(flag != 0){
        printf("Item not found");
    }
}

void display(){
    struct node *ptr;
    ptr = head;
    
    if(head == NULL){
        printf("\nnothing to print");  
    }
    else{
        printf("\n printing values ... \n");  
        while(ptr -> next != head){
            printf("%d -> ", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d", ptr -> data);

    }
}


int main(){

    insertAtHead();
    insertAtHead();

    insertAtLast();
    insertAtLast();
    insertAtLast();

    deleteFromHead();
    deleteFromLast();

    display();

    search();
    return 0;
}