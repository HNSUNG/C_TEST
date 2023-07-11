#include <stdio.h>
#include <stdlib.h> 

//#define DEBUG

int pointer1() {
	int **arr, m, n, i, j;
	printf(" decide m,n: ");
	scanf("%d%d", &m, &n);
	arr = (int **) malloc( m * sizeof(int *) );

	if (arr==NULL)
	{
		printf("memory is full\n");
		exit(1);
	}

	for (i = 0; i < m; i++)
		arr[i] = (int *) malloc(n * sizeof(int));

	for(i = 0; i < m; i++)
	{ for(j = 0; j < n; j++)
		{ printf("arr[%d][%d] : ",i,j);
			scanf("%d", *(arr + i) + j);}} //this statement

	for(i = 0; i < m; i++) {
		for(j = 0; j < n; j++) {
#ifdef DEBUG
			printf("%d ", *(*(arr + i) + j));
			printf("\n");
#endif 
		}
	}
	for(i = 0; i < m; i++) 
		free(arr[i]);

	free(arr);

	return 0;
}
