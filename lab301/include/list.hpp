#include <iostream>
#include <unordered_set>

namespace lib
{
template <typename T>
class node
{
public:
	T element;
	node *next;
	node *prev;
	node(T elemval, node *nextval = nullptr, node *prevval = nullptr) : element(elemval), next(nextval), prev(prevval) {}
	node(node *nextval = nullptr, node *prevval = nullptr) : next(nextval) {}

	T &operator()()
	{
		return element;
	}
};

template <typename T>
class list
{
private:
	node<T> *head;
	node<T> *tail;

	void init()
	{
		head = fence = tail = new node<T>(nullptr);
	}

public:
	node<T> *getHead() { return head; }
	node<T> *getTail() { return tail; }
	void setHead(node<T> *h) { head = h; }
	void setTail(node<T> *t) { tail = t; }
	node<T> *fence;
	int flag = 1;
	list() { init(); }
	bool append(T it)
	{
		tail->next = new node<T>(it, nullptr, tail);
		if (flag == 1)
		{
			head = tail->next;
			flag++;
			fence = head;
		}
		tail = tail->next;
		return true;
	}
	bool print()
	{
		if (head == nullptr)
			return 0;
		fence = head;
		while (fence != nullptr)
		{
			std::cout << fence->element << " ";
			fence = fence->next;
		}
		fence = head;
		return true;
	}

	list(const std::initializer_list<T> arr)
	{
		for (auto it = arr.begin(); it < arr.end(); it++)
		{
			if (flag == 1)
			{
				head = new node<T>(*it, nullptr);
				tail = head;
				fence = head;
				flag++;
			}
			else
			{
				append(*it);
			}
		}
	}

	node<T> *begin()
	{
		fence = head;
		return fence;
	}

	node<T> *find(T element)
	{
		fence = head;
		while (fence != nullptr)
		{
			if (fence->element == element)
				return fence;
			fence = fence->next;
		}
		return nullptr;
	}

	bool remove(T element)
	{
		fence = this->find(element);
		if (fence != nullptr)
		{
			if (tail == head)
			{
				fence = tail = head = nullptr;
			}
			else if (fence == head)
			{
				head->next->prev = nullptr;
				head = head->next;
			}
			else if (fence == tail)
			{
				tail->prev->next = nullptr;
				tail = tail->prev;
				fence = nullptr;
			}
			else
			{
				fence->next->prev = fence->prev;
				fence->prev->next = fence->next;
				fence = nullptr;
			}
			flag--;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const list<T> &l1);
};

template <typename T>
inline bool list<T>::operator==(const list<T> &l1)
{
	node<T> *f1 = l1.head;
	node<T> *f2 = this->head;

	while (f1 != nullptr && f2 != nullptr)
	{
		if (f1->element != f2->element)
			break;

		f1 = f1->next;
		f2 = f2->next;
	}

	return (f1 == nullptr && f2 == nullptr);
}

} // namespace lib