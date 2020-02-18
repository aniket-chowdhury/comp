#include <bits/stdc++.h>
#include "print.hpp"
using namespace std;
using lib::print;

int trucks(vector<int> truck, int v)
{
    if (v == 0)
        return 0;
    unsigned int inf = -1;
    for (int i = 0; i < truck.size(); i++)
    {
        if (truck[i] < v)
        {
            int base = trucks(truck, v - truck[i]);

            if (base != INT_MAX && base + 1 < inf)
                inf = base + 1;
        }
    }
    return inf;
}

int main()
{
    bool in = false;
    vector<int> vec = {25, 10, 5, 1};

    int v = 23640;
    if (in == true)
    {
        print("Enter total qty of sand:");
        cin >> v;
        print("Enter k:");
        int k;
        cin >> k;
        print("Enter sizes of k trucks:");
        vec.clear();
        for (int i = 0; i < k; i++)
        {
            int temp;
            std::cin >> temp;
            vec.push_back(temp);
        }
    }
    // print(trucks(vec,v));
    sort(vec.begin(), vec.end(), greater<int>());
// 
    vector<int> count;
    int i = 0;
    while (v > 0)
    {
        if (v <= vec[i])
        {
            count.push_back(0);
            i += 1;
            continue;
        }
        count.push_back((int)v / vec[i]);
        v = v % vec[i];
        i++;
    }
    for (i; i < vec.size(); i++)
    {
        count.push_back(0);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << count[i] << " trucks of size " << vec[i] << ".\n";
    }
    std::cout << "Sum=" << accumulate(count.begin(), count.end(), 0) << std::endl;
    return 0;
}