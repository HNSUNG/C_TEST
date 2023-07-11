#include<stdio.h>
#include <math.h>
void bmi()
{
	double weight, height;
	printf("weight and height:");
	scanf("%lf%lf",&weight,&height);;
	double bmi;
	bmi= weight/(height*height);
	printf((bmi>20.0)&&(bmi<25.0)?"\tstandard":"\tdiet");
	printf("\n");
}
