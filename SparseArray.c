#include<stdio.h>
int m,n,i,j,a,b;
Create(m,n)
{
	int mat[m][n];
	printf("Enter Your Matrix Elements:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("Row Column Value");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]!=0)
				printf("\n%d     %d      %d  ",i,j,mat[i][j]);
		}
	}
}
Add(m,n,a,b)
{
	if(m==a&&n==b)
	{
	int mat1[m][n],mat2[a][b];
	printf("Enter First Matrix Elements:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&mat1[i][j]);
	}
	printf("Enter Second Matrix Elements:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&mat2[i][j]);
	}
	printf("Sparse Matrix After Addition:\n");
	printf("Row Column Value");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat1[i][j]+mat2[i][j]!=0)
				printf("\n%d     %d      %d  ",i,j,mat1[i][j]+mat2[i][j]);	
		}
	}
 }
 else
   printf("Addion is not possible Becase Size is not Equal:\n");
}
Transposition(m,n)
{
    int mat[m][n];
	printf("Enter Your Matrix Elements:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	}
	printf("Sparse Matrix After Transposition:\n");
	printf("Row Column Value");	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]!=0)
				printf("\n%d     %d      %d  ",i,j,mat[j][i]);	
		}
	}
}
main()
{
	int choice;
	char option;
	do
	{
		printf("Choose An Option from the Following:\n");
		printf("1:Create Sparse Matrix:\n");
		printf("2:Add Two Sparse Matrix:\n");
		printf("3:Transposition of A Sparse Matrix:\n");
    	scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1: printf("Enter Size Sparse matrix: ");
                	scanf("%d %d",&m,&n);
                	Create(m,n);
                	break;
            case 2: printf("Enter First Matrix Size:");
                    scanf("%d %d",&m,&n);
                    printf("Enter Second Matrix Size:");
                    scanf("%d %d",&a,&b);
                    Add(m,n,a,b);
                    break;
            case 3: printf("Enter Size Sparse matrix: ");
                	scanf("%d %d",&m,&n);
                	Transposition(m,n);
                	break;
            default :printf(".....Invalid Choice.........");
                     break;       	
    	}
        printf("\n\nDo you Want to Continue (y/n): ");
   	    scanf("%s",&option);
    } while(option=='y'||option=='Y');
}
