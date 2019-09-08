#include<stdio.h>
#define MAX 5
int n,i,rear=-1,front=-1;
int arr[MAX];
Create()
{
	printf("How many Elements You Want:");
	scanf("%d",&n);
	arr[n];
	printf("Enter Your Data Element:\n");
	for(i=0;i<n;i++)
	{
		if(i<MAX){
			rear=rear+1;
			scanf("%d",&arr[rear]);
			if(i==0)
				front=0;
		}
		else
			printf("Queue Is Full:");
	}
}
Display()
{
	if(rear==-1&&front==-1)
		printf("\nqueue Is empty:\n");
	else 
	{
		if(front>rear)
		{
			for(i=front;i<=MAX-1;i++)
 				printf("%d ",arr[i]);
			for(i=0;i<=rear;i++)
				printf("%d ",arr[i]);
		}
		else
		{
			for(i=front;i<=rear;i++)
				printf("%d ",arr[i]);
		}
	}
}
Enqueue()
{
	if(rear==MAX-1)
	{
		if(front!=0){
			rear=0;
			scanf("%d",&arr[rear]);
		}
		else
			printf("Queue Is full");
	}
	else if(rear==front-1)
		printf("Queue Is Full");
	else
	{
		if(rear==-1)
			front=0;
		rear=rear+1;
		scanf("%d",&arr[rear]);
	}
}
Dequeue()
{
	if(rear==-1)
		printf("Queue is Empty:\n");
	else
	{
		if(rear==front)
		{
			front=-1;
			rear=-1;
		}
		else if(front==MAX-1&&rear<front)
			front=0;
		else 
			front=front+1;
	}
}
main()
{
	int choice;
	char option;
	do{
		printf("Choose An Option from the following:\n");
    	printf("1:Create a Circular Queue With 'n' Elements:\n");
    	printf("2:Show Queue Elements:\n");
    	printf("3:For Enqueue:\n");
    	printf("4:For Dequeue:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:Create();
			       break;
			case 2:Display();
			       break;
			case 3:Enqueue();
				   break;
			case 4:Dequeue();
			       break;
  		}
	  	printf("\n\nDo you want to continue:");
		scanf("%s",&option);
 	}while(option=='y'||option=='Y');
}
