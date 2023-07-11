#include <stdio.h>
void forwhile()
{	int i;
	for(i=0;i<5;i++)
	{int j;
	  for(j=0;j<5;j++)
	  {
	    if ((i==j)||(j+j==4))
	    { printf("*");}
	    else
	    {printf(" ");}
	  }
	  printf("\n");
	}
}	
