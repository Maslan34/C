#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10
#define ARRAY_SIZE 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct arrayForStack{
int top;	
struct dataStructures* array[ARRAY_SIZE];
};


struct dataStructures{
	int data;
	struct dataStructures *next;
};

typedef struct dataStructures node;
typedef struct arrayForStack stack;



node* createALinkedList(node*);
void  printingALinkedList(node*);
node* deletingADataFromLinkedList(node*);
node* insertingADataToLinkedList(node*);
void  countingNodeInALinkedList(node*);
node* destroyingALinkedList(node*);
node* insertingADataToCircularList(node* );
// LINKED LÝST

void initilazeStack(stack*stk);
void push(stack*,node*);

	

int main(int argc, char *argv[]) {
	
	
	int ogrenciAdet,i;
	
	stack stack1,ptr;
	node* ogrenci=NULL;
	node* ogrenci2=NULL;
	initilazeStack(&stack1);
	
	printf("Ogrenci adeti giriniz: ");
	scanf("%d",&ogrenciAdet);
	
	while(ogrenciAdet>0){
		
		ogrenci = createALinkedList(ogrenci);
		printingALinkedList(ogrenci);
		push(&stack1,&ogrenci);
		printf("\nOgrenci stack'e  eklendi\n");
		ogrenci=NULL;
		ogrenciAdet--;
		
	}
	
	printf("\nButun Ekleme Islemleri Tamamlandi...\n");
	
	return 0;
}

// 113 0 4 0 1 9 0 1 1 3
node* createALinkedList(node* head){
	
	int OgrenciNo,i;
	node*temp;
	printf("\nOGRENCI NO GIRINIZ: ->");  
	scanf("%d",&OgrenciNo);
	int ID = OgrenciNo;
	ID = OgrenciNo%1000;
	
	int number[9] ={};
	for(i=8; i>=0; i--){
		number[i] = OgrenciNo%10;
		OgrenciNo = OgrenciNo/10;
	}
	
	/*
	for(i=0; i<9; i++){
		printf("%d\n",number[i]);
	}
	*/
	
	for(i=0;i<10;i++){
		
		if(i==0){
			head=(node*)malloc(sizeof(node));
			head->data = ID;
			head->next=NULL;	
			temp=head;	
		}else{
			temp->next=(node*)malloc(sizeof(node));
			temp=temp->next;
			temp->data = number[i-1];
		}
		
	}
	temp->next=NULL;
	
	return head;
}
void  printingALinkedList(node*head){
	
	node* temp;
	temp=head;
	int printingChoice;
	
		while(temp!=NULL){
			
			printf("%d ",temp->data);
			temp=temp->next;
			
		}
	
	}
	
void initilazeStack(stack* stk){
	stk->top=-1;
}

void push(stack* stk,node* nod)
{
	if(stk->top ==STACK_SIZE)
	printf("Stack Dolu");
	else
	{		
		stk->array[++(stk->top)]=nod;
	}
}

