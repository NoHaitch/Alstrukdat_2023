#include <stdio.h>
#include "liststatik.c"

int main()
{
    // r : list sampah
    // p : list perjalanan
    ListStatik s, p;
    int i;
    readList(&s);
    readList(&p);
    printList(s);
    printf("\n");
    printList(p);
    printf("\n");

    return 0;
}