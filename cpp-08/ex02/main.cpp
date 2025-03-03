#include "MutantStack.tpp"

int main(void) {
	MutantStack<> ttmp;
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