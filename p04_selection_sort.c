//Selection_sort
#include <stdio.h>
#define MAX 10

int sel_sort(int arr1[])
{
	int i,j,temp;

	printf("Before sorting:\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\t",arr1[i]);
	}

	for(i=0;i<(MAX);i++)
		{
			for(j=i+1;j<(MAX);j++)
			{
				if(arr1[i] > arr1[j])
				{
					temp=arr1[i];
					arr1[i]=arr1[j];
					arr1[j]=temp;
				}
			}
		}

	printf("\nAfter sorting:\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\t",arr1[i]);
	}
	printf("\n");	
}

int main()
{
	int arr[MAX]={4,5,7,23,34,76,54,32,19,1};
	sel_sort(arr);
	return 0;
}
