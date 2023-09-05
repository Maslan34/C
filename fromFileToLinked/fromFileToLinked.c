#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student
{
	int number;
	char names[50];
	char jobs[50];
	struct student *next;
};

typedef struct student node;

int main(int argc, char *argv[]) {
	
	node *first,*newNode,*q;
	first=(node*)malloc(sizeof(node));

	FILE *textFile;
	int no,i=0;
	char name[50];
	char job[50];
	if((textFile=fopen("studentReg.txt","r"))==NULL)
	printf("File Opening Error ...");
	else
	{
	
		while(!feof(textFile))
		{
			fscanf(textFile,"%d %s %s",&no,name,job);
		
			if(i==0)
			{
			first->number=no;
			strcpy(first->names,name);
			strcpy(first->jobs,job);
			first->next=NULL;
			q=first;
			i++;
			}
			else{
			q->next=newNode=(node*)malloc(sizeof(node));
			q=q->next;
			q->number=no;
			strcpy(q->names,name);
			strcpy(q->jobs,job);
			
			}
		}
		
		q->next=NULL;
		q=first;
		while(q!=NULL)
		{
		printf("%d - %s - %s",q->number,q->names,q->jobs);
		q=q->next;	
		}		
	}
	return 0;
}
