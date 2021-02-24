#include <iostream>
#include <list>
#include "list.hpp"

int main()
{
	std::list<int> *a = new std::list<int>();
	a->push_front(8);
	a->push_front(7);
	a->push_front(6);
	a->push_front(5);
	a->push_front(4);
	std::list<int>::iterator it = a->begin();
	int i = 0;
	while(i < 20)
	{
		std::cout << *it << " = " << i << std::endl;
		it++;
		i++;
	}

	ft::List<int> *b = new ft::List<int>();

	b->push_front(44);
	b->push_front(55);
	b->push_front(88);
	b->push_front(222);
	b->pop_front();
	b->pop_front();
	b->pop_front();
	b->pop_front();
	b->pop_front();
	b->pop_front();

	b->pop_front();
	ft::List<int>::iterator ic = b->begin();
	std::cout << b->size() << std::endl;

	while(ic != b->end())
	{
		std::cout << *ic << std::endl;
		++ic;
	}
	return 0;
}

