#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <memory>

namespace ft {

	template<class Key, class T, class Compare = std::less<Key> >
	class MapIterator {
	protected:
		N *p;
	public:
		MapIterator() : p(0) {
			return;
		}

		MapIterator(N *p) : p(p) {
			return;
		}

		MapIterator(const MapIterator<T, N> &it) {
			p = it.p;
			return;
		}

		T getData(void) const {
			return this->p->data;
		}

		bool operator!=(const MapIterator<T, N> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return this->p->data;
		}

		MapIterator<T, N> &operator++() {
			p = p->next;
			return *this;
		}

		MapIterator<T, N> operator++(int) {
			MapIterator<T, N> tmp = *this;
			p = p->next;
			return tmp;
		}

		MapIterator<T, N> &operator--() {
			p = p->prev;
			return *this;
		}

		MapIterator<T, N> operator--(int) {
			MapIterator<T, N> tmp = *this;
			p = p->prev;
			return tmp;
		}

		void setp(N *p) {
			this->p = p;
			return;
		}

		N *getp() {
			return p;
		}

		N *getp() const {
			return p;
		}

	};

	template<class Key, class T, class Compare = std::less<Key> >
	std::ostream &operator<<(std::ostream &output, const MapIterator<T, N> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}


	template<class Key, class T, class Compare = std::less<Key> >
	class RevMapIterator {
	protected:
		N *p;
	public:
		RevMapIterator() : p(0) {
			return;
		}

		RevMapIterator(N *p) : p(p) {
			return;
		}


		RevMapIterator(const RevMapIterator<T, N> &it) {
			p = it.p;
			return;
		}

		T getData(void) const {
			return this->p->data;
		}

		bool operator!=(const RevMapIterator<T, N> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return this->p->data;
		}

		RevMapIterator<T, N> &operator--() {
			p = p->next;
			return *this;
		}

		RevMapIterator<T, N> operator--(int) {
			RevMapIterator<T, N> tmp = *this;
			p = p->next;
			return tmp;
		}

		RevMapIterator<T, N> &operator++() {
			p = p->prev;
			return *this;
		}

		RevMapIterator<T, N> operator++(int) {
			RevMapIterator<T, N> tmp = *this;
			p = p->prev;
			return tmp;
		}

		void setp(N *p) {
			this->p = p;
			return;
		}

		N *getp() {
			return p;
		}

		N *getp() const {
			return p;
		}

	};

	template<class Key, class T, class Compare = std::less<Key> >
	std::ostream &operator<<(std::ostream &output, const RevMapIterator<T, N> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}



	template<class Key, class T, class Compare = std::less<Key> >
	class ConstMapIterator {
	protected:
		N *p;
	public:
		ConstMapIterator() : p(0) {
			return;
		}

		ConstMapIterator(N *p) {
			this->p = p;
			return;
		}

		ConstMapIterator(const ConstMapIterator<T, N> &it) {
			p = it.p;
			return;
		}

		ConstMapIterator(const MapIterator<T, N> &it)
		{
			p = it.getp();
		}

		T getData(void) const {
			return this->p->data;
		}

		bool operator!=(const ConstMapIterator<T, N> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return this->p->data;
		}

		ConstMapIterator<T, N> &operator++() {
			p = p->next;
			return *this;
		}

		ConstMapIterator<T, N> operator++(int) {
			ConstMapIterator<T, N> tmp = *this;
			p = p->next;
			return tmp;
		}

		ConstMapIterator<T, N> &operator--() {
			p = p->prev;
			return *this;
		}

		ConstMapIterator<T, N> operator--(int) {
			ConstMapIterator<T, N> tmp = *this;
			p = p->prev;
			return tmp;
		}

		void setp(N *p) {
			this->p = p;
			return;
		}

		N *getp() {
			return p;
		}

		N *getp() const {
			return p;
		}

	};

	template<class Key, class T, class Compare = std::less<Key> >
	std::ostream &operator<<(std::ostream &output, const ConstMapIterator<T, N> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}

	template<class Key, class T, class Compare = std::less<Key> >
	class ConstRevMapIterator {
	protected:
		N *p;
	public:
		ConstRevMapIterator() : p(0) {
			return;
		}

		ConstRevMapIterator(N *p) : p(p) {
			return;
		}


		ConstRevMapIterator(const ConstRevMapIterator<T, N> &it) {
			p = it.p;
			return;
		}

		ConstRevMapIterator(const RevMapIterator<T, N> &it)
		{
			p = it.getp();
		}

		T getData(void) const {
			return this->p->data;
		}

		bool operator!=(const ConstRevMapIterator<T, N> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return this->p->data;
		}

		ConstRevMapIterator<T, N> &operator--() {
			p = p->next;
			return *this;
		}

		ConstRevMapIterator<T, N> operator--(int) {
			ConstRevMapIterator<T, N> tmp = *this;
			p = p->next;
			return tmp;
		}

		ConstRevMapIterator<T, N> &operator++() {
			p = p->prev;
			return *this;
		}

		ConstRevMapIterator<T, N> operator++(int) {
			ConstRevMapIterator<T, N> tmp = *this;
			p = p->prev;
			return tmp;
		}

		void setp(N *p) {
			this->p = p;
			return;
		}

		N *getp() {
			return p;
		}

		N *getp() const {
			return p;
		}

	};

	template<class Key, class T, class Compare = std::less<Key> >
	std::ostream &operator<<(std::ostream &output, const ConstRevMapIterator<T, N> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}

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

		map(iterator first, iterator last)

	};

}

#endif