#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>

namespace lib
{

class end
{
public:
    std::string s;

    end(std::string sval = "") : s(sval) {}
    end(int i) { s = std::to_string(i); }
    friend std::ostream &operator<<(std::ostream &out, const end e)
    {
        out << e.s;
        return out;
    }
};

template <typename T>
void print(T elem)
{
    std::cout << elem << " ";
}

template <typename T, typename... Args>
void print(T elem, Args... args)
{
    print(elem);
    if (sizeof...(Args) == 1)
    {

        std::cout << elem;
    }
    else
    {
        print(args...);
    }
}

}; // namespace lib

using lib::print;

std::vector<int> out;

int r()
{
    if (rand() % 3)
        return 1;
    else
        return -1;
}

std::pair<int, int> test(int i, int j, std::vector<int> vec)
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

std::vector<int> tests;

int run(const std::vector<int> &vec, std::vector<int> indexes)
{
    if (indexes.size() == 0)
        throw std::invalid_argument("indexes is empty");
    // for (auto &&i : indexes)
    // {
    //     print(i);
    // }
    // print("\n");

    int i = 0, cor = 0, wron = 0;
    tests.clear();
    for (int j = i + 1; j < indexes.size(); j++)
    {
        int index1 = indexes[i];
        int index2 = indexes[j];
        auto p = test(index1, index2, vec);
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
        out[indexes[0]] = 1;
        return indexes[0];
    }
    else
    {
        out[indexes[0]] = -1;
        return run(vec, tests);
    }
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));
    int n;
    // std::cin >> n;
    std::vector<int> vec(100000);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = r();
        // print(vec[i]);
    }

    std::vector<int> indexes(vec.size());
    out.resize(vec.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    int correct = run(vec, indexes);
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == correct)
            continue;
        auto p = test(correct, i, vec);
        if (p.second == 1)
            out[i] = 1;
        else
            out[i] = -1;
    }
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (out[i] != vec[i])
            print("fail");
    }
    print("success\n");
    return 0;
}