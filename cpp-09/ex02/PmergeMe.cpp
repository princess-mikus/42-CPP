#include "PmergeMe.hpp"

std::list<std::list<int> >	PmergeMe::mergeInsert(std::list<std::list<int> > lst) {
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
		comparisons++;
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

	if (!rest.empty())
		std::cout << "I have rest " << rest.front() << " " << rest.back() << std::endl;
	
	std::cout << "AFTER MERGE == ";
	
	/* CHECK RECURSIVE CALL */
	
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

	if (newList2.size() < 2)
		return (newList2);

	/* INSERT */

	std::list<std::list<int> > pend;
	std::list<std::list<int> > main;
	std::list<std::list<std::list <int> >::iterator > pairs;
	
	size_t i = 0;
	for (std::list<std::list<int> >::iterator it = newList2.begin(); it != newList2.end(); it++)
	{
		if (it != newList2.begin() && !(std::distance(newList2.begin(), it) % 2)) {
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

	unsigned int jPos = 3 - 1;
	unsigned int jPrevPos = 1; 
	size_t jN = 3;

	std::list<std::list<std::list <int> >::iterator >::iterator pairIt = pairs.begin();
	for (std::list<std::list<int> >::iterator pendIt = pend.begin(); !pend.empty();)
	{
		if (jPos - jPrevPos > pend.size())
		{
			std::advance(pendIt, pend.size());
			std::advance(pairIt, pend.size());
		}
		else
		{
			std::advance(pendIt, jPos - jPrevPos);
			std::advance(pairIt, jPos - jPrevPos);
		}
		for (; pendIt != --pend.begin();)
		{
			std::list<std::list<int> >::iterator temp = std::upper_bound(main.begin(), *pairIt, pendIt->back(), _comp);
			main.insert(temp, *pendIt);
			temp = pendIt--;
			pend.erase(temp);
			std::list<std::list<std::list <int> >::iterator >::iterator temp2 = pairIt--;
			pairs.erase(temp2);
		}
		jPrevPos = jPos;
		jPos = nextJacobsthal(++jN) - 1;
	}
	return (main);
}
