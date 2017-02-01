//Linear Search 
#include <stdio.h>
#define MAX 30

int search(int l,int n,int arr1[])
{
	int i=0;
	int pos=-1;
	for(i=0;i<l;i++)
	{
		pos++;
		if(n==arr1[pos])
		{
			printf("%d found at position %d\n",n,pos+1);
			break;
		}
	}
	if(pos==(l-1))
	{
		printf("Sorry...Element not found!\n");
	}
}

int main()
{
//int arr[MAX]={4,5,7,23,34,76,54,32,19,45,67,66,23,43,64,84,98,90,19,86,23,54,65,14,26,37,75,24,58,44};
int arr[50];
int i,len,num,found;
printf("Enter the lenght of the array:");
scanf("%d",&len);
printf("Enter the array elements:");
for(i=0;i<len;i++)
{
	scanf("%d",&arr[i]);
}
printf("Enter number to find:");
scanf("%d",&num);
search(len,num,arr);
return 0;
}
