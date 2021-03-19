#include <iostream>
#include <list>
#include "list.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

bool iss(int i1, int i2)
{
	return (i1 < i2);
}

int main()
{
	ft::List<int> *q = new ft::List<int>();
	q->push_front(9);
	q->push_back(99);
	ft::List<int>::iterator it = q->begin();
	q->pop_front();
	q->pop_front();
	while(it != q->end())
	{
		std::cout << *it << std::endl;
		it++;
	}

	return 0;
}

