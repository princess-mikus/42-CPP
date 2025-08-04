#include "MutantStack.hpp"
#include <list>

#if MAIN == 42
int main()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.erase(mstack.end() - 1);
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
#else
int main(void) {
	MutantStack<int> tmp;

	tmp.push(1);
	tmp.push(2);
	tmp.push(3);

	MutantStack<int>::iterator it;
	for (it = tmp.begin(); it != tmp.end(); ++it) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	MutantStack<int>::reverse_iterator rit;
	for (rit = tmp.rbegin(); rit != tmp.rend(); ++rit) {
		std::cout << *rit << " ";
	}

	std::cout << std::endl;

	const MutantStack<int> constStack = tmp;

	MutantStack<int>::const_iterator cit;
	for (cit = constStack.begin(); cit != constStack.end(); ++cit) {
		std::cout << *cit << " ";
	}

	std::cout << std::endl;

	const MutantStack<int> rconstStack(tmp);

	MutantStack<int>::const_reverse_iterator rcit;
	for (rcit = rconstStack.rbegin(); rcit != rconstStack.rend(); ++rcit)
		std::cout << *rcit << " ";

	std::cout << std::endl;

	return 0;
}
#endif