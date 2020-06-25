#include<stdio.h>
#include<stdlib.h>

#include "search.h"

int search_front(int key, int r[], int n)
    {
        int i,j;
        int tmp;
        for(i=0;i<n;i++)
            if (key==r[i])
                {
                    tmp=r[i];
                    for(j=i-1;j>=0;j--)
                        r[j+1]=r[j];
                    r[0]=tmp;
                    return(i+1);
                }
        return(-1);
    }

int search_transpose(int key,int r[],int n)
    {
        int i;
        int tmp;
        for(i=0;i<n;i++)
            if (key==r[i])
                {
                    tmp=r[i];
                    r[i]=r[i-1];
                    r[--i]=tmp;
                    return(i+2);
                }
        return(-1);
    }
    
int search(int key, int r[],int n)
    {
        int i;
        for(i=0;i<n;i++)
            if (key==r[i])
                 return(i+1);
        return(-1);
    }

int search_binary(int key, int r[],int n)
    {
        int mid,head=0,tail=n;
        while(head<=tail)
            {
                mid=(head+tail)/2;
                if(r[mid]==key)
                    return mid+1;
                else if(key<r[mid])
                    tail=mid-1;
                else head=mid+1;
            }
        return -1;
    }