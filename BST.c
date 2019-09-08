#include<stdio.h>
#include<malloc.h>
int n,i,key,max;
struct node{
	int data;
	struct node* left;
	struct node* right;
}*root=NULL,*ptr,*tree1,*min,*premin,*pre;
Insert(struct node* tree){
	if(tree==NULL){
		tree=ptr;
		return tree;
	}
	if(tree->data>ptr->data)
		tree->left=Insert(tree->left);
	else if(tree->data<=ptr->data)
		tree->right=Insert(tree->right);
}
Create(){
	printf("How Many Tree Member You Want:");
	scanf("%d",&n);
	printf("Enter Your Tree Members:");
	for(i=0;i<n;i++){
		ptr=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&ptr->data);
		ptr->left=NULL;
		ptr->right=NULL;
		if(root==NULL)
			root=ptr;
		else
			Insert(root);
	}
}
Inorder(struct node* tree){
	if(tree!=NULL){
		Inorder(tree->left);
		printf("%d\t",tree->data);
		Inorder(tree->right);
	}
}
Preorder(struct node* tree){
	if(tree!=NULL){
		printf("%d\t",tree->data);
		Preorder(tree->left);
		Preorder(tree->right);
	}
}
Postorder(struct node* tree){
	if(tree!=NULL){
		Postorder(tree->left);
		Postorder(tree->right);
		printf("%d\t",tree->data);
	}
}
Search(struct node* tree){
	if(tree==NULL)
		return 0;
	else if(tree!=NULL){
		if(key==tree->data){
			return tree;
    	}
    	else if(key!=tree->data)
    		tree1=tree;
		if(key<tree->data){
			Search(tree->left);
		}
		else{
			Search(tree->right);
		}
	}
}
Delete(struct node* tree){
	if(Search(tree)==0)
		printf("Key Not Found");
	else{
		struct node* tree2=Search(tree);
		if(tree2->left==NULL&&tree2->right==NULL){
			if(tree1->data>key)
				tree1->left=NULL;
			else
				tree1->right=NULL;
			free(tree2);
		}
		else if(tree2->left==NULL&&tree2->right!=NULL){
			if(tree1->data>key)
				tree1->left=tree2->right;
			else
				tree1->right=tree2->right;
			free(tree2);
		}
		else if(tree2->left!=NULL&&tree2->right==NULL){
			if(tree1->data>key)
				tree1->left=tree2->left;
			else
				tree1->right=tree2->left;
			free(tree2);
		}
		else if(tree2->left!=NULL&&tree2->right!=NULL){
			if(tree2->right->left==NULL&&tree2->right->right==NULL){
				tree2->data=tree2->right->data;
				free(tree2->right);
				tree2->right=NULL;
			}
			else{
				Minimum(tree2->right);
				if(tree2->right->left==NULL)
					premin=tree2;
				else
					Premin(tree2->right);
				tree2->data=min->data;
				if(min->right==NULL)
					premin->left=NULL;
				else{
					if(tree2->right->left==NULL)
						premin->right=min->right;
					else
						premin->left=min->right;
				}
				free(min);
			}
		}
		printf("..................Tree Member Successfully Deleted.....................");
	}
}
Premin(struct node* tree){
	if(tree->left->left==NULL){
		premin=tree;
		return;
	}
	Premin(tree->left);
}
Minimum(struct node* tree){
	if(tree->left==NULL){
		min=tree;
		return;
	}
	Minimum(tree->left);
}
Maximum(struct node* tree){
	if(tree->right==NULL){
			max=tree->data;
			return;
	}
	Maximum(tree->right);
}
main(){
	int choice;
	char option;
	do{
		printf("Choose An Option From The Following:\n");
		printf("1:Create A Binary Search Tree:\n");
		printf("2:Insert A Member:\n");
		printf("3:For Inorder Traversal:\n");
		printf("4:For PreOrder Traversal:\n");
		printf("5:For PostOrder Traversal:\n");
		printf("6:To Search A Member Of Tree:\n");
		printf("7:To Delete A Memeber Of Tree:\n");
		printf("8:For Minimum Member Of Tree:\n");
		printf("9:For Maximum Member Of Tree:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: Create();
					break;
			case 2: printf("Enter Your Tree Member:");
					ptr=(struct node*)malloc(sizeof(struct node));
					scanf("%d",&ptr->data);
					ptr->left=NULL;
					ptr->right=NULL;
					if(root==NULL)
						root=ptr;
					else
						Insert(root);
					break;
			case 3: if(root==NULL)
						printf("...............Tree Is Empty................");
					else{
						printf("Inorder Traversal:\n");
						Inorder(root);
					}
					break;
			case 4: if(root==NULL)
						printf("..................Tree Is Empty..................");
					else{
						printf("Preorder Traversal:\n");
						Preorder(root);
					}
					break;
			case 5: if(root==NULL)
						printf(".................Tree Is Empty................");
					else{
						printf("Postorder Traversal:\n");
						Postorder(root);
					}
					break;
			case 6: if(root==NULL)
						printf("............Tree Is Empty..............");
					else{
						printf("Enter Your Key Which You Want to Search:");
						scanf("%d",&key);
						if(root->data==key)
							printf("Key Is Found In tree:\n");
						else if(Search(root)==0)
							printf("Key Not Found");
						else
							printf("Key Is Found In Tree");
					}
					break;
			case 7: if(root==NULL)
						printf("............Tree Is Empty..............");
					else{
						printf("Enter your Key Which You Want To Delete:");
						scanf("%d",&key);
						if(root->left==NULL&&root->right==NULL&&key==root->data){
							free(root);
							root=NULL;
							printf("..................Tree Member Successfully Deleted.....................");
						}
						else if(root->left==NULL&&root->right==NULL&&key!=root->data)
							printf("................Key Not Found..................");
						else
							Delete(root);
					}
					break;
			case 8: if(root==NULL)
						printf("...............Tree Is Empty................");
					else{
						Minimum(root);
						printf("Minimum Member Of Tree=%d",min->data);
					}
					break;
			case 9: if(root==NULL)
						printf("...............Tree Is Empty................");
					else{
						Maximum(root);
						printf("Maximum Member Of Tree=%d",max);
					}
					break;
			default: printf("...........Invaid Choice............\n");
					break;
		}
		printf("\n\nDo you Want To Contnue:(y/n) ");
		scanf("%s",&option);
	}while(option=='y'||option=='Y');
}
