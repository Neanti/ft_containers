#include <list>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include "list.hpp"
int main()
{
	ft::list<int> *l = new ft::list<int>(5, 42);
	ft::list<int>::iterator it = l->begin();
	std::cout << *it << std::endl;
	ft::list<int>::const_iterator ir = l->begin();
	std::cout << *ir << std::endl;
	return 0;
}

