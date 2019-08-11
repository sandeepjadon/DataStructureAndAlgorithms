#include<stdio.h>
#include<malloc.h>
int i,n;
struct node
{
	int data;
	struct node *link;
}*p=NULL,*ptr,*top=NULL,*h;
Create()
{
	printf("How Many Element You Want To insert");
	scanf("%d",&n);
    printf("Enter Your Stack Elements:");
    for(i=0;i<n;i++)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&ptr->data);
        if(top==NULL)
		    p=ptr;		
		else
			top->link=ptr;
		top=ptr;   
    }
}
Show()
{
	if(p==NULL)
		printf("Stack Under Flow");
	else{
		ptr=p;
		printf("\nYour Entered Stack:\n");
		for(i=0;i<n;i++)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
    }
}
Push()
{
	h=(struct node*)malloc(sizeof(struct node));
	printf("Enter Your Element Which you Want to Push:\n");
	scanf("%d",&h->data);
	if(top==NULL)
	{
		p=h;
		top=p;
	}
	else
	{
		top->link=h;
		top=h;
	}
	n++;
}
Pop()
{
	
	if(top==NULL)
	   printf("\nStack Under Flow");
	else if(n==1)
	{
		h=p;
		p=NULL;
	}
	else
	{
		ptr=p;
		h=top;
		for(i=0;i<n-1;i++)
			ptr=ptr->link;
		top=ptr;
		free(h);
	   	n--;
    }
}
main()
{
	int choice;
	char option;
	do{
    	printf("Choose An option from the following:\n");
    	printf("1:Create a Stack using Linked List:\n");
    	printf("2:Show Stack Elements:\n");
    	printf("3:Push a Element to Stack:\n");
    	printf("4:Pop up a Element From Stack\n");
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
        }
        printf("\n\nDo you Want To continue:(y/n)");
        scanf("%s",&option);
    }while(option=='y'||option=='Y');
}
