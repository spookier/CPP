#include "BitcoinExchange.hpp"
#include "ParseInput.hpp"

int main(int argc, char **argv)
{

    if(argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return(0);
    }

    //float exchange_rate;

    try
    {
        BitcoinExchange btc("data.csv");
        ParseInput parse(argv[1], btc);
        //exchange_rate = btc.getExchangeRate(parse.getDate());
        //std::cout << exchange_rate << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    (void)argv;

}