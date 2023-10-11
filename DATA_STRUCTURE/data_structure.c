

//REFERENCES


//www.wikipedia.com
//www.geekforgeeks.com





#include <stdio.h>
#include <stdlib.h>




//HERE FOR 

struct dataStructures{
	int data;
	struct dataStructures *next;
};

typedef struct dataStructures node;

node* createALinkedList(node*);
void  printingALinkedList(node*);
node* deletingADataFromLinkedList(node*);
node* insertingADataToLinkedList(node*);
void  countingNodeInALinkedList(node*);
node* destroyingALinkedList(node*);
node* insertingADataToCircularList(node* );
// LINKED LÝST






//HERE FOR 

struct dataStructuresforDoubly{
	int data;
	struct dataStructuresforDoubly *next;
	struct dataStructuresforDoubly *previous;
};

typedef struct dataStructuresforDoubly bigNode;

bigNode* creatingADoubleLinkedList(bigNode*);
void printingDoubleLinkedList(bigNode*);
bigNode* destroyingADoubleLinkedList(bigNode*);
void countingNodeInADoubleList(bigNode*);
bigNode* deletingADataFromADoubleList(bigNode*);
bigNode* insertingADatatoDoubleList(bigNode*);
//DOUBLE





void getInformation(int);

int main(int argc, char *argv[]) {

		//INITIALIZATIONS
		int typeOfStruct,choice,dataForStack,stackType;
		node* head=NULL;	
		bigNode* headForDouble=NULL;
		
		//
	
		printf("----------DATA STRUCTURES IMPLEMENTATIONS----------\n");
	printf("     ------WRITTEN BY MUHARREM ASLAN------\n");
	
	
	printf("\n<-PLEASE SELECT YOUR THE STRUCTURE TYPE YOU WANT TO WORK->\n");
	printf("\n1-LINKED LIST\n2-DOUBLE LINKED LIST\n3-CIRCULAR LINKED LIST\n4-STACK\n5-QUEUE\n6-TREE\n7-BINARY SEARCH TREE\n8-EXIT\n\n->");
	
	scanf("%d",&typeOfStruct);

		while(1){
			
			if(typeOfStruct==1)
			{
				
				while(1){
					printf("\n1-CREATING A LINKED LIST\n2-PRINTING A LINKED LIST\n3-DELETING A DATA FROM A LINKED LIST\n");
					printf("4-INSERTING A DATA TO A LINKED LIST\n5-COUNTING  NODES A LINKED LIST\n6-DESTROYING A LINKED LIST\n7-GET INFORMATION\n8-BACK TO MAIN MENU\n\n->");
					scanf("%d",&choice);
							
							while(1){
							if(choice==1){
								head=createALinkedList(head);
								break;
							}
							
							else if(choice==2){
								printingALinkedList(head);
								break;
							}
							
							else if(choice==3){
								head=deletingADataFromLinkedList(head);
								break;
							}				
							
							else if(choice==4){
								head=insertingADataToLinkedList(head);
								break;
							}
							
							else if(choice==5){
								countingNodeInALinkedList(head);
								break;
							}
														
							else if(choice==6){
								head=destroyingALinkedList(head);
								break;
							}
							
							else if(choice==7){
								getInformation(typeOfStruct);
								break;
							}
													
							else if(choice==8)
								break;
						
							else{
								printf("\nYOU HAVE DIALED WRONG!\n");
								break;
							}
							
						}
						if(choice==8)
							break;
					}
					
			}
			else if(typeOfStruct==2){
				
				while(1){
					printf("\n1-CREATING A DOUBLE LINKED LIST\n2-PRINTING A DOUBLE LINKED LIST\n3-DELETING A DATA FROM A DOUBLE LINKED LIST\n");
					printf("4-INSERTING A DATA TO A DOUBLE LINKED LIST\n5-COUNTING  NODES A  DOUBLE LINKED LIST\n6-DESTROYING A DOUBLE LINKED LIST\n7-GET INFORMATION\n8-BACK TO MAIN MENU\n->");
					scanf("%d",&choice);
							
							while(1){
							if(choice==1){
								headForDouble=creatingADoubleLinkedList(headForDouble);
								break;
							}
							
							else if(choice==2){
								printingDoubleLinkedList(headForDouble);
								break;
							}
							
							else if(choice==3){
								headForDouble=deletingADataFromADoubleList(headForDouble);
								break;
							}				
							
							else if(choice==4){
								headForDouble=insertingADatatoDoubleList(headForDouble);
								break;
							}
							
							else if(choice==5){
								countingNodeInADoubleList(headForDouble);
								break;
							}
														
							else if(choice==6){
								headForDouble=destroyingADoubleLinkedList(headForDouble);
								break;
							}
													
							else if(choice==7){
								getInformation(typeOfStruct);
								break;
							}
													
							else if(choice==8)
								break;
						
							else{
								printf("\nYOU HAVE DIALED WRONG!\n");
								break;
							}
							
						}
						if(choice==8)
							break;
					}
				
				
			}
			else if(typeOfStruct==3){
					
						
				while(1){
				
					}
				
			}
			
			if(typeOfStruct==4)
			{
								
				
			}
			else if(typeOfStruct==5){
				
				while(1){
					
					}
				
			}
			
				else if(typeOfStruct==7){
				
				while(1){
				
					}
				
			}
			
			else if(typeOfStruct==8)
			break;
			
			else
			printf("\nYOU HAVE DIALED WRONG!\n");
			printf("\n<-PLEASE SELECT YOUR THE STRUCT TYPE YOU WANT TO WORK->\n");
			printf("\n1-LINKED LIST\n2-DOUBLE LINKED LIST\n3-CIRCULAR LINKED LIST\n4-STACK\n5-QUEUE\n6-TREE\n7-BINARY SEARCH TREE\n8-EXIT\n\n->");
			scanf("%d",&typeOfStruct);
			
		}
	
	return 0;
}



// LINKED LIST FUNCTIONS
node* createALinkedList(node* head){
	
	int theNumberOfNode,i;
	node*temp;
	printf("\nPLEASE ENTER THE NUMBER OF NODE->");
	scanf("%d",&theNumberOfNode);
	
	for(i=0;i<theNumberOfNode;i++){
		
		if(i==0){
			head=(node*)malloc(sizeof(node));
			printf("PLEASE ENTER THE %d.DATA->",i+1);
			scanf("%d",&head->data);
			
			head->next=NULL;	
			temp=head;	
		}else{
			temp->next=(node*)malloc(sizeof(node));
			temp=temp->next;
			printf("PLEASE ENTER THE %d.DATA->",i+1);
			scanf("%d",&temp->data);
			
		}
		
	}
	temp->next=NULL;
	
	return head;
}
void  printingALinkedList(node*head){
	node* temp;
	temp=head;
	int printingChoice;
	
	
	printf("In which direction do you want the information displayed?\n1-HORIZONTAL\n2-VERTICAL\n->");
	scanf("%d",&printingChoice);
	
	switch(printingChoice){
		case 1:
			printf("\n");
		while(temp!=NULL){
			
			printf("%d ",temp->data);
			temp=temp->next;
			
		}
		printf("\n");
		break;
		case 2:
			printf("\n");
			while(temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		break;
		default:
			printf("YOU HAVE DIALED WRONG!");
			break;
	}
	
}
node* deletingADataFromLinkedList(node* head){
	
	if(head==NULL){
		printf("\nYOU HAVE NOT A LINKED LIST YET.CREATE ONE FIRST\n");
		return head;
	}

	int dataWillBeDeleted;
	node* temp,*nodeWillBeDeleted;
	
	temp=head;
	
	printf("PLEASE ENTER THE DATA YOU WANT TO DELETE->");
	scanf("%d",&dataWillBeDeleted);
	

		if(head->data==dataWillBeDeleted)
		{
			
			free(head);
			return NULL;
		}
		else{
			while( (temp->next!=NULL) && (temp->next->data!=dataWillBeDeleted) ){
	
				temp=temp->next;
				
			}
			
			if(temp->next==NULL){
				printf("\nTHE DATA YOU ENTERED NOT FOUND IN THIS LINKED LIST!\n");
				return head;
			}else{
				nodeWillBeDeleted=temp->next;
				temp->next=nodeWillBeDeleted->next;
				free(nodeWillBeDeleted);
			}
	
		
		}
	
	return head;
}
node* insertingADataToLinkedList(node* head){
	
	if(head==NULL){
		printf("\nYOU HAVE NOT A LINKED LIST! PLEASE BEFORE INSERTING CREATE A LINKED LIST FIRST.\n");
		return head;
	}
	
	int dataWillBeInserted,insertedChoice,dataPoint;
	node* temp,*nodeWillBeInserted;

	printf("PLEASE ENTER THE DATA YOU WANT TO INSERT->");
	scanf("%d",&dataWillBeInserted);
	
	printf("PLEASE ENTER THE DATA IN THE LINKED LIST WILL BE A MARKER ->");
	scanf("%d",&dataPoint);
	
	printf("THE DATA ENTERED WILL BE PLACED BEFORE or AFTER of THIS MARKER ? PLEASE PRESS 1 for BEFORE 2 for AFTER\n->");
	scanf("%d",&insertedChoice);
	
		
		switch(insertedChoice){
		case 1:
				temp=head;
				while(temp!=NULL){		
				if(temp->data==dataPoint) //for root
				{				
					nodeWillBeInserted=(node*)malloc(sizeof(node));
					nodeWillBeInserted->data=dataWillBeInserted;
					nodeWillBeInserted->next=temp;
					head=nodeWillBeInserted;
					break;
				}
				else{ // middle and last
					while(temp->next!=NULL && temp->next->data!=dataPoint){// will stop on before node or not exist 
						
						temp=temp->next;
					}
					
					if(temp->data==dataPoint){
						nodeWillBeInserted=(node*)malloc(sizeof(node));
						nodeWillBeInserted->data=dataWillBeInserted;
						nodeWillBeInserted->next=temp->next;
						temp->next=nodeWillBeInserted;
						break;
					}
					else{
						printf("\nTHE DATA YOU ENTERED NOT FOUND IN THIS LINKED LIST!\n");
						break;
					}
				}
			}
	
		break;
		case 2:
			temp=head;	
			
			while(temp!=NULL){ 
				
				
				if(temp->data==dataPoint) //for root
				{
					nodeWillBeInserted=(node*)malloc(sizeof(node));
					nodeWillBeInserted->data=dataWillBeInserted;
					nodeWillBeInserted->next=temp->next;
					temp->next=nodeWillBeInserted;
					break;
				}
				else{
					while(temp->next!=NULL && temp->data!=dataPoint){ //will stop on the node
						
						temp=temp->next;
					}
					if(temp->data==dataPoint){
						
						nodeWillBeInserted=(node*)malloc(sizeof(node));
						nodeWillBeInserted->data=dataWillBeInserted;
						nodeWillBeInserted->next=temp->next;
						temp->next=nodeWillBeInserted;
						break;

					}
					else{
						printf("\nTHE DATA YOU ENTERED NOT FOUND IN THIS LINKED LIST!\n");
						break;
					}
				}
			}

			break;
		default:
			
			printf("YOU HAVE DIALED WRONG!");
			break;
	}
		return head;
}
void countingNodeInALinkedList(node* head){
	int counter=0;
	node* temp;
	temp=head;

	while(temp!=NULL)
	{
		counter++;
		temp=temp->next;
	}
	
	printf("\nTHE LINKED LIST YOU ENTERED HAS %d NODES\n",counter);

}
node* destroyingALinkedList(node*head){
	
	node* helperNode;
	helperNode=head;
	
	while(head!=NULL){
		head=head->next;
		free(helperNode);
		helperNode=head;
	}
	free(helperNode);
	return head;
}
// LINKED LIST FUNCTIONS











// DOOUBLE FUNCTIONS

bigNode* creatingADoubleLinkedList(bigNode* head){

	int theNumberOfNode,i;
	bigNode *temp,*back;
	printf("\nPLEASE ENTER THE NUMBER OF NODE->");
	scanf("%d",&theNumberOfNode);
	
	for(i=0;i<theNumberOfNode;i++){
		
		if(i==0){
			head=(bigNode*)malloc(sizeof(bigNode));
			printf("PLEASE ENTER THE %d.DATA->",i+1);
			scanf("%d",&head->data);
			
			head->next=NULL;
			head->previous=NULL;	
			temp=head;
			back=head;
		}else{
			temp->next=(bigNode*)malloc(sizeof(bigNode));
			temp=temp->next;
			printf("PLEASE ENTER THE %d.DATA->",i+1);
			scanf("%d",&temp->data);
			temp->previous=back;
			back=temp;
		
		}
		
	}
	temp->next=NULL;
	
	return head;
	
}
void printingDoubleLinkedList(bigNode* head){
	
	bigNode* temp=head;
	
	int printingChoice;
	
	printf("In which direction do you want the information displayed?\n1-STRAIGHT\n2-REVERSE\n->");
	scanf("%d",&printingChoice);
	
	switch(printingChoice){
		case 1:
			printf("\n");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
		break;
		case 2:
			printf("\n");
			
			while(temp->next!=NULL){
			temp=temp->next;
		}
		
		while(temp->previous!=NULL){
			printf("%d ",temp->data);
			temp=temp->previous;   // neden previous yok
		}
		printf("%d ",temp->data);
			printf("\n");
		break;
		default:
			printf("\nYOU HAVE DIALED WRONG!\n");
			break;
}
}
bigNode* destroyingADoubleLinkedList(bigNode* head){
	bigNode *helperNode=head;
	while(head!=NULL){
		head=head->next;
		free(helperNode);
		helperNode=head;
	}
	return head;
}
void countingNodeInADoubleList(bigNode* head){
	int counter=0;
	while(head!=NULL){
		head=head->next;
		counter++;
	}
	printf("\nTHE DOUBLE LIST YOU ENTERED HAS %d NODES\n",counter);
}
bigNode* deletingADataFromADoubleList(bigNode* head){ // can be written another way 
	
	if(head==NULL){
		printf("\nYOU HAVE NOT A DOUBLE LIST! PLEASE BEFORE INSERTING CREATE A CIRCULAR LIST FIRST.\n");
		return head;
	}
	
	int dataWillBeDeleted;
	bigNode *nodeWillBeDeleted,*temp=head;
	
	printf("\nPLEASE ENTER THE DATA WILL BE DELETED\n");
	scanf("%d",&dataWillBeDeleted);
	
	
	if(head->data==dataWillBeDeleted){
		head=head->next;
		free(temp);
		return head;
	}
	else{
		while( temp->next->data!=dataWillBeDeleted && temp->next->next!=NULL){	
							temp=temp->next;
					}
					
					if(temp->next->data==dataWillBeDeleted && temp->next->next==NULL){
						
						nodeWillBeDeleted=temp->next;
						temp->next=NULL;
						free(nodeWillBeDeleted);
						return head;
					
					}
					else if(temp->next->data==dataWillBeDeleted){
						
						nodeWillBeDeleted=temp->next;
						temp->next=nodeWillBeDeleted->next;
						nodeWillBeDeleted->next->previous=temp;	
						free(nodeWillBeDeleted);
						return head;
				
				}
				else{
						printf("\nTHE DATA YOU ENTERED NOT FOUND IN THIS LINKED LIST!\n");
						return head;
				}
		}	
			
	}	
bigNode* insertingADatatoDoubleList(bigNode* head){
	
	if(head==NULL){
		printf("\nYOU HAVE NOT A DOUBLE LIST! PLEASE BEFORE INSERTING CREATE A CIRCULAR LIST FIRST.\n");
		return head;
	}
	
	int dataWillBeInserted,insertedChoice,dataPoint;
	bigNode *temp,*nodeWillBeInserted;

	printf("PLEASE ENTER THE DATA YOU WANT TO INSERT->");
	scanf("%d",&dataWillBeInserted);
	
	printf("PLEASE ENTER THE POINT TO BE PLACE THE DATA ->");
	scanf("%d",&dataPoint);
	
	printf("THE DATA INSERTED BEFORE or AFTER? PLEASE PRESS 1 for BEFORE 2 for AFTER\n->");
	scanf("%d",&insertedChoice);
	
		
		switch(insertedChoice){
		case 1:
				
				temp=head;
				
					
				if(temp->data==dataPoint) //for root
				{				
					nodeWillBeInserted=(bigNode*)malloc(sizeof(node));
					nodeWillBeInserted->data=dataWillBeInserted;
					nodeWillBeInserted->previous=NULL;
					nodeWillBeInserted->next=temp;
					head=nodeWillBeInserted;
					break;
				}
				else{ // middle and last
					while(temp->next!=NULL && temp->next->data!=dataPoint){// will stop on before node
						
						temp=temp->next;
					}
					if(temp->next->data==dataPoint || temp->next==NULL){
						nodeWillBeInserted=(bigNode*)malloc(sizeof(node));
						nodeWillBeInserted->data=dataWillBeInserted;
						nodeWillBeInserted->next=temp->next;
						temp->next=nodeWillBeInserted;
						break;
					}
					else{
						printf("THE DATA YOU ENTERED NOT FOUND IN THIS LINKED LIST!");
						break;
					}
				}
			
			break;
		
		case 2:
				temp=head;
				

				if(temp->data==dataPoint)
				{
					nodeWillBeInserted=(node*)malloc(sizeof(node));
					nodeWillBeInserted->data=dataWillBeInserted;
					nodeWillBeInserted->next=temp->next;
					temp->next=nodeWillBeInserted;
					nodeWillBeInserted->previous=temp;
					break;
				}
				else{
					while(temp->next!=NULL && temp->data!=dataPoint){ //will stop on the node
						temp=temp->next;
					}
					if(temp->data==dataPoint || temp->next==NULL){
						
						nodeWillBeInserted=(node*)malloc(sizeof(node));
						nodeWillBeInserted->data=dataWillBeInserted;
						nodeWillBeInserted->next=temp->next;
						temp->next=nodeWillBeInserted;
						nodeWillBeInserted->previous=temp;	
					}
					else{
						printf("\nTHE DATA YOU ENTERED NOT FOUND IN THIS LINKED LIST!\n");
					}
				}
				
				break;
				
				default:
				printf("\nYOU HAVE DIALED WRONG!\n");
				break;		
			}
		return head;
	}
//









void getInformation(int typeOfStruct){
		if(typeOfStruct==1){
		
	printf("\n\n\n\nTYPE:LINKED LIST\n\nDEFINITION: a linked list is a linear collection of data elements whose order is not given by their physical placement in memory.Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence.This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.A drawback of linked lists is that access time is linear (and difficult to pipeline).Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists. \n\nAPPLICATION'S of LINKED LIST\n\n%c Polynomial Manipulation representation\n%c Addition of long positive integers\n%c Representation of sparse matrices\n%c Symbol table creation\n%c Mailing list\n%c Memory management\n%c Linked allocation of files\n%c Multiple precision arithmetic\n\n",175,175,175,175,175,175,175,175,175,175,175);
	printf(" PROS \t\t\t|\t\t\t CONS\n(+)Dynamic data structure  \t\t(-)Memory usage");
	printf("\n(+)No memory wastage %c%c%c%c%c%c\t\t(-)Memory usage",32,32,32,32,32,32,32);
	printf("\n(+)Dynamic data structure  \t\t(-)Traversal");
	printf("\n(+)Implementation  %c%c%c%c%c\t\t(-)Reverse Traversing",32,32,32,32,32);
	printf("\n(+)Insertion and Deletion Operations  \t(-)Random Access\n\n\n");
	
	
	}

	else if(typeOfStruct==2){
		
	printf("\n\n\n\nTYPE:DOUBLE LINKED LIST\n\nDEFINITION: is a linear data structure that contains an extra pointer, typically called the previous pointer, together with the next pointer and data which are there in a singly linked list. ");
	printf(" \n\nPROS \t\t\t\t\t\t|\t\t\t\t\t CONS\n(+)Dynamic data structure  \t\t\t\t\t\t\t(-)Memory usage");
	printf("\n(+) Bidirectional which is not possible in a singly linked list. %c%c%c%c%c%c\t\t(-)Slower Traversing",32,32,32,32,32,32,32);
	printf("\n(+)Implementing graph algorithms.  \t\t\t\t\t\t\(-)Implementing more complex");
	printf("\n(+)a low overhead compared to other data structures such as arrays.  %c%c%c%c%c\t(-)Reverse Traversing",32,32,32,32,32);
	printf("\n(+)Deletion of nodes is easy as compared to a Singly Linked List.  \t\t(-)Random Access\n\n\n");
	

		
	}
	else if(typeOfStruct==3){
		
	printf("\n\n\n\nTYPE:CIRCULAR LIST\n\nDEFINITION: The circular linked list is a linked list where all nodes are connected to form a circle. In a circular linked list, the first node and the last node are connected to each other which forms a circle. There is no NULL at the end. \n\nAPPLICATION'S of LINKED LIST\n\n%c Circular Linked Lists can be used to manage the computing resources of the computer.\n%c Data structures such as stacks and queues are implemented with the help of the circular linked lists.\n%c Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.\n%c It is also used in computer networking for token scheduling.\n\n\n",175,175,175,175);
	printf(" PROS \t\t\t|\t\t\t CONS\n(+)Dynamic data structure  \t\t(-)If the circular linked list is not handled properly then it can lead to an infinite loop as it is circular in nature.");
	printf("\n(+)It is possible to traverse from the last node back to the first i.e. the head node. %c%c%c%c%c%c\t\t(-)In comparison with singly-linked lists, doubly linked lists are more complex in nature",32,32,32,32,32,32,32);
	printf("\n(+)The starting node does not matter as we can traverse each and every node despite whatever node we keep as the starting node.  \t\t(-)Direct accessing of elements is not possible.");
	printf("\n(+)The previous node can be easily identified.  %c%c%c%c%c\t\t(-)It is generally a complex task to reverse a circular linked list.",32,32,32,32,32);
	printf("\n(+)There is no need for a NULL function to code.\n");
	printf("\n(+)Circular linked lists are beneficial for end operations as start and finish coincide.\n");
	printf("\n(+)Algorithms such as Round Robin setup can effectively complete online queues without having to meet NULL suspension or reference references.\n\n\n");
		
	}
	else if(typeOfStruct==4){
		
	printf("\n\n\n\nTYPE:LINKED LIST\n\nUSAGE: a linked list is a linear collection of data elements whose order is not given by their physical placement in memory.Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence.This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.A drawback of linked lists is that access time is linear (and difficult to pipeline).Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists. \n\nAPPLICATION'S of LINKED LIST\n\n%c Polynomial Manipulation representation\n%c Addition of long positive integers\n%c Representation of sparse matrices\n%c Symbol table creation\n%c Mailing list\n%c Memory management\n%c Linked allocation of files\n%c Multiple precision arithmetic\n\n",175,175,175,175,175,175,175,175,175,175,175);
	printf("PROS \t\t\t|\t\t\t CONS\n(+)Dynamic data structure  \t\t(-)Memory usage");
	printf("\n(+)No memory wastage %c%c%c%c%c%c\t\t(-)Memory usage",32,32,32,32,32,32,32);
	printf("\n(+)Dynamic data structure  \t\t(-)Traversal");
	printf("\n(+)Implementation  %c%c%c%c%c\t\t(-)Reverse Traversing",32,32,32,32,32);
	printf("\n(+)Insertion and Deletion Operations  \t(-)Random Access\n\n\n");
	
		
	}
	else if(typeOfStruct==5){
		
	printf("\n\n\n\nTYPE:LINKED LIST\n\nUSAGE: a linked list is a linear collection of data elements whose order is not given by their physical placement in memory.Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence.This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.A drawback of linked lists is that access time is linear (and difficult to pipeline).Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists. \n\nAPPLICATION'S of LINKED LIST\n\n%c Polynomial Manipulation representation\n%c Addition of long positive integers\n%c Representation of sparse matrices\n%c Symbol table creation\n%c Mailing list\n%c Memory management\n%c Linked allocation of files\n%c Multiple precision arithmetic\n\n",175,175,175,175,175,175,175,175,175,175,175);
	printf(" PROS \t\t\t|\t\t\t CONS\n(+)Dynamic data structure  \t\t(-)Memory usage");
	printf("\n(+)No memory wastage %c%c%c%c%c%c\t\t(-)Memory usage",32,32,32,32,32,32,32);
	printf("\n(+)Dynamic data structure  \t\t(-)Traversal");
	printf("\n(+)Implementation  %c%c%c%c%c\t\t(-)Reverse Traversing",32,32,32,32,32);
	printf("\n(+)Insertion and Deletion Operations  \t(-)Random Access\n\n\n");
	
		
	}
	else if(typeOfStruct==6){
		
	printf("\n\n\n\nTYPE:LINKED LIST\n\nUSAGE: a linked list is a linear collection of data elements whose order is not given by their physical placement in memory.Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence.This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.A drawback of linked lists is that access time is linear (and difficult to pipeline).Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists. \n\nAPPLICATION'S of LINKED LIST\n\n%c Polynomial Manipulation representation\n%c Addition of long positive integers\n%c Representation of sparse matrices\n%c Symbol table creation\n%c Mailing list\n%c Memory management\n%c Linked allocation of files\n%c Multiple precision arithmetic\n\n",175,175,175,175,175,175,175,175,175,175,175);
	printf(" PROS \t\t\t|\t\t\t CONS\n(+)Dynamic data structure  \t\t(-)Memory usage");
	printf("\n(+)No memory wastage %c%c%c%c%c%c\t\t(-)Memory usage",32,32,32,32,32,32,32);
	printf("\n(+)Dynamic data structure  \t\t(-)Traversal");
	printf("\n(+)Implementation  %c%c%c%c%c\t\t(-)Reverse Traversing",32,32,32,32,32);
	printf("\n(+)Insertion and Deletion Operations  \t(-)Random Access\n\n\n");
	
		
	}
	else if(typeOfStruct==7){
		
	printf("\n\n\n\nTYPE:LINKED LIST\n\nUSAGE: a linked list is a linear collection of data elements whose order is not given by their physical placement in memory.Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence.In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence.This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. More complex variants add additional links, allowing more efficient insertion or removal of nodes at arbitrary positions.A drawback of linked lists is that access time is linear (and difficult to pipeline).Faster access, such as random access, is not feasible. Arrays have better cache locality compared to linked lists. \n\nAPPLICATION'S of LINKED LIST\n\n%c Polynomial Manipulation representation\n%c Addition of long positive integers\n%c Representation of sparse matrices\n%c Symbol table creation\n%c Mailing list\n%c Memory management\n%c Linked allocation of files\n%c Multiple precision arithmetic\n\n",175,175,175,175,175,175,175,175,175,175,175);
	printf(" PROS \t\t\t|\t\t\t CONS\n(+)Dynamic data structure  \t\t(-)Memory usage");
	printf("\n(+)No memory wastage %c%c%c%c%c%c\t\t(-)Memory usage",32,32,32,32,32,32,32);
	printf("\n(+)Dynamic data structure  \t\t(-)Traversal");
	printf("\n(+)Implementation  %c%c%c%c%c\t\t(-)Reverse Traversing",32,32,32,32,32);
	printf("\n(+)Insertion and Deletion Operations  \t(-)Random Access\n\n\n");
	
		
	}
}

