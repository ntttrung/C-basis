#include<stdio.h>
#include "stack-array.h"
#include<string.h>
#include<ctype.h>
int main()
{
	char postfix[50];
	gets(postfix);
	stack s;
	s = create_stack();
	int i,result=0;
	for(i=0;postfix[i] != '\0';i++)
	{
		if (isdigit(postfix[i]))
		{
			push(s,postfix[i]-'0');
		}
		else
		{
			int a = top(s);
			s = pop(s);
			int b = top(s);
			s = pop(s);
			if (postfix[i] == '+')
			{
				result = (a) + (b);
			}
			if(postfix[i] == '-')
			{
				result = (a) - (b);
			}
			if(postfix[i] == '*')
			{
				result = (a) * (b);
			}
			if( postfix[i] == '/')
			{
				result = (a) + (b);
			}
			//printf("%d\n",result );
			push(s, result);
		}
	}
	printf("%d\n",result);
}
