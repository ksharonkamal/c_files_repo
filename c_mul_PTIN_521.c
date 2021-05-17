#include<stdio.h>
int main()
{
	int a[2][2],b[2][3],c[2][3];
	int i,j,k;
	
	printf("enter 2x2 matrix");
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);
	
	printf("enter 2x3 matrix");
	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
			scanf("%d",&b[i][j]);


	for(i=0;i<2;i++)
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<2;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}


	printf("resultant 2x3 matrix\n");
	for(i=0;i<2;i++,printf("\n"))
		for(j=0;j<3;j++)
			printf("%d ",c[i][j]);

}

