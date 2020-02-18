#include <bits/stdc++.h>
#include "print.hpp"
using namespace std;
using lib::print;

int main()
{
    int v = 236;
    vector<int> vec = {25, 10, 5, 1};
    vector<int> count;
    int i = 0;
    while (v > 0)
    {
        if (    v <=
         vec[i])
        {
            count.push_back(v);
            break;
        }
        count.push_back((int)v / vec[i]);
        v = v % vec[i];
        i++;
    }
    for (auto const &i : count)
    {
        print(i);
    }

    return 0;
}