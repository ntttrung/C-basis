#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack-arr-struct.h"
#include<ctype.h>


int rank(char c)
    {
        switch(c)
            {
                case '+':
                case '-': 
                    return 1;
                case '*':
                case '/': 
                    return 2;
                case '^': 
                    return 3; 
            }
    }
char* polish_str(char *str)
    {
        int i,j=0;
        char *pol;
        stack s=create_stack();
        for(i=0;i<strlen(str),i++)
            {
                if(isdigit(str[i])!=0)
                    {
                        pol[j]=str[i];
                        j++;
                    }

            }
        return pol;
    }

int main()
    {
        char str[30];
        printf("Enter the Polish notation: ");
        fflush(stdin);
        gets(str);
        printf("%d\n",polish_notation(str));
    }