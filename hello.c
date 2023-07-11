#include <stdio.h>
#include <math.h>
int hello()
{
	int i = 0x33cc33cc;
	i&= ~(1<<0 | 1<<6| 3<<24);
	printf("%x\n", i);
	int y = 0x33cc33cc;
	y&= ~((1<<0) + (1<<6) + (3<< 24));
	printf("%x\n" , y);

	return 0;
}



