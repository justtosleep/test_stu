#include "ex.h"

int main ()
{
    int a[] = {10,8,21,87,56,4,11,3,22,7};
    BinarySearchTree<int> tree;
    int x;
    int p;

    for (int i = 0; i < 10; ++i) tree.insert(a[i]);
    p = tree.find(56);
    if (p) cout << "find 56 is " << p << endl;
    else cout << "not found" << endl;

    tree.remove(56);
    p = tree.find(56);
    if (p) cout << "find 56 is " << p << endl;
    else cout << "not found" << endl;

    p = tree.find(21);
    if (p) cout << "find 21 is " << p << endl;
    else cout << "not found" << endl;

    tree.remove(21);
    p = tree.find(21);

    if (p) cout << "find 21 is " << p << endl;
    else cout << "not found" << endl;

    x=30;
    tree.insert(x);

    p = tree.find(30);
    if (p) cout << "find 30 is " << p << endl;
    else cout << "not found" << endl;

    return 0;
}
