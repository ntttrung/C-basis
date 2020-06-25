#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"book.h"

list l;
void xoa(char *str)
    {
        int i=strlen(str);
        str[i-1]='\0';
    }

void menu()
    {
        printf("-------------MENU--------------\n");
        printf("1,Doc co so du lieu\n");
        printf("2,Nhap thong tin sach\n");
        printf("3,Xoa 1 cuon sach\n");
        printf("4,Doi cho sach\n");
        printf("5,In thong tin xuat ban\n");
        printf("6,Ghi danh sach ra van ban\n");
        printf("7,Exit\n\n");
    }

list read_db(char *name)
    {
        FILE *fin;
        char str[100];
        element_t temp;
        int n,i,j,k;
        fin=fopen(name,"r");
        if(fin==NULL)
            {
                printf("Can\'t read from %s\n",name);
                return 0;
            }
        fgets(str,60,fin);
        n=atoi(str);
        for(i=1;i<=n;i++)
            {             
                for(j=1;j<=4;j++)
                    {
                        fgets(str,100,fin);
                        xoa(str);
                        if(j==1)
                            {
                                strcpy(temp.id,str);
                            }
                        if(j==2)
                            strcpy(temp.tittle,str);
                        if(j==3)
                            strcpy(temp.author,str);
                        if(j==4)
                            temp.published_year=atoi(str);
                    }
                l=insert_tail(l,temp);
            }
        fclose(fin);
        return l;
    }
void print_book(list l)
    {
        int dem=1;
        node_t tmp=l;
        while(tmp!=NULL)
            {
                printf("BOOK %d\n",dem);
                printf("\tID: %s\n",tmp->data.id);
                printf("\tTITLE: %s\n",tmp->data.tittle);
                printf("\tAUTHOR: %s\n",tmp->data.author);
                printf("\tPublished year: %d\n",tmp->data.published_year);
                tmp=tmp->next;
                dem++;
            }

    }
int check_id(char *id)
    {
        node_t tmp=l;
        while(tmp!=NULL)
            {
                if(strcasecmp(id,tmp->data.id)==0)
                    return 0;
                tmp=tmp->next;
            }
        return 1;

    }
node_t search_id(char *id)
    {
        node_t tmp=l;
        while(tmp!=NULL)
            {
                if(strcasecmp(id,tmp->data.id)==0)
                    return tmp;
                tmp=tmp->next;
            }
    }
list swap(char *id1, char *id2)
    {
        node_t tmp1,tmp2;
        element_t tmp3,tmp4;
        tmp1=search_id(id1);
        tmp2=search_id(id2);
        tmp3=tmp1->data;
        tmp4=tmp2->data;
        tmp1->data=tmp4;
        tmp2->data=tmp3;
        return l;
    }
void count()
    {
        node_t tmp=l;
        while(tmp)
    }

void transfer_db(char *name)
    {
        FILE *fout;
        char *a;
        fout=fopen(name,"w");
        node_t tmp=l;
        while(tmp!=NULL)
            {
                fputs(tmp->data.id,fout);
                fputs("\n",fout);
                fputs(tmp->data.tittle,fout);
                fputs("\n",fout);
                fputs(tmp->data.author,fout);
                fputs("\n",fout);
                // a=itoa(tmp->data.published_year);
                // fputs(a,fout);
                fputs("\n",fout);
                tmp=tmp->next;
            }
        fclose(fout);
    }

int main()
    {
        l=create_list();
        int o,dk=0;
        char name[30];
        do
            {
                menu();
                do
                    {
                        printf("Enter your option: ");
                        scanf("%d",&o);
                    }
                while(o>7||o<1);
                switch(o)
                    {
                        case 1:
                            {
                                system("cls");
                                printf("Enter the name of database: ");
                                fflush(stdin);
                                gets(name);
                                l=read_db(name);
                                print_book(l);
                                break;
                            }
                        case 2:
                            {
                                element_t tmp;
                                dk=0;
                                system("cls");
                                do
                                    {
                                       printf("Enter the ID: ");
                                       fflush(stdin);
                                       gets(tmp.id);
                                       dk=check_id(tmp.id);
                                    }
                                while(dk==0);
                                printf("Enter the title: ");
                                fflush(stdin);
                                gets(tmp.tittle);
                                printf("Enter the author: ");
                                fflush(stdin);
                                gets(tmp.author);
                                printf("Enter the published year: ");
                                scanf("%d",&tmp.published_year);
                                l=insert_tail(l,tmp);
                                print_book(l);
                                break;
                            }
                        case 3:
                            {
                                element_t tmp;
                                node_t tmp1;
                                dk=0;
                                do
                                    {
                                       printf("Enter the ID: ");
                                       fflush(stdin);
                                       gets(tmp.id);
                                       dk=check_id(tmp.id);
                                    }
                                while(dk==1);
                                tmp1=search_id(tmp.id);
                                l=remove_at(l,tmp1);
                                print_book(l);
                                break;
                            }
                        case 4:
                            {
                                element_t tmp,tmp0;
                                system("cls");
                                do
                                    {
                                       printf("Enter the first ID: ");
                                       fflush(stdin);
                                       gets(tmp.id);
                                       dk=check_id(tmp.id);
                                    }
                                while(dk==1);
                                do
                                    {
                                       printf("Enter the second ID: ");
                                       fflush(stdin);
                                       gets(tmp0.id);
                                       dk=check_id(tmp0.id);
                                    }
                                while(dk==1);
                                l=swap(tmp.id,tmp0.id);
                                print_book(l);
                                break;
                            }
                        case 5:
                            {
                                int year;
                                system("cls");
                                printf("ENter the published year: ");
                                scanf("%d",&year);
                                count();
                                break;
                            }
                        case 6:
                            {
                                system("cls");
                                printf("Enter the name: ");
                                fflush(stdin);
                                gets(name);
                                transfer_db(name);
                                break;
                            }
                    }
            }
        while(o!=7);
    }