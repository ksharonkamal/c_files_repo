#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>//for getpid
#define MAX 20


void input(int * ptr,int size);
void display(int * ptr,int size);
void bubble(int *ptr,int size);


int main()
{
	int a[MAX];
	input(a,MAX);//for initialisation
	printf("elements before sorting\n");
	display(a,MAX);
	bubble(a,MAX);
	printf("elements after sorting\n");
	display(a,MAX);
}

void bubble(int *ptr,int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		for(j=0;j<size-i;j++)
		{
			if(ptr[j]>ptr[j+1])
			{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
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
