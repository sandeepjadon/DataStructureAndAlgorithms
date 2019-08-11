#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 100
int stack[SIZE];
char suffix[SIZE];
int top=-1,c3;
Pop()
{
	int c=stack[top];
	top--;
	return(c);	
}
Push(int c)
{
	top++;
	stack[top]=c;
}
Calculation()
{
	int i;
	for(i=0;suffix[i]!='\0';i++)
	{
		if(suffix[i]=='+'||suffix[i]=='-'||suffix[i]=='*'||suffix[i]=='/'||suffix[i]=='%'||suffix[i]=='^')
		{
			int c1,c2;
			c1=Pop();
			c2=Pop();
			if(suffix[i]=='+')
				c3=c2+c1;
			if(suffix[i]=='-')
				c3=c2-c1;
			if(suffix[i]=='*')
				c3=c2*c1;
			if(suffix[i]=='/')
				c3=c2/c1;
			if(suffix[i]=='%')
				c3=c2%c1;
			if(suffix[i]=='^')
				c3=pow(c2,c1);
			Push(c3);
		}
		else
			Push(suffix[i]-'0');
	}
}
main()
{
	printf("Enter Your Suffix Expression:(+,-,*,/,^,%)\n");
	gets(suffix);
	Calculation();
	printf("Evaluation Of Expression:\n");
	printf("%d ",c3);
}
