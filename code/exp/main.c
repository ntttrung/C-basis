#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "stack-array.h"

int eval(int x, int y, char ex)
    {
        if(ex=='+') return x+y;
        if(ex=='-') return x-y;
        if(ex=='*') return x*y;
        if(ex=='/') return x/y;
    }

int polish(char* str)
    {
        int i,temp;
        stack s=create_stack();
        for(i=0;i<strlen(str);i++)
            {
                if(isdigit(str[i])!=0)
                    {
                        s=push(s,str[i]-'0');
                    }
                else 
                    {
                        temp=top(s);
                        s=pop(s);
                        temp=eval(top(s),temp,str[i]);
                        s=pop(s);
                        s=push(s,temp);
                    
                    }
            }
        return top(s);
    }
int priority(char c)
    {
        if(c=='+'||c=='-') return 1;
        if(c=='*'||c=='/') return 2;
        if(c=='^') return 3;
    }
int main()
    {
        stack s=create_stack();
        int count=0,i;
        char str[20],resul[20];
        printf("Enter bieu thuc trung to: ");
        fflush(stdin);
        gets(str);
        for(i=0;i<strlen(str);i++)
            {
                if(isdigit(str[i])!=0)
                    {
                        resul[count]=str[i];
                        count++;
                    }
                else 
                    {
                        if(top(s)==-1)
                            
                    }
            }
    }