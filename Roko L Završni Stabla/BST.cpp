#include "functions.hh"

int KEYMODE_INTEGER = 1; //vrsta kljucne rijeæi 1= integer
int KEYMODE_STRING = 2; //2= string

binarynode::binarynode(int value, string word, int mode) {
	this->leftchild = this->rightchild = nullptr;
	this->numberkey = value;
	this->stringkey = word;
	this->keymode = mode;
}
int binarynode::binarychecktype(binarypointer operand) {
	if (this->keymode != operand->keymode)
	{
		cout << "Unequel Key modes" << endl;
		return -1;
	}
	if (this->keymode == 1) {
		return 1; //ako je integer

	}
	return 2; //ako je string
}
int binarynode::binaryinsert(binarypointer operand) {
	switch (this->binarychecktype(operand)) {
	case 1:
		this->binaryinsertint(operand);
		return 0;
		break;
	case 2:
		this->binaryinsertstring(operand);
		return 0;
		break;
	default:
		return -1;
	}

}

binarypointer binarynode::binaryinsertstring(binarypointer operand) {
	if (this == NULL) {
		return operand;
	}
	if (operand->stringkey < this->stringkey) {
		this->leftchild = this->leftchild->binaryinsertstring(operand);
	}
	else if (operand->stringkey > this->stringkey) {
		this->rightchild = this->rightchild->binaryinsertstring(operand);
	}
	else {
		free(operand);
	}
	return this;
}

binarypointer binarynode::binaryinsertint(binarypointer operand) {
	if (this == NULL) {
		return operand;
	}
	if (operand->numberkey < this->numberkey) {
		this->leftchild = this->leftchild->binaryinsertint(operand);
	}
	else if (operand->numberkey > this->numberkey) {
		this->rightchild = this->rightchild->binaryinsertint(operand);
	}
	else {
		free(operand);
	}
	return this;
}

binarypointer minvaluenode(binarypointer operand) {
	/* loop down to find the leftmost leaf */
	while (operand && operand->leftchild != NULL)
		operand = operand->leftchild;

	return operand;
}

int binarynode::binarydelete(int value, string word, int mode) { //  https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
	if (mode == 1) {
		this->binarydeleteint(value);
	}
	else {
		this->binarydeletestring(word);
	}
	return 1;
}

binarypointer binarynode::binarydeletestring(string word) {
	if (this == NULL)
		return this;

	// If the key to be deleted is
	// smaller than the this's
	// key, then it lies in left subtree
	if (word < this->stringkey)
		this->leftchild = this->leftchild->binarydeletestring(word);

	// If the key to be deleted is
	// greater than the this's
	// key, then it lies in right subtree
	else if (word > this->stringkey)
		this->rightchild = this->rightchild->binarydeletestring(word);

	// if key is same as this's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (this->leftchild == NULL and this->rightchild == NULL) {
			free(this);
			return NULL;
		}
		// node with only one child or no child
		else if (this->leftchild == NULL) {
			binarypointer temp = this->rightchild;
			free(this);
			return temp;
		}
		else if (this->rightchild == NULL) {
			binarypointer temp = this->leftchild;
			free(this);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		binarypointer temp = minvaluenode(this->rightchild);

		// Copy the inorder successor's content to this node
		this->stringkey = temp->stringkey;

		// Delete the inorder successor

		this->rightchild->binarydeletestring(temp->stringkey);

		//free(temp);
	}
	return this;	
}
binarypointer binarynode::binarydeleteint(int value) {
	if (this == NULL)
		return this;

	// If the key to be deleted is
	// smaller than the this's
	// key, then it lies in left subtree
	if (value < this->numberkey)
		this->leftchild = this->leftchild->binarydeleteint(value);

	// If the key to be deleted is
	// greater than the this's
	// key, then it lies in right subtree
	else if (value > this->numberkey)
		this->rightchild = this->rightchild->binarydeleteint(value);

	// if key is same as this's ke	y, then This is the node
	// to be deleted
	else {
		// node has no child
		if (this->leftchild == NULL and this->rightchild == NULL){
			free(this);
			return NULL;
		}
		// node with only one child or no child
		else if (this->leftchild == NULL) {
			binarypointer temp = this->rightchild;
			free(this);
			return temp;
		}
		else if (this->rightchild == NULL) {
			binarypointer temp = this->leftchild;
			free(this);
			return temp;
		}
		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		binarypointer temp = minvaluenode(this->rightchild);
		// Copy the inorder successor's content to this node
		this->numberkey = temp->numberkey;
		// Delete the inorder successor
		this->rightchild->binarydeleteint(temp->numberkey);
	}
	return this;
}

int binarynode::printinorder() {
		if (this == NULL) return 0;
		this->leftchild->printinorder();
		cout << "Int key: " << this->numberkey << " string key: " << this->stringkey << "Keymode: " << this->keymode << endl;
		this->rightchild->printinorder();
		return 0;
}

int binaryclear(binarypointer node) {
	if (node == NULL) return 0;
	binaryclear(node->rightchild);
	binaryclear(node->leftchild);
	binarypointer temp = node;
	delete temp;
	node = NULL;
}
int binarynode::binarysearch(int value, string word, int mode) {
	if (mode == 1) {
		this->binarysearchint(value);
	}
	else {
		this->binarysearchstring(word);
	}
	return 1;
}

int binarynode::binarysearchint(int value) {
	if (this == NULL) {
		return 1;
	}
	cout << this->numberkey << endl;

	if (this->numberkey > value) {
		this->leftchild->binarysearchint(value);
	}
	else if (this->numberkey < value) {
		this->rightchild->binarysearchint(value);
	}
	else {
		cout << "Naðen je broj" << value << endl;
		return 0;
	}	
}
int binarynode::binarysearchstring(string word) {
	cout << this->stringkey << endl;
	if (this == NULL) {
		return 1;
	}
	if (this->stringkey < word) {
		this->leftchild->binarysearchstring(word);
	}
	else if (this->stringkey > word) {
		this->rightchild->binarysearchstring(word);
	}
	else {
		cout << "Naðen je broj" << word << endl;
		return 0;
	}
}
