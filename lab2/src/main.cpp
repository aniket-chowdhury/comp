#include "print.hpp"
#include <iostream>
#include <vector>

using lib::print;

int max(int a, int b)
{
    return a > b ? a : b;
}

template <typename T>
std::vector<T> makediff(std::vector<T> v)
{
    std::vector<int> v1(v.size()-1);
    for(int i =0;i<v.size()-1;i++){
        v1[i] = v[i+1]-v[i];
        // print(v1[i]);
    }
    return v1;
}

int sub2(std::vector<int> v)
{
    int next_sum = 0;
    int sum = 0;
    for (auto elem : v)
    {
        sum = max(0, sum + elem);
        next_sum = max(next_sum, sum);
    }
    return next_sum;
}

int sub(std::vector<int> v)
{
    int sum = 0;
    int prev_elem = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        auto elem = v[i];
        if (elem > prev_elem)
        {
            sum += elem - prev_elem;
        }
        prev_elem = elem;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    std::vector<int> vec = {80,100,110,90,65,70,75,90,80,70,100,80,65,60,55,50};
    std::vector<int> diff = {-1, -10, 3};
    // makediff(vec);
    // print(diff);
    print(sub2(makediff(vec)));
    return 0;
}
