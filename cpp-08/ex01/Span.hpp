#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	_vec;
	public:
		Span();
		Span(unsigned int max);
		Span(Span const &model);
		Span	&operator=(Span const &model);
		~Span();

		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		template <typename Container>
		void	addRange(typename Container::iterator begin, typename Container::iterator end) {
			for (typename Container::iterator it = begin; it != end; ++it) {
				_vec.push_back(*it);
			}
		}
};

