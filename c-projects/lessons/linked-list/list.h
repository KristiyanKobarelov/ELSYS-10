#ifndef H_LIST
#define H_LIST

typedef struct Node {
    int val;
    struct Node * next;

} Node;

typedef struct LinkedList {
    Node * head;

} List;

Node * init_node(int val);
List * init_llist();

void insertBegin(List* l, int val);
int isEmpty(List * l);
int popBegin(List* l);
Node * getAt(List* l, int i);

void print(List * l);
void clear(List * l);

#endif