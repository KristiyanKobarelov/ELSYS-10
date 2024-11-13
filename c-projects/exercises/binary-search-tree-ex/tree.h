#ifndef H_TREE
#define H_TREE

typedef struct Node {
    int val;
    struct Node * left;
    struct Node * right;
} Node;

Node * create_node(int);
Node * bst_insert(Node *, int);
void printTree(Node *);

int findmin(Node *);
int findmax(Node *);
int checkBST(Node *, int lower, int upper);

#endif