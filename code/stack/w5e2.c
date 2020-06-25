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
        int i,j=0,dk;
        char *pol;
        address tmp;
        stack s=create_stack();
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
                            {
                                tmp.c=str[i];
                                s=push(s,tmp);
                            }
                        else
                            {
                                stack p=s;
                                while(p->top!=0)
                                    {
                                        if(rank((s->data[s->top]).c)<=rank(str[i]))
                                            {
                                                dk=1;
                                                break;
                                            }
                                        else if(rank((s->data[s->top]).c)>rank(str[i]))
                                            {
                                                dk=0;
                                                break;
                                            }
                                        p=pop(p);
                                    }
                                if(dk==1)
                                    {
                                        tmp.c=str[i];
                                        s=push(s,tmp);
                                    }
                                else
                                    {
                                        pol[j]=str[i];
                                        j++;
                                    }


                            }
                    }

            }
        while(s->top!=0)
            {
                pol[j]=(s->data[s->top]).c;
                j++;
                s=pop(s);
            }
        return pol;
    }

int main()
    {
        char str[30];
        printf("Enter the notation: ");
        fflush(stdin);
        gets(str);
        puts(polish_str(str));
        // return 1;        
    }