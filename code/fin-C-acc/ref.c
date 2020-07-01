#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include "tree.h"


void menu()
    {
        printf("---------MENU--------\n");
        printf("1,Read data\n");
        printf("2,Print information\n");
        printf("3,Add/modify\n");
        printf("4,Translate\n");
        printf("5,Transfer\n");
        printf("6,Exit\n");
    }

tree readdata()
    {
        tree t=createNullTree();
        FILE* fin;
        element_t tmp;
        tree p;
        int i,n,j;
        fin=fopen("dict.txt","r");
        char str[50];
        // char str1[30],str2[30];
        while(fgets(str,49,fin)!=NULL)
            {
                sscanf(str,"%s %[^\n]",tmp.eng,tmp.vie);
                printf("%s %s\n",tmp.eng,tmp.vie);
                p=searchBST(t,tmp.eng);
                if(p==NULL)
                    t=insertBST(t,tmp);
            }
        fclose(fin);
        return t;
    }
void print_data(tree t)
    {
        breadth_first_search(t);
    }

void modify(tree t)
    {
        tree p;
        char str[2];
        element_t tmp;
        printf("Enter an English word: ");
        fflush(stdin);
        gets(tmp.eng);
        p=searchBST(t,tmp.eng);
        if(p==NULL)
            {
                printf("Enter the meaning: ");
                fflush(stdin);
                gets(tmp.vie);
                t=insertBST(t,tmp);
            }
        else 
            {
                printf("The word is exsist, do you want to change(y/n)?");
                fflush(stdin);
                gets(str);
                if(strcasecmp(str,"Y")==0)
                    {
                        printf("enter the meaning: ");
                        fflush(stdin);
                        gets(p->data.vie);
                    }
            }
    }

void translate(tree t)
    {
        tree p;
        char str[100],str1[100];
        char c[2]=" ";
        char *token;
        printf("Enter the sentence: ");
        fflush(stdin);
        gets(str);
        strcpy(str1,str);
        token=strtok(str,c);
        while(token!=NULL)
            {
                p=searchBST(t,token);
                if(p==NULL)
                    printf("%-15s <miss>\n",token);
                else 
                    printf("%-15s %s\n",token,p->data.vie);
                token=strtok(NULL,c);
            }
        token=strtok(str1,c);
        printf("Result: ");
        while(token!=NULL)
            {
                p=searchBST(t,token);
                if(p==NULL)
                    printf("<miss> ");
                else printf("%s ",p->data.vie);
                token=strtok(NULL,c);
            }
        printf("\n");
    }

void transfer(tree t)
    {
        FILE* fin=fopen("data.txt","w");
        extract_file(t,fin);
        fclose(fin);
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
                while(o<1||o>6);
                switch(o)
                    {
                        case 1:
                            {
                                system("cls");
                                t=readdata();
                                printf("%s\n",treeToString(t));
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                print_data(t);
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                modify(t);
                                break;
                            }
                        case 4:
                            {
                                system("cls");
                                translate(t);
                                break;
                            }
                        case 5:
                            {
                                system("cls");
                                transfer(t);
                                break;
                            }
                    }
            }
        while(o!=6);
    }