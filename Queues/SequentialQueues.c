#define MAX 5

struct Data{
	int data;
};

struct Node{
	struct Data data;
};

struct Queue{
	int currSize;
	int head;
	int tail;
	struct Node queueArray[MAX];
};

void initQueue(struct Queue** qPtr){
	struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
	Q->currSize = 0;
	Q->head = 0;
	Q->rear = 0;
	*qPtr = Q;
}

void enqueue(struct Queue* Q, struct Data d){
	Q->queueArray[Q->tail].data = d;
	Q->tail = (Q->tail+1)%MAX;
	Q->currSize++;
}

void dequeue(struct Queue* Q){
	Q->queueArray[Q->head].data = NULL;
	Q->head = (Q->head +1)%MAX;
	Q->currSize--;
}

int main(void){

}