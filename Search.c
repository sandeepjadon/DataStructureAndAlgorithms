#include<stdio.h>
#define MAX 100
int arr[MAX],i,c=0,d=0;
int n,key;
LinearSearch()
{
	int d;
	for(i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			printf("Key Found At Index %d",i);
			c++;
			break;
		}
	}
	if(c==0)
		printf("Key Not Found");	
}
BinarySearch(){
	if(arr[(c+n)/2]==key){
		printf("Result Found at %d",(c+n)/2);
		d++;
	}
	else{
		if((c+n)/2==n-2){
			if(arr[n-1]==key){
				printf("Result Found at %d",n-1);
				d++;
			}
		}
		else{
			if(key>arr[(c+n)/2])
			{
				c=n/2;
				BinarySearch();
			}
			else if(key<arr[(c+n)/2])
			{
				n=n/2;
				BinarySearch();
			}
		}
		if(d==0)
		printf("Key Not Found:");
	}
	
}
main()
{
	int choice;
	char option;
	do{
		printf("Enter Your Array Size:");
		scanf("%d",&n);
		arr[n];
		printf("Enter Your Array Element:");
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("Enter Your Element Which You Want to search:");
		scanf("%d",&key);
		printf("Choose An option From The Following:\n");
		printf("1:LinearSearch\n");
		printf("2:BinarySearch\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:LinearSearch();
					break;
			case 2:BinarySearch();
					break;
			default: printf("Invalid Choice");
					break;
		}
		printf("\n\nDo you want to continue:");
		scanf("%s",&option);
	}while(option=='y'||option=='Y');
}
