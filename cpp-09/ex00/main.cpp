#include "BitcoinExchange.hpp"

int	main(void)
{
	BitcoinExchange database("data.csv");
	BitcoinExchange::Date	date();

	date.getDate();

	/*for (std::string entry; std::getline(database, entry))
	{
		
	}
	
	database.exchange(date, amount);
*/
}