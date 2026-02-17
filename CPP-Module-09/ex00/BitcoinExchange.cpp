#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other)
	: _db(other._db) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ---------- helpers ----------

bool BitcoinExchange::isValidDate(std::string const & date)
{
	if (date.size() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7) continue;
		if (date[i] < '0' || date[i] > '9') return false;
	}
	int year  = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31)     return false;
	// Month day limits
	int maxDay[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > maxDay[month]) return false;
	if (month == 2 && day == 29) {
		// leap year
		if (!((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return false;
	}
	return true;
}

double BitcoinExchange::parseValue(std::string const & s)
{
	// trim whitespace
	std::size_t start = s.find_first_not_of(" \t");
	std::size_t end   = s.find_last_not_of(" \t");
	if (start == std::string::npos)
		throw std::runtime_error("empty value");
	std::string trimmed = s.substr(start, end - start + 1);

	// check characters: digits, optional leading '-', optional single '.'
	bool hasDot = false;
	for (std::size_t i = 0; i < trimmed.size(); ++i) {
		char c = trimmed[i];
		if (i == 0 && c == '-') continue;
		if (c == '.') {
			if (hasDot) throw std::runtime_error("bad value");
			hasDot = true;
			continue;
		}
		if (c < '0' || c > '9')
			throw std::runtime_error("bad value");
	}
	if (trimmed.empty() || trimmed == "-")
		throw std::runtime_error("bad value");

	std::istringstream iss(trimmed);
	double val;
	iss >> val;
	return val;
}

double BitcoinExchange::getRate(std::string const & date) const
{
	if (_db.empty())
		throw std::runtime_error("database is empty");

	// lower_bound gives first element >= date
	std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

	if (it == _db.end() || it->first != date) {
		// exact date not found: use closest lower date
		if (it == _db.begin())
			throw std::runtime_error("date before database range");
		--it;
	}
	return it->second;
}

// ---------- public ----------

void BitcoinExchange::loadDatabase(std::string const & csvFile)
{
	std::ifstream f(csvFile.c_str());
	if (!f.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(f, line);  // skip header "date,exchange_rate"

	while (std::getline(f, line)) {
		if (line.empty()) continue;
		std::size_t comma = line.find(',');
		if (comma == std::string::npos) continue;
		std::string date = line.substr(0, comma);
		std::string rateStr = line.substr(comma + 1);
		double rate = std::atof(rateStr.c_str());
		_db[date] = rate;
	}
}

void BitcoinExchange::processInput(std::string const & inputFile) const
{
	std::ifstream f(inputFile.c_str());
	if (!f.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(f, line);  // skip header "date | value"

	while (std::getline(f, line)) {
		if (line.empty()) continue;

		std::size_t pipe = line.find('|');
		if (pipe == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// trim date
		std::string datePart = line.substr(0, pipe);
		{
			std::size_t s = datePart.find_first_not_of(" \t");
			std::size_t e = datePart.find_last_not_of(" \t");
			datePart = (s == std::string::npos) ? "" : datePart.substr(s, e - s + 1);
		}

		if (!isValidDate(datePart)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string valuePart = line.substr(pipe + 1);
		double value;
		try {
			value = parseValue(valuePart);
		} catch (...) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate;
		try {
			rate = getRate(datePart);
		} catch (std::exception const & e) {
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}

		std::cout << datePart << " => " << value << " = " << value * rate << std::endl;
	}
}
