/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include "BinarySearchTree.h"

int main()
{
//    BinarySearchTree<int> bst (100);
//
//    cout <<"Initially the tree has  "<< bst << endl;
//
//    bst._insert (20);
//    cout <<"After Insertion of 20:  "<< bst << endl;
//
//    bst._insert (10);
//    cout <<"After Insertion of 10:  "<< bst << endl;
//
//    bst._insert (200);
//    cout <<"After Insertion of 200:  "<< bst << endl;
//
//    bst._insert (25);
//    cout <<"After Insertion of 25:  "<< bst << endl;
//
//    cout << "Trying to find 30..." << endl;
//    try {
//            bst.find(30);
//    }
//    catch (BinarySearchTreeNotFound e) {
//        cout << "Element 30 not found!!" << endl;
//    }
//
//   // bst.remove(25);
//    cout<<"After removal of 25:"<<bst<<endl;
//
//    cout << "Trying to find 25..." << endl;
//    try {
//            bst.find(25);
//    }
//    catch (BinarySearchTreeNotFound e) {
//        cout << "Element 25 not found!!" << endl;
//    }
//
//    bst.remove(100);
//    cout<<"After removal of 100:"<<bst<<endl;
//
//    bst.remove(20);
//    cout<<"After removal of 20:"<<bst<<endl;
//
//    bst.remove(10);
//    cout<<"After removal of 10:"<<bst<<endl;


    char letter;
    int xCor;
    int yCor;
    int id;
    int low, high, lowY, highY;
    int size = 100; //number of line in input file

   BinarySearchTree<int>* newBst = new BinarySearchTree<int>();

   for(int i = 0; i < size; i++){
	   if (i == size - 1)
		   size++;	//expand size to read new line

	   cin >> letter;
	   if (letter == 'I'){
		   cin >> xCor >> yCor >> id;
		   (*newBst).insert(xCor, yCor, id);
		   cout << xCor << " " << yCor << " " << id << " " << endl;

	   }
	   if (letter == 'R'){
		   cout << "Remove: ";
		   cin >> low >> high;
		   cout << low << " " << high << endl;

	   }
	   if (letter == 'S'){
		   cout << "Range search" << endl;
		   cin >> low >> high >> lowY >> highY;
		   cout << low << " " << high;
		   cout << lowY << " " << highY << endl;

	   }
	   if (letter == 'Y'){
		   cout << "Y tree balance" << endl;
		   cin >> yCor;
		   cout << yCor << endl;

	   }
	   if (letter == 'P'){
		   (*newBst).print();
	   }

    }

   	delete newBst;
    return 0;
}
