#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <filesystem>
#include <vector>
#include <random>

namespace fs = std::filesystem;

int cnt = 0;
std::mutex mut;

void nigga(std::ofstream& ref){
    for(int i = 0; i < 20; ++i){
        std::lock_guard<std::mutex> lock(mut);
        cnt++;
        ref << cnt << std::endl;
    }
}

int main()
{
    std::vector<const char*> brooo {
        "My",
        "Name",
        "Is",
        "Brume"
    };

    std::ofstream out = std::ofstream( "naija-file.txt" );//, std::ios::app);
    {
        std::jthread wk1( nigga, std::ref(out) );
        std::jthread wk2( nigga, std::ref(out) );
    }

    std::cout << "Count: " << cnt << "\n";

    if( !fs::exists( "naija-file.txt" ) )
    {
        std::cerr << "File does not exist, create it first!\n";
        return -1;
    }

    std::ifstream in = std::ifstream( "naija-file.txt" );

    if(!in.is_open())
    {
        std::cerr << "File is not open!\n";
        return -1;
    }

    std::cout << "File is open\n";

    std::string output;

    while(std::getline(in, output)){
        std::cout << output << "\n";
    }

    std::random_device rg;
    std::mt19937 seed(rg());
    std::uniform_int_distribution<int> rand(1, 100);

    for (const auto& x: brooo) std::cout << "Random number: " << rand(seed) << std::endl;
    return 0;
}
