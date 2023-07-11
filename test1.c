#include <stdio.h>
void bdisp(int a)
{ 
	int i;
	for (i =31; i>=0 ; i--)
	{  
		printf("%d", (a>>i)&1);
	}
	printf("\n");
}
void test1(void)
{
	int i= 0xac33aa55;
	unsigned char c = 0x80;
	bdisp(i);
	bdisp(c);
}

