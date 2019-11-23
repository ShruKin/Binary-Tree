#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* createBTree(int h)
{
    char *tree, val, buff;
    int size = pow(2,h) - 1, p = 0;
    tree = (char*)malloc(size * sizeof(char));

    for(int i=0; i<h; i++){
        for(int j=0; j<pow(2, i); ){
            if(i == 0){
                printf("Enter Root data: ");
                scanf(" %c", &tree[p]);
                if(tree[p] == 'n'){
                    printf("Root cannot be NULL! Try Again!\n");
                    j--;
                }                    
                j++;
            }
            else {
                if(tree[p] != 'n'){
                    printf("Enter the left child of %c: ", tree[p]);
                    scanf(" %c", &tree[(2*p) + 1]);
                    printf("Enter the right child of %c: ", tree[p]);
                    scanf(" %c", &tree[(2*p) + 2]);                
                }       
                j+=2;
                p++;   
            }
        }
    }
    return tree;
}

void display(char* tree, int h){
    int size = pow(2,h) - 1, l = 0;
    for(int i=0; i<size; i++){
        if(i == (pow(2, l)-1)){
            printf("\nLevel[%d]: ", l);
            l++;
        }
        printf("%c ", tree[i]);
    }
}

int main()
{
    int h;
    printf("Enter the height of the tree: ");
    scanf("%d", &h);
    
    char *tree = createBTree(h);
    display(tree, h);
    printf("\n");

    return 0;
}