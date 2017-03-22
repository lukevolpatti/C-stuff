//Sequential binary tree operations
//Works only on complete (perfect) binary trees

//check if a node is the root node:
int isRoot(int i){
	if(i==1){
		return 1;
	}
	return false;
}

//check if a node is a leaf node:
int isLeaf(int i, int n){
	int index = i*2;
	if(index>n){
		return 1;
	}
	return 0;
}

//find left child node index
int findLeftChild(int i, int n){
	int index = i*2;
	if(index <= n){
		return index;
	}
	else{
		return -1;
	}
}

//find right child node index
int findRightChild(int i, int n){
	int index = i*2 + 1;
	if(index <= n){
		return index;
	}
	else{
		return -1;
	}
}

//find parent node index
int findParent(int i){
	int index = i/2;
	if(index >= 1){
		return index;
	}
	else{
		return -1;
	}	
}
