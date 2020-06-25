#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"queuearray.h"

queue run_q,wait_q;
int count=0;
int mem,n;

void menu()
    {
        printf("\n------------MENU-----------\n");
        printf("1,Create new program\n");
        printf("2,Kill a program\n");
        printf("3,Status\n");
        printf("4,EXIT\n\n");
    }
void new_program()
    {
        element_t tmp;
        printf("Enter the id: ");
        fflush(stdin);
        gets(tmp.id);
        printf("Enter the memory this program requires: ");
        scanf("%d",&tmp.mem);
        if((tmp.mem<=mem)&&(count<n))
            {
                mem=mem-tmp.mem;
                count++;
                strcpy(tmp.stt,"running");
                run_q=enqueue(run_q,tmp);
            }
        else if((tmp.mem<=mem)&&(count>=n))
                {
                    mem=mem-tmp.mem;
                    strcpy(tmp.stt,"Waitting");
                    wait_q=enqueue(wait_q,tmp);
                }
            else
                {
                    printf("Memory left is not enough !!\n");
                }
        tmp.stt[0]='\0';

    }
void kill_program()
    {
        int dk=3;
        char id[20];
        int i;
        element_t tmp;
        printf("Enter the id: ");
        fflush(stdin);
        gets(id);
        for(i=run_q->front;i<=run_q->rear;i++)
            {
                if(strcasecmp(run_q->data[i].id,id)==0)
                    {
                        mem=mem+run_q->data[i].mem;
                        run_q=delete(run_q,run_q->data[i]);
                        count--;
                        dk=1;
                        break;
                    }
            }
        if(dk!=1)
            for(i=wait_q->front;i<=wait_q->rear;i++)
            {
                if(strcasecmp(wait_q->data[i].id,id)==0)
                    {
                        mem=mem+wait_q->data[i].mem;
                        wait_q=delete(wait_q,wait_q->data[i]);
                        dk=0;
                        break;
                    }
            }
        if((dk!=1)&&(dk!=0))
            printf("Cannot find %s\n",id);
        if(count<n)
            {
                count++;
                tmp=front(wait_q);
                wait_q=dequeue(wait_q);
                tmp.stt[0]='\0';
                strcpy(tmp.stt,"running");
                run_q=enqueue(run_q,tmp);
            }

    }
void status()
    {
        int i=1,j;
        printf("STT\tID\t\tMEMORY\tSTATUS\n");
        printf("-----------------------\n");
        for(j=run_q->front;j<=run_q->rear;j++)
            {
                if(j!=-1)
                    {
                        printf("%-2d\t%-10s\t%-5d\t%-10s\n",i,run_q->data[j].id,run_q->data[j].mem,run_q->data[j].stt);
                        i++;
                    }
            }
        for(j=wait_q->front;j<=wait_q->rear;j++)
            {
               if(j!=-1)
                    {
                        printf("%-2d\t%-10s\t%-5d\t%-10s\n",i,wait_q->data[j].id,wait_q->data[j].mem,wait_q->data[j].stt);
                        i++;
                    }
            }
        
    }
int main()
    {
        run_q=create_queue();
        wait_q=create_queue();
        int i,o;
        printf("Enter the number of programs that os can run: ");
        scanf("%d",&n);
        printf("Enter the memory: ");
        scanf("%d",&mem);
        do
            {
                menu();
                do
                    {
                        printf("Enter your option: ");
                        scanf("%d",&o);
                    }
                while(o<1||o>4);
                switch(o)
                    {
                        case 1:
                            {
                                system("cls");
                                new_program();
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                kill_program();
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                status();
                                break;
                            }
                    }
            }
        while(o!=4);
    }