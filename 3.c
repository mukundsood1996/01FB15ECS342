/*3. Given two queues q1 and q2, your routine should return a new queue q3 that alternately merges q1 and q2 elements. (q11, q21, q12, q22 etc). The two original queues q1 and q2 should remain as before. (Hint: You can use additional data structures).*/

#include<stdio.h>
#include<stdlib.h>

int q1[20], q2[20], q3[40], q4[20], q5[20];
int q1_size = 0, q2_size = 0, q3_size = 0, q4_size = 0, q5_size = 0;

void enqueue(int *Q, int *size, int value);
int dequeue(int *Q, int *size);
int top(int *Q, int size);
void AlternateMerge();
void display(int *Q, int size); /*For verification*/

int main()
{
	/*taking inputs*/
	int n = 0;
	printf("Enter elements of the first queue, 0 to stop\n");
	while(1)
	{
		printf("number: ");
		scanf("%d", &n);
		if(n == 0)
			break;
		else
			enqueue(q1, &q1_size, n);
	}
	printf("Enter elements of the second queue, 0 to stop\n");
	while(1)
	{
		printf("number: ");
		scanf("%d", &n);
		if(n == 0)
			break;
		else
			enqueue(q2, &q2_size, n);
	}
	AlternateMerge();
	/*Queues are not meant to be traversed but this is to
	show that the task is completed*/
	printf("Merged queues: ");	
	display(q3, q3_size);
	printf("Elements of q1: ");
	display(q4, q4_size);
	printf("Elements of q2: ");
	display(q5, q5_size);
	return 0;
}

void enqueue(int *Q, int *size, int value)
{
	if (*size >= 20)
	{
		printf("Overflow\n");
		return;
	}
	Q[(*size)++] = value;
}

int dequeue(int *Q, int *size)
{
	if (*size == 0)
	{
		printf("Empty queue\n");
		return -1;
	}
	int i, temp = Q[0];
	for(i=0; i < *size; i++)
		Q[i] = Q[i+1];
	(*size)--;
	return temp;		
}

void AlternateMerge()
{
	while(q1_size || q2_size) /*loop to merge*/
	{
		if(q1_size)
		{
			enqueue(q4, &q4_size, top(q1, q1_size)); /*Saving the elements*/
			enqueue(q3, &q3_size, dequeue(q1, &q1_size));
		}
		if(q2_size)
		{
			enqueue(q5, &q5_size, top(q2, q2_size));
			enqueue(q3, &q3_size, dequeue(q2, &q2_size));
		}
	}
}

void display(int *Q, int size)
{
	if (size <= 0)
	{
		printf("Empty\n");
		return;
	}
	int i = 0;
	for(i=0; i < size; i++)
		printf(" -> %d", Q[i]);
	printf("\n");
}

int top(int *Q, int size)
{
	if (size <= 0)
	{
		printf("Empty\n");
		return -1;
	}
	return Q[0]; 	
}
