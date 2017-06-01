struct Data{
	int data;
};

struct Node{
	struct Data d; 
	struct Node* next;
};

struct Queue{
	int currSize;
	struct Node* head;
	struct Node* tail;
};

void initQueue(struct Queue** qPtr){
	struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
	Q->currSize = 0;
	Q->head = NULL;
	Q->tail = NULL;
	*qPtr = Q;
}

void enqueue(struct Queue* Q, struct Data d){
	struct Node* newNode;
	newNode->d = d;
	newNode->next = NULL;

	if(Q->head == NULL){
		Q->head = newNode;
		Q->tail = newNode;
	}

	else{
		Q->tail->next = newNode;
		Q->tail = newNode;
	}
	Q->currSize++; 
}

void dequeue(struct Queue* Q, struct Data* d){
	struct Node* temp = Q->head;
	*d = temp->d;
	if(Q->head == Q->tail){
		Q->head = NULL;
		Q->tail = NULL;
	}
	else{
		Q->head = Q->head->next;
	}
	free(temp);
	Q->currSize--;
}


int main(void){
	
}
