#include <stdio.h>
#include "liststatik.h"

int main()
{
    ListStatik l;
    readList(&l);
    int n, i, x;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertFirst(&l, x);
    }
    sortList(&l, true);
    printList(l);
    printf("\n");
    return 0;
}