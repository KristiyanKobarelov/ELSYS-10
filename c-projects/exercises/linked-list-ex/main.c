#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void main() {
    printf("1\n");
    LList * list = init_llist();

    printf("2\n");
    insertEnd(list, 7);
    insertEnd(list, 8);
    insertEnd(list, 3);
    insertEnd(list, 4);

    printf("3\n");
    printList(list);
}