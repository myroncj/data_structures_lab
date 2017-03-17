#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node
{	int data;
	struct node *link;
}*first;
struct node *BeginInsert(struct node *first)
{	struct node *p = (struct node*) malloc(sizeof(struct node));
	printf("Enter the data of the new node");
	scanf("%d",&p->data);
	if(first==NULL)
	{	first=p;
		first->link=NULL;
	}
	else
	{	p->link=first;
		first=p;
	}
	return first;
}
void display(struct node *first)
{	struct node *q;
	if(first!=NULL)
	{	printf("top->");
		for(q=first;q->link!=NULL;q=q->link)
		{	printf("%d\t",q->data);
		}
		printf("%d",q->data);
		
	}
	else
	{	printf("List is empty");
	}
}
struct node *FrontDelete(struct node *first)
{	struct node *p;
	if(first==NULL)
	{	printf("List is empty");
	}
	else if(first->link==NULL)
	{	free(first);
		first=NULL;
	}
	else
	{	p=first;
		first=p->link;
		free(p);
	}
	return first;
}
void main()
{	int option;
	do
	{	system("cls");
		printf("\n------------Stack Operations----------\n");
		printf("1)Push\n");
		printf("2)Pop\n");
		printf("3)Display\n");
		printf("4)Exit");
		scanf("%d",&option);
		switch(option)
		{	case 1: first=BeginInsert(first);
					getch();
					break;
			case 2:	first=FrontDelete(first);
					getch();
					break;
			case 3: display(first);
					getch();
					break;	
			case 4:exit(0);		
		}
	}while(1);
}
