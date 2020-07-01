#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include "tree.h"

void menu()
    {
        printf("---------MENU--------\n");
        printf("1,Dang nhap\n");
        printf("2,Thoat\n\n");
    }

tree readdata()
    {
        tree t=createNullTree();
        FILE* fin;
        element_t tmp;
        tree p;
        int i,n,j;
        fin=fopen("sinhvien.txt","r");
        char str[50];
        // char str1[30],str2[30];
        while(fgets(str,49,fin)!=NULL)
            {
                sscanf(str,"%s %s %f",tmp.username,tmp.pass,&tmp.score);
                // printf("%s\n",tmp.username);
                p=searchBST(t,tmp.username);
                if(p==NULL)
                    t=insertBST(t,tmp);
            }
        fclose(fin);
        return t;
    }
void menu_sv()
    {
        printf("1,Xem diem\n");
        printf("2,Thay doi mat khau\n");
        printf("3,Exit\n");
    }

void login(tree t)
    {
        int count=0,dk=0;
        element_t tmp;
        char str1[20],str2[20];
        tree p;
        do
            {
                printf("Enter username: ");
                fflush(stdin);
                gets(tmp.username);
                p=searchBST(t,tmp.username);
                printf("Enter password: ");
                fflush(stdin);
                gets(tmp.pass);
                if(p!=NULL)
                    {
                        if(strcmp(tmp.pass,p->data.pass)==0)
                            dk=1;
                    }
                else {
                        dk=0;
                }
            }
        while(dk==0);
        int op;
        if(dk==1)
            {
                printf("Login success\n");
                do 
                    {
                        menu_sv();
                        do 
                            {
                                printf("Enter your option: ");
                                scanf("%d",&op);
                            }
                        while(op<1||op>3);
                        switch(op)
                            {
                                case 1:
                                    {
                                       printf("Diem: %f\n",p->data.score);
                                       break;
                                    }
                                case 2:
                                    {
                                        printf("Enter new password: ");
                                        fflush(stdin);
                                        gets(str1);
                                        printf("Enter new password: ");
                                        fflush(stdin);
                                        gets(str2);
                                        if(strcmp(str1,str2)==0)
                                            {
                                                printf("SUcCESS\n");
                                                strcpy(p->data.pass,str1);
                                            }
                                        else printf("Fail!\n");
                                    }
                            }
                    }
                while(op!=3);
                    }

    }

int main()
    {
        tree t=createNullTree();
        int o;
        do 
            {
                menu();
                do 
                    {
                        printf("Enter your option: ");
                        scanf("%d",&o);
                    }
                while(o<1||o>2);
                switch(o)
                    {
                        case 1:
                            {
                                // system("cls");
                                t=readdata();
                                login(t);
                                break;
                            }
                        case 2:
                            {
                
                            }
                    }
            }
        while(o!=2);
    }