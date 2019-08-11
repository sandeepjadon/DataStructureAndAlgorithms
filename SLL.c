#include<stdio.h>
#include<string.h>
#include<malloc.h>
int i,choice,n,sem,ph,a,b;
char option;
char name[20];
char usn[20];
char br[20];
struct node{
	char USN[20];
	char Name[20];
	char Branch[20];
	int Sem;
	int PhoneNo;
	struct node* link;
}*h,*ptr,*p=NULL,*t;                    
Create()
{
	printf("How many Student Record You Want:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		ptr=(struct node*)malloc(sizeof(struct node));
		if(p==NULL)
		    ptr->link=NULL;
		else
		    ptr->link=p;
		printf("Enter %dth Student USN:",n-i);
		scanf("%s",&usn);
		strcpy(ptr->USN,usn);
		printf("Enter %dth Student Name:",n-i);
		scanf("%s",&name);
		strcpy(ptr->Name,name);
		printf("Enter %dth Student's Branch:",n-i);
		scanf("%s",&br);
		strcpy(ptr->Branch,br);
		printf("Enter %dth Student's Sem:",n-i);
		scanf("%d",&sem);
		ptr->Sem=sem;
		printf("Enter %dth Phone No.",n-i);
		scanf("%d",&ph);
		ptr->PhoneNo=ph;
		p=ptr;
	}
}
Show()
{
	if(n==0)
		printf("...................Empty List...................");
	else
	{
		ptr=p;
	    for(i=0;i<n;i++)
	    {
	    	printf("USN=%s  ",ptr->USN);
	    	printf("Name=%s  ",ptr->Name);
    		printf("Branch=%s  ",ptr->Branch);
	    	printf("Sem=%d  ",ptr->Sem);
	    	printf("PHONE No=%d  \n\n",ptr->PhoneNo);
     		ptr=ptr->link;
    	}
        ptr=p;
    }
}
Add()
{
	printf("Enter Node At Which You Want to Insert A New Student Record (Node Started From Zero):\n");
	scanf("%d",&a);
	if(a<=n)
	{
    	for(i=0;i<a-1;i++)
	    	ptr=ptr->link;
	    h=(struct node*)malloc(sizeof(struct node));
     	printf("Enter Student USN:");
		scanf("%s",&usn);
		strcpy(h->USN,usn);
		printf("Enter Student Name:");
		scanf("%s",&name);
		strcpy(h->Name,name);
		printf("Enter Student's Branch:");
		scanf("%s",&br);
		strcpy(h->Branch,br);
		printf("Enter Student's Sem:");
		scanf("%d",&sem);
		h->Sem=sem;
		printf("Enter Phone No.");
		scanf("%d",&ph);
		h->PhoneNo=ph;
		if(a==0)
		{
			h->link=ptr;
			p=h;
		}
		else
		{
			h->link=ptr->link;
        	ptr->link=h;
        }
    	n++;
    }
    else
    	printf("..................Invalid Node At which You Want to Insert................... ");
}
Delete()
{
	if(n==0)
		printf("....................Empty List.................");
	else
	{
    	printf("Enter Node no. Which You Want To Delete started with Zero:\n");
    	scanf("%d",&b);
    	if(b<n)
    	{
        	for(i=0;i<b-1;i++)
         		ptr=ptr->link;
	    	if(b==0)
    		{
			t=ptr;
			p=ptr->link;
     		}
    		else
	    	{
         		t=ptr->link;
        		if(b==n-1)
        			ptr->link=NULL;
	    		else
            		ptr->link=t->link; 
	        }  
    		free(t); 
            n--;
        }
        else
        	printf("..................Invalid Node To Be Deleted.................");
    }
}
Count()
{
	printf("\nNo Of Student In the Record=%d ",n);
}
main()
{
	do{
		printf("Choose An Option from the Following:\n");
		printf("1:Create Student Record:\n");
		printf("2:Show Student Record:\n");
		printf("3:Add a Student Record At Any Position:\n");
		printf("4:Delete a Student Record:\n");
		printf("5:To Count NO. Of Student In Record:\n");
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
