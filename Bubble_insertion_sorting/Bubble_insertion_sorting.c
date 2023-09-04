#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int dizi[5]={7,3,5,1,2};
	
	BubbleSorting(dizi,5);	
	InsertionSorting(dizi,5);
	return 0;
}

void InsertionSorting(int array[], int size){
	
	int i,j=1,value;
		
		for(j;j<size;j++){
			
			value=array[j];
			i=j-1;
			
			while(i>=0 && array[i]>value){
				
				swap(&array[i],&array[i+1]);		
				i--;
			}
			
		}
		printf("\n");
		for(i=0;i<size;i++)
		{
			printf("%d ",array[i]);
		}
		
}
void swap(int* x,int*y){
	int var;
		
		var=*(y);
		*(y)=*(x);
		*(x)=var;
		
}
void BubbleSorting(int array[], int size){
	int i,j;
	
		for(i=0;i<size-1;i++)
		{
			for(j=0;j<size-1;j++)
			 {
			 	if(array[j]>array[j+1])
			 	{
			 		swap(&array[j],&array[j+1]);
	
				}
			 }
		}
	
	printf("\n");
		for(i=0;i<size;i++)
		{
			printf("%d ",array[i]);
		}
}
