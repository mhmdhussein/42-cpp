#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file)
        throw std::runtime_error("Error: could not open data.csv");

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string rateStr;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, rateStr))
            continue;

        _rates[date] = std::strtod(rateStr.c_str(), NULL);
    }
}

bool BitcoinExchange::validDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file)
        throw std::runtime_error("Error: could not open input file.");

    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') ||
            !std::getline(ss, valueStr))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(date.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));

        char *end;
        double value = std::strtod(valueStr.c_str(), &end);

        if (*end != '\0')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!validDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }


        std::map<std::string, double>::iterator it = _rates.lower_bound(date);

        if (it == _rates.end() || it->first != date)
        {
            if (it == _rates.begin())
            {
                std::cout << "Error: no earlier date available" << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date << " => " << value
                  << " = " << value * it->second << std::endl;
    }
}
