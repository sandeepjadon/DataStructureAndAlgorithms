#include<stdio.h>
#define MAX 100
int arr[MAX],i,c=0,d=0,temp;
int n,j,k,l;
BubbleShort(){
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
		printf("\nAfter %d Pass:\n",i);
		for(k=0;k<n;k++)
			printf("%d ",arr[k]);
		printf("\n");
	}
}
SelectionSort(){
	int small;
	for(i=0;i<n-1;i++){
		small=arr[i];
		c=i;
  		for(j=i;j<n;j++){
		  	if(small>arr[j]){
		 		small=arr[j];
		 		c=j;
			}
		}
		temp=arr[i];
		arr[i]=small;
		arr[c]=temp;
		printf("\nAfter %d Pass:\n",i);
		for(k=0;k<n;k++)
			printf("%d ",arr[k]);
		printf("\n");
  	}
}
InsertionSort(){                              
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(arr[i]<arr[j]){
				temp=arr[i];
				for(k=i;k>j;k--)
					arr[k]=arr[k-1];
				arr[j]=temp;
				break;
			}
		}
		printf("\nAfter %d Pass:\n",i);
		for(k=0;k<n;k++)
			printf("%d ",arr[k]);
		printf("\n");
	}
}
main(){
	int choice;
	char option;
	do{
		printf("Enter Your Array Size:");
		scanf("%d",&n);
		arr[n];
		printf("Enter Your Array Element:");
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("Your Entered Array Element:\n");
   		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n\nChoose An option From The Following:\n");
		printf("1:BubbleSort\n");
		printf("2:InsertionSort\n");	
		printf("3:SelectionSort\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: BubbleShort();
					break;
			case 2: InsertionSort();
					break;
			case 3: SelectionSort();
					break;
		    default: printf("Invalid Choice");
					break;
		}
		printf("\n\nDo you want to continue:");
		scanf("%s",&option);
	}while(option=='y'||option=='Y');
}
