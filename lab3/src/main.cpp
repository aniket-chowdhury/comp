#include "print.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using lib::print;

class Tester
{
public:
    std::vector<int> vec;
    Tester(std::vector<int> v)
    {
        vec = v;
    }

    int r()
    {
        if (rand() % 2)
            return 1;
        else
            return -1;
    }

    std::pair<int, int> test(int i, int j)
    {
        if (vec.size() == 0)
            throw std::invalid_argument("Empty array");
        if (i < 0 || j < 0 || i >= vec.size() || j >= vec.size())
            throw std::invalid_argument("i or j out of range");

        if (vec[i] == 1 && vec[j] == 1)
            return std::make_pair<int, int>(1, 1);

        else if (vec[i] == -1 && vec[j] == -1)
            return std::make_pair<int, int>(r(), r());

        else if (vec[i] == 1 && vec[j] == -1)
            return std::make_pair<int, int>(r(), -1);

        else
            return std::make_pair<int, int>(-1, r());
    }
};

int run(Tester t)
{
    auto vec = t.vec;
    std::vector<int> tests;

    int i = 0;
    int cor = 0;
    int wron = 0;
    for (int j = i + 1; i < vec.size(); i++)
    {
        auto p = t.test(i, j);
        if (p.first == 1)
        {
            cor++;
        }
        else
        {
            wron++;
            tests.push_back(j);
        }
    }
    if (cor > wron)
    {
        return i;
    }
    else
    {
        return run(Tester(tests));
    }
}

std::vector<int> validate(Tester t)
{
    auto vec = t.vec;

    std::vector<int> out(vec.size());

    size_t i = 0;
    int flag = 0;
    std::vector<int> tests;

    int cor = 0;
    int wron = 0;
    for (size_t j = i + 1; j < vec.size(); j++)
    {
        auto p = t.test(i, j);
        if (p.first == 1)
        {
            cor++;
        }
        else
        {
            wron++;
            tests.push_back(j);
        }
        if (cor > wron)
        {
            out[i] = 1;
            flag = 1;
        }
        else
        {
            out[i] = -1;
            i = run(Tester(tests));
        }
    }
    if (flag)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            auto p = t.test(i, j);
            out[j] = p.second;
        }
    }

    return out;
}

std::vector<int> run(int l, int r, Tester t, std::vector<int> out)
{
    auto vec = t.vec;
    if (r >= l)
    {
        bool flag = false;
        int mid = l + (r - l) / 2;
        for (size_t i = l, j = 0; i < mid; i++, j++)
        {
            if (out[i] == 1)
            {
                flag = true;
            }
        }
        auto temp = validate(Tester(std::vector<int>(t.vec.begin() + l, t.vec.begin() + r)));
        for (size_t i = l, j = 0; i < r; i++, j++)
        {
            out[i] = vec[j];
        }
    }
    return out;
}

int divide(Tester t)
{
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    std::vector<int> vec = {1, -1, 1, -1, 1, -1, 1, -1};
    std::random_shuffle(vec.begin(), vec.end());

    Tester t(vec);

    auto out = run(0, t.vec.size(), t, std::vector<int>(vec.size()));
    for (size_t i = 0; i < vec.size(); i++)
    {
        print(out[i] == vec[i]);
    }

    return 0;
}