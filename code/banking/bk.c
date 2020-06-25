#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "queuearray.h"

int main()
    {
        char o,str[10];
        int n,i,h,m;
        int j;
        char *token;
        element_t tmp[10];
        queue q[10];
        printf("Ngan hang BIDV- Ha Thanh 17 Ta Quang Buu\n");
        printf("So quay mo phong: ");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            {
                q[i]=create_queue();
            } 
        do
            {
                printf("Enter the time [hour:min]: ");
                fflush(stdin);
                gets(str);
                token = strtok(str,':');
                h=token-'0';
                token=strtok(NULL,':');
                m=token-'0';
                printf("Enter number of customers: ");
                scanf("%d",&i);
                for(j=1;j<=i;j++)
                    {
                        tmp[j].stt=j;
                        tmp[j].hour=h;
                        tmp[j].min=m;
                    }
                
            }
    }