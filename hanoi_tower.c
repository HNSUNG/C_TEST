#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n==1) printf("move 1 disk from %c to %c.\n",from,to);
	else{
	hanoi_tower(n-1,from,to,tmp);
	printf("move %d disk form %c to %c.\n",n,from,to);
	hanoi_tower(n-1,tmp,from,to);
	}
}
