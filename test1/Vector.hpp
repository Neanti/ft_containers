#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft {

	template<class T>
	class VecIterator {
	protected:
		T *p;
	public:
		VecIterator() : p(0) {
			return;
		}

		VecIterator(T *p) : p(p) {
			return;
		}

		VecIterator(const VecIterator<T> &it) {
			p = it.p;
			return;
		}

		T getData(void) const {
			return *p;
		}

		bool operator!=(const VecIterator<T> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return (*p);
		}

		VecIterator<T> &operator++() {
			p += 1;
			return *this;
		}

		VecIterator<T> operator++(int) {
			VecIterator<T> tmp = *this;
			p += 1;
			return tmp;
		}

		VecIterator<T> &operator--() {
			p -= 1;
			return *this;
		}

		VecIterator<T> operator--(int) {
			VecIterator<T> tmp = *this;
			p -= 1;
			return tmp;
		}

		void setp(T *p) {
			this->p = p;
			return;
		}

		T *getp() {
			return p;
		}

		T *getp() const {
			return p;
		}

	};

	template<class T>
	std::ostream &operator<<(std::ostream &output, const VecIterator<T> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}

	template<class T>
	class ConstVecIterator {
	protected:
		T *p;
	public:
		ConstVecIterator() : p(0) {
			return;
		}

		ConstVecIterator(T *p) : p(p) {
			return;
		}

		ConstVecIterator(const ConstVecIterator<T> &it) {
			p = it.p;
			return;
		}

		ConstVecIterator(const VecIterator<T> &it) {
			p = it.getp();
			return;
		}

		T getData(void) const {
			return *p;
		}

		bool operator!=(const ConstVecIterator<T> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return (*p);
		}

		ConstVecIterator<T> &operator++() {
			p += 1;
			return *this;
		}

		ConstVecIterator<T> operator++(int) {
			ConstVecIterator<T> tmp = *this;
			p += 1;
			return tmp;
		}

		ConstVecIterator<T> &operator--() {
			p -= 1;
			return *this;
		}

		ConstVecIterator<T> operator--(int) {
			ConstVecIterator<T> tmp = *this;
			p -= 1;
			return tmp;
		}

		void setp(T *p) {
			this->p = p;
			return;
		}

		T *getp() {
			return p;
		}

	};

	template<class T>
	std::ostream &operator<<(std::ostream &output, const ConstVecIterator<T> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}
	
	template<class T>
	class RevVecIterator {
	protected:
		T *p;
	public:
		RevVecIterator() : p(0) {
			return;
		}

		RevVecIterator(T *p) : p(p) {
			return;
		}


		RevVecIterator(const RevVecIterator<T> &it) {
			p = it.p;
			return;
		}

		T getData(void) const {
			return *p;
		}

		bool operator!=(const RevVecIterator<T> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return *p;
		}

		RevVecIterator<T> &operator--() {
			p += 1;
			return *this;
		}

		RevVecIterator<T> operator--(int) {
			RevVecIterator<T> tmp = *this;
			p += 1;
			return tmp;
		}

		RevVecIterator<T> &operator++() {
			p -= 1;
			return *this;
		}

		RevVecIterator<T> operator++(int) {
			RevVecIterator<T> tmp = *this;
			p -= 1;
			return tmp;
		}

		void setp(T *p) {
			this->p = p;
			return;
		}

		T *getp() {
			return p;
		}

		T *getp() const {
			return p;
		}

	};

	template<class T>
	std::ostream &operator<<(std::ostream &output, const RevVecIterator<T> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}

	template<class T>
	class ConstRevVecIterator {
	protected:
		T *p;
	public:
		ConstRevVecIterator() : p(0) {
			return;
		}

		ConstRevVecIterator(T *p) : p(p) {
			return;
		}


		ConstRevVecIterator(const ConstRevVecIterator<T> &it) {
			p = it.p;
			return;
		}

		ConstRevVecIterator(const RevVecIterator<T> &it) {
			p = it.getp();
			return;
		}


		T getData(void) const {
			return *p;
		}

		bool operator!=(const ConstRevVecIterator<T> &it) {
			if (this->p != it.p)
				return (true);
			return false;
		}

		const T &operator*() const {
			return *p;
		}

		ConstRevVecIterator<T> &operator--() {
			p += 1;
			return *this;
		}

		ConstRevVecIterator<T> operator--(int) {
			ConstRevVecIterator<T> tmp = *this;
			p += 1;
			return tmp;
		}

		ConstRevVecIterator<T> &operator++() {
			p -= 1;
			return *this;
		}

		ConstRevVecIterator<T> operator++(int) {
			ConstRevVecIterator<T> tmp = *this;
			p -= 1;
			return tmp;
		}

		void setp(T *p) {
			this->p = p;
			return;
		}

		T *getp() {
			return p;
		}

	};

	template<class T>
	std::ostream &operator<<(std::ostream &output, const ConstRevVecIterator<T> in) {
		std::cout << in.getData() << std::endl;
		return output;
	}
	
	template<class T, class Alloc = std::allocator <T> >
	class Vector {
	private:
		T *data;
		Alloc alloc;
		size_t _size;
		size_t _capacity;

		void check_size(int n) {

			if (_size + n > _capacity) {
				T *tmp;
				size_t cap = _capacity;
				if (_capacity == 0) {
					tmp = alloc.allocate(1);
					_capacity = 1;
				} else {
					tmp = alloc.allocate(2 * _capacity);
					_capacity = 2 * _capacity;

				}
				int i = 0;
				while (i < _size) {
					tmp[i] = data[i];
					i++;
				}
				alloc.deallocate(data, cap);
				data = tmp;
			}
			if (_size + n > _capacity)
				check_size(n);
		}

	public:

		typedef VecIterator<T> iterator;
		typedef RevVecIterator<T> reverse_iterator;
		typedef ConstRevVecIterator<T> const_reverse_iterator;
		typedef ConstVecIterator<T> const_iterator;

		void print() {
			int i = 0;
			while (i < _size) {
				std::cout << "data[" << i << "]=" << data[i] << std::endl;
				i++;
			}
		}

		~Vector() {
			alloc.deallocate(data, _capacity);
		}

		Vector() {
			_size = 0;
			_capacity = 0;
			data = 0;
		}

		Vector(size_t n, const T &val = T(), const Alloc &alloc = Alloc())
		{
			_size = 0;
			_capacity = 0;
			data = 0;

			while (n != _size)
			{
				push_back(val);
			}
		}

		Vector(iterator first, iterator last, const Alloc &alloc = Alloc())
		{
			_size = 0;
			_capacity = 0;
			data = 0;

			while(first != last)
			{
				push_back(*first);
				first++;
			}
		}

		Vector(const Vector<T> &x)
		{
			_size = 0;
			_capacity = 0;
			data = 0;

			iterator it = x.begin();
			while(it != x.end())
			{
				push_back(*it);
				it++;
			}
		}

		Vector<T> &operator=(const Vector<T> &x)
		{
			if (_capacity > 0)
				alloc.deallocate(data, _capacity);
			_size = 0;
			_capacity = 0;
			data = 0;

			iterator it = x.begin();
			while(it != x.end())
			{
				push_back(*it);
				it++;
			}
		}

		void push_back(const T &val) {
			check_size(1);
			data[_size] = val;
			_size++;
		}

		size_t size() const {
			return _size;
		}

		size_t capacity() const {
			return _capacity;
		}

		iterator begin() {
			return (iterator(data));
		}

		const_iterator begin() const{
			return (const_iterator(data));
		}

		iterator end() {
			return (iterator(&(data[_size])));
		}

		const_iterator end() const {
			return (const_iterator(&(data[_size])));
		}

		reverse_iterator rbegin() {
			return (reverse_iterator(&(data[_size - 1])));
		}

		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(&(data[_size - 1])));
		}

		reverse_iterator rend() {
			return (reverse_iterator(data - 1));
		}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(data - 1));
		}

		bool empty() const {
			if (_size == 0)
				return true;
		}

		void reserve(size_t n) {
			int i;
			i = n - _size;
			check_size(i);
		}

		size_t max_size() const {
			return (std::numeric_limits<size_t>::max() / sizeof(T));
		}

		void resize(size_t n, T val = T()) {
			if (n == _size)
				return;
			else if (n < _size) {
				_size = n;
			} else {
				while (n != _size) {
					push_back(val);
				}
			}
		}

		T &operator[](size_t i)
		{
			return (data[i]);
		}

		T &at(size_t n)
		{
			return (data[n]);
		}

		T &front()
		{
			return (data[0]);
		}

		T &back()
		{
			return (data[_size - 1]);
		}

		void assign(iterator it, iterator end)
		{
			if (_capacity > 0)
				alloc.deallocate(data, _capacity);
			_size = 0;
			_capacity = 0;
			data = 0;

			while(it != end)
			{
				push_back(*it);
				it++;
			}
		}

		void assign(size_t n, const T &val)
		{
			if (_capacity > 0)
				alloc.deallocate(data, _capacity);
			_size = 0;
			_capacity = 0;
			data = 0;

			while(n != _size)
			{
				push_back(val);
			}
		}

		void pop_back()
		{
			_size--;
		}

		T const &front() const
		{
			return (data[0]);
		}

		T const &back() const
		{
			return (data[_size - 1]);
		}

		void clear()
		{
			if (_capacity > 0)
				alloc.deallocate(data, _capacity);
			_size = 0;
			_capacity = 0;
			data = 0;
		}

		void swap(Vector<T> &x)
		{
			size_t tmp1;
			size_t tmp2;
			T* tmp_data;

			tmp1 = _capacity;
			tmp2 = _size;
			tmp_data = data;
			data = x.data;
			_capacity = x._capacity;
			_size = x._size;
			x._capacity = tmp1;
			x._size = tmp2;
			x.data = tmp_data;
			return;
		}

		iterator insert(iterator pos, const T &val)
		{
			iterator it = begin();
			int i = 0;
			while(it != pos)
			{
				i++;
				it++;
			}
			check_size(1);
			T tmp = data[i];
			T next;
			data[i] = val;
			it = iterator(data + i);
			_size++;
			i++;
			while(i < _size)
			{
				next = data[i];
				data[i] = tmp;
				tmp = next;
				i++;
			}
			return it;
		}

		void insert(iterator pos, size_t n, const T &val)
		{
			iterator it = pos;
			while(n > 0)
			{
				it = insert(it, val);
				n--;
			}
			return ;
		}

		void insert(iterator pos, iterator deb, iterator fin)
		{
			iterator it = pos;

			while(deb != fin)
			{
				it = insert(it, *deb);
				deb++;
			}
		}

		iterator erase(iterator pos)
		{

			iterator it = begin();
			int i = 0;

			while(it != pos)
			{
				it++;
				i++;
			}

			while(i != _size - 1)
			{
				data[i] = data[i + 1];
				i++;
			}
			_size--;
			return it;
		}

		iterator erase(iterator deb, iterator fin)
		{
			while(deb != fin)
			{
				deb = erase(deb);
				fin--;
			}
			return deb;
		}
	};

	template<class T, class Alloc>
	bool operator==(const Vector<T, Alloc> &lhs, const Vector<T, Alloc>& rhs)
	{
		typename ft::Vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::Vector<T>::const_iterator it_rhs = rhs.begin();

		if (rhs.size() != lhs.size())
			return (false);
		while(it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs)
		{
			it_lhs++;
			it_rhs++;
		}
		return (it_lhs == lhs.end() && it_rhs == rhs.end());
	}

	template<class T, class Alloc>
	bool operator!=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool operator<(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
	{
		typename ft::Vector<T>::const_iterator it_lhs = lhs.begin();
		typename ft::Vector<T>::const_iterator it_rhs = rhs.begin();

		if (lhs == rhs)
			return (false);
		while(it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs)
		{
			it_lhs++;
			it_rhs++;
		}

		if (it_rhs != rhs.end())
			return true;
		return false;
	}

	template<class T, class Alloc>
	bool operator<=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}

	template<class T, class Alloc>
	bool operator>(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
	{
		if (lhs == rhs)
			return false;
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	bool operator>=(const Vector<T, Alloc>& lhs, const Vector<T, Alloc>& rhs)
	{
		if (lhs == rhs)
			return true;
		return (!(lhs < rhs));
	}

	template<class T, class Alloc>
	void swap(Vector<T, Alloc>& x, Vector<T, Alloc>& y)
	{
		x.swap(y);
	}

}

#endif
