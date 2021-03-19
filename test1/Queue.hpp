#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <memory>
#include "list.hpp"

namespace ft {

	template<class T, class K = ft::List<T> >
	class Queue
	{
	protected:
		K list;
	public:

		Queue()
		{
			return;
		}

		~Queue()
		{
			return;
		}

		Queue(const K &l) : list(l)
		{}

		bool empty() const
		{
			return list.empty();
		}

		size_t size() const
		{
			return list.size();
		}

		T &front()
		{
			return list.front();
		}

		const T &front() const
		{
			return list.front();
		}

		T &back()
		{
			return list.back();
		}

		const T &back() const
		{
			return list.back();
		}

		void push(const T &v)
		{
			list.push_back(v);
		}

		void pop()
		{
			list.pop_front();
		}


	};

}

#endif






























