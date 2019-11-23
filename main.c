#include "btree.c"

int main(int argc, char const *argv[])
{
    struct Btree *root = create_btree_recur();
    preorder(root);

    return 0;
}
