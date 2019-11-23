#include "visualize.cpp"    //  as it has btree.c already included

int main(int argc, char const *argv[])
{
    struct Btree *root = create_btree_recur();

    printf("\n");
    printLevelOrder(root);

    return 0;
}
