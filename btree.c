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
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);	
	}
}

void inorder(struct Btree *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);	
		inorder(root->right);
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

void printGivenLevel(struct Btree *root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 

void printLevelOrder(struct Btree *root) // BFS
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) {
        printGivenLevel(root, i); 
        printf("\n");
    }
} 

int calc_degree(struct Btree *tree){
    int deg = 0;

    if(tree->left != NULL)
        deg++;
    if(tree->right != NULL)
        deg++;

    return deg;
}

int calc_leaf_nodes(struct Btree *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return calc_leaf_nodes(root->left) + calc_leaf_nodes(root->right);
}

int calc_internal_nodes(struct Btree *root){
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + calc_internal_nodes(root->left) + calc_internal_nodes(root->right);
}