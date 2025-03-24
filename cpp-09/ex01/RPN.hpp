#include <iostream>
#include <stack>
#include <stdexcept>
#include <limits>

class RPN
{
	private:
		RPN();
		~RPN();
	public:
		static	double calculate(const std::string &arg);
};
