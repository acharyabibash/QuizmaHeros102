#pragma once
#include "Question.h"
#include "Question_utils.h"
#include <algorithm>
#include <random>
#include <chrono>


class Question_vector {
private:
	Question_utils q1;
	std::vector<Question> question_answer_vector;
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine rng;/*(seed);*/

public:
	Question_vector();/* {}*/
	void displayQuestions();
};
