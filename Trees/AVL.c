//AVL Trees

#include"linkedBinaryTreeTraversal.c"

//Rotate tree right, return new root
struct Node *rightRotate(struct Node *n){
	struct Node * n1 = n->lChild;
	struct Node * n2 = n1->rChild;

	n->lChild = n2;
	n1->rChild = n;

	return n1;
}

//Rotate tree left, return new root
struct Node *leftRotate(struct Node *n){
	struct Node * n1 = n->rChild;
	struct Node * n2 = n1->lChild;

	n->rChild = n2;
	n1->lChild = n;

	return n1;
}

int main(void){
	struct Node * n1 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * n2 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * n3 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * n4 = (struct Node *)malloc(sizeof(struct Node));
	struct Node * n5 = (struct Node *)malloc(sizeof(struct Node));

	struct Data d1;
	struct Data d2;
	struct Data d3;
	struct Data d4;
	struct Data d5;

	d1.data = 10;
	d2.data = 5;
	d3.data = 11;
	d4.data = 2;
	d5.data = 8;	

	n1->d = d1;
	n2->d = d2;
	n3->d = d3;
	n4->d = d4;
	n5->d = d5;

	n1->lChild = n2;
	n1->rChild = n3;
	n2->lChild = n4;
	n2->rChild = n5;

	n3->lChild = NULL;
	n3->rChild = NULL;
	n4->lChild = NULL;
	n4->rChild = NULL;
	n5->lChild = NULL;
	n5->rChild = NULL;

	printPreOrder(n1);
	printf("//////\n");
	printPreOrder(rightRotate(n1));
	printf("//////\n");
	printPreOrder(leftRotate(rightRotate(n1))); //output from this line is a little off!

}
