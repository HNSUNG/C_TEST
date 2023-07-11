#include <stdio.h>
int recursion1(int n)
{
	if (n==1) return 1;
	else
	return (n + recursion1(n-1));
}	

double recursion2(int n)
{
	if (n==1) return 1.0;
	else
	return ((double)(1/n)+recursion2(n-1));	
}
int iteration1(int n)
{
	int i;
	int s=0;
	for(i=1;i<=n;i++)
	{s+=i;}
	return s;
}
int recursion3(int n,int k)
{
	if ((k==0)||(k==n))
	return 1;
	else
	return (recursion3((n-1),(k-1)) + recursion3((n-1),(k)));
}
	
void recursion()
{
	printf("%d\n",recursion1(5));
	printf("%lf\n",recursion2(5));
	printf("%d\n",iteration1(5));
	printf("%d\n", recursion3(5,3));
}

