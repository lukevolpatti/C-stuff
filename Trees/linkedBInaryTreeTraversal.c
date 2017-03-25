//Traversing a linked binary tree
//Queue functions and structs needed for level order traversal. 

struct Data{
	int data;
};

struct Node{
	struct Data d;
	struct Node *rChild;
	struct Node *lChild;
};

//traverse a list and print In-Order
void printInOrder(struct Node * currNode){
	if(currNode != NULL){
		printInOrder(currNode->lChild);
		printf("%d\n", currNode->d.data);
		printInOrder(currNode->rChild);
	}
}

void printPostOrder(struct Node * currNode){
	if(currNode != NULL){
		printPostOrder(currNode->lChild);
		printPostOrder(currNode->rChild);
		printf("%d\n", currNode->d.data);
	}
}

void printPreOrder(struct Node * currNode){
	if(currNode != NULL){
		printf(currNode->d.data);
		printPreOrder(currNode->lChild);
		printPreOrder(currNode->rChild);
	}
}

void printLevelOrder(struct Node * currNode){
	if(currNode != NULL){
		struct Queue * q;
		struct Node * temp;
		initQueue(&q);
		enqueue(q, currNode);
		while(!isQueueEmpty(q)){
			dequeue(q, temp);
			if(temp!=NULL){
				printf("%d\n", temp->d.data);
				enqueue(temp->lChild);
				enqueue(temp->rChild);
			}
		}
	}
	free(q);
}

int main(void){

}