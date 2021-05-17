#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *prev;
	struct queue *next;
};

struct queue *front=NULL;
struct queue *rear =NULL;

void enq(int d);
int deq();
int search(int d, struct queue *r);
void display(struct queue *f);

int main()
{
	int choice,data,flag,dat;
	while(1)
	{
		printf("1. ENQ 2. DEQ 3. SEARCH 4. DISPLAY 5. EXIT\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter data to be inserted\n");
				scanf("%d",&data);
				enq(data);
				break;
			case 2: if(front==NULL)
					printf("Queue is empty\n");
				else
					printf("data dequed is %d\n",deq());
				break;
			case 3: printf("enter data to be searched:");
			        scanf("%d",&dat);
			        flag=search(dat,front);
			        if(flag==-1)
			            printf("data not found \n");
			        else
			            printf("data found\n");
			            break;
			case 4: display(front);
				break;
			case 5: exit(0);
			default: printf("invalid choice\n");
		}
	}
}

void enq(int d)
{
	struct queue *newnode=NULL;
	newnode=(struct queue *)calloc(1,sizeof(struct queue));
	if(newnode==NULL)
	{
		printf("memory allocation failed\n");
		return;
	}
	else
	{
		newnode->data=d;
		if(front==NULL)
		{
			front=rear=newnode;
			newnode->next=NULL;
			newnode->prev=NULL;
		}
		else
		{
			rear->next=newnode;
			newnode->prev=rear;
			newnode->next=NULL;
			rear=newnode;
		}
	}
}

int deq()
{
	struct queue *temp=NULL;
	int d;
	d=front->data;
	if(front->next==NULL) //only one node present
	{
		temp=front;
		front=rear=NULL;	
	}
	else
	{
		temp=front;
		front->next->prev=NULL;
		front=front->next;
	}
	free(temp);
	return d;
}

int search(int d, struct queue *fptr)
{
	if(front==NULL)
	{
		printf("List is EMPTY\n");
		return -1;
	}
	else
	{
		while(fptr)
		{
			if(fptr->data==d)
				return 1;
			else
				fptr=fptr->next;
		}
	}
	return -1;
}

void display(struct queue *fptr)
{
	if(fptr)
	{
		printf("%d ",fptr->data);
		display(fptr->next);
	}
	else
		return;
		
}