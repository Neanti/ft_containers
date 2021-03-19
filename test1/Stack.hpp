#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <memory>
#include "list.hpp"

namespace ft {

	template<class T, class K = ft::List<T> >
	class Stack
	{
	protected:
		K list;
	public:

		Stack()
		{
			return;
		}

		~Stack()
		{
			return;
		}

		Stack(const K &l) : list(l)
		{}

		bool empty() const
		{
			return list.empty();
		}

		size_t size() const
		{
			return list.size();
		}

		T &top()
		{
			return list.back();
		}

		const T &top() const
		{
			return list.back();
		}

		void push(const T &v)
		{
			list.push_back(v);
		}

		void pop()
		{
			list.pop_back();
		}


	};

}

#endif






























