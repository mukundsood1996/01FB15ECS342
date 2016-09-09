/*2. An array called twoStacks[n] is used to represent two stacks. Stack1 has top1=0 starting at first element of the array. Stack2 has top2=n starting at the last element of the array. Write algorithm for push, pop, operations for both the stacks.*/

#include<stdio.h>
#include<stdlib.h>
#define  UP 50

int twoStacks[UP];
int size1 = 0, size2 = 0;

void push1(int value)
{
	if ((size1 + size2) >= UP)
	{
		printf("overflow\n");
		return;
	}
	int i;
	for(i = size1; i; i--)
		twoStacks[i] = twoStacks[i-1];
	twoStacks[0] = value;
	size1++;
}
void pop1()
{
	if (size1 <= 0)
	{
		printf("empty\n");
		return;
	}
	printf("popped from 1: %d\n", twoStacks[0]);
	int i;
	for(i=0; i<size1; i++)
		twoStacks[i] = twoStacks[i+1];
	size1--;
}
void pop2()
{
	if (size2 <= 0)
	{
		printf("empty\n");
		return;
	}
	printf("popped from 2: %d\n", twoStacks[UP]);
	int i;
	for(i=UP; i> UP-size2; i--)
		twoStacks[i] = twoStacks[i-1];
	size2--;
}
void push2(int value)
{
	if ((size1 + size2) >= UP)
	{
		printf("overflow\n");
		return;
	}
	int i;
	for(i = UP-size2; i<UP; i++)
		twoStacks[i] = twoStacks[i+1];
	twoStacks[UP] = value;
	size2++;
}

int main()
{
	int ch, value;
	printf("There are two stacks 1 and 2. Choose the operation\n");
	while(1)
	{
		printf("1.Push in 1\t2.Pop from 1\t3.Push in 2\t4.Pop from 2\t5.Quit\n");
		printf("Your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Number to push in stack1: ");
				scanf("%d", &value);
				push1(value);
				break;
			case 2: pop1();
				break;
			case 3: printf("Number to push in stack2: ");
				scanf("%d", &value);
				push2(value);
				break;
			case 4: pop2();
				break;
			case 5: return 0;
				break;
			default: printf("Invalid choice\n");
		}
	}
	return 0;
}
