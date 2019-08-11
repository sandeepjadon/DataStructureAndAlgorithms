#include<stdio.h>
#include<malloc.h>
int n,i;
struct node
{
	char SSN[20];
	char Name[20];
	char Dept[20];
	char Designation[20];
	int Sal;
	int PhoneNo;
	struct node *pre;
	struct node *next;
}*ptr,*p=NULL,*t,*h,*s;
Create()
{
	printf("How Many Nodes You Want To Create:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		printf("Enter %dth SSN: ",i+1);
		scanf("%s",&ptr->SSN);
		printf("Enter %dth Name:",i+1);
		scanf("%s",&ptr->Name);
		printf("Entger %dth Department:",i+1);
		scanf("%s",&ptr->Dept);
		printf("Enter %dth Designation:",i+1);
		scanf("%s",&ptr->Designation);
		printf("Enter %dth Salary:",i+1);
		scanf("%d",&(ptr->Sal));
		printf("Enter %dth Phone NO.",i+1);
		scanf("%d",&(ptr->PhoneNo));
		if(p==NULL)
		    t=ptr;
		else
	        p->next=ptr;
	    ptr->pre=p;
		p=ptr;	
	}
}
Show()
{
	if(n==0)
		printf("...................Empty List...................");
	else
	{
		ptr=t;
		for(i=0;i<n;i++)
		{
			printf("SSN=%s  ",ptr->SSN);
	    	printf("Name=%s  ",ptr->Name);
    		printf("Department=%s  ",ptr->Dept);
	    	printf("Designation=%s  ",ptr->Designation);
	    	printf("Salary=%d ",ptr->Sal);
	    	printf("PHONE No=%d  \n\n",ptr->PhoneNo);
     		ptr=ptr->next;
		}
	}
}
Add()
{
	int a;
	printf("Enter Node At Which You Want to Insert A New Employee Record (Node Started From Zero):\n");
	scanf("%d",&a);
	if(a<=n)
	{
		ptr=t;
		for(i=0;i<a-1;i++)
	    	ptr=ptr->next;
	    h=(struct node*)malloc(sizeof(struct node));
	    printf("Enter SSN: ");
		scanf("%s",&h->SSN);
		printf("Enter Name:");
		scanf("%s",&h->Name);
		printf("Enter Department:");
		scanf("%s",&h->Dept);
		printf("Enter Designation:");
		scanf("%s",&h->Designation);
		printf("Enter Salary:");
		scanf("%d",&(h->Sal));
		printf("Enter Phone NO.");
		scanf("%d",&(h->PhoneNo));
		if(a==0)
		{
			ptr->pre=h;
			h->next=ptr;
			t=h;
		}
		else
		{
			h->pre=ptr;
			h->next=ptr->next;
			ptr->next=h;
			if(a!=n)
			{
			p=h->next;
			p->pre=h;
	    	}
		}
	    n++;
	}
	  else
    	printf("..................Invalid Node At which You Want to Insert................... ");
}
Delete()
{
	int b;
	if(n==0)
		printf("....................Empty List.................");
	else
	{
		printf("Enter Node no. Which You Want To Delete started with Zero:\n");
    	scanf("%d",&b);
    	if(b<n)
    	{
    		ptr=t;
        	for(i=0;i<b-1;i++)
            	ptr=ptr->next;
	    	if(b==0)
    		{
	    		s=ptr;
    			if(n!=1)
	        	{	
    	    		ptr=ptr->next;
        			ptr->pre=NULL;
        			t=ptr;
         		}
     		}
     		else
     		{
     			s=ptr->next;
     			if(b==n-1)
        			ptr->next=NULL;
        		else
        		{
        		p=s->next;
     			ptr->next=p;
     			p->pre=ptr;
     		    }
			}
			free(s);
			n--;
        }
        else
        	printf("..................Invalid Node To Be Deleted.................");
	}
}
Count()
{
	printf("\nNo Of Employee In the Record=%d ",n);
}
main()
{
	int choice;
	char option;
	do{
		printf("Choose An Option from the Following:\n");
		printf("1:Create Employee Record:\n");
		printf("2:Show Employee Record:\n");
		printf("3:Add a Employee Record At Any Position:\n");
		printf("4:Delete a Employee Record:\n");
		printf("5:To Count NO. Of Employee In Record:\n");
	    scanf("%d",&choice);
    	switch(choice)
    	{
	    	case 1:Create();
		           break;
    		case 2:Show();
	    	       break;
    		case 3:Add();
	    	       break;
    	    case 4:Delete();
    	           break;
	        case 5:Count();
	               break;
    	    default: printf(".....................Invalid Choice.....................");
     	}
    printf("\n\nDo you Want to Continue (y/n): ");
   	scanf("%s",&option);
    } while(option=='y'||option=='Y');
}
