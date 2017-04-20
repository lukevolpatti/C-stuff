#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void insertAtFront(int d, struct Node** head){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = d;
	newNode->next = *head; 
	*head = newNode;
}

void insertAtEnd(int d, struct Node** head){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->next = NULL;
	newNode->data = d;

	struct Node* temp = *head;

	if(*head == NULL){
		*head = newNode;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void printList(struct Node* head){
	while(head != NULL){
		printf("%d\n", head->data);
		head = head->next;
	}
}

void deleteNode(int d, struct Node** head){
	struct Node* temp = *head, *prevNode = NULL;
	while(temp != NULL){
		if(temp->data == d){
			if(prevNode==NULL){
				*head = temp->next;
			}
			else{
				prevNode->next = temp->next;
			}
			free(temp);
			return;
		}
		prevNode = temp;
		temp = temp->next;
	}

}

int main(void){
	struct Node* myList = NULL;
	insertAtFront(6, &myList);
	insertAtFront(4, &myList);
	insertAtFront(5, &myList);
	insertAtFront(8, &myList);
	insertAtEnd(9, &myList);
	printList(myList);
	deleteNode(5,&myList);
	printList(myList);
}