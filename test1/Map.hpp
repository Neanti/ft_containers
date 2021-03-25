#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>

namespace ft {

	enum color {
		BLACK, RED
	};

	template <class T, class Compare>
			class NodeMap {
			public:
				T value;
				NodeMap *parent;
				NodeMap *left;
				NodeMap *right;
				color col;
				explicit NodeMap(T const &val = T(), color col = RED) : value(val), parent(0), left(0), right(0), col(color)
				{
					return;
				}
				~NodeMap()
				{
					return;
				}

			};

	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class Map{
		typedef std::pair<const Key, T> value_type;
	};

}

#endif