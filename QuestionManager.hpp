#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define SIZE_OF_ANS 4

namespace Quizma {

	class QuestionManager
	{

	public:

		std::string quest;
		std::string ans[SIZE_OF_ANS];

	public:
		QuestionManager() {}
		~QuestionManager() { }

		QuestionManager(std::string, std::string answer[SIZE_OF_ANS]);
		void setValue(std::string, std::string answer[SIZE_OF_ANS]);
		friend std::ostream &operator<<(std::ostream &, const QuestionManager &);
	};

}