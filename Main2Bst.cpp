/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include "BinarySearchTree.h"

//template <class DT>
//class xNode;

//template<class DT>
//class xNode
//{
//	protected:
//		int xCordinate;
//		int id;
//		BinarySearchTree<DT>* bst;
//	public:
//		xNode();
//		xNode(const DT& x, const DT& _id);
//		virtual ~xNode();
//		virtual void xInsert(const DT& data);
//		virtual void xRemove(const DT& data);
//		virtual DT xFind (const DT& q);
//		virtual void xRangeSearch(const DT& low, const DT& high);
//		virtual BinarySearchTree<DT>* balanceXTree(const DT& data);
//		virtual void print();
//
//};
//
////default constructor
//template <class DT>
//xNode<DT>::xNode(){
//	xCordinate = 0;
//	id = 0;
//	bst = new BinarySearchTree<DT>();
//}
//
////non-default constructor
//template <class DT>
//xNode<DT>::xNode(const DT& x, const DT& _id){
//	xCordinate = x;
//	id = _id;
//	bst = new BinarySearchTree<DT>();
//}
//
//template <class DT>
//xNode<DT>::~xNode(){
//	xCordinate = 0;
//	id = 0;
//}
//
//template <class DT>
//void xNode<DT>::xInsert(const DT& data){
//	bst->insert(data);
//}
//
//template <class DT>
//void xNode<DT>::xRemove(const DT& data){
//	bst->remove(data);
//}
//
//template <class DT>
//DT xNode<DT>::xFind(const DT& q){
//	bst->find(q);
//}
//
//template <class DT>
//void xNode<DT>::xRangeSearch(const DT& low, const DT& high){
//
//}
//
//template <class DT>
//void xNode<DT>::print(){
//
//}
//
////yNOde class
//template<class DT>
//class yNode
//{
//	protected:
//		int yCordinate;
//		int id;
//		BinarySearchTree<DT>* bst;
//	public:
//		yNode();
//		yNode(const DT& y, const DT& _id);
//		virtual ~yNode();
//		virtual void yInsert(const DT& data);
//		virtual void yRemove(const DT& data);
//		virtual DT yFind (const DT& q);
//		virtual void yRangeSearch(const DT& low, const DT& high);
//		virtual BinarySearchTree<DT>* balanceYTree(const DT& data);
//		virtual void print();
//
//};
//
////default constructor
//template <class DT>
//yNode<DT>::yNode(){
//	yCordinate = 0;
//	id = 0;
//	bst = new BinarySearchTree<DT>();
//}
//
////non-default constructor
//template <class DT>
//yNode<DT>::yNode(const DT& y, const DT& _id){
//	yCordinate = y;
//	id = _id;
//	bst = new BinarySearchTree<DT>();
//}
//
//template <class DT>
//yNode<DT>::~yNode(){
//	yCordinate = 0;
//	id = 0;
//}
//
//template <class DT>
//void yNode<DT>::yInsert(const DT& data){
//	bst->insert(data);
//}
//
//template <class DT>
//void yNode<DT>::yRemove(const DT& data){
//	bst->remove(data);
//}
//
//template <class DT>
//DT yNode<DT>::yFind(const DT& q){
//	bst->find(q);
//}
//
//template <class DT>
//void yNode<DT>::yRangeSearch(const DT& low, const DT& high){
//
//}
//
//template <class DT>
//void yNode<DT>::print(){
//
//}

int main()
{
    BinarySearchTree<int> bst (100);

    cout <<"Initially the tree has  "<< bst << endl;

    bst.insert (20);
    cout <<"After Insertion of 20:  "<< bst << endl;

    bst.insert (10);
    cout <<"After Insertion of 10:  "<< bst << endl;

    bst.insert (200);
    cout <<"After Insertion of 200:  "<< bst << endl;

    bst.insert (25);
    cout <<"After Insertion of 25:  "<< bst << endl;

    cout << "Trying to find 30..." << endl;
    try {
            bst.find(30);
    }
    catch (BinarySearchTreeNotFound e) {
        cout << "Element 30 not found!!" << endl;
    }

    bst.remove(25);
    cout<<"After removal of 25:"<<bst<<endl;

    cout << "Trying to find 25..." << endl;
    try {
            bst.find(25);
    }
    catch (BinarySearchTreeNotFound e) {
        cout << "Element 25 not found!!" << endl;
    }

    bst.remove(100);
    cout<<"After removal of 100:"<<bst<<endl;

    bst.remove(20);
    cout<<"After removal of 20:"<<bst<<endl;

    bst.remove(10);
    cout<<"After removal of 10:"<<bst<<endl;

//    bst.insert(5);
//    try {
//                bst.find(5);
//        }
//        catch (BinarySearchTreeNotFound e) {
//            cout << "Element 5 not found!!" << endl;
//        }


    int letter;
    int xCor;
    int yCor;
    int id;
    int size = 100; //number of line in input file

   BinarySearchTree<int>* newBst();
//    xNode<int>* xVal;
//    yNode<int>* yVal;
   for(int i = 0; i < size; i++){
	   if (i == size - 1)
		   size++;	//expand size to read new line

	   cin >> letter >> xCor >> yCor >> id;
	   if (letter == 'I'){

	   }

    }


    return 0;
}
