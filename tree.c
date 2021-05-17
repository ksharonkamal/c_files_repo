#include<stdio.h>
#include<stdlib.h>
struct bst
{
	int data;
	struct bst *left,*right;
};
struct bst * insert (struct bst *,int);
void inorder(struct bst*);
void preorder(struct bst*);
void postorder(struct bst*);


main()
{
	struct bst *root =NULL;
	int choice,data;
	struct bst *temp =NULL;
	while(1)
	{
		printf("1.Insert 2.display_INORDER 3.display_PREORDER 4.display_POSTORDER 5. exit\n");
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the data:");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2: inorder(root);
				break;
			case 3: preorder(root);
				break;
			case 4: postorder(root);
				break;
			
			case 5:exit(0);
			default:printf("invalid choice\n");	
		}
	}
}


struct bst * insert(struct bst* ptr,int d)
{
	struct bst*newnode=NULL;
	
	if(ptr==NULL)
	{
		newnode=(struct bst *)calloc(1,sizeof(struct bst));
		if(newnode==NULL)
		{
			printf("node not created\n");
		}
		else
		{
			newnode->data=d;
			ptr=newnode;
		}
	}
	else if(d < ptr->data)
	{
		ptr->left=insert(ptr->left,d);
	}
	else if(d > ptr->data)
	{
		ptr->right=insert(ptr->right,d);
	}
	else
		printf("data already exits\n");

	return ptr;
}

void preorder(struct bst *ptr)
{
	if(ptr)
	{
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}


void inorder(struct bst *ptr)
{
	if(ptr)
	{
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
}

void postorder(struct bst *ptr)
{
	if(ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	}
}
