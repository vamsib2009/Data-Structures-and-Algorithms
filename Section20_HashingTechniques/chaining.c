#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chains.h"


int hash(int key)
{
    return key%10;
}

void InsertinHT(struct Node *H[], int key)
{
    int index=hash(key);
    SortedInsert(&H[index], key);
}



int main(){


    struct Node *HT[10]; //array of pointers
    struct Node *temp;
    int i;

    for(i=0;i<10;i++)
        HT[i]=NULL;

    InsertinHT(HT,2);
    InsertinHT(HT,22);
    InsertinHT(HT,42);

    temp = Search(HT[hash(22)], 22);

    printf("%d", temp->data);

        return 0;

}