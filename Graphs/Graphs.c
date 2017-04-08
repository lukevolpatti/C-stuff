//Graphs

#include <stdio.h>
#include <stdlib.h>

#define NODES 8

struct listNode{
	int vertexLabel;
	struct listNode * next;
};

struct adjList{
	int visitedList[NODES];
	struct listNode *ptrArray[NODES];
};

struct adjMatrix{
	int matrix[NODES][NODES];
};

void breadthFirstTraversal(struct listNode * n, struct adjList * aL){
	struct Queue * q;
	struct listNode * l, *c;
	int i;

	initQueue(&q);
	enqueue(q, n);
	for(i = 0; i < NODES; i++){
		aL->visitedList[i] = 0;
	}
	while(isQueueEmpty(q) == 0){
		dequeue(q, &l);
		if(aL->visitedList[l->vertexLabel-1] == 0){ //if the node hasn't been visited
			printf("%d ", l->vertexLabel);
		}
		aL->visitedList[l->vertexLabel - 1] = 1;
		c = aL->ptrArray[l->vertexLabel - 1];
		while(c != NULL){
			if(aL->visitedList[c->vertexLabel - 1] == 0){
				enqueue(q, c);
			}
			c = c->next;
		}
	}
	free(q);
}

void depthFirstTraversal(struct listNode *n, struct adjList * aL){
	struct Stack *s, *sTemp;
		struct listNode *l, *c;
		int i;
		initStack(&s);
		initStack(*sTemp);
		push(s, n);
		for(i = 0; i < NODES; i++){
			aL->visitedList[i] = 0;
		}
		while(isEmpty(s) == 0){
			pop(s, &l);
			if(aL->visitedList[l->vertexLabel - 1] == 0){
				printf("%d ", l->vertexLabel);
				aL->visitedList[l->vertexLabel-1] = 1;
			}
			c = al->ptrArray[l->vertexLabel-1];
			while(c!=NULL){
				if(aL->visitedList[c->vertexLabel - 1] == 0){
					push(sTemp, c);
					aL->visitedList[c->vertexLabel-1] = 1;
				}
				c = c->next;
			}
			while(isEmpty(sTemp) == 0){
				pop(sTemp, &l);
				push(s, l);
			}
		}
		free(s);
}
