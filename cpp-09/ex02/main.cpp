#include "PmergeMe.hpp"


int nextJacobsthal(int n_jacobsthal)
{
    return(((pow(2, n_jacobsthal)) - (pow(-1, n_jacobsthal))) / 3);
}

void print_list(std::list<std::list<int> > lst) {
	const char *colors[] {
		RED,
		GREEN,
		BLUE,
		MAGENTA,
		YELLOW,
		CYAN,
		WHITE
	};

	size_t i = 0;
	for (std::list<std::list<int> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (i == 6)
			i = 0;
		for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << colors[i] << *it2 << " ";
		i++;
	}
	std::cout << RESET << std::endl;
}

void init_list(char *argv[], std::list<std::list<int> > &sequence) {
	std::list<int>	start;

	for (size_t i = 1; argv[i]; i++)
		start.push_back(atoi(argv[i]));
	
	for (std::list<int>::iterator it = start.begin(); it != start.end(); it++)
	{
		std::list<int> temp;

		temp.push_back(*it);
		sequence.push_back(temp);
	}
	print_list(sequence);
}


std::list<std::list<int> >	mergeInsert(std::list<std::list<int> > lst) {
	std::list<std::list<int> > newList;
	std::list<int> rest;

	/* IF LIST IS NOT EVEN */
	
	if (lst.size() % 2) {
		rest = lst.back();
		lst.pop_back();
	}
	
	/* MERGE */

	for (std::list<std::list<int> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		std::list<std::list<int> >::iterator first = it++;
		std::list<std::list<int> >::iterator second = it;
		std::list<int> temp;
		if (first->back() < second->back()) {
			temp = *first;
			temp.splice(temp.end(), *second, second->begin(), second->end());
		}
		else {
			temp = *second;
			temp.splice(temp.end(), *first, first->begin(), first->end());
		}
		newList.push_back(temp);
	}
	//print_list(newList);
	
	/* CHECK RECURSIVE CALL */

	print_list(newList);

	if (newList.size() > 1)
		newList = mergeInsert(newList);

	/* DIVIDE IN HALF */
	
	std::list<std::list<int> > newList2;

	for (std::list<std::list<int> >::iterator it = newList.begin(); it != newList.end(); it++)
	{
		std::list<int> temp;
		std::list<int>::iterator it2 = it->begin();

		std::advance(it2, it->size() / 2);
		temp.splice(temp.end(), *it, it2, it->end());
		newList2.push_back(*it);
		newList2.push_back(temp);
	}


	if (newList2.size() <= 2)
		return (newList2);

	/* INSERT */

	std::list<std::list<int> > pend;
	std::list<std::list<int> > main;

	for (std::list<std::list<int> >::iterator it = newList2.begin(); it != newList2.end(); it++)
	{
		if (it != newList2.begin() && std::distance(newList2.begin(), it) % 2) {
			pend.push_back(*it);
		}
		else {
			main.push_back(*it);
		}
	}

	
	if (rest.size())
		pend.push_back(rest);

	std::cout << "Pend == ";
	print_list(pend);
	std::cout << "Main == ";
	print_list(main);
	std::cout << std::endl;

	int jPos = 3 - 1;
	int jPrevPos = 1; 

	for (size_t i = 3; pend.size();)
	{
		std::list<std::list<int> >::iterator itPend = pend.begin();
		std::advance(itPend, jPos - jPrevPos);
	}
	
	std::cout << "Main == ";
	print_list(main);
	std::cout << std::endl;

	return (main);
}

int	main(int argc, char *argv[]) {
	if (argc < 2)
		return (0);
	std::list<std::list<int> > sequence;
	init_list(argv, sequence);
	mergeInsert(sequence);
}