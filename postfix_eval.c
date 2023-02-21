// postfix evaluation

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define ss 30
int stack[ss];
int top=-1,ans=0;
void push(int ele)
{
    if(top==ss-1)
    {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top]=ele;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return 0;
    }
    return(stack[top--]);
}

void main()
{
    char postfix[25],ele;
    int i=0,num1,num2;
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    printf("Postfix expression is %s\n",postfix);
    while(postfix[i]!='\0')
    {
        ele=postfix[i];
        if(isdigit(ele))
        {
            push(ele-'0');
        }
        else
        {
            num1=pop();
            num2=pop();
            switch(ele)
            {
                case '$':
                ans=pow(num2,num1);
                break;
                case '/':
                ans=num2/num1;
                break;
                case '*':
                ans=num2*num1;
                break;
                case '-':
                ans=num2-num1;
                break;
                case '+':
                ans=num2+num1;
                break;
            }
            push(ans);
        }
        i++;
    }
    printf("Answer=%d\n",pop());
}