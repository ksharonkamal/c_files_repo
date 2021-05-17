#include<stdio.h>
int recursive(int *arr,int num,int index,int size);
void non_recursive(int *arr,int num,int size);
int main()
{
	int array[20];
	int i;
	int flag=0,num;

	srand(getpid());
	for(i=0;i<20;i++)
		array[i]=rand()%20;

	for(i=0;i<20;i++)
		printf("%d ",array[i]);
	printf("\n");

	printf("enter number to be searched:");
	scanf("%d",&num);
	non_recursive(array,num,20);

	flag=recursive(array,num,0,20);
	if(flag!=-1)
		printf("vlaue found at index %d\n",flag);
	else
		printf("value not found\n");
	
//	non_recursive(array,num,20);

}

int recursive(int *arr,int num,int index,int size)
{

	int position=0;
	if(index > size)
		return -1;
	else if (arr[index]==num)
		return index;
	else
		recursive(arr,num,index+1,size);
}

void non_recursive(int *arr,int num,int size)
{
	int i=0;
	while(i<size)
	{
		if(arr[i]==num)
		{
		//	printf("in if condition i=%d arr=%d \n",i,arr[i]);
			printf("value found at %d using non_recursive function\n",i);
			break;
		}
		i++;
	}

	if(i==size)
		printf("value not Found\n");

}
