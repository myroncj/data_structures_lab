//Bubble sort
#include <stdio.h>
#define MAX 10

int bub_sort(int arr1[])
{
	int i,j,temp;

	printf("Before sorting:\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\t",arr1[i]);
	}

	for(i=0;i<(MAX-1);i++)
		{
			for(j=0;j<(MAX-i-1);j++)
			{
				if(arr1[j] > arr1[j+1])
				{
					temp=arr1[j];
					arr1[j]=arr1[j+1];
					arr1[j+1]=temp;
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
	int arr[MAX]={4,5,7,23,34,76,54,32,19,45};
	bub_sort(arr);
	return 0;
}
