#include <iostream>
#include <vector>
#include "list.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Vector.hpp"
#include "Map.hpp"


bool iss(int i1, int i2)
{
	return (i1 < i2);
}

int main() {
	ft::Vector<int> *l = new ft::Vector<int>(4, 12);
	ft::Vector<int>::iterator it = l->begin();
	std::cout << *it << std::endl;
	ft::Vector<int>::const_iterator ir = l->begin();
	std::cout << *ir << std::endl;
	ft::Vector<int>::reverse_iterator rit = l->rend();
	rit--;
	std::cout << *rit << std::endl;
	ft::Vector<int>::const_reverse_iterator rir = l->rend();
	rir--;
	std::cout << *rir << std::endl;

	return 0;
}


