#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: input file not provided." << std::endl;
        return 1;
    }
    BitcoinExchange(argv[1]);

    return 0;
}
