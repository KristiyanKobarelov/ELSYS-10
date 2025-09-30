#include <stdio.h>
#include <stdlib.h>

enum Color {
    RED,
    BLACK
} typedef Color;

struct Node {
    int val;
    Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} typedef Node;

Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->val = val;
    node->color = RED;

    return node;
}


/*                            
     x                               y
    / \     Right Rotation          /  \
   y   T3   - - - - - - - >        T1   x
  / \       < - - - - - - -            / \
 T1  T2                               T2  T3
*/
void left_rotation(Node **root, Node *x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x->parent->left == x) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    x->parent = y;

    if (T2 != NULL) {
        T2->parent = x;
    }   
}

void right_rotation(Node **root, Node *y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->parent = y->parent;

    if (y->parent == NULL) {
        *root = x;
    } else if (y->parent->left == y) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    y->parent = x;

    if (T2 != NULL) {
        T2->parent = y;
    }    
}

void treeFixup(Node **root, Node *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        Node *gp = z->parent->parent;

        if (gp->left == z->parent) {
            Node *uncle = gp->right;

            if (uncle != NULL && uncle->color == RED) {
                gp->color = RED;
                uncle->color = BLACK;
                z->parent->color = BLACK;

                z = gp;
            } else { 
                if (z->parent->right == z) {
                    left_rotation(root, z->parent);
                    z = z->left;
                }

                right_rotation(root, gp);
                gp->color = RED;
                z->parent->color = BLACK;
            }
        } else {
            Node *uncle = gp->left;

            if (uncle != NULL && uncle->color == RED) {
                gp->color = RED;
                uncle->color = BLACK;
                z->parent->color = BLACK;

                z = gp;
            } else { 
                if (z->parent->left == z) {
                    right_rotation(root, z->parent);
                    z = z->right;
                }

                left_rotation(root, gp);
                gp->color = RED;
                z->parent->color = BLACK;
            }
        }
    }

    (*root)->color = BLACK;
}

void insert(Node** root, int v) {
    if (*root == NULL) {
        *root = create_node(v);
        (*root)->color = BLACK;
        return;
    }
    
    Node* it = *root;
    while (1) {
        if (it->val > v) {
            if (it->left == NULL) {
                it->left = create_node(v);
                it->left->parent = it;
                it = it->left;
                break;
            }

            it = it->left;
        } else {
            if (it->right == NULL) {
                it->right = create_node(v);
                it->right->parent = it;
                it = it->right;
                break;
            }

            it = it->right;
        }
    }

    treeFixup(root, it);
}

void printTreePreorder(Node* root) {
    if (root == NULL) {
        return;
    }

    //preorder
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}

void printTreeInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printTreeInorder(root->left);
    printf("%d(%c) ", root->val, root->color == BLACK ? 'B' : 'R');
    printTreeInorder(root->right);
}


int getBH(Node *root)
{
     if(root == NULL) {
        return 0;
    }

    int h = 0;

    while(root->left != NULL) {
        if(root->color == BLACK) {
            h++;
        }
        root = root->left;
    }

    return h + 1;
}

Node * certainBH(Node * t1, Node * t2, int h, int bh) { // Обединява двете дървета по третия булет и намира y по втория булет, но не е готово :/
    if(t1 == NULL) {
        return NULL;
    }

    if(h < bh) {
        certainBH(t1, t2, h + 1, bh);
    } else if(h == bh) {
        return t1->val;
    } else if(h > bh) {
        printf("\nError!\n");
        return NULL;
    }


}
 
Node* joinTrees(Node* t1, Node* t2, int x) {
    if(t1 == NULL) {
        insert(&t2, x);
        return t2;
    }

    else if(t2 == NULL) {
        insert(&t1, x);
        return t1;
    }

    int bh1 = GetBH(t1, 0);
    int bh2 = GetBH(t2, 0);

    if(bh1 > bh2) {
        t1 = certainBH(t1, t2, 0, bh1);
        insert(t1, x);
        return t1;
    } else if (bh1 < bh2) {
        t2 = certainBH(t2, t1, 0, bh2);
        insert(t2, x);
        return t2;
    }
    
}

int isRBTree(Node *root)
{
    if(root == NULL) {
        return 0;
    }

    int lh = 0;
    int rh = 0;

    while(root->left != NULL) {
        if(root->color == BLACK) {
            lh++;
        }
        root = root->left;
    }

    while(root->right != NULL) {
        if(root->color == BLACK) {
            rh++;
        }
        root = root->right;
    }

    if(rh == lh) {
        return 1;
    } else return 0;
}

 
int main()
{
    struct Node *root = NULL;
 
    insert(&root, 101);
    insert(&root, 150);
    insert(&root, 180);
    insert(&root, 280);
    insert(&root, 320);
    insert(&root, 520);
    insert(&root, 410);
    insert(&root, 552);
    insert(&root, 441);
    insert(&root, 305);
    insert(&root, 965);
    insert(&root, 127);
    insert(&root, 117);
    insert(&root, 999);
    insert(&root, 588);
 
    struct Node *root2 = NULL;
 
    insert(&root2, 7);
    insert(&root2, 3);
    insert(&root2, 18);
    insert(&root2, 28);
    insert(&root2, 32);
 
 
    struct Node *joinned = joinTrees(root, root2, 100);
 
    printTreeInorder(joinned);
 
    if (isRBTree(joinned)) {
      printf("yes");
    }
 
    return 0;
}
 
/*
Задача 1:
Новия елемент винаги е червен в началото, защото NULL винаги е черно, а ако остане черен,
ще развали баланса.
 
Задача 2:
Диапазонът за брой връзки е: 1 до nlogn

Задача 3:
1. Да, може да бъде AVL, защото е балансирано спрямо височина и стойностите се приемат, че са
подредени по правилото на BST.

2. Да, може да бъде RB Tree, ако при тези стойности е тези цветове и е подредено по правилото на BST:
- 0 - черно
- 1 - черно
- 3 - черно
- 4 - червено
- 59 - черно
- 58 - черно
- 2 - червено
- 5 - черно
- 57 - черно
- 60 - червено
- 61 - черно
- 6 - черно
- 56 - черно
- 14 - червено
- 16 - черно

Задача 4: Сложността на join в най-лош случай е 0(n^2), като в най-добър случай е nlogn, защото в най-лош случай трябва да се
претърсят две дървета с височина +- 1 от друго и да се претърсят изцяло, за да се достигне до y, след което се използва insert
със сложност logn. В най-добрия случай едното дърво е с височина 1 и трябва просто да се претърси второто и пак да се ползва
insert.
*/

