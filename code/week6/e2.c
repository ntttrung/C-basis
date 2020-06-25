#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct 
    {
        char name[25];
        char phone[15];
        char email[30];
    }
Address;


int main()
    {
        Address data[15];
        char *token;
        char str[100];
        char name[20];
        char c[2]="|";
        int i=1,j;
        FILE *fin,*fout;
        if((fin=fopen("phonebook.txt","r"))==NULL)
            {
                printf("Can\'t read from phonebook.txt");
                exit(0);
            }
        else
            {
                fout=fopen("newfile.txt","w");
                while(fgets(str,80,fin)!=NULL)
                    {
                       token=strtok(str,c);
                       strcpy(data[i].name,token);
                       token=strtok(NULL,c);
                       strcpy(data[i].phone,token);
                       token=strtok(NULL,c);
                       strcpy(data[i].email,token);
                       i++;
                    }
            }
        printf("Enter the name: ");
        fflush(stdin);
        gets(name);
        for(j=1;j<i;j++)
            if(strcasecmp(name,data[j].name)==0)
                {
                    fputs(data[j].name,fout);
                    fputs("\t",fout);
                    fputs(data[j].phone,fout);
                    fputs("\t",fout);
                    fputs(data[j].email,fout);
                    fputs("\n",fout);
                }
        fclose(fin);
        fclose(fout);
        return(0);
    }



