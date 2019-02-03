#include <iostream>
#include "Word.h"
#include "WordList.h"


using namespace std;


int main(int argc, char* argv[]) {

	WordList myList;

	Word fifth("fifth");
	Word sixth = Word("sixth");
	Word* seventh = new Word("seventh");

	// tests add method
	myList.add(new Word("first"));
	myList.add(new Word("second"));
	myList.add(new Word("third"));
	myList.add(new Word("fourth"));
	myList.add(&fifth);
	myList.add(&sixth);
	myList.add(seventh);
	myList.add(new Word("eigth"));
	//myList.add(&Word("eighth"));
	myList.add(new Word("ninth"));
	myList.add(new Word("tenth"));


	// tests linked structure with at least 10 nodes & tests operator overload <<
	cout << "this is myList" << endl << myList << endl << endl;

	// tests copy constructor
	WordList copiedList(myList);
	cout << "this is copiedList" << endl << copiedList << endl << endl;

	// proves address differences of copied object
	cout << "the address of myList is: " << &myList << endl;
	cout << "the address of copiedList is: " << &copiedList << endl << endl;

	// shows size copied correctly
	cout << "Size of myList & size of copiedList: " << myList.getSize() << " & " << copiedList.getSize() << endl << endl;

	// shows modifying original list does not modify the copied list
	myList.add(new Word("last"));
	copiedList.add(new Word("added Word to copy"));
	cout << "this is copiedList after additions" << endl << copiedList << endl << endl;
	cout << "this is myList after additions" << endl << myList << endl << endl;

	WordList emptyList;
	WordList copiedEmptyList(emptyList);
	cout << emptyList << endl;
	cout << copiedEmptyList << endl;
	// proves address differences of copied object
	cout << "the address of emptyList is: " << &myList << endl;
	cout << "the address of copiedEmptyList is: " << &copiedList << endl << endl;

	// demonstrates recursive solution, could create helper function to eliminate the need for the "head" 
	// to be passed in since the head is in the list, the helper could call the "reversePrintR" and have 
	// a signature of similar to void reverse()
	cout << "Here is the reversed list using the recursive method: " << endl;
	myList.reversePrintR(myList.getHead());
	cout << endl;
	cout << "This shows that the recursive method did not modify the original list: " << endl;
	cout << myList << endl << endl;

	cout << "this tests the get function and will return the 5th index which should be the 6th word: " <<
		myList.get(5)->getWord() << endl;
	cout << "tests get for first and last indexes: " << myList.get(0)->getWord() << ", " <<
		myList.get(10)->getWord() << endl << endl;

	// demonstrates the iterative solution
	myList.reversePrintI();
	cout << endl;
	// shows can handle empty list
	emptyList.reversePrintI();


	cin.get();
}
