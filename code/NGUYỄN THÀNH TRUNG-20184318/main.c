#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#include "dangky.h"
#include "monhoc.h"

mhnode_t mlist;
dknode_t dlist;

void menu()
    {
        printf("______________________MENU___________________\n");
        printf("1,Doc du lieu\n");
        printf("2,Nhap thong tin mon hoc moi\n");
        printf("3,Nhap thong tin sinh vien\n");
        printf("4,Liet ke\n");
        printf("5,In thong tin sinh vien\n");
        printf("6,EXIT\n\n");
    }

void readData()
    {
        char str[70];
        FILE *fin = fopen("MONHOC.txt","r");
        monhoc_type tmp;
        int n,i;
        //read diemdo
        fgets(str,10,fin);
        sscanf(str,"%d",&n);
        for(i=1;i<=n;i++)
            {
                fgets(str,69,fin);
                sscanf(str,"%s %d %d",&tmp.id,&tmp.so_tin_chi,&tmp.hoc_ky);
                mlist=mhinsert_tail(mlist,tmp);
            }
        fclose(fin);

        fin=fopen("DANGKY.txt","r");
        char str1[70];
        dangky_type tmp1;
        // int n,i;
        fgets(str,10,fin);
        sscanf(str,"%d",&n);
        for(i=1;i<=n;i++)
            {
                fgets(str,69,fin);
                sscanf(str,"%s %d %[^\n]",tmp1.id,&tmp1.soluongmh,str1);
                int count=1;
                char c[2]=" ";
                char *token;
                token=strtok(str1,c);
                mhnode_t temp;
                while(token!=NULL)
                    {
                        strcpy(tmp1.dsmh[count].id,token);
                        temp=mhfind(mlist,tmp1.dsmh[count].id);
                        tmp1.dsmh[count].so_tin_chi=temp->data.so_tin_chi;
                        tmp1.dsmh[count].hoc_ky=temp->data.hoc_ky;
                        count++;
                        token=strtok(NULL,c);
                    }
                dlist=dkinsert_tail(dlist,tmp1);
            }
        fclose(fin);

    }

void print_monhoc()
    {
        mhnode_t p=mlist;
        printf("MON HOC \tSO TIN CHI \tHOC KY\n");
        printf("---------------------------------------\n");
        while(p!=NULL)
            {
                printf("%s\t\t%d\t\t%d\n",p->data.id,p->data.so_tin_chi,p->data.hoc_ky);
                p=p->next;
            }
        printf("\n");
    }

void print_dangky()
    {
        int i;
        printf("MA SV\t\tDANG KY\n");
        printf("--------------------------------------------------------\n");
        dknode_t p=dlist;
        while(p!=NULL)
            {
                printf("%s\t\t[",p->data.id);
                if(p->data.soluongmh!=0) printf("%s",p->data.dsmh[1].id);
                for(i=2;i<=p->data.soluongmh;i++)
                    printf(",%s",p->data.dsmh[i].id);
                printf("]\n");
                p=p->next;
            }
        printf("\n\n");
    }

void addmonhoc()
    {
        int dk=1;
        monhoc_type tmp;
        char monhoc[20];
        do
            {
                printf("Nhap ID mon hoc: ");
                fflush(stdin);
                gets(monhoc);
                if(mhfind(mlist,monhoc)!=NULL)
                    {
                        printf("Mon hoc nay da ton tai\n");
                        dk=0;
                    }
                else dk=1;
            }
        while(dk==0);
        strcpy(tmp.id,monhoc);
        printf("Nhap so tin chi: ");
        fflush(stdin);
        scanf("%d",&tmp.so_tin_chi);
        do
            {
                printf("Nhap hoc ky[1||2]: ");
                scanf("%d",&tmp.hoc_ky);
            }
        while(tmp.hoc_ky<1||tmp.hoc_ky>2);
        mlist=mhinsert_tail(mlist,tmp);
        print_monhoc();
    }

void addstudent()
    {
        int dk=1,i,count;
        char str[10];
        dknode_t sv;
        dangky_type tmp;
        char dangky[20];
        printf("Nhap ID sinh vien: ");
        fflush(stdin);
        gets(dangky);
        mhnode_t p;
        if(dkfind(dlist,dangky)!=NULL)
            {
                sv=dkfind(dlist,dangky);
                count=sv->data.soluongmh;
                count++;
                sv->data.soluongmh++;
                do  
                    {
                        printf("Nhap ID mon hoc: ");
                        fflush(stdin);
                        gets(str);
                        p=mhfind(mlist,str);
                        if(p==NULL)
                            printf("Non hoc nay khong ton tai!\n");
                    }
                while(p==NULL);
                sv->data.dsmh[count]=p->data;
                print_dangky();
            }
        else {
        strcpy(tmp.id,dangky);
        tmp.soluongmh=1;
        for(i=1;i<=tmp.soluongmh;i++)
            {
                do  
                    {
                        printf("Nhap ID mon hoc: ");
                        fflush(stdin);
                        gets(str);
                        p=mhfind(mlist,str);
                    }
                while(p==NULL);
                tmp.dsmh[i]=p->data;
            }
        dlist=dkinsert_tail(dlist,tmp);
        print_dangky();
    }}

void lietke()
    {
        int dk=0;
        char str[10];
        printf("Nhap ID mon hoc: ");
        fflush(stdin);
        gets(str);
        if(mhfind(mlist,str)==NULL)
            {
                printf("Khong tim thay mon hoc nay!\n");
            }
        else {
        dknode_t p=dlist;
        int i;
        printf("Danh sach sinh vien dang ky %s: ",str);
        while(p!=NULL)
            {
                for(i=1;i<=p->data.soluongmh;i++)
                    {
                        if(strcasecmp(str,p->data.dsmh[i].id)==0)
                            {
                                dk=1;
                                break;
                            }
                        dk=0;
                    }
                if(dk==1) printf("%s ",p->data.id);
                p=p->next;
            }
        printf("\n");}
    }
void print_sv()
    {
        int hk1=0,hk2=0,i;
        char str[10];
        printf("Nhap ID sinh vien: ");
        fflush(stdin);
        gets(str);
        if(dkfind(dlist,str)==NULL)
            {
                printf("Khong tim thay sinh vien %s!\n",str);
            }
        else
            {
                dknode_t p=dkfind(dlist,str);
                for(i=1;i<=p->data.soluongmh;i++)
                    {
                        if(p->data.dsmh[i].hoc_ky==1)
                            hk1=p->data.dsmh[i].so_tin_chi+hk1;
                        if(p->data.dsmh[i].hoc_ky==2)
                            hk2=p->data.dsmh[i].so_tin_chi+hk2;
                    }
                printf("Hoc ky 1: %d tin\n",hk1);
                printf("Hoc ky 2: %d tin\n",hk2);

            }
    }

int main()
    {
        int o,n;
        mlist=mhcreate_list();
        dlist=dkcreate_list();
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
                                readData();
                                print_monhoc();
                                print_dangky();
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                addmonhoc();
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                addstudent();
                                break;
                            }
                        case 4:
                            {
                                system("cls");
                                lietke();
                                break;
                            }
                        case 5:
                            {
                                system("cls");
                                print_sv();
                                break;
                            }
                    }
            }
        while(o!=6);
    }