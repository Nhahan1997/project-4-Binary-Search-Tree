/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> bst (100);

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

//    cout << "Trying to find 30..." << endl;
//    try {
//            bst._find(30);
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
//            bst._find(25);
//    }
//    catch (BinarySearchTreeNotFound e) {
//        cout << "Element 25 not found!!" << endl;
//    }
 //   bst._rangeSearch(0, 300);

//    bst._remove(100);
//    cout<<"After removal of 100:"<<bst<<endl;
//
//    bst._remove(20);
//    cout<<"After removal of 20:"<<bst<<endl;
//
//    bst._remove(10);
//    cout<<"After removal of 10:"<<bst<<endl;


    char letter;
    int xCor;
    int yCor;
    int id;
    int low, high, lowY, highY;
    int size = 100; //number of line in input file

   BinarySearchTree<int>* newBst = new BinarySearchTree<int>();

   //use for loop to read the file

   for(int i = 0; i < size; i++){
	   if (i == size - 1)
		   size++;	//expand size to read new line

	   cin >> letter;	//read the letter
	   //do insert
	   if (letter == 'I'){
		   cin >> xCor >> yCor >> id;
		   (*newBst).insert(xCor, yCor, id);
		   cout << xCor << " " << yCor << " " << id << " " << endl;

	   }
	   // do remove
	   if (letter == 'R'){
		   cout << "Remove: ";
		   cin >> xCor >> yCor;
		   cout << xCor << " " << yCor << endl;
		   (*newBst).remove(xCor, yCor);

	   }
	   // do range search
	   if (letter == 'S'){
		   cout << "Range search" << endl;
		   cin >> low >> high >> lowY >> highY;
		   cout << low << " " << high << " ";
		   cout << lowY << " " << highY << endl;
		   (*newBst).rangeSearch(low, high, lowY, highY);
	   }
	   //do find
	   if (letter == 'F'){
		   cin >> xCor >> yCor;
		   cout << "Find: " << xCor << " " << yCor << endl;
		   (*newBst).find(xCor, yCor);
	   }
	   //do balance the yTree
	   if (letter == 'Y'){
		   cout << "Y tree balance" << endl;
		   cin >> xCor;
		   cout << xCor << endl;
		   (*newBst).yBalance(xCor);

	   }
	   //print
	   if (letter == 'P'){
		   cout << "Print" << endl;
		   (*newBst).print();
	   }

    }

   	delete newBst;
    return 0;
}
