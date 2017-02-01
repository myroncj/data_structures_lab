//Binary Search
#include <stdio.h>

int b_search(int len,int num,int arr1[])
{
	int lwr=0;
	int upr=len-1;
	int mid=(lwr+upr)/2;

	while(lwr <= upr)
	{
		if(arr1[mid] < num)
		{
			lwr=mid+1;
		}
		else if(arr1[mid]==num)
		{
			printf("%d found at position: %d \n",num,mid+1);
			break;
		}
		else
		{
			upr=mid-1;
		}

		mid=(lwr+upr)/2;
	}

	if(lwr > upr)
	{
		printf("Sorry...Element not found!\n");
	}
}

int main()
{
	//int arr[MAX]={11,22,33,44,55,66,77,88,99};
	int arr[50];
	int len,i;
	printf("Enter the lenght of the array:");
	scanf("%d",&len);
	printf("Enter the elements of the array:");
	for(i=0;i<len;i++)
		{
			scanf("%d",&arr[i]);
		}
	int num,found;
	printf("Enter number to find:");
	scanf("%d",&num);
	b_search(len,num,arr);
	return 0;
}