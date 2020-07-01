#include<stdio.h>
#include<stdlib.h>


#include<string.h>
#include "tree.h"


void menu()
{
    printf("---------------MENU------------\n");
    printf("1.Load  Data\n");
    printf("2.Show Statistics Data\n");
    printf("3.Manually add Transaction \n");
    printf("4.Data Analysis\n");
    printf("5,Exit\n");
}

tree t;

void read_data()
{
    char filename[20]="giaodich.txt";
    FILE *pt;
    pt = fopen(filename, "r");
    if (pt == NULL )
    {
        printf("Cannot open file %s\n",filename );
    } 

    else
    {
        char str[50];
        element_t tmp;
        tree p;
        while(fgets(str, 50, pt) != NULL)
        {
            sscanf(str,"%s %s %lld %lld",tmp.id, tmp.name, &tmp.total1[1], &tmp.total2[1]);
            p = searchBST(t, tmp.id);
            if (p==NULL)
            {
                if (tmp.total1[1] > 0)
                {
                    tmp.electronics = 1;
                }
                else 
                    tmp.electronics = 0;
                if (tmp.total2[1] > 0)
                {
                    tmp.fashion = 1;
                }
                else
                    tmp.fashion = 0;

                t = insertBST(t, tmp);
            }
            else
            {
                if (tmp.total1[1] > 0)
                {
                
                    p->data.electronics += 1;
                    p->data.total1[p->data.electronics] = tmp.total1[1];
                }
                if (tmp.total2[1] >0)
                {
                    p->data.fashion += 1;
                    p->data.total2[p->data.fashion] = tmp.total2[1];
                }
            }

        } 


    }
    fclose(pt);
}
void print_data(tree t)
    {
        FILE* fin;
        int i,n,j;
        fin=fopen("giaodich.txt","r");
        char str[50];
        element_t tmp;
        tree p;
        while(fgets(str, 50, fin) != NULL)
        {
            sscanf(str,"%s %s %lld %lld",tmp.id, tmp.name, &tmp.total1[1], &tmp.total2[1]);
            printf("%-20s %-20s %-15lld %-15lld\n",tmp.id,tmp.name,tmp.total1[1],tmp.total2[1]);
         }
    }
void show()
{
    breadth_first_search(t);
}
int checkname(char *x)
{
    int i,dk = 0;
    for( i=0;i<strlen(x);i++)
    {
        if (x[i] == '@')
        {
            return 1;
            break;
        }

        else
            dk ++;
    }
    if(dk == strlen(x))
        return 0;
}
void Add_infor()
{
    
    element_t tmp;
    printf("Enter the ID: ");
    fflush(stdin);
    gets(tmp.id);
    tree p;
    p = searchBST(t, tmp.id);
    if (p==NULL)
    {
        do
        {
            printf("Enter name: ");
            gets(tmp.name);
            if(checkname(tmp.name) == 1)
                printf("Name should not contain @\n");

        }while(checkname(tmp.name) != 0);
        do
        {
            printf("Enter payment on electronics: ");
            scanf("%lld", &tmp.total1[1]);
            printf("Enter payment on fashion: ");
            scanf("%lld", &tmp.total2[1]);

        }while(tmp.total1[1] < 0 || tmp.total2[1] <0);
        if (tmp.total1[1] > 0)
            tmp.electronics = 1;
        else
            tmp.electronics = 0;
        if(tmp.total2[1]>0)
            tmp.fashion = 1;
        else
            tmp.fashion = 0;
        t = insertBST(t, tmp);
    }
    else
    {
        
        
        do
        {
            printf("Enter payment on electronics: ");
            scanf("%lld", &tmp.total1[1]);
            printf("Enter payment on fashion: ");
            scanf("%lld", &tmp.total2[1]);

        }while(tmp.total1[1] < 0 || tmp.total2[1] <0);
        if (tmp.total1[1]>0)
        {
            p->data.electronics += 1;
            p->data.total1[p->data.electronics] = tmp.total1[1];
        } 
        if(tmp.total2[2] > 0)
        {
            p->data.fashion +=1;
            p->data.total2[p->data.fashion] = tmp.total2[1];
        }

    }
    printf("Successful updated\n");
    


}
long long int comput_total(long long int *arr1, long long int *arr2, int n, int m)

{
    long long int total=0;
    int i;
    for(i=1;i<=n;i++)
    {
        total += arr1[i];
    }
    for(i = 1;i<=m;i++)
    {
        total += arr2[i];
    }
    return total;
}

void Analysis()
{
    Best(t);
    TotalPayment(t);

}

int main()
{
    char c;
    menu();
    while((c=getchar()) != '5')
    {
        if (c=='1')
        {
            read_data();
            print_data(t);
            menu();
        }
        
        if (c=='2')
        {
            show();
            menu();
        }
        if(c=='3')
        {
            Add_infor();
            menu();
        }
        if(c=='4')
        {
            Best(t);
            TotalPayment(t);
            menu();
        }
    }
}