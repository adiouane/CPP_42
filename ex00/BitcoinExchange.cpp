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
            if (pos != std::string::npos)
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
        getline(input_file, line);
        while (getline(input_file, line))
        {
            size_t pos = line.find('|');
            if (pos != std::string::npos)
            {
                std::string date = line.substr(0, pos);
                double value = atof(line.substr(pos + 1).c_str());
                if (date.size() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ' || line[12] != ' ')
                {
                    std::cout << "Error: bad input => " << line << std::endl;
                    continue;
                }
                if (value <= 0.0 || value > 1000.0)
                {
                    std::cout << "Error: not a positive number. " << std::endl;
                    continue;
                }

                int month = atoi(date.substr(5, 2).c_str());
                int day = atoi(date.substr(8, 2).c_str());
                int year = atoi(date.substr(0, 4).c_str());
                if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2009 || year > 2022)
                {
                    std::cout << "Error: invalid date." << std::endl;
                    continue;
                }

                for (int i = 0; i < 10; i++)
                {
                    if (i == 4 || i == 7)
                        continue;
                    if (date[i] < '0' || date[i] > '9')
                    {
                        std::cout << "Error: invalid date. " << std::endl;
                        continue;
                    }
                }

                std::map<std::string, double>::iterator it = database.find(date); // find returns an iterator to the element with the given key (date) ; if the key is not found, it returns an iterator to database.end()
                if (it != database.end())
                {
                    std::cout << date << " => " << value << " = " << value * it->second << std::endl;
                }
                else
                {
                    std::map<std::string, double>::iterator it = database.lower_bound(date); // lower_bound returns an iterator to the first element that is not less than the given key (date) ; if the key is not found, it returns an iterator to the first element that is greater than the given key
                    if (it != database.end())
                    {
                        it--;
                        std::cout << date << " => " << value << " = " << value * it->second << std::endl;
                    }
                    else
                        std::cout << "Error: no BTC price found for " << date << std::endl;
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
