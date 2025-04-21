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

bool _comp(const int first, const std::list<int> second)
{
	comparisons++;
	return(first < second.back());
}

int maxComp(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

void isSorted(std::list<std::list<int> > sequence, unsigned int argc) {
	if (argc - 1 != sequence.size())
	{
		std::cout << "You lost numbers along the way!" << std::endl;
		return;
	}
		for (std::list<std::list<int> >::iterator it = sequence.begin(); it != --sequence.end();)
	{
		std::list<std::list<int> >::iterator previous = it++;
		if (previous->back() > it->back()) {
			std::cout << previous->back() << " " << it->back() << " Not sorted!" << std::endl;
		}
	}
	std::cout << "Sorted!" << std::endl;
	
}

int	main(int argc, char *argv[]) {
	if (argc < 2)
		return (0);
	std::list<std::list<int> > sequence;
	init_list(argv, sequence);
	sequence = mergeInsert(sequence);
	isSorted(sequence, argc);
	print_list(sequence);
	std::cout << "Comparisons: " << comparisons << " vs " << maxComp(sequence.size()) << std::endl;
}