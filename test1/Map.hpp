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
				explicit NodeMap(T const &val = T(), color col = RED) : value(val), parent(0), left(0), right(0), col(col)
				{
					return;
				}
				~NodeMap()
				{
					return;
				}

				NodeMap *getnext()
				{
					NodeMap* next(this);
					if (next->right)
					{
						next = next->right;
						while(next->left)
							next = next->left;
					}
					else {
						NodeMap *tmp = next;
						next = next->parent;
						while (next->left != tmp)
						{
							tmp = next;
							next = next->parent;
						}
					}
					return next;
				}

				bool operator==(const NodeMap &other)
				{
					return value == other.value;
				}
				bool operator!=(const NodeMap &other)
				{
					return value != other.value;
				}
				bool operator<(const NodeMap &other)
				{
					return value < other.value;
				}
				bool operator>(const NodeMap &other)
				{
					return value > other.value;
				}
				bool operator<=(const NodeMap &other)
				{
					return value <= other.value;
				}
				bool operator>=(const NodeMap &other)
				{
					return value >= other.value;
				}

			};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class Map{
	private:
		typedef std::pair<const Key, T> value_type;
		NodeMap<value_type, Compare> *root;
		Compare comp;
		size_t lenght;
	public:

		Map(const Compare comp = Compare(), const Alloc &alloc = Alloc())
		{
			lenght = 0;
			this->comp = comp;
			root = 0;
		}



	};

}

#endif