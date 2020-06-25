#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"tree.h"
#include"list.h"

void menu()
    {
        printf("-------------MENU-----------\n");
        printf("1,Read data\n");
        printf("2,Statistic\n");
        printf("3,Eat most\n");
        printf("4,Popular food\n");
        printf("5,Exit\n\n");
    }

list readdata()
    {
        list l=create_list();
        int dk=-1;
        person_t tmp;
        node_t p;
        char str1[20],str2[20],str[20];
        FILE* fin;
        fin=fopen("data.txt","r");
        while(fgets(str,19,fin)!=NULL)
            {
                sscanf(str,"%s %[^\n]",str1,str2);
                p=find(l,str1);
                if(p==NULL)
                    {
                        strcpy(tmp.name,str1);
                        tmp.count_food=1;
                        strcpy(tmp.food[1].name,str2);
                        tmp.food[1].times=1;
                        l=insert_tail(l,tmp);
                    }
                else 
                    {
                        dk=find_food(l,str2);
                        if(dk==0)
                            {
                                p->data.count_food++;
                                strcpy(p->data.food[p->data.count_food].name,str2);
                                p->data.food[p->data.count_food].times=1;
                            }
                        else
                            {
                                p->data.food[dk].times++;
                            }
                    }
                
            }
        fclose(fin);
        return l;
    }

void printf_list(list l)
    {
        list p=l;
        int i;
        while(p!=NULL)
            {
                printf("%s\t",p->data.name);
                for(i=1;i<=p->data.count_food;i++)
                    {
                        printf("%s:%d   ",p->data.food[i].name,p->data.food[i].times);
                    }
                printf("\n");
                p=p->next;
            }
    }

int main()
    {
        list l;
        tree t;
        int o;
        do
            {
                menu();
                do 
                    {
                        printf("Enter your option: ");
                        scanf("%d",&o);
                    }
                while(o<1||o>5);
                switch(o)
                    {
                        case 1:
                            {
                                // system("cls");
                                l=readdata();
                                printf_list(l);
                                break;
                            }
                    }
            }
        while(o!=5);
    }