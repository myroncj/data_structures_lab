#include <stdio.h>

void insort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp = arr[i];
		j=i-1;
		while(temp<arr[j] && j>=0) //Descending temp>arr[j]
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
int max(int arr[],int n)
{	
	int maximum;
	int i;
	for(i=1;i<n;i++)
	{	
		if(maximum<arr[i])
			maximum=arr[i];
	}
	return maximum;
}
void bucketsort(int arr[],int n)
{	
	int buckets[10][10],bcount[10],i,j,maximum,divisor=1;
	for(i=0;i<10;i++)
		bcount[i]=0;
	maximum=max(arr,n);
	while(maximum>10)
	{	maximum=maximum/10;
		divisor=divisor*10;
	}
	for(i=0;i<n;i++)
	{	j=arr[i]/divisor;
		buckets[j][bcount[j]]=arr[i];
		bcount[j]++;
	}
	for(i=0;i<9;i++)
	{	
		if(bcount[i]!=0)
			insort(buckets[i],bcount[i]);
	}
	printf("\nAfter sorting: ");
	for(i=0;i<9;i++)
	{
		for(j=0;j<bcount[i];j++)
			printf("%d ",buckets[i][j]);	
	}
}
void main()
{
	int arr[50],i,n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Before sorting: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	bucketsort(arr,n);
	printf("\n");
}