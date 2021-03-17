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
#include "VectorIterator.hpp"
#include "Node.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> > 
	class Vector {

		public:

			// ALIASES:

			typedef T 													value_type;
			typedef Node<value_type> 									node_type;
			typedef std::allocator<node_type> 							allocator_type;
			typedef allocator_type 										node_allocator;
			typedef value_type											&reference;
			typedef value_type const	 								&const_reference;
			typedef node_type 											*pointer;
			typedef node_type const	 									*const_pointer;
			typedef VectorIterator<value_type > 						iterator;
			typedef VectorIterator<value_type const > 					const_iterator;
			typedef VectorReverse_Iterator<value_type > 				reverse_iterator;
			typedef VectorReverse_Iterator<value_type const > 			const_reverse_iterator;
			// typedef typename difference_type Iterator_traits<Iterator>::difference_type;
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
			
			// // >>> copy 
			Vector (const Vector& x) {
				//std::cout << "COPYING" << std::endl;
				_container = NULL;
				_size = 0;
				_capacity = 0;

		 		assign(x.begin(), x.end());

			}; 

			Vector& operator= (const Vector& x) {
				//std::cout << "IN OP=" << std::endl;
				clear();

				assign(x.begin(), x.end());

				return *this;
			}; //destroy all content then copy


			//----------------------------------------------


			//DESTRUCTOR:

			~Vector() { 
				clear(); 
				// if (_container)
				// 	delete[] _container;
				
				//delete[] _containerPtr; 
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

				return (std::numeric_limits<size_type>::max() / (sizeof(node_type)));
			};
			//returns max nb of elements Vector can hold, due to system or library limitations

	// 		void resize (size_type n, value_type val = value_type()) {

	// 			node_type *tmp = _begin;
	// 			node_type *next;
	// 			size_type i = 0;

	// 			if (_size > n) {
	// 				while (i++ < n)
	// 					tmp = tmp->getNext();
	// 				while (i++ <= _size) {
	// 					next = tmp->getNext();
	// 					tmp->delNode();
	// 					tmp = next;
	// 				}
	// 			}
	// 			else if (_size < n) {
	// 				iterator it = this->end();
	// 				i = _size;
	// 				while (i++ < n)
	// 					it = insert(it, val);
	// 			}
	// 			_size = n;

	// 			_begin = _end->getBegin();
	// 			_end->setEnd();
	// 		};
	// 		//either removes elements beyond n elements or add elements until container size is n 

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

				size_type newCapacity = _capacity;
				
				//MUST CHECK THIS
				// if (n > 128)
				// 	n = 128;
				if (newCapacity == 0)
					newCapacity = n;
				while (n > newCapacity)
					newCapacity *= 2;

				value_type *newVector = new value_type[newCapacity]();

				for (size_type i = 0; i < _size; i++) {
					newVector[i] = _container[i];
					// *newIt = *oldIt;
					// newIt++;
					// oldIt++;
				}
				if (_capacity)
					delete[] _container;
				_container = newVector;

				_capacity = newCapacity;
			};
			// requests that the vector capacity be at least enough to contain n elements, reallocate if needed.

	// 		//----------------------------------------------


	// 		// ELEMENT ACCESS:
			//reference operator[] (size_type n);
			//const_reference operator[] (size_type n) const;

			// reference at (size_type n);
			// const_reference at (size_type n) const;

	// 		reference front() {

	// 			return _begin->getValue();
	// 		};

	// 		const_reference front() const{

	// 			return _begin->getValue();
	// 		};
	// 		//same as begin() but returns a reference

	// 		reference back() {

	// 			if (size())
	// 				return _end->getPrev()->getValue();
	// 			return _end->getValue();
	// 		};

	// 		const_reference back() const{

	// 			if (size())
	// 				return _end->getPrev()->getValue();
	// 			return _end->getValue();
	// 		};
	// 		//returns a reference to the last Vector element(not after it)


	// 		//----------------------------------------------
			

	// 		// MODIFIERS

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

				// clear();
				// reserve(n);

				// while (_size < n) 
				// 	push_back(val);

				clear();
				reserve(n);
				while (_size < n) {
					push_back(val);
				}
			};
	// 		//Assigns new contents to the Vector container, replacing its current contents, and modifying its size accordingly.

			void push_back (const value_type& val) { 

				// iterator it = iterator(_containerPtr);
				// std::cout << "push back bef reserve" << std::endl;
				// for (size_t i = 0; i < _size; i++) {
				// 	std::cout << *it << std::endl;
				// 	it++;
				// }
				reserve(_size + 1);
				// it = iterator(_containerPtr);
				// std::cout << "push back aft reserve" << std::endl;
				// for (size_t i = 0; i < _size; i++) {
				// 	std::cout << *it << std::endl;
				// 	it++;
				// }
				_container[_size] = val;
				_size++;
				//_end->setEnd();
			};
			//Adding elements to a vector = adding nodes before end. 

	// 		void pop_back() {

	// 			if (_size == 1) { //case 1 = Node1 endNode 
	// 				_begin->delNode();//last node = Node1
	// 				_size--;
	// 			}
	// 			else if (_size > 1) { //case 2 = Node1 Node2 Node3 endNode
	// 				_end->getPrev()->delNode();//delete Node3
	// 				_size--;
	// 			}

	// 			_begin = _end->getBegin();
	// 			_end->setEnd();
	// 		};
	// 		//remove & destroy last element

			iterator insert (iterator position, const value_type& val) {
				
				reserve(_size + 1);
				iterator it = begin();
				size_type index = 0;
				if (position != it)
					while (++it != position)
						index++;
				
				iterator ret = it;
				value_type stockNext;//stockNext = c
				value_type stock = *it;//stock = b
	
                           //a b d e
					_container[index++] = val; //1 2 3 4
				while (index <= _size) {//pos = 3
					stockNext = _container[index];
					_container[index++] = stock;

					stock = stockNext;
					//prev = stock;
				}
				_container[index++] = stock;
				_size++;

				return ret;

			}; 
			//remove 1 element
    		
			// >>> fill
			void insert (iterator position, size_type n, const value_type& val) {

				reserve(_size + n);
				iterator it = begin();
				while (it != position)
					it++;

				for (size_type i = 0; i < n; i++)
					it = insert(it, val);
			};
			
			// >>> range
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last) {

				reserve(_size + (last - first));
				iterator it = begin();
				while (it != position)
					it++;

				while (first != last) {
					insert(it, *first);
					first++;
				}

			};
    		//Extend the container by inserting new elements before the element at the specified position

	// 		iterator erase (iterator position) {
				
	// 			iterator ret = iterator(position.getNode()->getNext());
				
	// 			position.getNode()->delNode();
	// 			_size--;

	// 			_begin = _end->getBegin();
	// 			_end->setEnd();
	// 			return ret;
	// 		};
			
	// 		iterator erase (iterator first, iterator last) {

	// 			iterator ret = iterator(last.getNode()->getNext());

	// 			if (last.getNode() == _end)
	// 				ret = this->end();

	// 			while (first != last)
	// 				erase(first++);

	// 			_begin = _end->getBegin();
	// 			_end->setEnd();
	// 			return ret;
	// 		};
	// 		// remove & destroy either 1 element or a range of elements. 

	// 		void swap (Vector& x) {

	// 			node_type *tmp;
	// 			int sz = _size;

	// 			tmp = _begin;
	// 			_begin = x._begin;
	// 			x._begin = tmp;

	// 			tmp = _end;
	// 			_end = x._end;
	// 			x._end = tmp;

	// 			_size = x._size;
	// 			x._size = sz;
	// 		};
	// 		//exchange content with container of the same type

	
			void clear() {
				
				// iterator it = iterator(_begin);
				//int a = 0;
				for (size_type i = 0; i < _size; i++) {
					_container[i] = value_type();
					// _container[i].forgetValue();
					// _container[i].forgetNode();
				}
				_size = 0;
			};
	// 		//removes all elements (size == 0)
			

		private:

			//pointer 			_containerPtr;
			value_type 			*_container;

			size_type 			_size;
			size_type 			_capacity;
			node_allocator 		_node_allocator;
			
	};
	
	
	// //----------------------------------------------		


	// //NON MEMBER FUNCTION OVERLOADS

	// template < class T, class Alloc>
	// bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
	
	// 	if (lhs.size() != rhs.size())
	// 		return false;

	// 	Iterator< const T, const Node<T> > lhsIt = lhs.begin();
	// 	Iterator< const T, const Node<T> > rhsIt = rhs.begin();
		
	// 	size_t i = 0;

	// 	while (i++ != lhs.size()) {
	// 		if (*lhsIt != *rhsIt)
	// 			return false;
	// 		lhsIt++;
	// 		rhsIt++;
	// 	}

	// 	return true;
	// };

	// template <class T, class Alloc>
	// bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	// 	if (rhs == lhs)
	// 		return false;

	// 	return true;
	// };

	// template <class T, class Alloc>
	// bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	// 	if (lhs.size() > rhs.size())
	// 	 	return false;

	// 	Iterator< const T, const Node<T> > lhsIt = lhs.begin();
	// 	Iterator< const T, const Node<T> > rhsIt = rhs.begin();
	
	// 	size_t i = 0;
	// 	while (i != lhs.size() && i != rhs.size()) {
	// 		if (*lhsIt < *rhsIt)
	// 			return true;
	// 		lhsIt++;
	// 		rhsIt++;
	// 		i++;
	// 	}
		
	// 	return false;
	// };

	// template <class T, class Alloc>
	// bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	// 	if (lhs == rhs)
	// 		return true;

	// 	return (lhs < rhs);
	// };

	// template <class T, class Alloc>
	// bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {
	
	// 	if (lhs.size() < rhs.size())
	// 		return false;

	// 	Iterator< const T, const Node<T> > lhsIt = lhs.begin();
	// 	Iterator< const T, const Node<T> > rhsIt = rhs.begin();
	
	// 	size_t i = 0;
	// 	while (i != lhs.size() && i != rhs.size()) {
	// 		if (*lhsIt > *rhsIt)
	// 			return true;
	// 		lhsIt++;
	// 		rhsIt++;
	// 		i++;
	// 	}
		
	// 	return false;
	// };

	// template <class T, class Alloc>
	// bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs) {

	// 	if (lhs == rhs)
	// 		return true;

	// 	return (lhs > rhs);
	// };

	// template <class T, class Alloc>
  	// void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y) {

	// 	  x.swap(y);
	// };

};

#endif