#include "bTree.h"

int main() {
    bTree A;
    char preorder[27], midorder[27];
    cin >> preorder >> midorder;
    int length = strlen(preorder);

    A.createBtree(preorder, midorder, length);
    A.print();

    return 0;
}