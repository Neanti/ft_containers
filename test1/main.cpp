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
	ft::List<int> *l = new ft::List<int>(4, 12);
	l->print_l();
	ft::List<int>::reverse_iterator it = l->rbegin();
	std::cout << *it << std::endl;
	ft::List<int>::const_reverse_iterator ir = l->rbegin();
	std::cout << *ir << std::endl;
	ft::List<int>::reverse_iterator rit = l->rend();
	std::cout << *rit << std::endl;
	ft::List<int>::const_reverse_iterator rir = l->rend();
	std::cout << *rir << std::endl;

	return 0;
}


