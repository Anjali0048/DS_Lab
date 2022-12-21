#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
int stack[MAX],opp1,opp2,top=-1;
void push(int x)
	{   
		top++;
		stack[top]=x;
	}
int pop()
	{   
	    char c;
	    c=stack[top];
	    top=top-1;
	    printf("%c",c);
	}
int prefixeval()
{ 
    int len;
	char prefix[20];
	int res,i;
	gets(prefix);
	len=strlen(prefix);
	for(i=len-1;prefix[i]>=0;i--)
	{
		if(isdigit(prefix[i]))
		{
		 push(prefix[i]-48);
		}
		else
		{
		opp1=pop();
		opp2=pop();
		switch(prefix[i])
		{
			case '+':push(opp1+opp2);
			         break;
			case '-':push(opp1-opp2);
			         break;
		    case '*':push(opp1*opp2);
			         break;
			case '/':push(opp1/opp2);
			         break;
			case '^':res=pow(opp1,opp2);
			         push(res);
			         break;
		}
		
	   }
   }   
	printf("result is %d",pop());
}
int main()
{   
    char prefix[20];
	printf("enter string : ");
	scanf("%s",prefix);
	prefixeval(prefix);
	
}