#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node * next;
};

//add a new node
void push(struct Node ** head, int data){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

//count how many times a number appears in a linked list
int count(struct Node*head, int searchFor){
	int counter = 0;
	struct Node *temp = head;
	while(temp != NULL){
		if(temp->data == searchFor){
			counter++;
		}
		temp = temp->next;
	}
	return counter;
}

//get the data of the nth index
int getNth(struct Node *head, int index){
	int currInd = 0;
	struct Node *temp = head;
	while(temp != NULL){
		if(currInd == index){return temp->data;}
		currInd++;
		temp = temp->next;
	}
	printf("Error: invalid index");
	return 0;

}

//dealocates all nodes and sets head pointer to null
void deleteList(struct Node** headRef){
	struct Node* current = *headRef;
	struct Node* next;

	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	*headRef = NULL;
}

//take a non-empty list and removes the front node
int pop(struct Node** headRef){
	struct Node *temp = *headRef;
	int data = temp->data;

	//insert assert here to make sure that temp!= NULL?

	*headRef = temp->next;
	free(temp);

	return data;
}

//insert a node at specified index
void InsertNth(struct Node** headRef, int index, int data){
	struct Node *temp = *headRef;
	int currInd = 0;

	if(index == 0){
		push(headRef, data);
	}

	else{
		while(currInd != index - 1){
			if(temp->next != NULL){
				temp = temp->next;
				currInd ++;
			}
			else{return;}
		}

		if(currInd == index - 1){
			struct Node *newNode = (struct Node *)malloc(sizeof(Node));
			newNode->data = data;
			newNode->next = NULL;

			if(temp->next == NULL){return;}
			
			newNode = temp->next;
			temp->next = newNode;
		}
	}

}

int main(void){
	struct Node * first  = (struct Node*)malloc(sizeof(struct Node));
	struct Node * second = (struct Node*)malloc(sizeof(struct Node));
	struct Node * third  = (struct Node*)malloc(sizeof(struct Node));

	struct Node *pL = first;

	first->data = 1;
	first->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	push(&pL, 7);
	push(&pL, 9);
	push(&pL, 11);


	struct Node *temp = pL;
	while(temp->next != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	printf("%d\n", temp->data);

	printf("there are: %d\n", count(pL, 9));

	printf("the nth elem is: %d\n", getNth(pL, 5));
	printf("pop!: %d\n", pop(&pL));
}
