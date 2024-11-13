#include "list.h"
#include <stdlib.h>
#include <stdio.h>

Node* init_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->val = val;
    node->prev = NULL;

    return node;
}

LList* init_llist() {
    LList* l = (LList*)malloc(sizeof(LList));

    l->head = NULL;
    l->tail = NULL;

    return l;
}

void insertBegin(LList* l, int val) {
    Node* newNode = init_node(val);

    newNode->next = l->head;
    l->head = newNode;
}

void insertEnd(LList * l, int val) {
    Node * node = init_node(val);
    
    l->tail->next = node;
    node->prev = l->tail;
    node = l->tail;
}

int isEmpty(LList *l) {
    return l->head == NULL;
}

int popBegin(LList* l) {
    if (isEmpty(l)) {
        printf("Cannot pop from empty list");
        exit(1);
    }

    int val = l->head->val;
    Node* tmp = l->head;

    l->head = l->head->next;

    free(tmp);

    return val;
}

int popEnd(LList * l, int val) {
    if (isEmpty(l)) {
        printf("Cannot pop from empty list");
        exit(1);
    }

    Node * tmp = l->tail;
    tmp->prev = l->tail->prev->prev;
    tmp->prev->next = l->tail;
    free(tmp);

    return val;
}

Node* getAt(LList* l, int index) {
    Node *it = l->head;

    if (it == NULL) {
        printf("Cannot get from empty list");
        exit(0);
    }

    for (int i = 0; i < index; i++) {
        if (it == NULL) {
            printf("index bigger than list size\n");
            exit(0);    
        }
        
        it = it->next;
    }

    return it;
}

void printList(LList *l) {
    Node *it = l->head;

    if (it == NULL) {
        printf("Empty list.\n");
        return;
    }

    while (it != NULL) {
        printf("%d ", it->val);
        it = it->next;
    }
}

void clear(LList* l) {
    Node *it = l->head;

    while (it != NULL) {
        Node* tmp = it;

        it = it->next;

        free(tmp);
    }

    l->head = NULL;
}

void freeList(LList* l) {
    clear(l);
    free(l);
}