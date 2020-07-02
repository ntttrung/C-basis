#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "tree.h"
#include "giaodich.h"
int BestAccu;
int main(){
    BestAccu = -1;
    tree root = NULL;
    int choice;
    do{
        printf("1.Import Data\n2.Display\n3.Add information\n4.Data Analysis\n5.Exit\n");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Importing....\n");
                FILE *fin = fopen("giaodich.txt","r+");
                root = read_db(fin,&BestAccu);
            break;
            case 2:
                printData(root);
            break;
            case 3:
                printf("Enter the information of new transaction\n");
                char newId[6],newName[31];
                int newElecPayment,newFashionPayment;
                printf("Enter the ID: ");
                fflush(stdin);
                scanf("%s",newId);
                do{
                    fflush(stdin);
                    printf("Enter the Name: ");
                    scanf("%s",newName);
                }while(checkNameError(newName));
                do{
                    printf("Enter the Electronic Payment: ");
                    scanf("%d",&newElecPayment);
                }while(newElecPayment < 0);
                do{
                    printf("Enter the Fashion Payment: ");
                    scanf("%d",&newFashionPayment);
                }while(newFashionPayment < 0);
                int newNumElec = 0;
                int newNumFashion = 0;
                if(newElecPayment > 0) newNumElec = 1;
                if(newFashionPayment > 0) newNumFashion = 1;
                element_t newData = createData(newId,newName,newElecPayment + newFashionPayment,newNumElec,newNumFashion,newElecPayment,newFashionPayment);
                tree node = search(root,newData);
                if(node == NULL) insert(&root,newData);
                else{
                    node->data->accumulated += newElecPayment + newFashionPayment;
                    node->data->numsElectronic += newNumElec;
                    node->data->numsFashion += newNumFashion;
                    node->data->electronicPayment += newElecPayment;
                    node->data->fashionPayment += newFashionPayment;
                    if(node->data->accumulated > BestAccu) BestAccu = node->data->accumulated;
                }
            break;
            case 4:
                printf("Best of all Customer: \n");
                scanfBestCustomer(root,BestAccu);
                int TotalElec=0;int TotalFashion = 0; int TotalTransElec = 0;int TotalTransFashion = 0;
                countPayment(root,&TotalElec,&TotalFashion,&TotalTransElec,&TotalTransFashion);
                printf("%30s%20s\n","TotalPayment","NumberOfTrans");
                printf("%-18s","Electronic");
                printf("%-19d%d\n",TotalTransElec,TotalElec);
                printf("%-18s","Fashion");
                printf("%-19d%d\n",TotalTransFashion,TotalFashion);
            break;
        }
    }while(choice != 5);
}