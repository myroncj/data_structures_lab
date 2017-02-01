#include <stdio.h>
#define max 10
 
int top1, top2, stk_arr[max];
 
void push();
void pop();
void display();
 
void main()
{
	int ch;
	top1=-1,top2=max;
	do
	{
		printf("\n 1: Push\n 2: Pop\n 3: Display\n 4: Exit\n Enter Choice:");
		scanf("%d", &ch);
		switch (ch)	
		{
		case 1:push();
			break;
		case 2:pop();
			break;
		case 3:display();
			break;
		case 4:printf("Exiting from program...\n");
			break;
		default:printf("Invalid Choice\n");
			break;
		}
	}while(ch!=4);
}

void push()
{
	int x,ch;
	if(top1==top2-1)
	{
		printf("Stack Overflow \n");
		return;
	}
	printf("Enter a No: \n");
	scanf("%d",&x);
	printf("\n Press 1 to Push in stack1 OR Press 2 for Stack2:");
	scanf("%d",&ch);
	if(ch==1)
	stk_arr[++top1]=x;
	else
	stk_arr[--top2]=x;
	printf("\n %d element is successfully pushed \n",x);
	return;
}
 
void pop()
{
	int y,ch;
	printf("\n Press 1 to Pop from Stack1 OR Press 2 for Stack2:");
	scanf("%d",&ch);
	if(ch==1)
	{
		if(top1==-1)
		{
			printf("Stack Underflow\n");
			return;
		}
	y=stk_arr[top1];	
	stk_arr[top1--]=0;
	}
	else
	{
		if(top2==max)
		{
			printf("Stack Underflow\n");
			return;
		}
	y=stk_arr[top2];
	stk_arr[top2++]=0;
	}
	printf("\n%d Element is successfully POPed from stack \n", y);
	return;
}
 
void display()
{
	int i;
	if (top1 == -1)
	{
		printf("Stack 1 Underflow \n");
	}
	else
	{	
		printf("Elements of Stack 1 are : \n");
		for (i = 0; i <= top1; i++)
		{
			printf("%d\n",stk_arr[i]);
		}
	}
	if (top2 == max)
	{
		printf("Stack 2 Underflow \n");
	}
	else
	{
		printf("Elements of Stack 2 are : \n");
		for (i = max-1; i >= top2; i--)
		{
		printf("%d\n",stk_arr[i]);
		}
	}
	return;
}