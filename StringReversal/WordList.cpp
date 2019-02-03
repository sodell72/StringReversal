#include "WordList.h"




WordList::WordList() {
	this->head = nullptr;
	this->size = 0;
}


WordList::WordList(const WordList& list) {
	if (list.head == nullptr) {
		this->head = nullptr;
		return;
	}
	Word* currentWord = list.head;
	while (currentWord != nullptr) {
		std::string word = currentWord->getWord();
		Word* newWord = new Word(word);
		this->add(newWord);
		if (currentWord == list.head) {
			this->head = newWord;
		}
		currentWord = currentWord->getNext();
	}
}



WordList::~WordList() {

}

void WordList::add(Word* word) {
	if (this->head == nullptr) {
		this->head = word;
		this->size = 1;
		return;
	}
	Word* currentWord = this->head;
	while (currentWord->getNext() != nullptr) {
		currentWord = currentWord->getNext();
	}
	currentWord->setNext(word);
	this->size++;
	return;
}

Word* WordList::getHead() {
	return this->head;
}

int WordList::getSize() {
	return this->size;
}

std::ostream& operator<<(std::ostream& out, WordList& const list) {
	if (!list.getHead()) {
		out << "this list is empty";
		return out;
	}

	Word* currentWord = list.getHead();
	while (currentWord != nullptr) {
		out << currentWord->getWord();
		if (currentWord->getNext() != nullptr) {
			out << std::endl;
		}
		currentWord = currentWord->getNext();
	}
	return out;
}


void WordList::reversePrintR(Word* head) {
	if (head->getNext() != nullptr) {
		reversePrintR(head->getNext());
	}
	std::cout << head->getWord() << std::endl;
	return;
}

Word* WordList::get(int index) {
	Word* current = this->getHead();
	int count = 0;
	while (count < index) {
		current = current->getNext();
		count++;
	}
	return current;
}

void WordList::reversePrintI() {
	if (this->getSize() == 0) {
		std::cout << "reversing an empty list is too easy!!" << std::endl;
	}
	int size = this->getSize();
	for (int i = size - 1; i >= 0; i--) {
		std::cout << this->get(i)->getWord() << std::endl;
	}
	return;
}