#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>//for getpid
#define MAX 20


void input(int * ptr,int size);
void display(int * ptr,int size);
void selection(int *ptr,int size);

int main()
{
	int a[MAX];
	input(a,MAX);//for initialisation
	printf("elements before sorting\n");
	display(a,MAX);
	selection(a,MAX);
	printf("elements after sorting\n");
	display(a,MAX);
}

void selection(int *ptr,int size)
{
	int i,j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(ptr[i]>ptr[j])
			{
				temp=ptr[i];
				ptr[i]=ptr[j];
				ptr[j]=temp;
			}
		}
	}
}

void input(int * ptr,int size)
{
	int i=0;
	srand(getpid());
	for(i=0;i<size;i++)
		ptr[i]=rand()%100;
}

void display(int * ptr,int size)
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%d ",ptr[i]);
	printf("\n");
}
