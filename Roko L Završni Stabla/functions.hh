#pragma once
#ifndef HEADER
#define HEADER
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string.h>
#include <stdexcept>

using namespace std;
extern int KEYMODE_INTEGER; //vrsta kljucne rijeæi 1= integer
extern int KEYMODE_STRING; //2= string
typedef class binarynode* binarypointer;
typedef class avlnode* avlpointer;

class binarynode {
public:
	binarypointer leftchild;
	binarypointer rightchild;
	int numberkey;
	string stringkey;
	int keymode;
	binarynode(int = 0, string = "", int = 1); //create new binary node
	
	int binarysearch(int = 0, string = "", int =1);
	int binarysearchint(int);
	int binarysearchstring(string);

	int binaryread(); //print out the content of node
	int binarychecktype(binarypointer);

	int binaryinsert(binarypointer); //instert current node into the root of another node, use binaryinsertstring/int depending on keymode
	binarypointer binaryinsertstring(binarypointer); //if strings
	binarypointer binaryinsertint(binarypointer); //if integers

	int binarydelete(int = 0, string = "", int = 1); //destroy the node of that value and rearange other nodes
	binarypointer binarydeleteint(int);
	binarypointer binarydeletestring(string);


	int printinorder();
	 // for avl tree
	virtual int height() {
		return 0;
	}
	virtual int  difference() {
		return 0;
	}
	/*virtual avlpointer balance(avlpointer) {
		return NULL;
	}*/	
	virtual avlpointer avlinsertint(avlpointer) { return NULL; }
	virtual avlpointer avlinstertstring(avlpointer) {return NULL;}
	virtual avlpointer rr_rotat() { return NULL; }
	virtual avlpointer ll_rotat() { return NULL; }
	virtual avlpointer lr_rotat() { return NULL; }
	virtual avlpointer rl_rotat() { return NULL; }
};

int binaryclear(binarypointer node); //deletes all children of this 
binarypointer minvaluenode(binarypointer);

class avlnode : public binarynode {
public:
	int height();
	int difference();


	avlpointer rr_rotat();
	avlpointer ll_rotat();
	avlpointer lr_rotat();
	avlpointer rl_rotat();


	using binarynode::binarynode;
	
};
	int avldelete(avlpointer, int = 0, string = "", int = 1); //destroy the node of that value and rearange other nodes
	avlpointer avldeleteint(avlpointer, int);
	avlpointer avldeletestring(avlpointer, string);

	int avlinsert(avlpointer, avlpointer);
	avlpointer avlinsertint(avlpointer, avlpointer);
	avlpointer avlinsertstring(avlpointer, avlpointer);

	avlpointer balance(avlpointer);


#endif