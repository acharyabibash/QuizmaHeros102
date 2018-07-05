#pragma once
#include "Question.h"

#define SIZE_OF_QA_ARRAY ((std::string::size_type)(sizeof(qa_array) / sizeof(qa_array[0])))

class Question_utils {
private:
	std::ifstream question_file;
	std::string line;
	char delimiter = ':';
	std::string qa_array[5];
	std::string *qa_pointer = qa_array;
	std::vector<Question> qa_vector;

public:
	Question_utils() {}
	std::vector<Question> loadQuestion();
};

