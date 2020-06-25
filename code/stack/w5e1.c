#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"stack-array.h"
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
        stack s;
        char *pol;
        char c;
        int dk=0,i,j=0;
        for(i=0;i<strlen(str);i++)
            {
                if(isdigit(str[i])!=0)
                    {
                        pol[j]=str[i];
                        j++;
                    }
                else
                    {
                        if(s->top==0)
                            s=push(s,str[i]);
                        else 
                            {
                                stack tmp=s;
                                while(tmp->top!=0)
                                    {
                                        if(rank(top(tmp))<=rank(str[i]))
                                            {
                                                dk=1;
                                                tmp=pop(tmp);
                                            }
                                        else
                                            {
                                                dk=0;
                                                break;
                                            }
                                    }
                                if(dk==1)
                                    s=push(s,str[i]);
                                else 
                                    {
                                        c=top(s);
                                        while(top(s)!=c)
                                            {
                                                pol[j]=str[i];
                                                j++;
                                                s=pop(s);
                                            }
                                    }


                            }
                    }
            }
        pol[j]='\0';
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
    