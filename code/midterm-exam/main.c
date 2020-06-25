#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#include "tuyenxe.h"
#include "diemdo.h"

busnode_t blist;
txnode_t  tlist;

void menu()
    {
        printf("-------------------MENU------------------\n");
        printf("1,Doc du lieu\n");
        printf("2,Nhap thong tin diem do moi\n");
        printf("3,Nhap thong tin mot chuyen xe\n");
        printf("4,Nhap mot diem do\n");
        printf("5,Best route\n");
        printf("6,Transfer databse\n");
        printf("7,Exit\n\n");
    }
void readData()
    {
        char str[70];
        FILE *fin = fopen("DIEMDO.txt","r");
        bus_type tmp;
        int n,i;
        //read diemdo
        fgets(str,10,fin);
        sscanf(str,"%d",&n);
        for(i=1;i<=n;i++)
            {
                fgets(str,69,fin);
                sscanf(str,"%s %d %d",&tmp.id,&tmp.x,&tmp.y);
                blist=businsert_tail(blist,tmp);
            }
        fclose(fin);

        fin=fopen("TUYENXE.txt","r");
        char str1[70];
        tx_type tmp1;
        // int n,i;
        fgets(str,10,fin);
        sscanf(str,"%d",&n);
        for(i=1;i<=n;i++)
            {
                fgets(str,69,fin);
                sscanf(str,"%s %d %[^\n]",tmp1.id,&tmp1.sodiemdo,str1);
                int count=1;
                char c[2]=" ";
                char *token;
                token=strtok(str1,c);
                busnode_t temp;
                while(token!=NULL)
                    {
                        strcpy(tmp1.dsDiemdo[count].id,token);
                        temp=busfind(blist,tmp1.dsDiemdo[count].id);
                        tmp1.dsDiemdo[count].x=temp->data.x;
                        tmp1.dsDiemdo[count].y=temp->data.y;
                        count++;
                        token=strtok(NULL,c);
                    }
                tlist=txinsert_tail(tlist,tmp1);
            }
        fclose(fin);

    }
void print_diemdo()
    {
        busnode_t p=blist;
        printf("DIEM DO \tTOA DO\n");
        printf("-----------------------------------\n");
        while(p!=NULL)
            {
                printf("%s\t\t(%-3d,%2d)\n",p->data.id,p->data.x,p->data.y);
                p=p->next;
            }
        printf("\n");
    }

void print_tuyenxe()
    {
        int i;
        printf("TUYEN XE\tLO TRINH\n");
        printf("--------------------------------------------------------\n");
        txnode_t p=tlist;
        while(p!=NULL)
            {
                printf("%s\t\t[",p->data.id);
                if(p->data.sodiemdo!=0) printf("%s",p->data.dsDiemdo[1].id);
                for(i=2;i<=p->data.sodiemdo;i++)
                    printf(",%s",p->data.dsDiemdo[i].id);
                printf("]\n");
                p=p->next;
            }
        printf("\n\n");
    }
void addbus()
    {
        int dk=1;
        bus_type tmp;
        char diemdo[20];
        do
            {
                printf("Nhap ma diem do: ");
                fflush(stdin);
                gets(diemdo);
                if(busfind(blist,diemdo)!=NULL)
                    {
                        printf("Diem do nay da ton tai\n");
                        dk=0;
                    }
                else dk=1;
            }
        while(dk==0);
        strcpy(tmp.id,diemdo);
        printf("Nhap toa do x: ");
        fflush(stdin);
        scanf("%d",&tmp.x);
        printf("Nhap toa do y: ");
        scanf("%d",&tmp.y);
        blist=businsert_tail(blist,tmp);
        print_diemdo();
    }
void addtx()
    {
        int dk=1,i;
        char str[10];
        tx_type tmp;
        char tuyenxe[20];
        do
            {
                printf("Nhap ma tuyen xe: ");
                fflush(stdin);
                gets(tuyenxe);
                if(txfind(tlist,tuyenxe)!=NULL)
                    {
                        printf("Tuyen xe nay da ton tai\n");
                        dk=0;
                    }
                else dk=1;
            }
        while(dk==0);
        busnode_t p;
        strcpy(tmp.id,tuyenxe);
        printf("Nhap so diem do: ");
        scanf("%d",&tmp.sodiemdo);
        for(i=1;i<=tmp.sodiemdo;i++)
            {
                do  
                    {
                        printf("Nhap ID diem do thu %d: ",i);
                        fflush(stdin);
                        gets(str);
                        p=busfind(blist,str);
                    }
                while(p==NULL);
                tmp.dsDiemdo[i]=p->data;
            }
        tlist=txinsert_tail(tlist,tmp);
        print_tuyenxe();
    }
void findtx()
    {
        int dk=0;
        char str[10];
        printf("Nhap ID diem do: ");
        fflush(stdin);
        gets(str);
        if(busfind(blist,str)==NULL)
            {
                printf("Khong tim thay diem do!\n");
            }
        else {
        txnode_t p=tlist;
        int i;
        printf("Danh sach tuyen xe di qua %s: ",str);
        while(p!=NULL)
            {
                for(i=1;i<=p->data.sodiemdo;i++)
                    {
                        if(strcasecmp(str,p->data.dsDiemdo[i].id)==0)
                            {
                                dk=1;
                                break;
                            }
                        dk=0;
                    }
                if(dk==1) printf("%s ",p->data.id);
                p=p->next;
            }
        printf("\n");
    }}
void bestroute()
    {
        int x,y;
        char loca[10];
        float d;
        printf("Nhap toa do x: ");
        scanf("%d",&x);
        printf("Nhap toa do y: ");
        scanf("%d",&y);
        busnode_t p=blist;
        d=sqrt((p->data.x-x)*(p->data.x-x)+(p->data.y-y)*(p->data.y-y));
        strcpy(loca,p->data.id);
        p=p->next;
        while(p!=NULL)
            {
                if(d>=sqrt((p->data.x-x)*(p->data.x-x)+(p->data.y-y)*(p->data.y-y)))
                    {
                        d=sqrt((p->data.x-x)*(p->data.x-x)+(p->data.y-y)*(p->data.y-y));
                        strcpy(loca,p->data.id);
                    }
                p=p->next;
            }
        printf("The nearest bus is %s\n",loca);
    }
void tranferdata()
    {
        FILE *fout;
        fout=fopen("DIEMDO2.txt","w+");
        busnode_t p=blist;
        while(p!=NULL)
            {
                fprintf(fout,"%s \t %d  %d\n",p->data.id,p->data.x,p->data.y);
                p=p->next;
            }
        fclose(fout);


        fout=fopen("TUYENXE2.txt","w+");
        txnode_t q=tlist;
        int i;
        while(q!=NULL)
            {
                fprintf(fout,"%s \t%d ",q->data.id,q->data.sodiemdo);
                for(i=1;i<=q->data.sodiemdo;i++)
                    fprintf(fout,"%s ",q->data.dsDiemdo[i].id);
                fprintf(fout,"\n");
                q=q->next;
            }
        fclose(fout);
    }

int main()
    {
        int o,n;
        tlist=txcreate_list();
        blist=buscreate_list();
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
                                readData();
                                print_diemdo();
                                print_tuyenxe();
                                break;
                            }
                        case 2:
                            {
                                system("cls");
                                addbus();
                                break;
                            }
                        case 3:
                            {
                                system("cls");
                                addtx();
                                break;
                            }
                        case 4:
                            {
                                system("cls");
                                findtx();
                                break;
                            }
                        case 5:
                            {
                                system("cls");
                                bestroute();
                                break;
                            }
                        case 6:
                            {
                                system("cls");
                                tranferdata();
                                break;
                            }
                    }
            }
        while(o!=7);
    }