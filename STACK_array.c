#include<stdio.h>
#define MAX 10
int arr[MAX];
int n,top=-1,i;
Create()
{
	printf("How Many Element You Want To insert");
	scanf("%d",&n);
	printf("Enter Your Stack Elements:");
	for(i=0;i<n;i++)
	{
		if(top==-1)
		{
			printf("\nStack Under Flow:");
			scanf("%d",&arr[i]);
			top=top+1;
		}
		else if(top==MAX-1)
		    printf("\nStack OverFlow:");
		else
		{
			scanf("%d",&arr[i]);
			top=top+1;
		}	
	}
}
Show()
{
	if(top==-1)
	   printf("\nStack Under Flow:\n");
	for(i=0;i<n;i++)
	   printf("%d  ",arr[i]);
}
Push()
{
	if(top==MAX-1)
	    printf("\nStack Over Flow:");
	else
	{
		printf("Enter your Element you want to insert:");
		top=top+1;
		scanf("%d",arr[top]);
		n++;
	}
}
Pop()
{
	if(top==-1)
	   printf("\nStack Under Flow:\n");
	else
	{
		top=top-1;
		n--;
	}
}
Palindrom()
{
	int a,b=0;
	if(top==-1)
	     printf("Stack Under Flow:");
	else
	{
		a=n/2;
		for(i=0;i<a;i++)
		{
			if(arr[i]!=arr[n-i-1])
			   b++;
		}
		if(b==0)
		{
			printf("Entered Stack is A palindrom:\n");
		}
		else
		    printf("Stack is not Palindrom:\n");
	}
	    
}
main()
{
	int choice;
	char option;
	do{
    	printf("Choose An option from the following:\n");
    	printf("1:Create a Stack:\n");
    	printf("2:Show Stack Elements:\n");
    	printf("3:Push an Element:\n");
    	printf("4:Pop Up an Element:\n");
    	printf("5:Check Stack Elements Are Palindrom or Not:\n");
    	scanf("%d",&choice);
    	switch(choice)
    	{
	        case 1:Create();
	               break;
        	case 2:Show();
        	       break;
        	case 3:Push();
        	       break;
        	case 4:Pop();
			       break;
		    case 5:Palindrom();
			       break;	
        }
        printf("\nAre you Want To continue:(y/n)");
        scanf("%s",&option);
    }while(option=='y'||option=='Y');
}
