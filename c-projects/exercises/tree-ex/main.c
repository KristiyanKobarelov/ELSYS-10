#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100

typedef struct package {
    int id;
    int bribe;
} Package;

typedef struct imp_package {
    Package heap[MAX_HEAP];
} Imp_package;

Package * init_package(Imp_package *ptr, int size )
{
   ptr->size = 0;
}


void swap(Package *a, Package *b)
{
    Package temp = *a;
    *a = *b;
    *b = temp;
}

Package *addPackage(Imp_package *pq, int id, int bribe) {
    int size;
   if(pq->size >= MAX_HEAP) {
        printf("\nThe heap is full.\n");
        return 1;
   }
   int i = pq->size + 1;
   pq->heap[i].id = id;
   pq->heap[i].bribe = bribe;

   while(i > 0) {
        int parent = (i - 1) / 2;
        if(pq->heap[parent].bribe > pq->heap[i].bribe) 
        {
            swap(pq->heap[parent], pq->heap[i]);
            break;
        }
}
    i = parent;
}


Package * process_package(int id, int bribe, int size, Imp_package *pq)
{
    
}

Package print_package(Package heap[MAX_HEAP], int size)
{
    for(int i = 0; i < pq->size; i++) {
        printf("ID: %d, Bribe: %d\n", heap[i]->id, heap[i]->size);
    }
}

int main(void)
{
    Imp_package *pq;
    addPackage(&pq, 4, 243);
    addPackage(&pq, 6, 654);
    addPackage(&pq, 3, 123);
    print_package(heap[MAX_HEAP], 68)
}