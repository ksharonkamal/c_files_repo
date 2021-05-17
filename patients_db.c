#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct patient
{
	int id;
	int age;
	char name[20];
	char diagnosis[20];
	char location[25];
}*db=NULL;
int cnt=0;
int flag=0;//to warn the user about data saving to disk
static int num=0;

void printMenu(void)
{
	printf("\n----MENU----\n");
	printf("1. Add New Record\n");
	printf("2. Delete Record\n");
	printf("3. Print All Records\n");
	printf("4. Save Records\n");
}
void input()
{
	db=realloc(db,(cnt+1)*sizeof(struct patient));
	
	puts("Enter Patient's Name:");
	__fpurge(stdin);
	gets(db[cnt].name);

	puts("Enter Patient's Age:");
	__fpurge(stdin);
	scanf("%d",&(db[cnt].age));

	puts("Enter Diagnosis:");
	__fpurge(stdin);
	gets(db[cnt].diagnosis);
	
	puts("Enter Patient's Location:");
	__fpurge(stdin);
	gets(db[cnt].location);

	db[cnt].id=++num;

	cnt++;
	flag=0;
	
}

void delete()
{
	int i;
	int id2delete;
	printf("enter id to delete:");
	scanf("%d",&id2delete);

	for(i=0;i<cnt;i++)
		if(db[i].id==id2delete)
			break;

	if(i==cnt)
	{
		puts("ERROR: Record not found");
		return;
	}

	memmove(db+i,db+i+1,(cnt-i-1)*sizeof(struct patient));
	cnt--;

	db=realloc(db,cnt*sizeof(struct patient));
	if(cnt==0)
		db=NULL;
	flag=0;
}
void print()
{
	int i;
	printf("ID Name Age Diagnosis Location\n");
	for(i=0;i<cnt;i++)
	{
		printf("%d %s %d %s %s\n",db[i].id,db[i].name,db[i].age,db[i].diagnosis,db[i].location);
	}
}
void save()
{
	FILE *fp;
	fp=fopen("patient.dat","w");
	fwrite(db,sizeof(struct patient),cnt,fp);
	fclose(fp);
	flag=1;
}

void syncFile()
{
	FILE *fp;
	fp=fopen("patient.dat","r");
	if(fp==NULL)
		return;

	fseek(fp,0,2);
	cnt=ftell(fp)/sizeof(struct patient);

	db=malloc(cnt*sizeof(struct patient));
	fseek(fp,0,0);

	fread(db,sizeof(struct patient),cnt,fp);
	fclose(fp);

	num=cnt;
//	printf("num=%d,cnt=%d",db[cnt].id,cnt);
}
int main()
{
	int choice;
	syncFile();
	while(1)
	{
		printMenu();
		puts("Enter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: input();
				break;
			case 2: delete();
				break;
			case 3: print();
				break;
			case 4: save();
				break;
			default:("Ïnvalid Choice\n");
		}
	}
}
