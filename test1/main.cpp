#include <iostream>
#include <vector>
#include "list.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "Vector.hpp"

bool iss(int i1, int i2)
{
	return (i1 < i2);
}

int main() {

//	std::vector<int> *g = new std::vector<int>();
//	g->push_back(1);
//	g->push_back(2);
//	g->push_back(3);
//	g->push_back(4);
//	g->push_back(5);
//	std::vector<int>::iterator tt = g->begin();
//	tt++;
//	tt++;
//	g->insert(tt, 42);
//	std::cout << *tt << std::endl;
//	tt = g->begin();
//	while (tt != g->end())
//	{
//		std::cout << *tt << std::endl;
//		tt++;
//	}

//	ft::Vector<int> *g = new ft::Vector<int>();
//	g->push_back(-1);
//	g->push_back(-2);
//	g->push_back(-3);
//	g->push_back(-4);


	ft::Vector<int> *v = new ft::Vector<int>();
	v->push_back(1);
	v->push_back(2);
	v->push_back(3);
	v->push_back(4);
	v->push_back(5);
	v->push_back(6);

	ft::Vector<int>::iterator it = v->begin();
	ft::Vector<int>::iterator ie = v->end();
	ie--;
	ie--;

	it = v->erase(v->begin(), ie);
	std::cout << *it << std::endl;
	v->print();
	return 0;
}


