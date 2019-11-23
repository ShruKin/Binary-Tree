#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct Btree{
    int data;
    struct Btree *left, *right;
};

struct Btree* create_btree_recur(){
    int d;
    printf("Enter data: ");
    scanf("%d", &d);

    if(d == -1)
        return NULL;

    struct Btree *root = (struct Btree*) malloc(sizeof(struct Btree));
    root->data = d;
    
    printf("Enter left child of %d ", root->data);
    root->left = create_btree_recur();

    printf("Enter right child of %d ", root->data);
    root->right = create_btree_recur();

    return root;
}

void preorder(struct Btree *root)
{
	if(root != NULL)
	{
		printf("%d ",root->data);	
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Btree *root)
{
	if(root != NULL)
	{
		preorder(root->left);
		preorder(root->right);
		printf("%d ",root->data);	
	}
}

void inorder(struct Btree *root)
{
	if(root != NULL)
	{
		preorder(root->left);
		printf("%d ",root->data);	
		preorder(root->right);
	}
}

int height(struct Btree *root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {  
        int lheight = height(root->left);  
        int rheight = height(root->right);  

        if (lheight > rheight)  
            return(lheight + 1);  
        else 
            return(rheight + 1);  
    }  
}  
