#include <stdio.h>
void pointer(void)
{
	char arr[5][10] = {"Kim", "Lew", "Kang", "Song", "Park"};
	char (*p)[10];

	p=arr;
	printf("%s\n", (char *)p);

	printf("%s\n", *p);
	printf("%s\n", *(p+1));
	printf("%c\n", *(*(p+2)+1));

	printf("%s\n", p[0]);
	printf("%s\n", p[1]);
	printf("%c\n", p[2][1]);

}
