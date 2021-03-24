#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <memory>

namespace ft {

	template<class T>
	struct Node {
		Node<T> *next;
		Node<T> *prev;
		T data;
	};

	template<class T, class N>
	class ListIterator {
	protected:
		N *p;
	public:
		ListIterator() : p(0) {
			return;
		}

		ListIterator(N *p) : p(p) {
			return;
		}

		ListIterator(const ListIterator<T, N> &it) {
			p = it.p;
			return;
		}

		T getData(void) const {
			return this->p->data;
		}

		bool operator!=(const ListIterator<T, N> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return this->p->data;
		}

		ListIterator<T, N> &operator++() {
			p = p->next;
			return *this;
		}

		ListIterator<T, N> operator++(int) {
			ListIterator<T, N> tmp = *this;
			p = p->next;
			return tmp;
		}

		ListIterator<T, N> &operator--() {
			p = p->prev;
			return *this;
		}

		ListIterator<T, N> operator--(int) {
			ListIterator<T, N> tmp = *this;
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

	};

	template<class T, class N>
	std::ostream &operator<<(std::ostream &output, const ListIterator<T, N> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}


	template<class T, class N>
	class RevListIterator {
	protected:
		N *p;
	public:
		RevListIterator() : p(0) {
			return;
		}

		RevListIterator(N *p) : p(p) {
			return;
		}


		RevListIterator(const RevListIterator<T, N> &it) {
			p = it.p;
			return;
		}

		T getData(void) const {
			return this->p->data;
		}

		bool operator!=(const RevListIterator<T, N> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return this->p->data;
		}

		RevListIterator<T, N> &operator--() {
			p = p->next;
			return *this;
		}

		RevListIterator<T, N> operator--(int) {
			RevListIterator<T, N> tmp = *this;
			p = p->next;
			return tmp;
		}

		RevListIterator<T, N> &operator++() {
			p = p->prev;
			return *this;
		}

		RevListIterator<T, N> operator++(int) {
			RevListIterator<T, N> tmp = *this;
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

	};

	template<class T, class N>
	std::ostream &operator<<(std::ostream &output, const RevListIterator<T, N> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}


	//
//	template<class T, class N>
//	class ConstListIterator {
//	protected:
//		N *p;
//	public:
//		ConstListIterator() : p(0) {
//			return;
//		}
//
//		ConstListIterator(N *p) : p(p) {
//			return;
//		}
//
//		ConstListIterator(const ConstListIterator<T, N> &it) {
//			p = it.p;
//			return;
//		}
//
//		T getData(void) const {
//			return this->p->data;
//		}
//
//		bool operator!=(const ConstListIterator<T, N> &it) {
//			if (this->p != it.p)
//				return (true);
//			return false;
//		}
//
//		const T &operator*() const {
//			return this->p->data;
//		}
//
//		ConstListIterator<T, N> &operator++() {
//			p = p->next;
//			return *this;
//		}
//
//		ConstListIterator<T, N> operator++(int) {
//			ConstListIterator<T, N> tmp = *this;
//			p = p->next;
//			return tmp;
//		}
//
//		ConstListIterator<T, N> &operator--() {
//			p = p->prev;
//			return *this;
//		}
//
//		ConstListIterator<T, N> operator--(int) {
//			ConstListIterator<T, N> tmp = *this;
//			p = p->prev;
//			return tmp;
//		}
//
//		void setp(N *p) {
//			this->p = p;
//			return;
//		}
//
//		N *getp() {
//			return p;
//		}
//
//	};

	//
	
	
	template<class T, class Alloc = std::allocator <T> >
	class List {
	private:
		Node<T> *_begin;
		Node<T> *_end;
		size_t _size;
	public:
		typedef ListIterator<T, Node<T> > iterator;
		typedef RevListIterator<T, Node<T> > reverse_iterator;
//		typedef ConstListIterator<T, Node<T> > const_iterator;

		void print_l() {
			iterator it = begin();
			std::cout << "PRINT NEW LIST" << std::endl;
			while (it != end()) {
				std::cout << "List: " << *it << std::endl;
				it++;
			}
		}

		void rprint_l() {
			reverse_iterator it = rbegin();
			std::cout << "PRINT NEW LIST REV" << std::endl;
			while (it != rend()) {
				std::cout << "List: " << *it << std::endl;
				it++;
			}
		}


		List(const Alloc &alloc = Alloc()) {
			_size = 0;
			_end = new Node<T>;
			_end->next = _begin;
			_end->prev = _begin;
			_begin = _end;
			_begin->prev = _end;
			_begin->next = _end;
			return;
		}

		List(size_t n, const T &val, const Alloc &alloc = Alloc()) {
			T v = val;
			_size = 0;
			_end = new Node<T>;
			_end->next = _begin;
			_begin = _end;
			_begin->prev = _end;

			while (n != _size) {
				push_front(v);
			}
			return;
		}

		List(iterator first, iterator last, const Alloc &alloc = Alloc()) {
			_size = 0;
			_end = new Node<T>;
			_end->next = _begin;
			_end->prev = _begin;
			_begin = _end;
			_begin->prev = _end;
			_begin->next = _end;
			insert(_begin, first, last);
		}

		List(const List<T> &x) {
			_size = 0;
			_end = new Node<T>;
			_end->next = _begin;
			_end->prev = _begin;
			_begin = _end;
			_begin->prev = _end;
			_begin->next = _end;
			insert(_begin, x.begin(), x.end());
		}

		List<T> &operator=(const List<T> &x) {
			clear();
			_size = 0;
			_end = new Node<T>;
			_end->next = _begin;
			_end->prev = _begin;
			_begin = _end;
			_begin->prev = _end;
			_begin->next = _end;
			insert(_begin, x.begin(), x.end());
			return *this;
		}

		~List() {
			Node<T> *b = _begin;
			while (b != _end) {
				_begin = b->next;
				delete b;
				b = _begin;
			}
			delete _end;
			return;
		}

		iterator begin() {
//			iterator *it = new ListIterator<T, Node<T> >;
//			it->setp(_begin);
//			return *it;
			return (iterator(_begin));
		}

//		const_iterator begin() const {
////			const_iterator *it = new ConstListIterator<T const, Node<T> const >;
////			it->setp(_begin);
////			return *it;
//			return (const_iterator(_begin));
//
//		}

		iterator end() {
			iterator *it = new ListIterator<T, Node<T> >;
			it->setp(_end);
			return *it;
		}

		reverse_iterator rbegin() const {
			reverse_iterator *it = new RevListIterator<T, Node<T> >;
			it->setp(_end->prev);
			return *it;
		}

		reverse_iterator rend() const {
			reverse_iterator *it = new RevListIterator<T, Node<T> >;
			it->setp(_end);
			return *it;
		}

		bool empty(void) const {
			if (_size == 0)
				return true;
			else
				return false;
		}

		size_t size(void) const {
			return _size;
		}

		T &front(void) {
			return _begin->data;
		}

		const T &front(void) const {
			return _begin->data;
		}

		T &back(void) {
			return _end->prev->data;
		}

		const T &back(void) const {
			return _end->prev->data;
		}

		void assign(unsigned int n, const T &val) {
			clear();
			while (_size != n)
				push_front(val);
		}

		void assign(iterator first, iterator last) {
			clear();
			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		iterator insert(iterator pos, const T &val) {
			Node<T> *n = new Node<T>;
			T v;
			v = val;
			n->data = v;
			n->next = pos.getp();
			n->prev = pos.getp()->prev;
			pos.getp()->prev->next = n;
			pos.getp()->prev = n;
			if (_size == 0)
				_begin = n;
			_size++;
			iterator *il = new iterator(n);
			return (*il);
		}

		void insert(iterator pos, size_t n, const T &val) {
			int i = 0;
			while (i < n) {
				insert(pos, val);
				i++;
			}
		}

		void insert(iterator pos, iterator first, iterator last) {
			while (first != last) {
				insert(pos, *first);
				first++;
			}
		}

		void push_front(const T &val) {
			Node<T> *a = new Node<T>;
			a->data = val;
			a->prev = _end;
			a->next = _begin;
			_begin->prev = a;
			_begin = a;
			_begin->prev = _end;
			_end->next = a;
			_size++;
			return;
		}

		void pop_front() {
			Node<T> *a;

			if (_size == 0)
				return;
			a = _begin;
			_size--;
			_begin = a->next;
			_begin->prev = _end;
			delete a;
		}

		void push_back(const T &val) {
			_size++;
			Node<T> *a = new Node<T>;

			a->data = val;
			if (_size == 1) {
				a->prev = _end;
				a->next = _end;
				_begin = a;
				_begin->prev = _end;
				_end->next = _begin;
				_end->prev = a;
			} else {
				a->prev = _end->prev;
				_end->prev->next = a;
				_end->prev = a;
				a->next = _end;
			}
		}

		void pop_back() {
			if (_size == 0)
				return;
			if (_size == 1) {
				_size = 0;
				delete _begin;
				_begin = _end;
				_begin->prev = _end;
				return;
			}
			Node<T> *tmp;
			tmp = _end;

			tmp = tmp->prev;
			tmp->prev->next = _end;
			_end->prev = tmp->prev;
			_size--;
			delete tmp;
		}

		void clear() {
			Node<T> *tmp;
			if (_size == 0)
				return;
			while (tmp != _end) {
				tmp = _begin->next;
				std::cout << _begin << "    " << tmp << "    " << _end << std::endl;

				delete _begin;
				_begin = tmp;
			}
			_size = 0;
			_end = new Node<T>;
			_end->next = _begin;
			_begin = _end;
			_begin->prev = _end;
			return;
		}

		void reverse() {
			int i = 0;
			T tmp;
			Node<T> *d = _begin;
			Node<T> *f = _end->prev;
			while ((d != f && _size % 2 == 1) || (d->prev != f && _size % 2 == 0)) {
				tmp = d->data;
				d->data = f->data;
				f->data = tmp;
				f = f->prev;
				d = d->next;
				i++;
			}
		}

		void unique() {
			Node<T> *tmp = _begin->next;
			Node<T> *tt = tmp->prev;
			while (tmp != _end) {
				if (tmp->data == tmp->prev->data) {
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					_size--;
					delete tmp;
					tmp = tt->next;
				} else {
					tmp = tmp->next;
					tt = tt->next;
				}
			}
		}

		iterator erase(iterator pos) {
			Node<T> *p = pos.getp();
			p->next->prev = p->prev;
			p->prev->next = p->next;
			iterator *it = new iterator(p->next);
			if (p == _begin)
				_begin = it->getp();
			delete p;
			_size--;
			return *it;
		}

		iterator erase(iterator first, iterator last) {
			iterator it;
			while (first != last) {
				it = erase(first);
				first = it;
			}
			return it;
		}

		void resize(size_t n, T val = T()) {
			if (n > _size) {
				while (n != _size) {
					push_back(val);
				}
			} else if (_size > n) {
				while (n != _size) {
					pop_back();
				}
			}
		}

		void splice(iterator pos, List<T> &x) {
			if (_size == 0) {
				_begin = x._begin;
				delete _end;
				_end = x._end;
				_size = x._size;
				x._size = 0;
				x._end = new Node<T>();
				x._begin = x._end;
				x._end->next = _begin;
				x._end->prev = _begin;
				return;
			}
			_size += x._size;
			pos.getp()->prev->next = x.begin().getp();
			x.begin().getp()->prev = pos.getp()->prev;
			x.end().getp()->prev->next = pos.getp();
			pos.getp()->prev = x.end().getp()->prev;
			x._begin = x._end;
			x.begin().getp()->next = x.end().getp();
			x.begin().getp()->prev = x.end().getp();
			x._size = 0;
			x.end().getp()->prev = x.begin().getp();
			x.end().getp()->next = x.begin().getp();
		}

		void splice(iterator pos, List<T> &x, iterator i) {
			Node<T> *n;
			n = i.getp();
			n->next->prev = n->prev;
			n->prev->next = n->next;
			if (n == x._begin)
				x._begin = n->next;
			if (pos.getp() == _begin)
				_begin = n;
			pos.getp()->prev->next = n;
			n->prev = pos.getp()->prev;
			n->next = pos.getp();
			pos.getp()->prev = n;
		}

		void splice(iterator pos, List<T> &x, iterator first, iterator last) {
			Node<T> *n;
			first++;
			while (first != last) {
				n = first.getp()->prev;
				first++;
				splice(pos, x, iterator(n));
			}
			n = first.getp()->prev;
			first++;
			splice(pos, x, iterator(n));
		}

		void remove(const T &val) {
			iterator it = begin();

			while (it != end()) {
				if (*it == val)
					it = erase(it);
				else
					it++;
			}
		}

		template<class Predicate>
		void remove_if(Predicate pred) {
			iterator it = begin();

			while (it != end()) {
				if (pred(*it))
					it = erase(it);
				else
					it++;
			}
		}

		template<class BinaryPredicate>
		void unique(BinaryPredicate b_pred) {
			Node<T> *tmp = _begin->next;
			Node<T> *tt = tmp->prev;
			int i = 0;
			while (tmp != _end) {
				if (b_pred(tmp->data, tmp->prev->data)) {
					tmp->prev->next = tmp->next;
					tmp->next->prev = tmp->prev;
					_size--;
					delete tmp;
					tmp = tt->next;
				} else {
					tmp = tmp->next;
					tt = tt->next;
				}
			}

		}

		void merge(List<T> &x) {
			if (&x == this)
				return;
			iterator it = begin();
			iterator ix = x.begin();
			while (it != end()) {
				if (*ix < *it) {
					splice(it, x, ix);
					ix = x.begin();
				} else
					it++;
			}
			splice(end(), x);
		}

		template<class Compare>
		void merge(List<T> &x, Compare comp) {
			if (&x == this)
				return;
			iterator it = begin();
			iterator ix = x.begin();
			while (it != end()) {
				if (comp(*it, *ix)) {
					splice(it, x, ix);
					ix = x.begin();
				} else
					it++;
			}
			splice(end(), x);
		}

		void sort() {
			if (_size == 0 || _size == 1)
				return;
			iterator it = begin();
			int b = 1;
			while (b) {
				b = 0;
				it = begin();
				it++;
				while (it != end()) {
					if (*it < it.getp()->prev->data) {

						b = 1;
						Node<T> *p = it.getp()->prev;
						Node<T> *c = it.getp();
						Node<T> *n = it.getp()->next;
						std::cout << p->data << "  " << c->data << "  " << n->data << std::endl;
						p->prev->next = c;
						c->prev = p->prev;
						n->prev = p;
						p->next = n;
						p->prev = c;
						c->next = p;
						if (p == _begin) {
							_begin = c;
						}
					}
					it++;
				}
			}
		}

		template<class Compare>
		void sort(Compare comp) {
			if (_size == 0 || _size == 1)
				return;
			iterator it = begin();
			int b = 1;
			while (b) {
				b = 0;
				it = begin();
				it++;
				while (it != end()) {
					if (comp(*it, it.getp()->prev->data)) {
						b = 1;
						Node<T> *p = it.getp()->prev;
						Node<T> *c = it.getp();
						Node<T> *n = it.getp()->next;
						std::cout << p->data << "  " << c->data << "  " << n->data << std::endl;
						p->prev->next = c;
						c->prev = p->prev;
						n->prev = p;
						p->next = n;
						p->prev = c;
						c->next = p;
						if (p == _begin) {
							_begin = c;
						}
					}
					it++;
				}
			}
		}

		void swap(List<T> &x) {
			List<T> *tmp = new List<T>();
			tmp->splice(tmp->begin(), x);
			x.splice(x.begin(), *this);
			splice(begin(), *tmp);
		}

		size_t max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(T));
		}
	};
}

#endif






























