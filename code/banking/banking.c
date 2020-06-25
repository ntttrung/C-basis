#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "queuearray.h"

int wait(int h1,int m1,int h2,int m2)
    {
        int t;
        t=(h2-h1-1)*60+60-m1+m2-15;
        if(t>0) return 0;
        else return -t;
    }
int main()
    {
        float t;
        int guest=0;
        int time=0;
        char o,str[10];
        char c[2]=":";
        int n,i,h,m,dk=0,mark=1;
        int j,fix_time;
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
                token = strtok(str,c);
                h=atoi(token);
                token=strtok(NULL,c);
                m=atoi(token);
                printf("Enter number of customers: ");
                scanf("%d",&i);
                guest=guest+i;
                for(j=1;j<=i;j++)
                    {
                        tmp[j].hour=h;
                        tmp[j].min=m;
                    }
                j=1;
                while(j<=i)
                    {
                        mark=1;
                        for(h=1;h<=n;h++)
                            if(is_empty(q[h])==1)
                                {
                                    tmp[j].actual_wait=0;
                                    time=time+tmp[j].actual_wait;
                                    q[h]=enqueue(q[h],tmp[j]);
                                    dk=1;
                                    mark=h;
                                    break;
                                }
                            else
                                {
                                    tmp[j].wai[h]=wait(rear(q[h]).hour,rear(q[h]).min,tmp[j].hour,tmp[j].min);
                                    dk=0;
                                }
                        fix_time=tmp[j].wai[1];
                        if(dk==0)
                            {
                                for(h=1;h<=n;h++)
                                    {
                                        if(fix_time>tmp[j].wai[h])
                                            {
                                                mark=h;
                                                fix_time=tmp[j].wai[h];
                                            }
                                    }
                                tmp[j].actual_wait=fix_time;
                                m=tmp[j].min+tmp[j].actual_wait;
                                if(m>=60)
                                    {
                                        tmp[j].hour++;
                                        tmp[j].min=m-60;
                                    }
                                else tmp[j].min=m;
                                time=time+tmp[j].actual_wait;
                                q[mark]=enqueue(q[mark],tmp[j]);
                            }
                        printf("Nguoi thu %d vao quay so: %d va doi: %d\n",j,mark,tmp[j].actual_wait);
                        j++;
                    }
                printf("Do you want to continue(Y/N)?: ");
                fflush(stdin);
                scanf("%c",&o);
            }
        while(toupper(o)!='N');
        printf("\n");
        printf("Tong cong co %d khach hang, tong tho gian cho: %d phut\n",guest,time);
        t=(float)time/guest;
        printf("Trung binh moi khach phai cho: %.2f phut\n",t);
    }
