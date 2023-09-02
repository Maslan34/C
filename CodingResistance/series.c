#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	
	printf("\n\n\n Series Circuit \n\n\n");
	float voltage_source,resistance,Res=0,current,*allResistance;
	int numberResistance,i=0,j;
	allResistance=(double *)malloc(sizeof(double)*(i+1));
	printf("please enter voltage source value: ");
	scanf("%f",&voltage_source);
	//printf("%f",voltage_source);
	printf("Please enter the resistor value(In case of 0 or - the input process will be terminated.): ");
	scanf("%f",&resistance);
	while(resistance>0 && resistance!=0)
	{
			Res+=resistance;
			//printf("%f\n",resistance);
			*(allResistance+i)=resistance;
			//printf("%f\n",*(allResistance+i));
			i++;
			allResistance=realloc(allResistance,sizeof(double)*(i+1));
			numberResistance++;
			scanf("%f",&resistance);
	}
	
	current=voltage_source/Res;
	printf("\nMAIN CURRENT IN YOUR CIRCUIT: %f\n",current);
	/*
	for(j=0;j<i;j++)
	{
		printf("\n%f",*(allResistance+j));
	}
*/	
	if(voltage_source>0)
	{
		for(j=0;j<i;j++)
		{
			printf("Voltage falling on your %d resistor->%f --- Amount of power consumed by your %d resistor->%f\n",j+1,(*(allResistance+j)*(current)),j+1,(current*current)*(*(allResistance+j)));
		}
	}
	else{
				for(j=0;j<i;j++)
				{
					printf("Voltage falling on your %d resistor->%f --- Amount of power consumed by your %d resistor->%f\n",j+1,(*(allResistance+j)*(current)),j+1,(current*current)*(*(allResistance+j)));
				}
		}
	
	
	
	
	return 0;
}
