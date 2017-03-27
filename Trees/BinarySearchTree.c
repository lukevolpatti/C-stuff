//Search a BST to see if a node has a given data member.
int search(struct Node *n, struct Data d){
	if(n == NULL){
		return 0;
	}
	else{
		if(n->d.data == d.data){
			return 1;
		}
		else if(n->d.data > d.data){
			return search(n->lChild, d);
		}
		else if(n->d.data < d.data){
			return search(n->rChild, d);
		}
	}
	return 0;
}

//Insert into a BST
struct Node *insertR(struct Node * n, struct Data d, int * count){
	if(n == NULL){
		*count = *count + 1;
		return newNode(d);
	}

	else{
		if(n->d.data > d.data){
			return insertR(n->lChild, d, count);
		}
		else if(n->d.data < d.data){
			return insertR(n->rChild, d, count);
		}
	}
	return n;
}