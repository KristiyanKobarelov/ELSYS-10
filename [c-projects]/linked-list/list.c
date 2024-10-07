#include <stdio.h>
#include "list.h"

Node * init_node(int val);
List * init_llist();

void insertBegin(List* l, int val)
{
    Node * newNode = init_node(val);

    newNode->next = l->head;
    l->head = newNode;
}

int isEmpty(List * l) {
    if (l->head == NULL)
        return 1;
    
    return 0;
}

int popBegin(List* l) {
    int val = l->head->val;
    Node * tmp = l->head;

    l->head = l->head->next;

    free(tmp);

    return val;
}


Node * getAt(List* l, int k) {
    Node * it = l->head;

    if (it == NULL) {
        printf("Empty");
    }

    for (int i = 0; i < k; i++) {
        if (it == NULL) {
            printf("Index bigger than list\n");
            exit(0);
        }
    }
}

void print(List * l) {
    Node * it = l->head;

    if(it == NULL) {
        printf("Empty List :(\n");
    }

    while (it != NULL) {
        printf("%d\n", it->val);

        it = it->next;
    }
}

void clear(List * l) {
    Node * it = l->head;

    while (it != NULL) {
        Node * tmp = it;

        it = it->next;

        free(tmp);
    }

    free(it);
}