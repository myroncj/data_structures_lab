//Merge_sort
#include <stdio.h>

void merge_all(int arr1[],int l1,int u1,int l2,int u2)
{
	int temp[50];
	int st1,st2,k=0;
	st1=l1;
	st2=l2;

	while(st1<=u1 && st2<=u2)
	{
		if(arr1[st1]<arr1[st2])
		{
			temp[k++]=arr1[st1++];
		}
		else
		{
			temp[k++]=arr1[st2++];
		}
	}

	while(st1<=u1)
	{
		temp[k++]=arr1[st1++];
	}

	while(st2<=u2)
	{
		temp[k++]=arr1[st2++];
	}

	for(st1=l1,st2=0;st1<=u2;st1++,st2++)
	{
		arr1[st1]=temp[st2];
	}	
}

void merge_sort(int arr1[],int l,int u)
{
	int mid;

	if(l<u)
	{
		mid=(l+u)/2;
		merge_sort(arr1,l,mid);
		merge_sort(arr1,mid+1,u);
		merge_all(arr1,l,mid,mid+1,u);
	}
}

int main()
{
	int arr1[50],len=0;
	int i;

	printf("Enter the lenght of array:");
	scanf("%d",&len);
	printf("\nEnter %d elements:",len);
	for(i=0;i<len;i++)
	{
		scanf("%d",&arr1[i]);
	}
	merge_sort(arr1,0,len-1);
	printf("The sorted array is...\n");
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr1[i]);
	}	
	printf("\n");
	return 0;
}
