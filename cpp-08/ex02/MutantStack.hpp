#include <iostream>
#include <stack>

template <typename T, typename C = std::deque<T>>
class MutantStack: public std::stack
{
private:

public:
	MutantStack();
	~MutantStack();
};
	
