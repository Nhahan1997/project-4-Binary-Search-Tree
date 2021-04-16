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
	virtual BinarySearchTree<DataType>* left (BinarySearchTree<DataType>* bst);
	// setter for the left subtree
	virtual BinarySearchTree<DataType>* right (BinarySearchTree<DataType>* bst);
	// setter the right subtree
	virtual BinarySearchTree<DataType>* yTree ();
	// returns the yTree of xNode
	virtual BinarySearchTree<DataType>* setYTree(BinarySearchTree<DataType>* bst);
	virtual bool subtree();
	//return _subtree which is true or false
	virtual void makeEmpty ();
	//make the tree empty
	virtual void find (const DataType& x, const DataType& y);
	//find the element at coordinate x-y
	virtual void _remove (const DataType& data);
	//remove the  node data in tree
	virtual void remove (const DataType& x, const DataType& y);
	//remove the element at coordinate x-y
	virtual void _rangeSearch (const DataType& low, const DataType& high);
	//search the element in range of ytree
	virtual void rangeSearch (const DataType& low, const DataType& high, const DataType& lowY, const DataType& highY);
	//search element in range for xNode what element in range of xNode's yTree
	virtual BinarySearchTree<DataType>* _insert (const DataType& data);
	//insert the data
	virtual void insert (const DataType& x, const DataType& y, int ID);
	//insert element at x-y coordinate with its ID
	virtual int getInorderTraversal(BinarySearchTree<DataType>* node,
			BinarySearchTree<DataType>** inOrderArray, int index);
	//method used to fill inOrderArray and return last index of array
	virtual BinarySearchTree<DataType>* GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r);
	//balance the tree
	virtual void print();	//print out the tree
	virtual void inOrder_xTreeDisplay();	//print xTree in inOrder traversal
	virtual void inOrder_yTreeDisplay();	//print yTree in inOrder traversal
	virtual void preOrder_xTreeDisplay();	//print xTree in preOrder traversal
	virtual void preOrder_yTreeDisplay();	//print xTree in preOrder traversal
	virtual void yBalance(const DataType& x);	//balance the yTree at xNode x



};

//print BST in in-order traversal
template <class DataType>
ostream& operator<< (ostream& s,  BinarySearchTree<DataType>& X) {
	cout << "INORDER TRAVERSAL: ";
	cout << endl;
	X.inOrder_xTreeDisplay();	//call inOrder_xTreeDisplay method
	cout << "PREORDER TRAVERSAL: ";
	cout << endl;
	X.preOrder_xTreeDisplay();	//call preOrder_xTreeDisplay method
	return s;
}

// ==============================================================
//default constructor. set null for all _root, _left, _right, _ytree
//set 0 for ID, false for _subTree
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
//non-default constructor
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree (const DataType& data)
{
	_subtree = false;
	_root = new DataType(data);		//root of tree now is data
	//if (data == NULL) throw BinaryTreeMemory();
	_left = makeSubtree ();		//make a left tree
	_right = makeSubtree ();	//make a right tree
	_yTree = NULL;
	// inOrderArray with size of the tree
	ID = 0;
}
// --------------------------------------------------------------
//display xtree in inOrder traversal
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
//display ytree in inOrder traversal
template <class DataType>
void BinarySearchTree<DataType>::inOrder_yTreeDisplay(){
	if (!left()->isEmpty()){	// if left child of ytree not null, print it by using recursive
		left()->inOrder_yTreeDisplay();
	}
	//print root of ytree and its ID
	cout << " " << this->root() << "(" << this->ID << ") ";
	if (!right()->isEmpty()){	// if right child of ytree not null, print it by using recursive
		right()->inOrder_yTreeDisplay();
	}
}
//--------------------------------------------------------------
//display xTree on preOrder traversal
template <class DataType>
void BinarySearchTree<DataType>::preOrder_xTreeDisplay(){
	//print the root of xtree
	cout << this->root() << ": " << endl;
	if (!this->yTree()->isEmpty())		// if left child not null, print it by using recursive
		this->yTree()->preOrder_yTreeDisplay();
	cout << endl;
	if (!this->left()->isEmpty())
		this->left()->preOrder_xTreeDisplay();

	if (!this->right()->isEmpty()){		// if right child not null, print it by using recursive
		this->right()->preOrder_xTreeDisplay();
	}
}
// --------------------------------------------------------------
//display yTree on preOrder traversal
template <class DataType>
void BinarySearchTree<DataType>::preOrder_yTreeDisplay(){
	//print the root of ytree and its ID
	cout << " " << this->root() << "(" << this->ID << ") ";
	if (!left()->isEmpty()){		// if left child of ytree not null, print it by using recursive
		left()->preOrder_yTreeDisplay();
	}
	if (!right()->isEmpty()){		// if right child of ytree not null, print it by using recursive
		right()->preOrder_yTreeDisplay();
	}

}
// --------------------------------------------------------------
//create a empty tree
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::makeSubtree()
{
	BinarySearchTree<DataType>* bst = new BinarySearchTree<DataType> ();
	bst->_subtree = true;
	return bst;
}
// --------------------------------------------------------------
//destructor
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
    ID = 0;
}
// --------------------------------------------------------------
//check if a tree is empty or not
template <class DataType>
bool BinarySearchTree<DataType>::isEmpty()
{
	if (_root == NULL)		//if root = null, return true else return false
		return true;
	else return false;

	return true;
}
// --------------------------------------------------------------
//get the height of tree
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
// setter bst to yTree
// --------------------------------------------------------------
template <class DataType>
bool BinarySearchTree<DataType>::subtree() { return _subtree; }
//return _subtree
// --------------------------------------------------------------
template <class DataType>
//set null for all content in tree
void BinarySearchTree<DataType>::makeEmpty ()
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
//copy the bst tree
template <class DataType>
void BinarySearchTree<DataType>::copyTree(BinarySearchTree<DataType>* bst)
{
	_root = bst->_root;
	_left = bst->_left;
	_right = bst->_right;
}
// --------------------------------------------------------------
//set null for root, left child and right child of tree
template <class DataType>
void BinarySearchTree<DataType>::_makeNull ()
{
	_root = NULL;
	_left = NULL;
	_right = NULL;
}
// --------------------------------------------------------------
//find the data in tree and return it as a new tree with root is data
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_find (const DataType& data)
{
	BinarySearchTree<DataType>* bst = this;
	while (true)
	{
		if (bst->isEmpty())		//if it is empty, return
			return bst;
		if (*(bst->_root) < data)	// if data > root, data is in the right child
		{
			bst = bst->_right;		//bst now is right child of bst
		}
		else if (*(bst->_root) > data)	// if data < root, data is in the left child
		{
            bst = bst->_left;		//bst now is right child of bst
		}
		else	//else the data is found at root of tree
		{
			return bst;
		}
	}
}
// --------------------------------------------------------------
template <class DataType>
void BinarySearchTree<DataType>::find (const DataType& x, const DataType& y)
{
	//create bst tree with the root is x
	BinarySearchTree<DataType>* bst = _find (x);
	try{
		//if bst empty throw exception
		if (bst->isEmpty()) throw BinarySearchTreeNotFound();
		if (bst->root() == x){	//if x is found
			//create bst2 is the ytree of bst at node y
			BinarySearchTree<DataType>* bst2 = bst->_yTree->_find(y);
			//if bst2 empty throw exception
			if (bst->isEmpty()) throw BinarySearchTreeNotFound();
			if (bst2->root() == y)	//if y is found
				//print out x-y coordinate and its ID
				cout<<"\nThe coordinates "<<bst->root()<< ", " << bst2->root()
				<< " is found in the tree with ID value " << bst2->ID  << endl;
		}

	}
	//catch exception and print out comment
	catch(BinarySearchTreeNotFound e)
	{
		cout<<"\nSorry!!! Coordinate is not found in the X tree";
		cout<<endl;
	}
	//catch exception when root of a tree is null and print comment
	catch(BinaryTreeEmptyTree e)
	{
		cout<<"\nSorry!!! Coordinate is not found in the X tree";
		cout<<endl;
	}
}
// --------------------------------------------------------------
//insert the node data to tree
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::_insert (const DataType& data)
{
	//create bst tree with the root is data
	BinarySearchTree<DataType>* bst = _find (data);
	//if bst empty
	if (bst->isEmpty())
	{
		bst->_root = new DataType (data);	//create the root = data
		bst->_left = makeSubtree ();		//create LC
		bst->_right = makeSubtree ();		//create RC
	}
	else	//if it not empty
	{
        delete bst->_root;	//delete the old root and create new root to avoid garbage
		bst->_root = new DataType (data);
	}
	return bst;	//return the tree
}
// --------------------------------------------------------------
//insert element at x-y node and its ID
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
//remove element at x-y coordinate
template <class DataType>
void BinarySearchTree<DataType>::remove(const DataType& x, const DataType& y){
	//create temp1 tree with root is x using _find
	BinarySearchTree<DataType>* temp1 = _find(x);
	if (temp1->isEmpty()){		//if it is empty, print out comment
		cout << "The element you are trying to remove is not in the tree";
		cout << endl;
	}
	else{	//else create temp2 is the yTree of temp1 at node y by using _find
		BinarySearchTree<DataType>* temp2 = temp1->_yTree->_find(y);
		if (temp2->isEmpty()){
			//if temp2 empty, print out comment
			cout << "The element you are trying to remove is not in the tree";
			cout << endl;
		}
		else{
			//else remove element at x-y coordinate
			temp2->_remove(y);
			if(temp1->_yTree->size() == 0)
				temp1->_remove(x);
		}
	}
}
// --------------------------------------------------------------
//search the element of yTree in range
template <class DataType>
void BinarySearchTree<DataType>::_rangeSearch (const DataType& lowY, const DataType& highY)
{
	if (isEmpty()) return;
	if (*_root >= lowY){	//search all element in left of tree
		_left->_rangeSearch(lowY, highY);	//by using recursive
		if (*_root <= highY)
			cout << " " << *_root << " ";	//print out the element in range
	}
	if (*_root <= highY)
		_right->_rangeSearch(lowY, highY);	//do the process agian by search all element in right of tree
}
// --------------------------------------------------------------
//search elements in range x-y coordinate
template <class DataType>
void BinarySearchTree<DataType>::rangeSearch(const DataType& low, const DataType& high, const DataType& lowY, const DataType& highY)
{
	//first search all element of xTree using same algorithm in _rangeSreach
	if (isEmpty()) return;
	if (*_root >= low)
	{
		_left->rangeSearch(low, high, lowY, highY);
		if (*_root <= high)
		{
			int x = *_root;			//x is the _root that in range
			cout << x << " :";		//print all xNode in range
			//create temp1 as the tree with root is x
			BinarySearchTree<DataType>* temp1 = _find(x);
			//then search all the yNode in range of temp1's ytree
			temp1->_yTree->_rangeSearch(lowY, highY);
			cout << endl;
		}
	}
	if (*_root <= high)
		_right->rangeSearch(low, high, lowY, highY);

}
// --------------------------------------------------------------
//balance the tree. inOrderArray is the array with element is node follow inOrder traversal
//l is first index of array and r is last index of array
template <class DataType>
BinarySearchTree<DataType>* BinarySearchTree<DataType>::GlobalRebalance(BinarySearchTree<DataType>** inOrderArray, int l, int r){
	int mid = 0;
	BinarySearchTree<DataType>* temp = new BinarySearchTree<DataType>();
	if(l <= r)
	{
		mid = ((l + r) / 2);
		temp = inOrderArray[mid];	//root of tree is middle element of inOrderArray
		temp->left((GlobalRebalance(inOrderArray, l, mid - 1)));	//using recursive to balance LC and set new LC for temp
		temp->right((GlobalRebalance(inOrderArray, mid + 1, r)));	//using recursive to balance RC and set new RC for temp
	}
	return temp;
}
// --------------------------------------------------------------
//method to fill the inOrderArray with tree start at node, and return the last index of array
template <class DataType>
int BinarySearchTree<DataType>::getInorderTraversal(BinarySearchTree<DataType>* node, BinarySearchTree<DataType>** inOrderArray, int index)
{
	//if node empty, throw exception
	try{
		if (node->isEmpty()) throw BinarySearchTreeNotFound();
	}
	catch(BinarySearchTreeNotFound e){
		 return index;
	}

	//if it is not empty
	if (!this->isEmpty()) {
		//go to the very left child of _root of tree
		if(node->left()->_root != NULL)
		{
			//using recursive to handle that
			index = node->left()->getInorderTraversal(node->left(), inOrderArray, index);
		}
		//add the node to array and increase index
		inOrderArray[index++] = node;
		//befor move to right child, the _root of tree is inserted to array
		//go to very right of the tree
		if(node->right()->_root != NULL)
		{
			//using recursive to handle that
			index = node->right()->getInorderTraversal(node->right(), inOrderArray, index);
		}
	}
	return index;
}
// --------------------------------------------------------------
//method used to balance ytree of x node
template <class DataType>
void BinarySearchTree<DataType>::yBalance(const DataType& x){
	//create bst temp1 with root is x by using _find
	BinarySearchTree<DataType>* temp1 = _find(x);
	//create bst temp2 is ytree of temp1
	BinarySearchTree<DataType>* temp2 = temp1->_yTree;
	int size = temp2->size();	//get the size of temp2
	//create inOrderArray with size is size if temp1' ytree
	BinarySearchTree<DataType>** inOrderArray = new BinarySearchTree<DataType>*[size];
	for (int i = 0; i < size; i++){
		inOrderArray[i] = NULL;		//set null for each element in array
	}
	//fill the array by invoke getInorderTraversal method with temp2 is the tree dealing with
	// and start at index 0
	getInorderTraversal(temp2, inOrderArray, 0);
	//after that set the new ytree of temp1 using setYTree and GlobalRebalance method
	temp1->setYTree(GlobalRebalance(inOrderArray, 0, size-1));


}
// --------------------------------------------------------------
//print the BST
template <class DataType>
void BinarySearchTree<DataType>::print(){
	cout << *this << endl;
}


#endif
