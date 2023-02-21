#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 10

int stack[SIZE];
int top = -1;

void push(int value){
    if(top == SIZE-1){
        printf("overflow");
    }
    else{
        stack[++top] = value;
    }
}

void pop(){
    if(top == -1){
        printf("underflow");
    }
    else{
        printf("deleted ele : %d", stack[top--]);
    }
}

void display(){
    if(top == -1){
        printf("stack is empty");
    }
    else{
        printf("stack element : ");
        for(int i=0; i<=top; i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

int main(){

    int value, choice;
    printf("******* MENU ********\n");
    while(1){
        printf("1. push\n2. pop\n3. Display\n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        int n;
        switch(choice){
            case 1:
                printf("enter no. of elements : ");
                scanf("%d", &n);
                printf("enter the values to be inserted : ");
                for(int i=0; i<n; i++){
                    scanf("%d",&value);
                    push(value);
                }
                printf("Instruction success !!!\n");
                break;
            
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("try again");
        }
    }
}