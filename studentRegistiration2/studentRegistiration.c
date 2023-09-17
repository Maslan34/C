#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  
#define STACK_SIZE 10
#define ARRAY_SIZE 10

struct arrayForStack {
    int top;
    struct dataStructures* array[ARRAY_SIZE];
};

struct dataStructures {
    int data;
    struct dataStructures* next;
};

typedef struct dataStructures node;
typedef struct arrayForStack stack;

node* createALinkedList(node*);
void printingALinkedList(node*);
void initializeStack(stack*);
void push(stack*, node*);
int findMinimumSchoolNumber(stack*);

int main(int argc, char* argv[]) {

    int studentNumber, i;

    stack stack1;
    node* student = NULL;

    initializeStack(&stack1);

    printf("Enter Student Number: ");
    scanf("%d", &studentNumber);

    while (studentNumber > 0) {

        student = createALinkedList(student);
        printingALinkedList(student);
        push(&stack1, student);
        printf("\nAdded Student\n");
        student = NULL;
        studentNumber--;
    }

    int minSchoolNumber = findMinimumSchoolNumber(&stack1);
    printf("\nMinumum School Number: %d\n", minSchoolNumber);

    return 0;
}

node* createALinkedList(node* head) {

    int StudentNo, i, ID, number;
    node* temp;
    printf("\nENTER STUDENT NO: ->");
    scanf("%d", &StudentNo);

    ID = StudentNo % 1000;
    char formattedNumber[4];  // 3 basamak + 1 bitiþik sýfýr için yer ayrýlýyor
    sprintf(formattedNumber, "%03d", number);
    
    
    sscanf(formattedNumber, "%d", &number);
    printf("\n%03d->ID\n",ID);

    int numberArray[9]= {};
    for (i = 8; i >= 0; i--) {
        numberArray[i] = StudentNo % 10;
        StudentNo = StudentNo / 10;
    }

    for (i = 0; i < 10; i++) {

        if (i == 0) {
            head = (node*)malloc(sizeof(node));
            head->data = ID;
            head->next = NULL;
            temp = head;
        } else {
            temp->next = (node*)malloc(sizeof(node));
            temp = temp->next;
            temp->data = numberArray[i - 1];
        }

    }
    temp->next = NULL;

    return head;
}

void printingALinkedList(node* head) {

    node* temp;
    temp = head;

    while (temp != NULL) {
       printf("%d ", temp->data);
       temp = temp->next;
   }
}

void initializeStack(stack* stk) {
    stk->top = -1;
}

void push(stack* stk, node* nod) {
    if (stk->top == STACK_SIZE)
        printf("Stack Full");
    else {
        stk->array[++(stk->top)] = nod;
    }
}

int findMinimumSchoolNumber(stack* stk) {
    int minNumber = INT_MAX;

    int i, j;
    for (i = 0; i <= stk->top; i++) {
        node* currentNode = stk->array[i];

        int currentNumber = 0;
        for (j = 0; j < 3; j++) {
            currentNumber = currentNumber * 10 + currentNode->data;
            currentNode = currentNode->next;
        }

        if (currentNumber < minNumber) {
            minNumber = currentNumber;
        }
    }

    return minNumber;
}

