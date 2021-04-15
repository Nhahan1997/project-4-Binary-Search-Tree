/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include <iostream>
using namespace std;

#ifndef __BINARYSEARCHTREE__H
#define __BINARYSEARCHTREE__H

#include <cstdlib>

//find the max
int max (int a, int b)
{
	if (a < b) return b;	//return b if b greater than a, else return a
	else return a;
}

class Exception {};

class BinaryTreeException : Exception {};
class BinaryTreeMemory : BinaryTreeException {};
class BinaryTreeEmptyTree : BinaryTreeException {};

class BinarySearchTreeException: BinaryTreeException {};
//class BinarySearchTreeChangedSubtree : BinarySearchTreeException {};
class BinarySearchTreeNotFound : BinarySearchTreeException {};

template <class DataType>
class BinarySearchTree;

template <class DataType>
ostream& operator << (ostream& s,  BinarySearchTree<DataType>& X);

// /////////////////////////////////////////////////////////////
template <class DataType>
class BinarySearchTree
// /////////////////////////////////////////////////////////////
{
	friend ostream& operator<< <DataType> (ostream& s,  BinarySearchTree<DataType>& X);
protected:
	DataType* _root;	//root of tree
	BinarySearchTree<DataType>* _left;	//left child of root
	BinarySearchTree<DataType>* _right;	//right child of root
	BinarySearchTree<DataType>* _yTree;
//	BinarySearchTree<DataType>** inOrderArray;

	int ID;
//	int k;
	bool _subtree;	//subtree
	virtual BinarySearchTree<DataType>* makeSubtree();	//create a new subtree
	virtual void copyTree (BinarySearchTree<DataType>* bst);
	virtual void _makeNull ();
	BinarySearchTree<DataType>* _find (const DataType& data);
public:
	BinarySearchTree ();	//default constructor
	BinarySearchTree (const DataType& data);	//non-default constructor
	virtual ~BinarySearchTree ();	//destructor
	virtual bool isEmpty();
    // returns true if tree is empty,
    // but otherwise returns false
	virtual int height ();
    // returns the height (or depth) of the tree
	virtual int size ();
    // returns the number of nodes in the tree
	virtual DataType& root ();
    // returns data from the root
	virtual BinarySearchTree<DataType>* left ();
    // returns the left subtree
	virtual BinarySearchTree<DataType>* right ();
    // returns the right subtree
	virtual BinarySearchTree<DataType>* left (BinarySearchTree<DataType>* bst);
	// setter for the left subtree
	virtual BinarySearchTree<DataType>* right (BinarySearchTree<DataType>* bst);
	// setter the right subtree
	virtual BinarySearchTree<DataType>* yTree ();
	// returns the yTree of xNode
	virtual BinarySearchTree<DataType>* setYTree(BinarySearchTree<DataType>* bst);
//	virtual BinarySearchTree<DataType>** getInOrderArray ();
	virtual bool subtree();
	virtual void makeEmpty ();
	virtual void find (const DataType& x, const DataType& y);
	virtual void _remove (const DataType& data);
	virtual void remove (const DataType& x, const DataType& y);
	virtual void _rangeSearch (const DataType& low, const DataType& high);
	virtual void rangeSearch (const DataType& low, const DataType& high, const DataType& lowY, const DataType& highY);
	virtual BinarySearchTree<DataType>* _insert (const DataType& data);
	virtual void insert (const DataType& x, const DataType& y, int ID);
	virtual int getInorderTraversal(BinarySearchTree<DataType>* node,
			BinarySearchTree<DataType>** inOrderArray, int index);
	virtual BinarySearchTree<DataType>* GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r);
	virtual void print();
	virtual void inOrder_xTreeDisplay();
	virtual void inOrder_yTreeDisplay();
	virtual void preOrder_xTreeDisplay();
	virtual void preOrder_yTreeDisplay();
	virtual void yBalance(const DataType& x);



};

//print BST in in-order traversal
template <class DataType>
ostream& operator<< (ostream& s,  BinarySearchTree<DataType>& X) {
//	if(!X.isEmpty()){
//		s << *(X.left()) << " " << X.root() << " " << *(X.right());
//	}

	cout << "INORDER  TRAVERSAL: ";
	cout << endl;
	X.inOrder_xTreeDisplay();
	cout << "PREORDER  TRAVERSAL: ";
	cout << endl;
	X.preOrder_xTreeDisplay();
	return s;
}

// ==============================================================
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree ()
{
	_root = NULL;
	_left = NULL;
	_right = NULL;
	_yTree = NULL;
	ID = 0;
	_subtree = false;
//	inOrderArray = new BinarySearchTree<DataType>*[0];
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree (const DataType& data)
{
	_subtree = false;
	_root = new DataType(data);
	//if (data == NULL) throw BinaryTreeMemory();
	_left = makeSubtree ();
	_right = makeSubtree ();
	_yTree = NULL;
//	inOrderArray = new BinarySearchTree<DataType>*[this->size()];
//	for (int i = 0; i < this->size(); i++){
//		inOrderArray[i] = NULL;
//	}
	ID = 0;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::inOrder_xTreeDisplay(){
	if (!this->left()->isEmpty()){		// if left child not null, print it by using recursive
		this->left()->inOrder_xTreeDisplay();
	}

	cout << this->root() << ": " << endl;	//print the root

	if (!this->yTree()->isEmpty()){
		this->yTree()->inOrder_yTreeDisplay();	// if _yTree not null, call the inOrder_yTreeDisplay
	}
	cout << endl;
	if (!this->right()->isEmpty()){		// if right child not null, print it by using recursive
		this->right()->inOrder_xTreeDisplay();
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::inOrder_yTreeDisplay(){
	if (!left()->isEmpty()){
		left()->inOrder_yTreeDisplay();
	}
	cout << " " << this->root() << "(" << this->ID << ") ";
	if (!right()->isEmpty()){
		right()->inOrder_yTreeDisplay();
	}
}
//--------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::preOrder_xTreeDisplay(){
	cout << this->root() << ": " << endl;
	if (!this->yTree()->isEmpty())
		this->yTree()->preOrder_yTreeDisplay();
	cout << endl;
	if (!this->left()->isEmpty())
		this->left()->preOrder_xTreeDisplay();

	if (!this->right()->isEmpty()){
		this->right()->preOrder_xTreeDisplay();
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::preOrder_yTreeDisplay(){
	cout << " " << this->root() << "(" << this->ID << ") ";
	if (!left()->isEmpty()){
		left()->preOrder_yTreeDisplay();
	}
	if (!right()->isEmpty()){
		right()->preOrder_yTreeDisplay();
	}

}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::makeSubtree()
{
	BinarySearchTree<DataType>* bst = new BinarySearchTree<DataType> ();
	bst->_subtree = true;
	return bst;
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>::~BinarySearchTree ()
{
	if (_root != NULL)
        delete _root;
    _root = NULL;
	if (_left != NULL)
        delete _left;
    _left = NULL;
	if (_right != NULL)
        delete _right;
    _right = NULL;
    if (_yTree != NULL)
       	delete _yTree;
    _yTree = NULL;
}
// --------------------------------------------------------------
template <class DataType>
bool BinarySearchTree<DataType>::isEmpty()
{
//	return (_root == NULL);
	if (_root == NULL)
		return true;
	else return false;

	return true;
}
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::height ()
{
	if (isEmpty()) return 0;
    return (1 + max (_left->height(), _right->height()));
   	// max() is in stdlib.h
}
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::size ()
// returns the number of nodes in the tree
{
	if (isEmpty())
		return 0;
	return (1 + _left->size() + _right->size());
}
// --------------------------------------------------------------
template <class DataType>
DataType& BinarySearchTree<DataType>::root ()
{
	if (isEmpty()) throw BinaryTreeEmptyTree();
	return *_root;
}
// returns data from the root
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::left () { return _left; }
// returns the left subtree
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::right (){ return _right; }
// returns the right subtree
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::left (BinarySearchTree<DataType>* bst)
{
	return _left = bst;
}
// setter the left subtree
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::right (BinarySearchTree<DataType>* bst)
{
	return _right = bst;
}
// setter the right subtree
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::yTree (){ return _yTree; }
// returns the yTree of xNode
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::setYTree (BinarySearchTree<DataType>* bst){
	return _yTree = bst;
}
// set bst to yTree
// --------------------------------------------------------------
//template <class DataType>
//BinarySearchTree<DataType>** BinarySearchTree<DataType>::getInOrderArray (){ return inOrderArray; }
// returns the yTree of xNode
// --------------------------------------------------------------
template <class DataType>
bool BinarySearchTree<DataType>::subtree() { return _subtree; }
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::makeEmpty ()
{
	//if (_subtree) throw BinarySearchTreeChangedSubtree();
	if (_root != NULL)
   		delete _root;
    _root = NULL;
	if (_left != NULL)
	   	delete _left;
    _left = NULL;
	if (_right != NULL)
	   	delete _right;
    _right = NULL;
    if (_yTree != NULL)
    	delete _yTree;
    _yTree = NULL;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::copyTree(BinarySearchTree<DataType>* bst)
{
	_root = bst->_root;
	_left = bst->_left;
	_right = bst->_right;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::_makeNull ()
{
	_root = NULL;
	_left = NULL;
	_right = NULL;
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_find (const DataType& data)
{
	BinarySearchTree<DataType>* bst = this;
	while (true)
	{
		if (bst->isEmpty())
			return bst;
		if (*(bst->_root) < data)
		{
			bst = bst->_right;
		}
		else if (*(bst->_root) > data)
		{
            bst = bst->_left;
		}
		else
		{
			return bst;
		}
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::find (const DataType& x, const DataType& y)
{
	BinarySearchTree<DataType>* bst = _find (x);
	try{
		if (bst->isEmpty()) throw BinarySearchTreeNotFound();
		if (bst->root() == x){
			BinarySearchTree<DataType>* bst2 = bst->_yTree->_find(y);
			if (bst->isEmpty()) throw BinarySearchTreeNotFound();
			if (bst2->root() == y)
				cout<<"\nThe coordinate "<<bst->root()<< ", " << bst2->root()
				<< " is found in the tree with ID value " << bst2->ID  << endl;
		}

	}
	catch(BinarySearchTreeNotFound e)
	{
		cout<<"\nSorry!!! Coordinate is not found in the X tree";
		cout<<endl;
	}
	catch(BinaryTreeEmptyTree e)
	{
		cout<<"\nSorry!!! Coordinate is not found in the X tree";
		cout<<endl;
	}
}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_insert (const DataType& data)
{
	//if (_subtree) throw BinarySearchTreeChangedSubtree();
	BinarySearchTree<DataType>* bst = _find (data);
	if (bst->isEmpty())
	{
		bst->_root = new DataType (data);
		bst->_left = makeSubtree ();
		bst->_right = makeSubtree ();
	}
	else
	{
        delete bst->_root;
		bst->_root = new DataType (data);
	}
	return bst;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::insert (const DataType& x, const DataType& y, int IDT)
{
	//using _find to find where x coordinate in tree, returned
	//and store it in searchBST object
	BinarySearchTree<DataType>* searchBST = _find(x);
	if (searchBST->isEmpty()){	//if searchBST is empty
		//create a temp1 object and use _insert to return pointer from _insert into temp1
		BinarySearchTree<DataType>* temp1 = _insert(x);
		// check if temp1->_yTree is NULL
		if (temp1->_yTree == NULL){
			BinarySearchTree<DataType>* yTree = new BinarySearchTree<DataType>(y);	//if it is null create new yTree with root is y coordinate
			yTree->ID = IDT;	//pass the IDT to ID of x-y coordinate
			temp1->_yTree = yTree;		//store yTree to _yTree of temp1

		}
		else{	//if searchBST is not empty
			//  create new BST pointer object temp2 and use _insert to pass the y coordinate to BST->yTree
			BinarySearchTree<DataType>* temp2 = temp1->_yTree->_insert(y);
			temp2->ID = IDT;	//pass the IDT to of x-y coordinate
		}

	}
	else{	//the searchBST is not empty
		// check if searchBST->_yTree is NULL
		if (searchBST->_yTree == NULL){
			//if it is null create new yTree with root is y coordinate
			BinarySearchTree<DataType>* yTree = new BinarySearchTree<DataType>(y);
			searchBST->_yTree = yTree;		//store yTree to _yTree of sreachBST
			searchBST->_yTree->ID = IDT;	//pass the IDT to of x-y coordinate
		}
		else{
			//  create new BST pointer object temp2 and use _insert to pass the y coordinate to BST->yTree
			BinarySearchTree<DataType>* temp2 = searchBST->_yTree->_insert(y);
			temp2->ID = IDT;		//pass the IDT to of x-y coordinate
		}
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::_remove (const DataType& data)
{
	//if (_subtree) throw BinarySearchTreeChangedSubtree();
	BinarySearchTree<DataType>* bst;
	BinarySearchTree<DataType>* bst2;
	BinarySearchTree<DataType>* bst3;

	bst = _find (data);
	if (bst->isEmpty()) throw BinarySearchTreeNotFound();

    // dispose of the existing data; the pointer will be overwritten
    delete bst->_root;

    // .............................................................
	if (bst->_left->isEmpty())
	{
        // the left subtree exists, but the pointer will be overwritten,
        // so we must dispose of it
        delete bst->_left;
        bst2 = bst->_right;		// save the pointer to the right subtree
		bst->copyTree (bst2);	// copy the right subtree;
        // this empties tree if right empty
        bst2->_makeNull ();		// prepare right subtree for deletion
        delete bst2;				// delete right subtree to avoid garbage
	}

	else if (bst->_right->isEmpty())
	{
        // the right subtree exists, but the pointer will be overwritten,
        // so we must dispose of it
        delete bst->_right;
        bst2 = bst->_left;		// save the pointer to the left subtree
		bst->copyTree (bst2);	// copy the left subtree
        bst2->_makeNull ();		// prepare left subtree for deletion
        delete bst2;				// delete left subtree to avoid garbage
	}

	else		// both subtrees non-empty
	{
        // move to the right
		bst2 = bst->_right;
        // then move down to the left as far as possible
		while (!bst2->_left->isEmpty()) bst2 = bst2->_left;
        // overwrite the data pointer
		bst->_root = bst2->_root;

        // bst2's left child is known to be empty and pointer will be overwritten
     	delete bst2->_left;
        // now bst2's right child is copied into it
		if (bst2->_right->isEmpty())
        {
	     	delete bst2->_right;
            bst2->_makeNull();
        }
		else
        {
            bst3 = bst2->_right;
            bst2->copyTree(bst2->_right);
            bst3->_makeNull ();
            delete bst3;
        }
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::remove(const DataType& x, const DataType& y){
	BinarySearchTree<DataType>* temp1 = _find(x);
	if (temp1->isEmpty()){
		cout << "The element you are trying to remove is not in the tree";
		cout << endl;
	}
	else{
		BinarySearchTree<DataType>* temp2 = temp1->_yTree->_find(y);
		if (temp2->isEmpty()){
			cout << "The element you are trying to remove is not in the tree";
			cout << endl;
		}
		else{
			temp2->_remove(y);
			if(temp1->_yTree->size() == 0)
				temp1->_remove(x);
		}
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::_rangeSearch (const DataType& lowY, const DataType& highY)
{
	if (isEmpty()) return;
	if (*_root >= lowY){
		_left->_rangeSearch(lowY, highY);
		if (*_root <= highY)
			cout << *_root << " ";
	}
	if (*_root <= highY)
		_right->_rangeSearch(lowY, highY);
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::rangeSearch(const DataType& low, const DataType& high, const DataType& lowY, const DataType& highY)
{
	if (isEmpty()) return;
	if (*_root >= low)
	{
		_left->rangeSearch(low, high, lowY, highY);
		if (*_root <= high)
		{
			int x = *_root;
			cout << x << " : ";
			BinarySearchTree<DataType>* temp1 = _find(x);
			temp1->_yTree->_rangeSearch(lowY, highY);
			cout << endl;
		}
	}
	if (*_root <= high)
		_right->rangeSearch(low, high, lowY, highY);

}
// --------------------------------------------------------------
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r){
	int mid = 0;
	BinarySearchTree<DataType>* temp = new BinarySearchTree<DataType>();

	if(l <= r)
	{
		mid = ((l + r) / 2);
		temp = inOrderArray[mid];
		temp->left((GlobalRebalance(inOrderArray, l, mid - 1)));
		temp->right((GlobalRebalance(inOrderArray, mid + 1, r)));
	}

	return temp;
}
// --------------------------------------------------------------
template <class DataType>
int BinarySearchTree<DataType>::getInorderTraversal(BinarySearchTree<DataType>* node, BinarySearchTree<DataType>** inOrderArray, int index)
{
	try{
		if (node->isEmpty()) throw BinarySearchTreeNotFound();
	}
	catch(BinarySearchTreeNotFound e){
		 return index;
	}

	if (!this->isEmpty()) {
		if(node->left()->_root != NULL)
		{
			index = node->left()->getInorderTraversal(node->left(), inOrderArray, index);
		}

		inOrderArray[index++] = node;

		if(node->right()->_root != NULL)
		{
			index = node->right()->getInorderTraversal(node->right(), inOrderArray, index);
		}
	}
	return index;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::yBalance(const DataType& x){
	BinarySearchTree<DataType>* temp1 = _find(x);
	BinarySearchTree<DataType>* temp2 = temp1->_yTree;
	int size = temp2->size();
	BinarySearchTree<DataType>** inOrderArray = new BinarySearchTree<DataType>*[size];
	for (int i = 0; i < size; i++){
		inOrderArray[i] = new BinarySearchTree<DataType>();
	}
	getInorderTraversal(temp2, inOrderArray, 0);
	temp1->setYTree(GlobalRebalance(inOrderArray, 0, size-1));


}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::print(){
	cout << *this << endl;
}


#endif
