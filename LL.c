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
    ptr = (struct node*) malloc(sizeof(struct node*));
    
    if(ptr == NULL)
        printf("\nOverflow");
    
    else{
        printf("enter values : ");
        scanf("%d", &item);
        ptr -> data = item;
        ptr -> next = head;
        head = ptr;
    }
}

void insertAtLast(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*) malloc(sizeof(struct node));
    
    if(ptr == NULL){
        printf("Overflow");
    }
    else{
        printf("Enter Value : ");
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
}

void randomInsert(){
    struct node *ptr, *temp;
    int item, loc;
    ptr = (struct node*) malloc(sizeof(struct node));
    
    if(ptr == NULL)
        printf("Overflow");
        
    else{
        printf("Enter Value : ");
        scanf("%d", &item);
        ptr -> data = item;
        
        printf("enter the location : ");
        scanf("%d", &loc);
        temp = head;
        
        for(int i=0; i<loc; i++){
            temp = temp -> next;
            if(temp == NULL){
                printf("can't insert");
                return;
            }
            ptr -> next = temp -> next;
            temp -> next = ptr;
        }    
    }
}

void deleteFromHead(){
    struct node *ptr;
    
    if(ptr == NULL)
        printf("underflow");
        
    else{
        ptr = head;
        head = ptr -> next;
        free(ptr);
    }
}

void deleteFromLast(){
    struct node *ptr, *ptr1;
    
    if(ptr == NULL)
        printf("underflow");
        
    else if(head -> next == NULL){
        head = NULL;
        free(head);
    }
    else{
        ptr = head;
        while(ptr -> next != NULL){
            ptr1 = ptr;
            ptr = ptr -> next;
        }
        ptr1 -> next = NULL;
        free(ptr);
    }
}

void randomDelete(){
    struct node *ptr, *ptr1;
    int loc, i;
        
    printf("enter the location : ");
    scanf("%d", &loc);
    ptr = head;
        
    for(i=0; i<loc; i++){
        ptr1 = ptr;
        ptr = ptr -> next;
        
        if(ptr == NULL){
            printf("can't delete");
            return;
        }
    }
    ptr1 -> next = ptr -> next;
    free(ptr);
    printf("deleted node %d", loc+1);
}


void display(){
    struct node *ptr;
    ptr = head;
    
    if(ptr == NULL)
        printf("Nothing to print");
    
    else{
        while(ptr != NULL){
            printf("%d -> ", ptr -> data);
            ptr = ptr -> next;
        }
    }
}

int main(){

    //insertAtHead();
    //insertAtHead();
    //display();
   
    printf("\n1. insert at head\n2. insert at Last\n3. Random insert\n4. delete from head\n5. delete from end\n6. random Delete\n7. display\n8. exit\n");
    
    
    int choice;
    while(choice != 8){
    
        
        printf("enter choice : ");
        scanf("%d", &choice);
       
        switch(choice){
            case 1 :
                insertAtHead();
                break;
            case 2 :
                insertAtLast();
                break;
            case 3 :
                randomInsert();
                break;
            case 4 :
                deleteFromHead();
                break;
            case 5 :
                deleteFromLast();
                break;
            case 6 :
                randomDelete();
                break;
            case 7 :
                display();
                break;
            case 8 :
                exit(0);
                break;
            default:
                printf("Enter valid choice");
        }
    }
}














