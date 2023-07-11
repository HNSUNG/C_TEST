#include <stdio.h>
void unknown()
{
	int ch;
	if ((ch=getchar()) !='\n')
	unknown();
	putchar(ch);
}
