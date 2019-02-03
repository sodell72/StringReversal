#include "Word.h"





Word::Word(std::string word) {
	this->word = word;
	this->next = nullptr;
}

Word::~Word() {

}

void Word::setNext(Word* word) {
	this->next = word;
}

Word* Word::getNext() {
	return this->next;
}

std::string Word::getWord() {
	return this->word;
}