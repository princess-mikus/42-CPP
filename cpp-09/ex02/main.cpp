#include "PmergeMe.hpp"

extern int comparisons;

static void print_list(listlist lst) {
	#if __cplusplus > 199711L
		const char *colors[] {
			RED,
			GREEN,
			BLUE,
			MAGENTA,
			YELLOW,
			CYAN,
		};
	#else
		const char *colors[6];
		colors[0] = RED;
		colors[1] = GREEN;
		colors[2] = BLUE;
		colors[3] = MAGENTA;
		colors[4] = YELLOW;
		colors[5] = CYAN;
	#endif

	size_t i = 0;
	for (listlist::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (i == 6)
			i = 0;
		for (std::list<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << colors[i] << *it2 << " ";
		i++;
	}
	std::cout << RESET << std::endl;
}


static int maxComp(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

static void isSorted(listlist sequence, unsigned int argc) {
	if (argc - 1 != sequence.size())
	{
		std::cout << "You lost numbers along the way!" << std::endl;
		return;
	}
		for (listlist::iterator it = sequence.begin(); it != --sequence.end();)
	{
		listlist::iterator previous = it++;
		if (previous->back() > it->back()) {
			std::cout << previous->back() << " " << it->back() << " Not sorted!" << std::endl;
		}
	}
	std::cout << "Sorted!" << std::endl;
	
}

int	main(int argc, char *argv[]) {
	if (argc < 2)
		return (0);
	listlist sequence;
	listPmergeMe::init_list(argv, sequence);
	std::cout << "Original Sequence:" << std::endl;
	print_list(sequence);
	std::cout << std::endl;

	sequence = listPmergeMe::mergeInsert(sequence);
	std::cout << "----- FOR LISTS -----" << std::endl;
	isSorted(sequence, argc);
	print_list(sequence);
	std::cout << "Comparisons: " << comparisons << ", max: " << maxComp(sequence.size()) << std::endl;
	std::cout << std::endl;

}