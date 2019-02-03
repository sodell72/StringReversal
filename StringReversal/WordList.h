#pragma once
#include "Word.h"
#include <iostream>


class WordList {

private:

	Word* head;
	int size;

public:

	WordList();

	// this copy constructor has an O(n^2), n being the number of Word objects in the WordList to be copied.
	// the second order of n comes from the add function that is called in the copy constructor for each node
	// that is looped through.  The add function loops through all the nodes that have already been added to the
	// copied list.  I could reduce the Big-O of this by not using the add functionality and manually setting the
	// next node.
	WordList(const WordList &list);

	~WordList();
	void add(Word*);
	Word* getHead();
	int getSize();

	friend std::ostream& operator<<(std::ostream& out, WordList& const list);

	// this is the recursive solution to print the list in reverse.
	// this has an O(n) for time because it calls the reversePrintR function ~n times
	// this has a O(n) for space as well because it recurses through the list till the end once and it has to 
	// store all the values until the end of the recurse finishes
	void reversePrintR(Word*);

	// this is O(n), it goes through each node from the head until it findes the index it is looking for
	Word* get(int);

	// this is O(n^2) because it calls the "get" function n times and it's big O is O(n).
	// space complexity is O(1)
	void reversePrintI();

};