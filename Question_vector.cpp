#include "Question_vector.h"

Question_vector::Question_vector()
{
	rng.seed(this->seed);
	question_answer_vector = q1.loadQuestion();
	std::shuffle(question_answer_vector.begin(), question_answer_vector.end(), rng);
}

void Question_vector::displayQuestions()
{
	for (decltype(question_answer_vector.size()) i = 0; i < question_answer_vector.size(); i++) {
		std::cout << question_answer_vector.at(i) << std::endl;
	}
}
