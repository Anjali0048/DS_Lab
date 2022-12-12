#include<stdio.h>
#include<string.h>

//char stack
char stack[25];
int top=-1;

//push elements in the stack
void push(char item){
    stack[++top] = item;
}

char pop(){
    return stack[top--];
}

char precedence(char ch){

    switch(ch){
        
        case '+' :
        case '-' :
            return 2;
            break;
            
        case '/' :
        case '*' :
            return 3;
            break;
            
        case '^' :
            return 4;
            break;
            
        case '(':
        case ')':
        case '#':
            return 1;
            break;
            
        default :
            return 0;        
    }
}



int isOperator(char symbol){

    switch(symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 1;
            break;
        
        default:
            return 0;
            
    }
}



void convert(char infix[], char prefix[]){

    int i, symbol, j=0;
    stack[++top] = '#';
    
    for(i=0; i<strlen(infix); i++){
        symbol = infix[i];
        
        if(isOperator(symbol)==0){
            prefix[j] = symbol;
            j++;
        }
        else{
            if(symbol==')'){
                push(symbol);
            }
            else{
                if(symbol == '(' ){
                    while(stack[top] != ')' ){
                        prefix[j] = pop();
                        j++;
                    }
                    pop();
                }
                else{
                    if(precedence(symbol) >= precedence(stack[top])){
                        push(symbol);
                    }
                    else{
                        while(precedence(symbol) <= precedence(stack[top])){
                            prefix[j] = pop();
                            j++;
                        }  
                        push(symbol);                     
                    }
                }
            }
        }
    }
    
    while(stack[top] != '#'){
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
   
}

void reverse(char infix[]){
    int i=0, j=strlen(infix)-1;
    while(i<=j){
        int temp = infix[i];
        infix[i] = infix[j];
        infix[j] = temp;
        i++;
        j--;
    }
    
}



int main(){
    char prefix[25];
    char infix[] =  "(a+b)/c+d";
    printf("given infix expression is : %s\n", infix);
    reverse(infix);
    convert(infix,prefix);
    reverse(prefix);
    printf("prefix exp is : %s\n", prefix);  
}
























