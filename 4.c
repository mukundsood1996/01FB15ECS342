/*4. Implement Josephus problem using a circular queue.
For a given input k, your program should print the sequence of numbers exiting the queue.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *head;

int k, size = 0;

void enqueue(int value);
void dequeue();

int main()
{
	head = malloc(sizeof(node));
	int n;

	printf("Enter the unique numbers for each person, 0 to stop\n");
	while(1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		enqueue(n);
	}
	printf("Enter number of people to be skipped: ");
	scanf("%d", &k);
	
	while(size > 1)
		dequeue();

	printf("%d will be freed!\n", head->data);
	return 0;
}

void enqueue(int value)
{
	if (size == 0)
	{
		head->data = value;
		head->next = head;
	}
	else
	{
		node *temp = head;
		node *new = malloc(sizeof(node));
		new->next = head;
		new->data = value;
		while(temp->next != head)
			temp = temp->next;	
		temp->next = new;
	}
	size++;
}
void dequeue()
{
	if (size <= 1)
		return;
	node *temp = head;
	int i;
	for(i=1; i<k; i++)
		temp =  temp->next;
	node *temp2 = temp->next; //node to be removed
	printf("%d will be executed\n", temp2->data);
	temp->next = temp2->next;
	free(temp2);
	head = temp->next;
	size--;
}
