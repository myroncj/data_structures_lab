#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int q1[MAX];
int q2[MAX];

int q1r = -1, q2r = -1;
int q1f = -1, q2f = -1;

void pop();
void push();
void display();

void main()
{
	int ch;
	while(1)
	{
		printf("\n1. Push Element.");
		printf("\n2. Pop Element.");
		printf("\n3. Display.");
		printf("\n4. Exit");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:exit(0);

			default:printf("\n\nInvalid Choice!!\n");
		}
	}
}

void push()
{
	int element;
	if(q1r == MAX - 1)
	{
		printf("\n\n--Stack Overflow!--\n\n");
		return;
	}
	else
	{
		if(q1f == -1)
		q1f = 0;
		printf("\nEnter element to be inserted:");
		scanf("%d",&element);
		q1r = q1r + 1;
		q1[q1r] = element;
	}
}

void pop()
{
	int element;
	if(q1f == -1 || q1f > q1r)
	{
		printf("\n\nStack Underflow!--\n\n");
		return;
	}
	else
	{
		while(q1f != q1r)
		{
			if(q2f == -1)
				q2f = 0;
			//q2r = q2r + 1;
			q2[++q2r] = q1[++q1f];
		}

		element=q1[q1f];
		q1r=q1f=-1;

		while(q2f != q2r)
		{
			if(q1f == -1)
				q1f = 0;
			//q1r = q1r + 1;
			q1[++q1r] = q2[++q2f];
		}
		q2f=q2r=-1;
	}
	printf("Element deleted: %d",element);
}

void display()
{
	if(q1f == -1)
		printf("\n\n--Stack Underflow!--\n\n");
	else
	{
		printf("Queue is :\t");
		for(int i=q1f; i<=q1r; i++)
		{
			printf("\t%d",q1[i]);
		}
		printf("\n\n");
	}
}