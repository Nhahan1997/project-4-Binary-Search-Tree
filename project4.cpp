/*
 *    Data Structures Featuring C++  (c) 2021 Sridhar Radhakrishnan
 */

#include "BinarySearchTree.h"

int main()
{
    char letter;
    int xCor;	//x coordinate
    int yCor;	//y coordinate
    int id;		//id
    int low, high, lowY, highY;		//the x range and y range

   BinarySearchTree<int>* newBst = new BinarySearchTree<int>();

   //use for loop to read the file
   while(!cin.eof()){
	   cin.get(letter);	//read the letter
	   //do insert
	   if (letter == 'I'){
		   cin >> xCor >> yCor >> id;
		   (*newBst).insert(xCor, yCor, id);
		   cout << xCor << " " << yCor << " " << id << endl;

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
		   cout << "Range search " << endl;
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
