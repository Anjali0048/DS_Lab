#include<stdio.h>
#include<string.h>
int stack[30],top=-1;

void push(int ele)
{
	top++;
	stack[top]=ele;
}

int pop()
{
	int ele;
	ele=stack[top];
	top--;
	return(ele);
}

int main()
{
	char prefix[30];
	int a,b,c,i;

	printf("Enter the prefix expression \n");
	scanf("%s",prefix);

	for(i=strlen(prefix)-1;i>=0;i--)
	{
		if(prefix[i]=='+')
		{
			c=pop()+pop();
			push(c);
		}
		else if(prefix[i]=='-')
		{
			a=pop();
			b=pop();
			c=a-b;
			push(c);
		}
		else if(prefix[i]=='*')
		{	
			a=pop();
		    b=pop();
		    c=b*a;
	    	push(c);
		}
		else if(prefix[i]=='/')
		{
			a=pop();
			b=pop();
			c=a/b;
			push(c);
		}
		else
		{
			push(prefix[i]-48);
		}
	}
	printf("ans = %d",pop());
	return 0;
}