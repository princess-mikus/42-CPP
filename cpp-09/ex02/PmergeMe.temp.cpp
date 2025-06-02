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
	deckdeck	newDeck;

	while (!deck.empty()) {
		deckdeck::iterator	second = deck.begin();
		deckdeck::iterator	first = second++;
		std::deque<int>	temp;

		if (first->back() < second->back()) {
			temp.insert(temp.end(), first->begin(), first->end());
			temp.insert(temp.end(), second->begin(), second->end());
		}
		else {
			temp.insert(temp.end(), second->begin(), second->end());
			temp.insert(temp.end(), first->begin(), first->end());
		}
		deck.pop_front();
		deck.pop_front();
		newDeck.push_back(temp);
	}
	
	return (newDeck);
}

deckdeck	dequePmergeMe::halve(deckdeck deck) {
	deckdeck	newDeck;

	while (!deck.empty()) {
		std::deque<int>	firstHalf;
		std::deque<int>	secondHalf;

		size_t	halfDeck = 2;
		if (deck.begin()->size() > 1)
		halfDeck = deck.begin()->size() / 2;
		
		for (size_t i = 0; i < halfDeck; i++)
		{
			firstHalf.push_back(deck.begin()->front());
			deck.begin()->pop_front();
		}
		while (!deck.begin()->empty()) {
			secondHalf.push_back(deck.begin()->front());
			deck.begin()->pop_front();
		}
		newDeck.push_back(firstHalf);
		newDeck.push_back(secondHalf);
		deck.pop_front();
	}
	print_deck(newDeck);
	return (newDeck);
}

void	dequePmergeMe::constructMainPend(deckdeck deck, deckdeck &main, deckdeck &pend, 
									iteratordeckdeck &pairs, std::deque<int> rest) {
	for (deckdeck::iterator it; i < count; i++)
	{
		/* code */
	}

}

deckdeck	dequePmergeMe::mergeInsert(deckdeck deck) {
	std::deque<int> rest;

	if (deck.size() % 2) {
		rest = deck.back();
		deck.pop_back();
	}

	deck = dequePmergeMe::merge(deck);

	if (deck.size() > 1)
		deck = mergeInsert(deck);
	
	print_deck(deck);
	std::cout << std::endl << std::endl;
	deck = dequePmergeMe::halve(deck);
	
	if (deck.size() < 2)
		return (deck);	

	deckdeck			main;
	deckdeck			pend;
	iteratordeckdeck	pairs;
	
	dequePmergeMe::constructMainPend(deck, main, pend, pairs, rest);
	//dequePmergeMe::insert(main, pend);

	return (main);

}
