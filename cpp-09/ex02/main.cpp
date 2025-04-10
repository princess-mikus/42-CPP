#include "PmergeMe.hpp"
#include <stdlib.h>

void print_list(std::list<std::list<int> > lst) {
	const char *colors[] {
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
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
	std::cout << std::endl;
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

void	mergeInsert(std::list<std::list<int> > &lst) {
	std::list<std::list<int> > newList;
	std::list<int> rest;

	if (lst.size() % 2) {
		rest = lst.back();
		lst.pop_back();
	}

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
	print_list(newList);
	
	if (lst.size() > 1)
		mergeInsert(newList);
}

int	main(int argc, char *argv[]) {
	if (argc < 2)
		return (0);
	std::list<std::list<int> > sequence;
	init_list(argv, sequence);
	mergeInsert(sequence);
}