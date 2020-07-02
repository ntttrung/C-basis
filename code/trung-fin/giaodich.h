#ifndef __BANK__
#define __BANK__
#include "tree.h"
tree read_db(FILE *fin,int *BestAcu);

int checkDuplicate(tree node,keyvalue x);

void printData(tree root);
int checkNameError(char name[]);
void scanfBestCustomer(tree root,int bestAccu);
void countPayment(tree root,int *TotalElec,int *TotalFashion,int *TotalTransElec,int *TotalTransFashion);
#endif