#include "functions.hh"

int main() {
	/* binarypointer a = new binarynode(3);
	binarypointer b = new binarynode(1);
	binarypointer c = new binarynode(5);
	binarypointer d = new binarynode(4);
	binarypointer e = new binarynode(6);
	a->binaryinsert(b);
	a->binaryinsert(c);
	
	a->binaryinsert(d);
	
	a->binaryinsert(e);

	a->printinorder();
	puts("");
	a->binarydelete(3);
	a->printinorder();
	puts("");
	a->binarydelete(5);
	a->binarydelete(6);
	a->printinorder();
	puts("");
	binaryclear(a);
//	a->printinorder(); */
/*  binarypointer a = new binarynode(0, "apple", 2);
	binarypointer b = new binarynode(0, "word", 2);
	binarypointer c = new binarynode(0, "water", 2);
	binarypointer d = new binarynode(0, "dragon", 2);
	binarypointer e = new binarynode(0, "ip", 2);
	a->binaryinsert(b);
	a->binaryinsert(c);

	a->binaryinsert(d);

	a->binaryinsert(e);

	a->printinorder(); */
	avlpointer a = new avlnode(1, "", 1);
	avlpointer b = new avlnode(-2, "", 1);
	avlpointer c = new avlnode(2, "", 1);
	avlpointer d = new avlnode(4);
	avlpointer e = new avlnode(3);
	avlpointer f = new avlnode(5);
	avlpointer g = new avlnode(6);

	/*
	avlinsert(b, a);
	avlinsert(c, a);
	avlinsert(d, a);
	
	avlinsert(e, a);
	avlinsert(f, a);
	avlinsert(g, a);
	*/
	//cout << a->height() << " "<< a->difference() << endl;
	a->binaryinsert(b);
	a->binaryinsert(c);

	a->binaryinsert(d);

	a->binaryinsert(e); 
	a->binaryinsert(f);
	a->binaryinsert(g);
	a = balance(a);
	a->printinorder();
	//balance((avlpointer)a->leftchild);
	//balance((avlpointer)a->rightchild);
	cout << endl;
	//avldelete(a, 4);
	//avldelete(a, 2);
	cout << a->height() << " " << a->difference() << endl;
	a->printinorder();	
	b->printinorder();
	cout << endl;
	c->printinorder();
	cout << endl;
	d->printinorder();
	cout << endl;
	e->printinorder();
	cout << endl;
	cout << e->height() << " " << e->difference() << endl;
	a->binarysearch(-2);
	cout << endl;
	b->binarysearchint(6);
	f->printinorder();
	cout << endl;

	binaryclear(e);
	return 0;
}