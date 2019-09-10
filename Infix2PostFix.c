#include<stdio.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
char postfix[SIZE];
int top=-1,j=0;
Pop()
{
	if(stack[top]!='(')
	{
    	postfix[j]=stack[top];
    	j++;
    }
	top--;	
}
Push(char c)
{
	++top;
	stack[top]=c;
}
Check(char c)
{
	if(c=='^')
		Push(c);
	else if(c=='*'||c=='/'||c=='%')
	{
		if(stack[top]=='^'||stack[top]=='*'||stack[top]=='/'||stack[top]=='%'&&stack[top]!='(')
		{
			while(top!=-1)
	    	{
	    		Pop();
	    		if(stack[top]=='(')
	    			break;
	    	}
	    	Push(c);
		}
		else
	    	Push(c);
	}
	else if(c=='+'||c=='-')
	{
		if(stack[top]!='(')
		{
     		while(top!=-1)
	    	{
     			Pop();
     			if(stack[top]=='(')
     				break;
    		}
    		Push(c);
	    }
	    else
	    	Push(c);
	}
	else if(c=='(')
		Push(c);
	else if(c==')')
	{
		while(stack[top]!='(')
			Pop();
		top--;
	}
}
InfixToPost(char infix_exp[])
{
	int i;
	for(i=0;infix_exp[i]!='\0';i++)
	{
		if(infix_exp[i]=='+'||infix_exp[i]=='-'||infix_exp[i]=='*'||infix_exp[i]=='/'||infix_exp[i]=='%'||infix_exp[i]=='^'||infix_exp[i]=='('||infix_exp[i]==')')
			Check(infix_exp[i]);
		else
		{
			postfix[j]=infix_exp[i];
			j++;
		}
	}
	while(top!=-1)
		Pop();
	postfix[j]='\0';
}
main()
{
	char infix[SIZE];
	printf("Enter your Infix Expression:\n");
	gets(infix);
	InfixToPost(infix);
	printf("Your Postfix Expression is:\n");
	puts(postfix); 	
}
