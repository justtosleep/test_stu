#include "ex.h"

int main()
{
    binaryTree<char> tree;

    tree.createTree('@');
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree.delLeft('L');
    tree.delRight('C');
    tree.delLeft('C');



    return 0;
}
