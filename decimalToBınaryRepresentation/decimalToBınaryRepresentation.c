#include <stdlib.h>
#include <stdio.h>

int main()
{
	
	float operation,number,result,round;
	int screen=0;

	
	printf("Enter a decimal number: ");
	scanf("%f",&number);

	operation=number/2;
	printf("\n%f",operation);

	while(operation>0.25)
	{
		round=floor(operation);
		result=(operation-round)*2;
		operation=floor(operation);
		
		if(result==1)
		{
			screen*=10;
			screen+=result;
		}
		else
		{
			screen=screen*10;
			
		}
		operation=operation/2;
		printf("\n%f",operation);
		
	}
	
	long long int secondScreen=0;
	while(screen/10!=0)
	{
		
		secondScreen*=10;
		secondScreen+=screen%10;
		screen=screen/10;
		
	}
	secondScreen*=10;
	secondScreen+=screen%10;
	printf("\n\nResult: %d",secondScreen);

	return 0;
}
