#ifndef PRINT__
#define PRINT__

#include <iostream>
#include <string>

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
        
        std::cout << "in";
    }
    else
    {
        print(args...);
    }
}

}; // namespace lib
#endif