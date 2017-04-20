struct listNode{
	int vertexLabel;
	struct listNode* next;
};

struct adjList{
	struct listNode* ptrArray[NODES];
	int visitedNodes[NODES];
};

struct adjMat{
	int matrix[NODES][NODES];
};

void breadthFirstTraversal(struct listNode* n, struct adjList* aL){
	struct Queue* q;
	initQueue(&q);
	struct listNode* temp, deleted;
	int i;

	for(i = 0; i < NODES; i++){
		aL->visitedNodes[i] = 0;
	}
	enqueue(q, listNode->vertexLabel);

	while(!isEmpty(q)){
		dequeue(q, deleted);
		if(aL->visitedNodes[deleted->vertexLabel - 1] == 0){
			printf("%d\n", deleted->vertexLabel);
		}
		aL->visitedNodes[deleted->vertexLabel - 1] = 1;
		temp = aL->visitedNodes[deleted->vertexLabel - 1];

		while(temp != NULL){
			if(aL->visitedNodes[temp->vertexLabel - 1] == 0){
				enqueue(q, temp->vertexLabel);
			}
			temp = temp->next;
		}
	}
	free(q);
}

void depthFirstTraversal(struct listNode* n, struct adjList* aL){
	struct Stack* s, sTemp;
	initStack(&s);
	initStack(&sTemp);
	int i, j;

	struct Node* deleted, temp;

	for(i=0; i<NODES; i++){
		aL->visitedNodes[i] = 0;
	}

	push(s, listNode);
	while(!isEmpty(s)){
		pop(s, deleted);
		if(aL->visitedNodes[deleted->vertexLabel - 1] == 0){
			printf("%d\n", deleted->vertexLabel);
		}
		aL->visitedNodes[deleted->vertexLabel - 1] = 1;
		temp = aL->visitedNodes[deleted->vertexLabel - 1];
		while(temp != NULL){
			if(aL->visitedNodes[temp->vertexLabel - 1] == 0){
				push(sTemp, temp->vertexLabel);
			}
			temp = temp->next;
		}
		while(!isEmpty(sTemp)){
			pop(sTemp, &deleted);
			push(s, deleted);
		}
	}
	free(s);
}
