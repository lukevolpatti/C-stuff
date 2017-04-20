#include <stdio.h>
#include <stdlib.h>

struct Data{
	int data;
};

struct Node{
	struct Data d;
	struct Node* next;
};

struct Stack{
	int currSize;
	struct Node* top;
};

void initStack(struct Stack** sPtr){
	struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
	S->currSize = 0;
	S->top = NULL;
	*sPtr = S;
}

void push(struct Stack* S, struct Data d){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->d = d;

	newNode->next = S->top;
	S->top = newNode;
	S->currSize++;
}

void pop(struct Stack* S, struct Data* d){

	if(S->currSize!=0){
		struct Node* temp = S->top;
		*d = temp->d;
		S->top = temp->next;
		free(temp);
		S->currSize--;
	}
}

int main(void){

}
