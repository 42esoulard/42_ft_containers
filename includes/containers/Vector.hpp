/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/13 16:36:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <limits>
#include <iostream>

namespace ft {

	template < class value_type >
	class VectorIterator {

		public:

			VectorIterator() {value_type *tmp = NULL; p = tmp;};
			VectorIterator(value_type *x) :p(x) {};
			VectorIterator(const VectorIterator& mit) : p(mit.p) {};

			VectorIterator& operator++() {
				++p;
				return *this;
			};

			VectorIterator operator++(int) {VectorIterator tmp(*this); operator++(); return tmp;};
			VectorIterator const operator++(int) const {VectorIterator tmp(*this); operator++(); return tmp;};

			// node_type *getNode() {return p;};

			bool operator==(const VectorIterator& rhs) const {return p==rhs.p;};
			bool operator!=(const VectorIterator& rhs) const {return p!=rhs.p;};
			value_type &operator*() const {return *p;};

		private:

			value_type* p;
	};

	template < class value_type >
	class VectorReverse_Iterator : public VectorIterator<value_type > {

		public:
			VectorReverse_Iterator() {value_type *tmp = NULL; p = tmp;};
			VectorReverse_Iterator(value_type *x) :p(x) {};
			VectorReverse_Iterator(const VectorReverse_Iterator& mit) : p(mit.p) {};

			VectorReverse_Iterator< value_type >& operator++() {--p;return *this;};
			VectorReverse_Iterator< value_type > operator++(int) {VectorReverse_Iterator<value_type > tmp(*this); operator++(); return tmp;};
			bool operator==(const VectorReverse_Iterator< value_type >& rhs) const {return p==rhs.p;}
			bool operator!=(const VectorReverse_Iterator< value_type >& rhs) const {return p!=rhs.p;}
			value_type &operator*() const {return *p;};

		private:

			value_type* p;
	};

	//************************************************************************************************

	template < class T, class Alloc = std::allocator<T> > 
	class Vector {

		public:

			// ALIASES:

			typedef T 													value_type;
			typedef value_type											&reference;
			typedef value_type const	 								&const_reference;
			typedef value_type 											*pointer;
			typedef value_type const	 								*const_pointer;
			typedef VectorIterator<value_type > 						iterator;
			typedef VectorIterator<value_type const > 					const_iterator;
			typedef VectorReverse_Iterator<value_type > 				reverse_iterator;
			typedef VectorReverse_Iterator<value_type const > 			const_reverse_iterator;
			typedef std::ptrdiff_t 										difference_type;
			typedef unsigned long  										size_type;
			

			//----------------------------------------------


			// CONSTRUCTORS:

			// >>> default
			explicit Vector () {

				_container = NULL;
				_size = 0;
				_capacity = 0;
			};

			// >>> fill
			explicit Vector (size_type n, const value_type& val = value_type()) {

				_container = NULL;
				_size = 0;
				_capacity = 0;

				assign(n, val);
			};

			// >>> range
			template <class InputIterator>
		 	Vector (InputIterator first, InputIterator last)  {

		 		_container = NULL;
				_size = 0;
				_capacity = 0;

		 		assign(first, last);
		 	};	
			
			// >>> copy 
			Vector (const Vector& x) {

				_container = NULL;
				_size = 0;
				_capacity = 0;

		 		assign(x.begin(), x.end());
			}; 

			Vector& operator= (const Vector& x) {

				clear();
				assign(x.begin(), x.end());

				return *this;
			}; 
			//destroy all content then copy


			//----------------------------------------------


			//DESTRUCTOR:

			~Vector() { 

				clear(); 
				if (_container)
					delete[] _container;
			};


			//----------------------------------------------


	// 		//ITERATORS:

			iterator 		begin() {

				return iterator(_container);
			};

			const_iterator 	begin() const{

				return const_iterator(_container);
			};

			iterator end(){

				return iterator(&_container[_size]);
			};

			const_iterator end() const{
				
				return const_iterator(&_container[_size]);
			};
			// points after last Vector element

			reverse_iterator rbegin() {

				if (_size)
					return (reverse_iterator(&_container[_size - 1]));
				return (reverse_iterator(&_container[_size]));
			};

			const_reverse_iterator rbegin() const {

				if (_size)
					return (const_reverse_iterator(&_container[_size - 1]));
				return (const_reverse_iterator(&_container[_size]));
			};
			// point to last element, incrementing actually decrements

			reverse_iterator rend() {

				return (reverse_iterator(_container));
			};

			const_reverse_iterator rend() const {

				return (const_reverse_iterator(_container));
			};
			// point to hypothetical element BEFORE first element


	// 		//----------------------------------------------


	// 		//SIZE:

			size_type size() const {

				return _size;
			};

			size_type max_size() const {

				size_type maxDiff = std::numeric_limits<difference_type>::max();
				size_type maxVal = std::numeric_limits<size_type>::max() / (sizeof(value_type));

				if (maxDiff < maxVal)
					return maxDiff;
				return maxVal;
			};
			//returns max nb of elements Vector can hold, due to system or library limitations

			void resize (size_type n, value_type val = value_type()) {

				reserve(n);

				size_type i = 0;
				if (_size > n) {
					while (i < n)
						i++;
					while (i < _size)
						_container[i++] = value_type();
				}
				else if (_size < n) {
					iterator it = this->end();
					it++;
					i = _size;

					while (++i < n)
						it = insert(it, val);		
				}
				_size = n;
			};
			//either removes elements beyond n elements or add elements until container size is n 

			size_type capacity() const {

				return _capacity;
			};

			bool empty() const {

				if (_size == 0)
					return true;
				return false;
			}

			void reserve (size_type n) {

				if (n <= _capacity)
					return;

				value_type *newVector = new value_type[n]();
				for (size_type i = 0; i < _size; i++)
					newVector[i] = _container[i];
			
				if (_capacity)
					delete[] _container;

				_container = newVector;
				_capacity = n;
			};
			// requests that the vector capacity be at least enough to contain n elements, reallocate if needed.


			//----------------------------------------------


			// ELEMENT ACCESS:
			reference operator[] (size_type n) {

				return _container[n];
			};

			const_reference operator[] (size_type n) const {

				return _container[n];
			};

			reference at (size_type n){

				if (n >= _size)
					throw std::out_of_range("vector");
				return _container[n];
			};

			const_reference at (size_type n) const {

				if (n >= _size)
					throw std::out_of_range("vector");
				return _container[n];
			};

			reference front() {

				return _container[0];
			};

			const_reference front() const{

					return _container[0];
			};
			//same as begin() but returns a reference

			reference back() {

				return _container[_size - 1];
			};

			const_reference back() const{

				return _container[_size - 1];
			};
			//returns a reference to the last Vector element(not after it)


			//----------------------------------------------
			

			// MODIFIERS

			// >>> range
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last) {

				clear();

  				while (first != last) {
		 			push_back(*first);
		 			first++;
		 		}
  			};

			// >>> fill
			void assign (size_type n, const value_type& val) {

				clear();

				if (n > _capacity && n < _capacity * 2)
					n = 2 * _capacity;
				reserve(n);

				while (_size < n)
					push_back(val);
			};
			//Assigns new contents to the Vector container, replacing its current contents, and modifying its size accordingly.

			void push_back (const value_type& val) { 

				size_t n = _size + 1;
				if (n > _capacity && n < _capacity * 2)
					n = 2 * _capacity;
				reserve(n);

				_container[_size] = val;
				_size++;
			};
			//Adding elements to a vector = adding nodes before end. 

			void pop_back() {

				if (_size) {
					_container[_size - 1] = value_type();
					_size--;
				}
			};
			//remove & destroy last element

			iterator insert (iterator position, const value_type& val) {

				iterator it = begin();
				size_type index = 0;
				if (position != it)
					while (it++ != position)
						index++;
				
				size_t n = _size + 1;
				if (n > _capacity && n < _capacity * 2)
					n = 2 * _capacity;
				reserve(n);

				value_type stockNext;
				iterator ret = iterator(&_container[index]);
				value_type stock = *ret;
                    
				_container[index++] = val;
				while (index < _size) {
					stockNext = _container[index];
					_container[index++] = stock;
					stock = stockNext;
				}
				if (_size)
					_container[index++] = stock;
				_size++;

				return ret;
			}; 

			// >>> fill
			void insert (iterator position, size_type n, const value_type& val) {

				iterator it = begin();
				size_type index = 0;
				if (position != it)
					while (it++ != position)
						index++;

				size_t newCap = _size + n;
				if (newCap > _capacity && newCap < _capacity * 2)
					newCap = 2 * _capacity;
				reserve(newCap);

				it = begin();
				for (size_t i = 0; i < index; i++)
					it++;
				for (size_type i = 0; i < n; i++)
					it = insert(it, val);
			};
			
			// >>> range
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last) {

				iterator it = begin();
				size_type index = 0;
				if (position != it)
					while (it++ != position)
						index++;
				
				iterator tmp = first;
				size_type n = _size;
				while (tmp++ != last)
					n++;
				if (n > _capacity && n < _capacity * 2)
					n = 2 * _capacity;
				value_type *newContainer = new value_type[n]();

				size_type cursor = 0;
				while (cursor != index) {
					newContainer[cursor] = _container[cursor];
					cursor++;
				}
				while (first != last) {
					newContainer[cursor++] = *first;
					first++;
				}
				while (index != _size) 
					newContainer[cursor++] = _container[index++];
				
				delete[] _container;
				_container = newContainer;
				_size = cursor;
			};
    		//Extend the container by inserting new elements before the element at the specified position

			iterator erase (iterator position) {
				
				iterator it = begin();
				size_type index = 0;
				if (position != it)
					while (it++ != position)
						index++;

				size_type cursor = 0;
				while (cursor != index)
					cursor++;
	
				it = iterator(&_container[cursor]);
				while (cursor < _size - 1) {
					_container[cursor] = _container[cursor + 1];
					cursor++;
				}
				_container[cursor] = value_type();
				_size--;

				return it;
			};
			
			iterator erase (iterator first, iterator last) {

				iterator it = begin();
				size_type index = 0;
				if (first != it)
					while (it++ != first)
						index++;

				iterator tmp = first;
				size_t step = 0;
				while (tmp++ != last)
					step++;

				it = iterator(&_container[index]);

				if (_size) {
					while (index < _size) {
						if (index + step < _size)
							_container[index] = _container[index + step];
						else
							_container[index] = value_type();
						index++;
					}
				}
				_size -= step;
				return it;
			};
			// remove & destroy either 1 element or a range of elements. 

			void swap (Vector& x) {

				value_type *tmp = x._container;
				size_type sz = x._size;
				size_type ca = x._capacity;

				x._container = _container;
				x._size = _size;
				x._capacity = _capacity;

				_container = tmp;
				_size = sz;
				_capacity = ca;
			};
			//exchange content with container of the same type

	
			void clear() {
				
				for (size_type i = 0; i < _size; i++)
					_container[i] = value_type();

				_size = 0;
			};
			//removes all elements (size == 0)
			

		private:

			value_type 			*_container;
			size_type 			_size;
			size_type 			_capacity;
			
	};
	
	
	//----------------------------------------------		


	//NON MEMBER FUNCTION OVERLOADS

	template < class T, class Alloc>
	bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
	
		if (lhs.size() != rhs.size())
			return false;

		VectorIterator< const T > lhsIt = lhs.begin();
		VectorIterator< const T > rhsIt = rhs.begin();
		
		size_t i = 0;

		while (i++ != lhs.size()) {
			if (*lhsIt != *rhsIt)
				return false;
			lhsIt++;
			rhsIt++;
		}

		return true;
	};

	template <class T, class Alloc>
	bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

		if (rhs == lhs)
			return false;

		return true;
	};

	template <class T, class Alloc>
	bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

		if (lhs.size() > rhs.size())
		 	return false;

		VectorIterator< const T > lhsIt = lhs.begin();
		VectorIterator< const T > rhsIt = rhs.begin();
	
		size_t i = 0;
		while (i != lhs.size() && i != rhs.size()) {
			if (*lhsIt < *rhsIt)
				return true;
			lhsIt++;
			rhsIt++;
			i++;
		}
		
		return false;
	};

	template <class T, class Alloc>
	bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

		if (lhs == rhs)
			return true;

		return (lhs < rhs);
	};

	template <class T, class Alloc>
	bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
	
		if (lhs.size() < rhs.size())
			return false;

		VectorIterator< const T > lhsIt = lhs.begin();
		VectorIterator< const T > rhsIt = rhs.begin();
	
		size_t i = 0;
		while (i != lhs.size() && i != rhs.size()) {
			if (*lhsIt > *rhsIt)
				return true;
			lhsIt++;
			rhsIt++;
			i++;
		}
		
		return false;
	};

	template <class T, class Alloc>
	bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

		if (lhs == rhs)
			return true;

		return (lhs > rhs);
	};

	template <class T, class Alloc>
  	void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y) {

		  x.swap(y);
	};

};

#endif