#include<conio.h>
#include<stdio.h>
int binarysearch(int a[10],int low,int high,int seek)
{	int mid=(high+low)/2;
	if (high<low)
		printf("Element not found");
	if(a[mid]==seek)
		printf("Element is in the %d position",mid+1);
	else if(a[mid]>seek)
		binarysearch(a,low,mid-1,seek);
	else 
		binarysearch(a,mid+1,high,seek);
}
void main()
{	int i,j,n,a[10],temp,pos;
	printf("Enter the limit of N");
	scanf("%d",&n);
	printf("Enter the sorted array elements one by one");
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);
	}
	printf("Enter the search element");
	scanf("%d",&temp);
	binarysearch(a,0,n,temp); 
}

