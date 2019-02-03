#pragma once
#include <string>

class Word {

private:

	std::string word;
	Word* next;

public:

	Word(std::string);
	~Word();

	void setNext(Word*);
	Word* getNext();
	std::string getWord();

};