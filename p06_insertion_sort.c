#include <stdio.h>

void insertion_sort(int arr1[],int l)
{
	int c,d,temp;
	for(c=1;c<=l-1;c++)
	{
		d=c;
		while(d > 0 && arr1[d] < arr1[d-1])
		{
			temp=arr1[d];
			arr1[d]=arr1[d-1];
			arr1[d-1]=temp;
			d--;
		}
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
	insertion_sort(arr1,len);
	printf("The sorted array is...\n");
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr1[i]);
	}	
	printf("\n");
	return 0;
}