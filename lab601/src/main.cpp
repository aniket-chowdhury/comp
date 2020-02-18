#include "print.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <stdexcept>

using lib::print;

void print_v(std::vector<std::tuple<std::string, int, int>> &v)
{
    for (auto elem : v)
    {
        std::cout << std::get<0>(elem) << "\t\t\t"
                  << std::get<1>(elem) << "\t\t\t"
                  << std::get<2>(elem) << "\t\t\t"
                  << std::endl;
    }
}

int main(int argc, char *argv[])
{

}