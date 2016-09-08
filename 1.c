/*1. Write a program that reads in a positive integer and prints the binary representation of that integer.
Hint:  divide the integer by 2 and use stack or queue.*/

#include<stdio.h>
#include<stdlib.h>

int *stack;
int SIZE = 0;

void push(int value)
{
	stack = (int *)realloc(stack, sizeof(int)*(++SIZE));
	stack[SIZE-1]= value;
}
int pop()
{
	if (SIZE)
	{
		int temp = stack[SIZE-1];
		stack = (int *)realloc(stack, sizeof(int)*(--SIZE));		
		return temp;
	}
	else
	{
		printf("Stack empty\n");
		return -1;
	}
}

int main()
{
	int n = 1;
	printf("Enter number: ");
	scanf("%d", &n);
	if (n <= 0)
	{
		printf("Invalid entry\n");
		return 0;
	}
	while(n)
	{
		push(n%2);
		n /= 2;
	}
	while(SIZE)
		printf("%d", pop());
	printf("\n");
	return 0;	
}
