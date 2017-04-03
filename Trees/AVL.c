//AVL Trees

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
	struct Node n1 = n->rChild;
	struct Node n2 = n1->lChild;
	n->rChild = n2;
	n1->lChild = n;

	return n1;
}