#include "BitcoinExchange.hpp"


int main(int argc, char* argv[])
{
    // Check if input file is provided
    if (argc != 2) {
        std::cerr << "Error: input file not provided." << std::endl;
        return 1;
    }

    // Call BitcoinExchange function with input file
    BitcoinExchange(argv[1]);

    return 0;
}

