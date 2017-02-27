#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	int data;
	struct node *right;
};

struct node *create();
void insert(struct node *,struct node *);
void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);

int main()
{
	while(1)
	{
		struct node *root = NULL, *temp;
		char op='y';
		int ch;

		if(op=='y'||op=='Y')
		{
			temp=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter Data:");
			scanf("%d",&temp->data);
			temp->left=temp->right=NULL;

			if(root == NULL)
				root = temp;
			else
				insert(root,temp);
			
			printf("\nDo you want to add more elements? (y/n)");
			scanf("%c",op);
		}

		printf("\nTraversals...\n");
		printf("1. In order traversal.\n");
		printf("2. Pre Order traversal.\n");
		printf("3. Post Order traversal.\n");
		printf("4. Exit");

		printf("Enter Your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: //inorder(root);
					break;

			case 2: preorder(root);
					break;

			case 3: //postorder(root);
					break;
			case 4: exit(0);

			default: printf("Invalid Choice!");
		}
	}
	return 0;
}

void insert(struct node *root, struct node *temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }
    
    if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}