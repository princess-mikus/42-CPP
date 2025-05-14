#include "PmergeMe.hpp"

extern int comparisons;

static int nextJacobsthal(int n_jacobsthal)
{
	return(((pow(2, n_jacobsthal)) - (pow(-1, n_jacobsthal))) / 3);
}

std::deque<int>	dequePmergeMe::splice(std::deque<int> &deck, std::deque<int>::iterator first, std::deque<int>::iterator last) {

	std::deque<int>	newDeck;

	for (; first != last; )
	{
		newDeck.push_back(*first);
		std::deque<int>::iterator temp = first++;
		deck.erase(temp);
	}
	
	return (newDeck);
}

bool dequePmergeMe::comp(const int first, const std::deque<int> second)
{
	comparisons++;
	return(first < second.back());
}

void	dequePmergeMe::init_deck(char *argv[], deckdeck &sequence) {
	std::deque<int>	start;

	for (size_t i = 1; argv[i]; i++)
		start.push_back(atoi(argv[i]));
	
	for (std::deque<int>::iterator it = start.begin(); it != start.end(); it++)
	{
		std::deque<int> temp;

		temp.push_back(*it);
		sequence.push_back(temp);
	}
}

deckdeck	dequePmergeMe::merge(deckdeck deck) {
	deckdeck newDeck;

	for (deckdeck::iterator it = deck.begin(); it != deck.end(); it++)
	{
		deckdeck::iterator first = it++;
		deckdeck::iterator second = it;
		std::deque<int> temp;
		comparisons++;
		if (first->back() < second->back()) {
			temp = *first;
			temp = dequePmergeMe::splice(*second, second->begin(), second->end());
		}
		else {
			temp = *second;
			temp = dequePmergeMe::splice(*second, first->begin(), first->end());
		}
		newDeck.push_back(temp);
	}

	return (newDeck);
}

deckdeck	dequePmergeMe::halve(deckdeck deck) {
	deckdeck newDeck;

	for (deckdeck::iterator it = deck.begin(); it != deck.end(); it++)
	{
		std::deque<int> temp;
		std::deque<int>::iterator it2 = it->begin();

		std::advance(it2, it->size() / 2);
		temp = dequePmergeMe::splice(*it, it2, it->end());
		newDeck.push_back(*it);
		newDeck.push_back(temp);
	}
	return (newDeck);
}

void	dequePmergeMe::constructMainPend(deckdeck lst, deckdeck &main, deckdeck &pend, iteratordeckdeck &pairs, std::deque<int> rest) {
	size_t i = 0;
	for (deckdeck::iterator it = lst.begin(); it != lst.end(); it++)
	{
		if (it != lst.begin() && !(std::distance(lst.begin(), it) % 2)) {
			pend.push_back(*it);
		}
		else {
			main.push_back(*it);
			if (i++ > 1)
				pairs.push_back(--main.end());
		}
	}

	if (rest.size())
	{
		pend.push_back(rest);
		pairs.push_back(main.end());
	}
}

deckdeck	dequePmergeMe::insert(deckdeck &main, deckdeck pend/*, iteratordeckdeck pairs*/) {
	unsigned int jacobsthalPos = 3 - 1;
	unsigned int jacobsthalPrevPos = 1; 
	size_t jacobsthalN = 3;

	//iteratordeckdeck::iterator pairIt = pairs.begin();
	for (deckdeck::iterator pendIt = pend.begin(); !pend.empty();)
	{
		if (jacobsthalPos - jacobsthalPrevPos > pend.size())
		{
			std::advance(pendIt, pend.size());
			//std::advance(pairIt, pend.size());
		}
		else
		{
			std::advance(pendIt, jacobsthalPos - jacobsthalPrevPos);
			//std::advance(pairIt, jacobsthalPos - jacobsthalPrevPos);
		}
		for (; pendIt != --pend.begin();)
		{
			main.insert(std::upper_bound(main.begin(), main.end(), pendIt->back(), comp), *pendIt);
			deckdeck::iterator tempPendIt = pendIt--;
			pend.erase(tempPendIt);
			//iteratordeckdeck::iterator tempPairIt = pairIt--;
			//pairs.erase(tempPairIt);
		}
		jacobsthalPrevPos = jacobsthalPos;
		jacobsthalPos = nextJacobsthal(++jacobsthalN) - 1;
	}

	return (main);
}

deckdeck	dequePmergeMe::mergeInsert(deckdeck lst) {
	std::deque<int> rest;

	if (lst.size() % 2) {
		rest = lst.back();
		lst.pop_back();
	}

	lst = dequePmergeMe::merge(lst);

	if (lst.size() > 1)
		lst = mergeInsert(lst);

	lst = dequePmergeMe::halve(lst);

	if (lst.size() < 2)
		return (lst);

	deckdeck			main;
	deckdeck			pend;
	iteratordeckdeck	pairs;
	
	dequePmergeMe::constructMainPend(lst, main, pend, pairs, rest);
	dequePmergeMe::insert(main, pend);

	return (main);
}
