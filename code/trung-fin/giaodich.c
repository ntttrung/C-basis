#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "giaodich.h"

tree read_db(FILE *fin,int *BestAcu){
    tree head = NULL;
    while(!feof(fin)){
        element_t newNode = (element_t) malloc(sizeof(struct Node));
        int electronic,fashion;
        fscanf(fin,"%s %s %d %d\n",newNode->id,newNode->name,&electronic,&fashion);
        newNode->accumulated = electronic + fashion;
        newNode->electronicPayment = electronic;
        newNode->fashionPayment = fashion;
        newNode->numsFashion = 0;
        newNode->numsElectronic = 0;
        if(electronic > 0) newNode->numsElectronic = 1;
        if(fashion > 0) newNode->numsFashion = 1;
        insert(&head,newNode);
        if(newNode->accumulated > (*BestAcu)) (*BestAcu) = newNode->accumulated;
        printf("%-6s%-31s%-15d%d\n",newNode->id,newNode->name,newNode->electronicPayment,newNode->fashionPayment);
    }
    return head;
}

void printData(tree root){
    printf("%-6s%-30s%-15s%-15s%s\n","ID","Name","Accumualated","NumsElec","NumsFashion");
    traversal(root);
}
int checkNameError(char name[]){
    int i;
    for( i = 0 ; i <strlen(name); i++)
        if(name[i] == '@') return 1;
    return 0;
}
void scanfBestCustomer(tree root,int bestAccu){
    if(root == NULL) return;
    scanfBestCustomer(root->left,bestAccu);
    if(root->data->accumulated == bestAccu) printf("%-6s%-30s%-15d%-15d%d\n",root->data->id,root->data->name,root->data->accumulated,root->data->numsElectronic,root->data->numsFashion);
    scanfBestCustomer(root->right,bestAccu);
}
void countPayment(tree root,int *TotalElec,int *TotalFashion,int *TotalTransElec,int *TotalTransFashion){
    if(root == NULL) return;
    countPayment(root->left,TotalElec,TotalFashion,TotalTransElec,TotalTransFashion);
    (*TotalElec) = (*TotalElec) + root->data->numsElectronic;
    (*TotalFashion) = (*TotalFashion) + root->data->numsFashion;
    (*TotalTransElec) = (*TotalTransElec) + root->data->electronicPayment;
    (*TotalTransFashion) = (*TotalTransFashion) + root->data->fashionPayment;
    countPayment(root->right,TotalElec,TotalFashion,TotalTransElec,TotalTransFashion);
}