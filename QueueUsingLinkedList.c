#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node
{	int data;
	struct node *link;
}*first;
struct node *EndInsert(struct node *first)
{	struct node *p = (struct node*) malloc(sizeof(struct node));
	struct node *q;
	q=first;
	printf("Enter the data of the new node");
	scanf("%d",&p->data);
	p->link=NULL;
	if(first==NULL)
	{	first=p;
	}
	else
	{	while(q->link!=NULL)
		{	q=q->link;
		}
		q->link=p;
	}
	return first;
}
void display(struct node *first)
{	struct node *q;
	if(first!=NULL)
	{	printf("Front->");
	
		for(q=first;q->link!=NULL;q=q->link)
		{	printf("%d\t",q->data);
		}
		printf("%d",q->data);
		printf("<-Rear");
	}
	else
	{	printf("List is empty");
	}
}
struct node *EndDelete(struct node *first)
{	struct node *p,*q;
	if(first==NULL)
	{	printf("List is empty");
	}
	else if(first->link==NULL)
	{	free(first);
		first=NULL;
	}
	else
	{	q=first;
		while(q->link!=NULL)
		{	p=q;
			q=q->link;
		}
		free(q);
		p->link=NULL;
	}
	return first;
}void main()
{	int option;
	do
	{	system("cls");
		printf("\n------------QUEUE Operations----------\n");
		printf("1)Insert\n");
		printf("2)Delete\n");
		printf("3)Display\n");
		printf("4)Exit");
		scanf("%d",&option);
		switch(option)
		{	case 1: first=EndInsert(first);
					getch();
					break;
			case 2:	first=EndDelete(first);
					getch();
					break;
			case 3: display(first);
					getch();
					break;	
			case 4:exit(0);		
		}
	}while(1);
}
