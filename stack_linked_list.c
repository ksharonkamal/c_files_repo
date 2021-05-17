#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

struct stack *top;
void push(int);
int pop();
int peek();
int search(int, struct stack *);
void display(struct stack *temp);

int main()
{
	int choice,data,flag,dat;
	while(1)
	{
		printf("1. PUSH 2. POP 3. PEEK 4.SEARCH 5. DISPLAY 6.EXIT\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter data to be pushed\n");
				scanf("%d",&data);
				push(data);
				break;
			case 2: if(top==NULL)
					printf("stack is empty\n");
				else
					printf("data popped is %d\n",pop());
				break;
			case 3: if(top==NULL)
					printf("stack is empty\n");
				else
					printf("top of the stack pointing to %d\n", peek());
				break;
			case 4: printf("enter data to be searched:");
			        scanf("%d",&dat);
			        flag=search(dat,top);
			        if(flag==-1)
			            printf("data not found \n");
			        else
			            printf("data found\n");
			            break;
			case 5: display(top);
				break;
			case 6: exit(0);
			default: printf("invalid choice\n");
		}
	}
}

void push(int d)
{
	struct stack *newnode=NULL;
	newnode=(struct stack *)calloc(1,sizeof(struct stack));
	if(newnode == NULL)
	{
		printf("stack is full\n");
	}
	else
	{
		newnode->data=d;
		newnode->next=top;
		top=newnode;
	}
}

int pop()
{
	struct stack *temp=NULL;
	int d;
	temp=top;
	top=top->next;
	d=temp->data;
	free(temp);
	temp=NULL;
	return d;
}

int peek()
{
	return top->data;
}

int search(int dat, struct stack *temp)
{
    if(temp==NULL)
        return -1;
    else if(temp->data==dat)
        return 1;
    else
        search(dat,temp->next);
}

void display(struct stack *temp)
{
	if(temp)
	{
		printf("%d ",temp->data);
		display(temp->next);
	}
	else
		return;
}