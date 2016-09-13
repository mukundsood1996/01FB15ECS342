/*5. Write a program (or algorithm) to convert postfix expression to infix.*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char value;
    struct node *next;
} node;

void push(node**, char);
char pop(node**);
void display(node*);
int isempty(node*);
int size;

int main()
{
	node *a = NULL,*b1 = NULL,*b2 = NULL;
	size = 0;
	int i,c1,c2;
	char post[50];
	printf("Enter a valid expression: ");
	scanf("%s", post);
	for(i = 0; post[i] != '\0'; ++i)
	{
		if(post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^')
		{
			c1 = 0;c2 = 0;
			do
			{
				if(a -> value == ')')
					++c1;
				push(&b1,pop(&a));
				if(b1 -> value == '(')
					++c2;
			}while(c1 != c2);
			
			c1 = 0;c2 = 0;
			do
			{
				if(a -> value == ')')
					++c1;
				push(&b2,pop(&a));
				if(b2 -> value == '(')
					++c2;
			}while(c1 != c2);
			
			push(&a,'(');
			while(!isempty(b2)){
				push(&a,pop(&b2));
			}
			push(&a,post[i]);
			while(!isempty(b1)){
				push(&a,pop(&b1));
			}
			push(&a,')');	
		}	
		else
			push(&a,post[i]);
	}
	while(!isempty(a))
		push(&b1,pop(&a));
	while(!isempty(b1))
		printf("%c",pop(&b1));
	printf("\n");
	return 0;
}

void push(node **top,char v)
{
	node *temp = malloc(sizeof(node));
	temp -> value = v; 
	if(isempty(*top)){
		*top = temp;
		(*top) -> next = NULL;
	}
	else{
		temp -> next = *top;
		*top = temp;
	}
	++size;
}

char pop(node **top)
{
	char r;
	if(isempty(*top)){
		printf("underflow\n");
	}
	else{
		node *t = *top;
		*top = (*top) -> next;
		r = t -> value;
		free(t);
		--size;
		return r;
	}
}

int isempty(node *top)
{
	if(top == NULL)
		return 1;
	return 0;	
}

