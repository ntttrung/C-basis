#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include "tree.h"


void menu()
    {
        printf("---------MENU--------\n");
        printf("1,Read data\n");
        printf("2,Input information\n");
        printf("3,Lookup information\n");
        printf("4,Do money transfer\n");
        printf("5,Remove account\n");
        printf("6,Transfer data\n");
        printf("7,Exit\n\n");
    }

tree readdata()
    {
        tree t=createNullTree();
        FILE* fin;
        element_t tmp;
        tree p;
        int i,n,j;
        fin=fopen("bank.db","r");
        char str[50];
        char str1[50];
        fgets(str,10,fin); sscanf(str,"%d",&n);
        for(i=1;i<=n;i++)
            {
                for(j=1;j<=3;j++)
                    {
                        fgets(str,49,fin);
                        sscanf(str,"%[^\n]",str1);
                        if(j==1) 
                            strcpy(tmp.name,str1);
                        if(j==2) 
                            strcpy(tmp.telephone,str1); 
                        if(j==3) 
                            tmp.balance=atoi(str1);
                    }
                p=searchBST(t,tmp.name);
                t=insertBST(t,tmp);
            }
        fclose(fin);
        return t;
    }
void print_data(tree t)
    {
        printf("Name\t\t\tBalance\t\tTel\n");
        printf("--------------------------------------------------------\n");
        breadth_first_search(t);
    }

void input_data(tree t)
    {
        tree p;
        int i,dk=0;
        element_t tmp;
        printf("Enter the account name: ");
        fflush(stdin);
        gets(tmp.name);
        printf("Enter the telephone: ");
        fflush(stdin);
        gets(tmp.telephone);
        printf("Enter the balance: ");
        scanf("%lld",&tmp.balance);
        p=searchBST(t,tmp.name);
        if(p==NULL) 
            t=insertBST(t,tmp);
        else
            {
                for(i=1;i<=p->data.total;i++)
                    if(strcasecmp(tmp.telephone,p->data.account[i].telephone)==0)
                        {
                            dk=1;
                            break;
                        }
                    else dk=0;
                if(dk==1) printf("Dupplication Error!\n\n");
                else 
                    {
                        t=insertBST(t,tmp);
                    }
            }
    }
    
void look_up(tree t)
    {
        tree p;
        int i,dk=0;
        char str[30],str1[30];
        printf("Enter the account name: ");
        fflush(stdin);
        gets(str);
        p=searchBST(t,str);
        if(p==NULL)
            printf("Not found!\n");
        else if(p->data.total==1)
                {
                    printf("Name\t\t\tBalance\t\tTel\n");
                    printf("--------------------------------------------------------\n");
                    printf("%-20s\t%lld\t\t%s\n",p->data.name,p->data.account[1].balance,p->data.account[1].telephone);
                }
            else 
                {
                    printf("Enter the telephone number: ");
                    fflush(stdin);
                    gets(str1);
                    for(i=1;i<=p->data.total;i++)
                        if(strcasecmp(str1,p->data.account[i].telephone)==0)
                            {
                                dk=1;
                                break;
                            }
                        else dk=0;
                    if(dk==1)
                        {
                            printf("Name\t\t\tBalance\t\tTel\n");
                            printf("--------------------------------------------------------\n");
                            printf("%-20s\t%lld\t\t%s\n",p->data.name,p->data.account[i].balance,p->data.account[i].telephone);
                        }
                    else printf("Incorrect telephone number!\n");
                }
    }

money_transfer(tree t)
    {
        tree p;
        long long int x;
        int i,dk=0,j;
        char str[30],str1[30],name[30];
        do {
        printf("Enter the first account name: ");
        fflush(stdin);
        gets(str);
        p=searchBST(t,str);
        if(p==NULL)
            printf("Not found!\n");} while(p==NULL);
        if(p->data.total==1)
                {
                    j=1;
                }
            else 
                {
                    do 
                        {
                            printf("Enter the telephone number: ");
                            fflush(stdin);
                            gets(str1);
                            for(i=1;i<=p->data.total;i++)
                                if(strcasecmp(str1,p->data.account[i].telephone)==0)
                                    {
                                        dk=1;
                                        break;
                                    }
                                else dk=0;
                            if(dk==1)
                                {
                                    j=i;
                                }
                            else printf("Incorrect telephone number!\n");
                        }
                    while(dk==0);
                }
        do 
            {
                printf("Enter the money you want to transfer: ");
                scanf("%lld",&x);
                if(x>p->data.account[j].balance) printf("Not enough money!\n");
                if(x<=0) printf("Incorrect money!\n");
            }
        while(x<=0||x>p->data.account[j].balance);
        p->data.account[j].balance=p->data.account[j].balance-x;
        
        ///////////
        int dk1=0;
        do {
            printf("Enter the second account name: ");
            fflush(stdin);
            gets(str);
            p=searchBST(t,str);
            if(p==NULL)
                {
                    printf("Not found!\n");
                    dk1=0;
                }
            else dk1=1;
        } while(dk1==0);
            if(p->data.total==1)
                {
                    j=1;
                }
            else 
                {
                    do
                        {
                            printf("Enter the telephone number: ");
                            fflush(stdin);
                            gets(str1);
                            for(i=1;i<=p->data.total;i++)
                                if(strcasecmp(str1,p->data.account[i].telephone)==0)
                                    {
                                        dk=1;
                                        break;
                                    }
                                else dk=0;
                            if(dk==1)
                                {
                                    j=i;
                                    dk1=1;
                                }
                            else 
                                {
                                    printf("Incorrect telephone number!\n");
                                    dk1=0;
                                }
                        }
                    while(dk1==0);
                }
            p->data.account[j].balance=p->data.account[j].balance+x;
    }

tree remove_account(tree t)
    {
        tree p;
        char str[30];
        do
            {
                printf("Enter the account name: ");
                fflush(stdin);
                gets(str);
                p=searchBST(t,str);
                if(p==NULL)
                    printf("Not found!\n");
            }
        while(p==NULL);
        t=deleteNode(t,p->data.name);
        return t;
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
                while(o<1||o>7);
                switch(o)
                    {
                        case 1:
                            {
                                system("cls");
                                t=readdata();
                                print_data(t);
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                input_data(t);
                                print_data(t);
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                look_up(t);
                                break;
                            }
                        case 4:
                            {
                                system("cls");
                                money_transfer(t);
                                print_data(t);
                                break;
                            }
                        case 5:
                            {
                                system("cls");
                                t=remove_account(t);
                                print_data(t);
                                break;
                            }
                        case 6:
                            {
                                system("cls");
                                FILE* fout=fopen("database.txt","w");
                                transfer_data(t,fout);
                                fclose(fout);
                                break;
                            }
                    }
            }
        while(o!=7);
    }