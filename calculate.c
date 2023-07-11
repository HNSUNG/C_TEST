#include <stdio.h>
#include <math.h>
#include <string.h> 
void calculate()
{
	printf("enter the operation: ");
	int a,b; char op[2];
	scanf("%d %1s%d",&a, op, &b);
	int res;
	if (strcmp(op,"+")==0) res=a+b;
	else if (strcmp(op,"-")==0) res=a-b;
	else if (strcmp(op,"*")==0) res=a*b;
	else if (strcmp(op,"/")==0) res=a/b;
	
	printf("%d\n",res);
}
