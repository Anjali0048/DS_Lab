#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

//int stack
int stack_int[25]; 
int top_int = -1; 

void push_int(int item) {
   stack_int[++top_int] = item; 
} 

char pop_int() {
   return stack_int[top_int--]; 
} 

//evaluates postfix expression
int evaluate(char postfix[]){

   char ch;
   int i = 0,operand1,operand2;

   while( (ch = postfix[i++]) != '\0') {
	
      if(isdigit(ch)) {
	     push_int(ch-'0');  // Push the operand 
      } 
      else {
         //Operator,pop two  operands 
         operand2 = pop_int();
         operand1 = pop_int();
			
         switch(ch) {
            case '+':
               push_int(operand1+operand2);
               break;
            case '-':
               push_int(operand1-operand2);
               break;
            case '*':
               push_int(operand1*operand2);
               break;
            case '/':
               push_int(operand1/operand2);
               break;
         }
      }
   }
	
   return stack_int[top_int];
}

void main() { 
   char postfix[] = "100 200 + 2 / 5 * 7 +";
   printf("Evaluated expression is: %d\n" , evaluate(postfix));
} 