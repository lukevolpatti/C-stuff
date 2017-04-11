#define M 7

struct Info{
	int data;
};

struct Key{
	int key;
};

struct TableEntry{
	struct Info I;
	struct Key K;
};

struct Table{
	struct TableEntry T[M];
};

//Create a table and set all key/info entries to -1
struct Table initTable(){
	int i;
	struct Table table;
	for(i = 0; i<M; i++){
		table.T[i].I.data = -1;
		table.T[i].K.data = -1;
	}
	return table;
}

//Return index of cell to be stored in
int h(struct Key K){
	return K.data % M;
}

//To be used when double hashing:
int p(struct Key K){
	int quo = K.data/M;
	if(quo != 0){
		return quo;
	}
	else{
		return 1;
	}
}

//Insert a key with info into 
void insertKey(struct Key K, struct Info I, struct Table * table){
	int index = h(K);
	int probeSize = p(k);
	while(table->T[index].K.data != -1){
		index -= probeSize;
		if(index < 0){
			index += M;
		}
	}
	table->T[index].K = K;
	table->T[index].I = I;
}

//Search for a key in a hash table, return 1 if the key is in the table
int searchKey(struct Key K, struct Table* table){
	int index = h(K);
	int probeSize = p(K);
	while((table->T[index].K.data != -1) && (table->T[index].K != K)){
		index -= probeSize;
		if(index < 0){
			index += M;
		}
	}
	
}
