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
    srand(static_cast<unsigned int>(time(0)));
    std::vector<std::tuple<std::string, int, int>> v;
    v.push_back(std::make_tuple<std::string, int, int>("Silent disco", 24, 100000));
    v.push_back(std::make_tuple<std::string, int, int>("Bonfire Nit", 24, 500000));
    v.push_back(std::make_tuple<std::string, int, int>("Street Play", 14, 60000));
    v.push_back(std::make_tuple<std::string, int, int>("Dancing Comp", 20, 75000));
    v.push_back(std::make_tuple<std::string, int, int>("Short Film", 22, 45000));
    v.push_back(std::make_tuple<std::string, int, int>("Rangoli ", 16, 50000));
    v.push_back(std::make_tuple<std::string, int, int>("scavenger ", 17, 200000));
    v.push_back(std::make_tuple<std::string, int, int>("face art", 16, 40000));
    v.push_back(std::make_tuple<std::string, int, int>("solo music", 19, 95000));
    v.push_back(std::make_tuple<std::string, int, int>("group music", 19, 150000));
    v.push_back(std::make_tuple<std::string, int, int>("mime competit", 23, 120000));
    v.push_back(std::make_tuple<std::string, int, int>("poetry recit", 14, 300000));

    struct
    {
        bool operator()(std::tuple<std::string, int, int> a,
                        std::tuple<std::string, int, int> b) const
        {
            if (std::get<1>(a) == std::get<1>(b))
                return std::get<2>(a) > std::get<2>(b);

            return std::get<1>(a) < std::get<1>(b);
        }
    } cost;
    sort(v.begin(), v.end(), cost);
    print_v(v);
    int curr_t = 12;
    int penalty = 0;
    int e_t;
    for (int i = 0; i < v.size(); i++)
    {
        auto elem = v[i];
        e_t = std::get<1>(elem);
        std::cout << std::get<0>(elem) << "\t\t" << std::get<1>(elem) << "\t\t"
                  << std::get<2>(elem) << "\tat " << curr_t << "\n";
        if (curr_t >= e_t)
            penalty += std::get<2>(elem);
        curr_t += 1;
    }
    std::cout << "Penalty = " << penalty << "\n";
    return 0;
}