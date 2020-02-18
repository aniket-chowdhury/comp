#include <iostream>
#include <exception>
#include <new>

namespace lib
{

template <typename T>
class node
{
public:
    T element;
    node *next;
    node(node *nextval = nullptr) : next(nextval) {}
    node(T elemval, node *nextval = nullptr) : element(elemval), next(nextval) {}
};

template <typename T>
class queue
{
private:
    node<T> *rear;
    node<T> *fence;
    void init() { rear = nullptr; }

public:
    queue() { init(); }

    bool enqueue(T it)
    {
        if (rear == nullptr)
        {
            node<T> *n = new node<T>(it);
            rear = n;
            return true;
        }
        node<T> *n = new node<T>(it, rear->next);
        rear = n;
        return true;
    }

    bool print()
    {
        fence=rear->next;
        while(fence!=rear){
            std::cout << fence->element << " ";
            fence=fence->next;
        }
    }
};
} // namespace lib
