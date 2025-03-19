#include <iostream>
#include <stack>
#include <stdexcept>

class RPN
{
	private:
		RPN();
		~RPN();
	public:
		static	double calculate(std::string arg);
		static	bool istoken(char c);
};
