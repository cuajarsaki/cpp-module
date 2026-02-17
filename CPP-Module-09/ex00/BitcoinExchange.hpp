#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & other);
	BitcoinExchange & operator=(BitcoinExchange const & other);
	~BitcoinExchange();

	void loadDatabase(std::string const & csvFile);
	void processInput(std::string const & inputFile) const;

private:
	std::map<std::string, double> _db;  // date -> exchange_rate

	static bool   isValidDate(std::string const & date);
	static double parseValue(std::string const & s);
	double        getRate(std::string const & date) const;
};

#endif
