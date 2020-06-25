#include<stdio.h>
#include<string.h>
#include "tree.h"

tree t;
void menu()
    {
        printf("----------MENU-----------\n");
        printf("1,Read data\n");
        printf("2,Search\n");
        printf("3,Add\n");
        printf("4,Delete\n");
        printf("5,Transfer\n");
        printf("6,Exit\n\n");
    }

void readata()
    {
        FILE *fin;
        element_t tmp;
        char str[70],str1[69];
        char c[2]=":";
        char *token;
        fin=fopen("data.txt","r");
        while(fgets(str,69,fin)!=NULL)
            {
                sscanf(str,"%[^\n]",str1);
                token=strtok(str1,c);
                strcpy(tmp.eng,token);
                token=strtok(NULL,c);
                strcpy(tmp.vie,token);
                t=insertBST(t,tmp);
            }
        fclose(fin);
    }

void add()
    {
        element_t tmp;
        printf("Enter the word: ");
        fflush(stdin);
        gets(tmp.eng);
        printf("Enter the meaning: ");
        fflush(stdin);
        gets(tmp.vie);
        t=insertBST(t,tmp);
    }

void delete()
    {
        tree tmp;
        char str[20];
        printf("Enter the word: ");
        fflush(stdin);
        gets(str);
        tmp=searchBST(t,str);
        if(tmp==NULL) printf("This word dose not exist!\n");
        else t=removeBST(t,tmp->data);
    }
void transfer()
    {
        FILE* fin;
        fin=fopen("data2.txt","w");
        tree tmp=t;
        while(tmp!=NULL)
            {
                fprintf(fin,"%s:%s\n",tmp->data.eng,tmp->data.vie);
                tmp=removeRootBST(tmp);
            }
        fclose(fin);
    }

int main()
    {
        t=createNullTree();
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
                                readata();
                                printf("%s\n",treeToString(t));
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                char str[15];
                                tree tmp;
                                printf("Enter the word: ");
                                fflush(stdin);
                                gets(str);
                                tmp=searchBST(t,str);
                                if(tmp==NULL) printf("This word dose not exist\n");
                                else printf("%s:%s\n",tmp->data.eng,tmp->data.vie);
                                printf("%s\n",treeToString(t));
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                add();
                                printf("%s\n",treeToString(t));
                                break;
                            }
                        case 4:
                            {
                                system("cls");
                                delete();
                                printf("%s\n",treeToString(t));
                                break;
                            }
                        case 5:
                            {
                                system("cls");
                                transfer();
                                break;
                            }
                    }
            }
        while(o!=6);
    }