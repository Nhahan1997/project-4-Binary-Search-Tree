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
	int ID;
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
	virtual BinarySearchTree<DataType>* yTree ();
	// returns the yTree of xNode
	virtual bool subtree();
	virtual void makeEmpty ();
	virtual DataType find (const DataType& q);
	virtual void remove (const DataType& data);
	virtual void rangeSearch (const DataType& low, const DataType& high);
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



};

//print BST in in-order traversal
template <class DataType>
ostream& operator<< (ostream& s,  BinarySearchTree<DataType>& X) {
//	if (!X.isEmpty()){
//	s << *(X.left()) << " " << X.root() << " " << *(X.right()) ;
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
	if (!this->right()->isEmpty()){		// if right child not null, print it by using recursive
		this->right()->inOrder_xTreeDisplay();
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::inOrder_yTreeDisplay(){
	if (!this->left()->isEmpty()){
		this->left()->inOrder_yTreeDisplay();
	}
	cout << " " << this->root() << "(" << this->ID << ") ";
	cout << "hello";
	if (!this->right()->isEmpty()){
		this->right()->inOrder_yTreeDisplay();
	}
}
//--------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::preOrder_xTreeDisplay(){
	cout << this->root() << ": " << endl;
	this->yTree()->inOrder_yTreeDisplay();
	if (!this->left()->isEmpty()){
		this->left()->inOrder_xTreeDisplay();
	}
	if (!this->right()->isEmpty()){
		this->right()->inOrder_xTreeDisplay();
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::preOrder_yTreeDisplay(){
	cout << " " << this->root() << "(" << this->ID << ") ";
	this->yTree()->left()->inOrder_yTreeDisplay();
	this->yTree()->right()->inOrder_yTreeDisplay();

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
BinarySearchTree<DataType>* BinarySearchTree<DataType>::yTree (){ return _yTree; }
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
DataType BinarySearchTree<DataType>::find (const DataType& q)
{
	BinarySearchTree<DataType>* bst = _find (q);
	try{
		if (bst->isEmpty()) throw BinarySearchTreeNotFound();
		if (bst->root() == q){
			cout<<"\nThe element "<<bst->root()<<" is found in the tree"<<endl;
			return bst->root();
		}
		else return find(q);
	}
	catch(Exception e)
	{
//		cout<<"\nSorry!!! Element is not found in the tree";//<<endl;
//		cout<<endl;
//		return q; //We need to fix this
		return -1;
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
		//create a yTree object as the _yTree of temp1
		BinarySearchTree<DataType>* yTree = temp1->_yTree;
		if (yTree == NULL){
			yTree = new BinarySearchTree<DataType>(y);	//if it is null create new yTree with root is y coordinate
			yTree->ID = IDT;	//pass the IDT to ID of x-y coordinate
		}
		else{	//if searchBST is not empty
			// just create new yTree BST pointer object and use _insert to pass the y coordinate to BST->yTree
			BinarySearchTree<DataType>* temp2 = _insert(y);
			temp2->ID = IDT;
		}

	}
	else{
		BinarySearchTree<DataType>* yTree = searchBST->_yTree;
		if (yTree == NULL){
			yTree = new BinarySearchTree<DataType>(y);
			yTree->ID = IDT;
		}
		else{
			BinarySearchTree<DataType>* temp2 = _insert(y);
			temp2->ID = IDT;
		}
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::remove (const DataType& data)
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
void BinarySearchTree<DataType>::rangeSearch (const DataType& low, const DataType& high)
{
	if (isEmpty()) return;
	if (*_root >= low)
    {
        _left->rangeSearch(low,high);
		if (*_root <= high)
		{
			cout << *_root << "  ";
		}
    }
	if (*_root <= high)
        _right->rangeSearch(low,high);
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
//		temp->left() = GlobalRebalance(inOrderArray, l, mid - 1);
//		temp->right() = GlobalRebalance(inOrderArray, mid + 1, r);
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
		cout << "No tree for inorder traversal";
		cout << endl;
		return index;
	}

	cout << "value: " << this->root() << endl;
	cout << "left: " << *(this->left()->_root) << endl;
	cout << "right: " << *(this->right()->_root) << endl;

	if (!this->isEmpty()) {
		if(node->left()->_root != NULL)
		{
			// cout << "\tcalling left" << endl;
			index = node->left()->getInorderTraversal(node->left(), inOrderArray, index);
		}

		inOrderArray[index++] = node;
		// cout << "index: " << index - 1 << " inOrderArray[i]: " << inOrderArray[index - 1]->root() << endl;

		if(node->right()->_root != NULL)
		{
			// cout << "\tcalling right" << endl;
			index = node->right()->getInorderTraversal(node->right(), inOrderArray, index);
		}
	}
	return index;
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::print(){
//	BinarySearchTree<DataType>* bst = this;
//	cout << *bst << endl;
	cout << *this << endl;
}


#endif
