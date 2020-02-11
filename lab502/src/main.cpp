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
    std::vector<std::tuple<std::string, int, float>> v;
    v.push_back(std::make_tuple<std::string, int, float>("Silent disco", 24, 2));
    v.push_back(std::make_tuple<std::string, int, float>("Bonfire Nit", 24,2));
    v.push_back(std::make_tuple<std::string, int, float>("Street Play", 14, 1));
    v.push_back(std::make_tuple<std::string, int, float>("Dancing Comp", 20, 1));
    v.push_back(std::make_tuple<std::string, int, float>("Short Film", 22, 0.5));
    v.push_back(std::make_tuple<std::string, int, float>("Rangoli ", 16, 0.5));
    v.push_back(std::make_tuple<std::string, int, float>("scavenger ", 17, 1.5));
    v.push_back(std::make_tuple<std::string, int, float>("face art", 16, 0.5));
    v.push_back(std::make_tuple<std::string, int, float>("solo music", 19, 0.5));
    v.push_back(std::make_tuple<std::string, int, float>("group music", 19, 1));
    v.push_back(std::make_tuple<std::string, int, float>("mime competit", 23, 1));
    v.push_back(std::make_tuple<std::string, int, float>("poetry recit", 23, 1));

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
    // print_v(v);
    float curr_t = 12;
    int penalty = 0;
    float e_t;
    for (int i = 0; i < v.size(); i++)
    {
        auto elem = v[i];
        e_t = std::get<1>(elem);
        std::cout << std::get<0>(elem) << "\t\t" << std::get<1>(elem) << "\t\b\b\b\b" << std::get<2>(elem)
                  << "\tfrom " << curr_t << " to " << curr_t+std::get<2> (elem) << "\n";
        curr_t += std::get<2>(elem);
        if (curr_t >= e_t)
            penalty += 50000;
    }
    std::cout << "Penalty = " << penalty << "\n";
    return 0;
}