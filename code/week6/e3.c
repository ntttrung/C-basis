#include<stdio.h>
#include "search.h"

int main()
    {
        int data[5]= {1,3,4,5,6};
        int i;
        printf("%d\n",search_binary(4,data,5));
        for(i=0;i<=4;i++)
            printf("%d ",data[i]);
        printf("\n");
    }