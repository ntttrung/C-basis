#include<stdio.h>
#include "stack-array.h"
#include<string.h>
#include<ctype.h>
int prior(char x)
{
	if (x=='(')
		return 0;
	if( x == '*' || x=='/' || x=='%')
		return 2;
	if( x =='+' || x=='-')
		return 1;
	return 3;
}
int main()
{
	stack s;
	s = create_stack();
	char postfix[50];
	char infix[50];
	gets(infix);
	int i,j=0;
	for(i=0; infix[i] != '\0';i++)
	{
		if (isdigit(infix[i]))
		{

			postfix[j++] = infix[i];

		}

		else
		{
			if (infix[i] == ')')
				push(s, infix[i]);
			else
			{
				if (infix[i] == '(')
				{
					while(top(s) != ')')
					{
						postfix[j++] = top(s);
						s = pop(s);
					}
				}
				else
				{
					
					if (is_empty(s))
					{
						push(s, infix[i]);	
					}
					else
					{
						while(!is_empty(s))
						{
							if ((prior(infix[i]) < prior(top(s))))

							{
								postfix[j++]=top(s);
								s=pop(s);
							} 
						}
						push(s, infix[i]);
					}
				}

			}
		}
	}
	while(!is_empty(s))
	{
		postfix[j++] = top(s);
		s = pop(s);
	}
	postfix[j] = '\0';
	printf("%s\n",postfix);

}