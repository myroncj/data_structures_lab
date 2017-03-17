#include<stdio.h>
#include<conio.h>
#include<process.h>
int stack[10];
int f=-1,r=-1,size=5;
void reverse()
{	int f1,r1,temp;
	f1=f;
	r1=r;
	while(f1<r1)
	{	temp=stack[f1];
		stack[f1]=stack[r1];
		stack[r1]=temp;
		f1++;
		r1--;
	}
}
void insert(int n)
{	
	if(f==-1 && r==-1)
	{	
		f++;
		r++;
		stack[r]=n;
	}
	else if(r==size-1)
		printf("The stack is full");
	else
	{	
		r++;
		stack[r]=n;
	}
}
int deleteQ()
{	
	int a;
	if(f==-1 && r==-1)
		printf("Stack is empty");
	else
	{	
		a=stack[f++];
		if(f>r)
		{	
			f=-1;
			r=-1;
		}
		return a;
	}
}
void pop(int f)
{	
	int a;
	if(f==r)
		deleteQ();
	else
	{	
		a=deleteQ();
		pop(f+1);
		insert(a);
	}
}
void display()
{	int i;
	for(i=f;i<=r;i++)
		printf("%d\t",stack[i]);
}
void main()
{	while(1)
	{	int ch;
		system("cls");
		printf("\n\n\t Program Of Stack Opration.\n");
		printf("\n\t 1. Push");
		printf("\n\t 2. Pop");
		printf("\n\t 3. Display");
		printf("\n\t 0. Exit");
		printf("\n\t Enter the choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter a number to insert");
					scanf("%d",&ch);
					insert(ch);
					getch();
					break;
			case 2:	pop(f);
					reverse();
					getch();
					break;
			case 3:	display();
					getch();
					break;
			case 0:exit(1);
			default:printf("\n Invalid Choice");
		}
	}
}
