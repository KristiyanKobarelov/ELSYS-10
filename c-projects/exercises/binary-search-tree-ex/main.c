#include <stdio.h>
#include "tree.h"

int main() {
    Node* root = create_node(10);
    bst_insert(root, 5);
    bst_insert(root, 15);
    bst_insert(root, 30);
    bst_insert(root, 0);
    bst_insert(root, 4);
    bst_insert(root, 26);
    int min = findmin(root);
    int max = findmax(root);
    printf("Min: %d, Max: %d\n", min, max);
    int checker = checkBST(root, min, max);
    if(checker) {
        printf("Yessir\n");
    } else {
        printf("Nuh uh\n");
    }

    
    printTree(root);

    return 0;
}