/*  Nama : Raden Francisco Trianto Bratadiningrat
    NIM : 13522091
    tanggal : 3 November 2023
    Soal No : 2
*/

#include <stdio.h>
#include "list_circular.c"

void deleteAt(List *l, int idx) {
    if (isEmpty(*l)) {
        return; // List is empty, nothing to delete
    }

    Address p = FIRST(*l);
    Address prev = NULL;
    int count = 0;

    // Traverse the list to find the node at the specified index
    while (count < idx) {
        prev = p;
        p = NEXT(p);
        count++;
    }

    // Adjust the pointers to bypass the node at the specified index
    if (prev == NULL) {
        // Deleting the first node
        FIRST(*l) = NEXT(p);
    } else {
        // Deleting a node other than the first
        NEXT(prev) = NEXT(p);
    }

    // Deallocate the memory of the deleted node
    deallocate(p);
}

int main() {
    int n, i;
    scanf("%d", &n);
    List l;
    CreateList(&l);
    for (i = 1; i < n + 1; i++) {
        insertLast(&l, i);
    }
    boolean shiftLeft = false;
    int currIdx = 0;
    for (i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        currIdx = (currIdx + a);
        printf("current id : %d\n",currIdx);
        printf("before -> ");
        displayList(l);
        printf("\n");
        deleteAt(&l, currIdx);
        printf("after -> ");
        displayList(l);
        printf("\n");
    }
    printf("%d\n", INFO(FIRST(l)));
    return 0;
}
