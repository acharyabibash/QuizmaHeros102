#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define SIZE_OF_ANS 4

class Question {
private:
	std::string quest;
	std::string ans[SIZE_OF_ANS];

public:
	Question() {}
	Question(std::string, std::string answer[SIZE_OF_ANS]);
	void setValue(std::string, std::string answer[SIZE_OF_ANS]);
	friend std::ostream &operator<<(std::ostream &, const Question &);
};