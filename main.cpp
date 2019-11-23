#include "visualize.cpp"    //  as it has btree.c already included

int main(int argc, char const *argv[])
{
    /*  if someone makes a menu driven program here, then my happiness stack
        gonna overflow :P . Anyways! I'm bored :{   */
    struct Btree *root = create_btree_recur();

    printf("\n");
    printLevelOrder(root);

    return 0;
}
