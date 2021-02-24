#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

namespace ft {

	template<class T>
	struct Node {
		Node<T> *next;
		Node<T> *prev;
		T		data;
	};

	template<class T, class N>
	class ListIterator {
	protected:
		N* p;
	public:
		ListIterator() : p(0) {
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
			N tmp;
			p = p->next;
			return tmp;
		}

		ListIterator<T, N> &operator--() {
			p = p->prev;
			return ;
		}

		ListIterator<T, N> operator--(int) {
			N tmp;
			p = p->prev;
			return tmp;
		}

		void setp(N* p)
		{
			this->p = p;
			return;
		}

	};

	template<class T, class N>
	std::ostream &operator<<(std::ostream &output, const ListIterator<T,N> in){
		std::cout << in.getData() << std::endl;
		return output;
	}










	template<class T>
	class List {
	private:
		Node<T> *_begin;
		Node<T> *_end;
		unsigned long _size;
	public:
		typedef ListIterator<T, Node<T> > iterator;
		List() {
			_size = 0;
			_begin = 0;
			_end = 0;
			return;
		}
		List(unsigned long n, T value) {

		}
		//List iterator debut, fin
		List(const List<T> &x);
		~List();
		List<T> &operator=(const List<T> &x);

		//ITERATORS FNCTION

		iterator begin() {
			iterator *it = new ListIterator<T, Node<T> >;
			it->setp(_begin);
			return *it;
		}

		iterator end() {
			iterator *it = new ListIterator<T, Node<T> >;
			it->setp(_end);
			return *it;
		}

		bool empty(void) const {
			if (_size == 0)
				return true;
			else
				return false;
		}

		unsigned long size(void) const {
			return _size;
		}

		unsigned int max_size(void); // voir

		T& front(void) {
			return _begin->data;
		}
		const T& front(void) const {
			return _begin->data;
		}
		T& back(void) {
			return _end->prev->data;
		}
		const T& back(void) const {
			return _end->prev->data;
		}

		//assign iterator deb, fin;
		void assign(unsigned int n, const T& val);
		void push_front(const T& val) {
			Node<T> *a = new Node<T>;
			a->data = val;
			a->prev = 0;
			a->next = _begin;
			this->_begin = a;
			_size++;
			return;
		}
		void pop_front() {
			Node<T> *a;

			if (_begin == 0)
				return;
			a = _begin;
			_size--;
			_begin = a->next;
			delete a;
		}
		void push_back(const T& val) {
			_size++;
			Node <T> *a = new Node<T>;

			a->next = _end;
			a->data = val;

		}

		void pop_back();
		//insert *3
		//erase*2
		void swap(List<T> &x);
		//resize voir value_type(); constructor
		void clear();
		//splice *3
		void remove(const T& val);
		//remove_if voir predicated
		void unique();
		//unique predicated
		void merge(List<T>& x);
		//merge class compare ?
		void sort();
		//sort class Compare ?s
		void reverse();
		//relation et swap
	};
}

#endif
