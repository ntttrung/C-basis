#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


typedef struct 
    {
        char word[10];
        char meaning[20];
    }
dictionary;


int main()
    {
        dictionary data[100];
        char *token;
        char str[100];
        char look[20];
        char c[2]=":";
        int i=1,j,k,dk=0;
        FILE *fin;
        if((fin=fopen("dictionary.txt","r"))==NULL)
            {
                printf("Can\'t read from phonebook.txt");
                exit(0);
            }
        else
            {
                while(fgets(str,100,fin)!=NULL)
                    {
                       token=strtok(str,c);
                       strcpy(data[i].word,token);
                       token=strtok(NULL,c);
                       strcpy(data[i].meaning,token);
                       i++;
                    }
            }
        printf("Enter the word: ");
        fflush(stdin);
        gets(look);
        for(j=1;j<i;j++)
            {
                for(k=0;k<strlen(look);k++)
                    {
                        if(toupper(data[j].word[k])==toupper(look[k]))
                            dk=1;
                        else
                            {
                                dk=0;
                                break;
                            }
                    }
                if(dk==1)
                    printf("%s\t:%s",data[j].word,data[j].meaning);
            }
        fclose(fin);
        return(0);
    }



