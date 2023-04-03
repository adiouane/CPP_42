#include "BitcoinExchange.hpp"

void BitcoinExchange(std::string file)
{
    std::map<std::string, double> database;
    std::ifstream database_file("data.csv");

    if (database_file.is_open())
    {
        std::string line;
        while (getline(database_file, line))
        {
            size_t pos = line.find(',');
            if (pos != line.size())
            {
                std::string date = line.substr(0, pos);
                double price = atof(line.substr(pos + 1).c_str());
                database[date] = price;
            }
        }
        if (database.empty())
        {
            std::cout << "Error: database is empty." << std::endl;
            return;
        }
        database_file.close();
    }
    else
    {
        std::cout << "Error: could not open database file." << std::endl;
        return;
    }

    std::ifstream input_file(file);
    if (input_file.is_open())
    {
        std::string line;
        while (getline(input_file, line))
        {
            if (line.empty())
            {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (strcmp(line.substr(0, 12).c_str(), "date | value") == 0)
                continue;
            size_t pos = line.find('|');
            if (pos != line.size())
            {
                std::string date = line.substr(0, pos);
                std::string value_str = line.substr(pos + 1);
                double value = atof(line.substr(pos + 1).c_str());
                int month = atoi(date.substr(5, 2).c_str());
                int day = atoi(date.substr(8, 2).c_str());
                int year = atoi(date.substr(0, 4).c_str());
                int parce = 0;

                for (size_t i = 0; i < value_str.size(); i++)
                {
                    if (!isdigit(value_str[i]) && value_str[i] != ' ' && value_str[i] != '.' && value_str[i] != '-')
                    {
                        parce = 1;
                        std::cout << "Error: invalid value. " << std::endl;
                        break;
                    }
                }
                for (int i = 0; i < 10; i++)
                {
                    if (i == 4 || i == 7)
                        continue;
                    if (date[i] < '0' || date[i] > '9')
                    {
                        parce = 1;
                        std::cout << "Error: invalid date. " << std::endl;
                        break;
                    }
                }

                if (date.size() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ' || line[12] != ' ' || value == 0)
                {
                    parce = 1;
                    std::cout << "Error: bad input => " << line << std::endl;
                    continue;
                }
                else if (value > 1000.0)
                {
                    parce = 1;
                    std::cout << "Error: too large a number. " << std::endl;
                    continue;
                }
                else if (value <= 0.0)
                {
                    parce = 1;
                    std::cout << "Error: not a positive number. " << std::endl;
                    continue;
                }

                else if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2009 || year > 2022)
                {
                    parce = 1;
                    std::cout << "Error: invalid date." << std::endl;
                    continue;
                }

                if (parce == 0)
                {
                    std::map<std::string, double>::iterator it = database.find(date);
                    if (it != database.end())
                    {
                        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
                    }
                    else
                    {
                        std::map<std::string, double>::iterator it = database.lower_bound(date);
                        if (it != database.end())
                        {
                            it--;
                            std::cout << date << " => " << value << " = " << value * it->second << std::endl;
                        }
                        else
                            std::cout << "Error: no BTC price found for " << date << std::endl;
                    }
                }
            }
            else if (line[0] == '\0' || line[0] == '\n' || line[0] == '\t' || line[0] == ' ')
            {
                std::cout << "Error: bad input =>  " << line << std::endl;
                continue;
            }
            else
            {
                std::cout << "Error: bad input =>  " << line << std::endl;
                continue;
            }
        }
        if (line.empty())
        {
            std::cout << "Error: input file is empty." << std::endl;
            return;
        }
        input_file.close();
    }
    else
    {
        std::cout << "Error: could not open input file." << std::endl;
        return;
    }
}
