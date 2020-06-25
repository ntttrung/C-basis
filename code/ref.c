#include <stdio.h>
#include <string.h>
#include "park-list.h"
#include "bus-list.h"

void readParkOfBus(busItem *p, char *str){
    int i, j, k;
    int count = 0;

    i = 0;
    while(i < strlen(str)){
        j = i;
        while(j < strlen(str)){
            if(str[j] == ' ') break;
            j++;
        }
        for(k = i; k < j; k++) p->park[count][k-i] = str[k];
        p->park[count][k-i] = '\0';
        count++;
        i = j + 1;
    }
}

void printPark(parkNode *parkRoot){
    parkNode *temp = parkRoot;

    printf("\n\n%-20s%-s\n\n", "Diem Do", "Toa do");
    while(temp != NULL){
        printf("%-20s(%d, %d)\n", temp->data.id, temp->data.x, temp->data.y);
        temp = temp->next;
    }
    printf("________________________________________\n");
}

void printBus(busNode*busRoot){
    busNode *temp = busRoot;
    int i;

    printf("\n%-20s%-s\n\n", "Tuyen xe", "Lo trinh");
    while(temp != NULL){
        printf("%-20s", temp->data.id);
        printf("[ ");
        for(i = 0; i < temp->data.nPark; i++){
            printf("%s ", temp->data.park[i]);
        }
        printf("]\n");
        temp = temp->next;
    }

}

void readData(parkNode **parkRoot, busNode **busRoot){
    char str[50];
    FILE *file = fopen("DIEMDO.txt", "r");
    parkItem p;
    int nPark, i;

    //read park
    fgets(str, 5, file); sscanf(str, "%d", &nPark);
    for(i = 0; i < nPark; i++){
        fgets(str, 49, file);
        sscanf(str, "%s %d %d", p.id, &p.x, &p.y);
        *parkRoot = addPark(*parkRoot, p);
    }
    fclose(file);

    file = fopen("TUYENXE.txt", "r");
    char str1[50];
    busItem b;
    int nBus;

    //read bus
    fgets(str, 5, file); sscanf(str, "%d", &nBus);
    for(i = 0; i < nBus; i++){
        fgets(str, 49, file);
        sscanf(str, "%s %d %[^\n]", b.id, &b.nPark, str1);
        readParkOfBus(&b, str1);
        *busRoot = addBus(*busRoot, b);
    }
    fclose(file);

    printPark(*parkRoot);
    printBus(*busRoot);

}

void addAPark(parkNode **parkRoot){
    char str[10];
    parkItem p;
    parkNode *temp;

    while(1){
        printf("Nhap ID: "); scanf("%s", p.id);
        temp = findPark(*parkRoot, p.id);
        if(temp) printf("\nDiem do nay da ton tai\n");
        else break;
    }
    
    printf("Nhap toa do diem do\n"); 
    printf("\tNhap toa do x: ");
    scanf("%d",&p.x);
    printf("\tNhap toa do y: ");
    scanf("%d",&p.y);

    *parkRoot = addPark(*parkRoot, p);

    printPark(*parkRoot);
}

void addABus(busNode **busRoot, parkNode *parkRoot){
    busItem p;
    busNode *temp;
    parkNode *temp1;
    int flag;
    int i;

    while(1){
        printf("Enter ID: "); scanf("%s", p.id);
        temp = findBus(*busRoot, p.id);
        if(temp) printf("\nID da ton tai!\n");
        else break;
    }

    while(1){
        printf("Nhap so luong diem do: "); scanf("%d", &p.nPark);
        if(!p.nPark) printf("\nInvalid value!\n");
        else break;
    }

    i = 0;
    while(i < p.nPark){
        printf("Nhap so luong diem do %d: ", i+1);
        scanf("%s", p.park[i]);
        temp1 = findPark(parkRoot, p.park[i]);
        if(!temp1) printf("\nDiem do nay khong ton tai!\n");
        else i++;
    }

    *busRoot = addBus(*busRoot, p);

    printBus(*busRoot);
}

void findAnyBus(busNode *busRoot, parkNode *parkRoot){
    parkNode *tempPark;
    busNode *tempBus;
    char str[10];
    int i;

    printf("Nhap id cua diem do: "); scanf("%s", str);
    tempPark = findPark(parkRoot, str);
    if(!tempPark) printf("\nDiem Do nay khong ton tai!\n");
    else {
        tempBus = busRoot;
        while(tempBus != NULL){
            for(i = 0; i < tempBus->data.nPark; i++){
                if(!strcmp(tempBus->data.park[i], str)){
                    printf("%-20s", tempBus->data.id);
                    for(i = 0; i < tempBus->data.nPark; i++){
                        printf("%s ", tempBus->data.park[i]);
                    }
                    printf("\n");
                    break;
                }
            }
            tempBus = tempBus->next;
        }
    }
}

void findNearestPark(parkNode *parkRoot){
    parkNode *temp = parkRoot;
    parkNode *minPointer = NULL;
    float x, y;
    float min = 9999999, d;

    printf("Nhap x va y: "); scanf("%f %f", &x, &y);
    while(temp != NULL){
        d = (x - temp->data.x)*(x - temp->data.x) + (y - temp->data.y)*(y - temp->data.y);
        if(d < min){
            min = d;
            minPointer = temp;
        }
        temp = temp->next;
    }
    printf("%-20s%d, %d\n", minPointer->data.id, minPointer->data.x, minPointer->data.y);

}

void writeIntoFile(parkNode *parkRoot, busNode *busRoot){
    FILE *file = fopen("DIEMDO2.txt", "w+");
    parkNode *tempPark = parkRoot;
    fprintf(file, "%d\n", lengthPark(parkRoot));
    while(tempPark != NULL){
        fprintf(file, "%-20s%d, %d\n", tempPark->data.id, tempPark->data.x, tempPark->data.y);
        tempPark = tempPark->next;
    }
    fclose(file);

    file = fopen("TUYENXE2.txt", "w+");
    busNode *tempBus = busRoot;
    int i;
    fprintf(file, "%d\n", lengthBus(busRoot));
    while(tempBus != NULL){
        fprintf(file, "%-20s", tempBus->data.id);
        for(i = 0; i < tempBus->data.nPark; i++){
            fprintf(file, "%s ", tempBus->data.park[i]);
        }
        fprintf(file, "\n");
        tempBus = tempBus->next;
    }
    fclose(file);
}

int main(){
    int choice;
    parkNode *parkRoot = createListPark();
    busNode *busRoot = createListBus();

    do{
        printf("\n---------------------MENU-----------------\n");
        printf("1. Doc du lieu\n");
        printf("2. them diem do moi\n");
        printf("3. them tuyen xe\n");
        printf("4. Liet ke cac tuyen xe\n");
        printf("5. Tim cho do gan nhat\n");
        printf("6. Luu du lieu\n");
        printf("7. Exit\n");
        printf("Option: "); scanf("%d", &choice);
        switch(choice){
            case 1:{
                readData(&parkRoot, &busRoot);
                break;
            };
            case 2:{
                addAPark(&parkRoot);
                break;
            };
            case 3:{
                addABus(&busRoot, parkRoot);
                break;
            };
            case 4:{
                findAnyBus(busRoot, parkRoot);
                break;
            };
            case 5:{
                findNearestPark(parkRoot);
                break;
            }
            case 6:{
                writeIntoFile(parkRoot, busRoot);
                break;
            };
            case 7:{
                break;
            }
            default:{
                printf("\nInvalid value!\n");
                break;
            }
        }
    } while(choice != 7);

    return 0;
}