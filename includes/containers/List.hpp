/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/30 17:28:48 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include <limits>
#include <iostream>
#include "ListNode.hpp"
#include "Iterator.hpp"

namespace ft {

	template < class value_type, class node_type >
	class ListIterator {

		public:

			ListIterator() {node_type tmp = node_type(); p = &tmp;};
			ListIterator(node_type *x) :p(x) {};
			ListIterator(const ListIterator& mit) : p(mit.p) {};

			ListIterator& operator++() {
				p = p->getNext();
				
				return *this;
			};

			ListIterator operator++(int) {ListIterator tmp(*this); operator++(); return tmp;};
			ListIterator const operator++(int) const {ListIterator tmp(*this); operator++(); return tmp;};

			node_type *getNode() {return p;};

			bool operator==(const ListIterator& rhs) const {return p==rhs.p;};
			bool operator!=(const ListIterator& rhs) const {return p!=rhs.p;};
			value_type &operator*() const {return p->getValue();};

		private:

			node_type* p;
	};

	template < class value_type, class node_type >
	class ListReverse_Iterator : public ListIterator<value_type,node_type > {

		public:
			ListReverse_Iterator() {node_type *tmp; p = tmp;};
			ListReverse_Iterator(node_type *x) :p(x) {};
			ListReverse_Iterator(const ListReverse_Iterator& mit) : p(mit.p) {};

			ListReverse_Iterator<value_type,node_type >& operator++() {p = p->getPrev();return *this;};
			ListReverse_Iterator<value_type,node_type > operator++(int) {ListReverse_Iterator<value_type,node_type > tmp(*this); operator++(); return tmp;};
			bool operator==(const ListReverse_Iterator<value_type,node_type >& rhs) const {return p==rhs.p;}
			bool operator!=(const ListReverse_Iterator<value_type,node_type >& rhs) const {return p!=rhs.p;}
			value_type &operator*() const {return p->getValue();};

		private:

			node_type* p;
	};

	//************************************************************************************************

	template < class T, class Alloc = std::allocator<T> > 
	class List {

		public:

			// ALIASES:

			typedef T 													value_type;
			typedef ListNode<value_type> 								node_type;
			typedef typename std::allocator<node_type> 					allocator_type;
			//typedef allocator_type 										Alloc;
			typedef value_type											&reference;
			typedef value_type const	 								&const_reference;
			typedef node_type 											*pointer;
			typedef node_type const	 									*const_pointer;
			typedef ListIterator<value_type, node_type> 					iterator;
			typedef ListIterator<value_type const, node_type const> 		const_iterator;
			typedef ListReverse_Iterator<value_type, node_type> 			reverse_iterator;
			typedef ListReverse_Iterator<value_type const, node_type const> const_reverse_iterator;
			typedef std::ptrdiff_t 										difference_type;
			typedef unsigned long  										size_type;
			

			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/*\CONSTRUCTORS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			// >>> default
			explicit List () {

				_begin = new node_type();
				_end = _begin;
				_size = 0;
				
				_end->setEnd();
			};

			// >>> fill
			explicit List (size_type n, const value_type& val = value_type()) {

				_begin = new node_type();
				_end = _begin;
				_size = 0;

				assign(n, val);

				_end->setEnd();
			};

			// >>> range
			template <class InputIterator>
		 	List (InputIterator first, InputIterator last)  {

		 		_begin = new node_type();
				_end = _begin;
				_size = 0;

		 		assign(first, last);

				_end->setEnd();
		 	};	
			
			// >>> copy 
			List (const List& x) {

				_begin = new node_type();
				_end = _begin;
				_size = 0;

		 		assign(x.begin(), x.end());

				_end->setEnd();
			}; 

			List& operator= (const List& x) {

				clear();
				assign(x.begin(), x.end());

				return *this;
			}; //destroy all content then copy


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/*\DESTRUCTORS/*\*/*\///
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			~List() { 

				clear(); 
				delete _end; 
			};


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/*\*/ITERATORS/*\*/*\*//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			iterator 		begin() {

				return iterator(_begin);
			};

			const_iterator 	begin() const{

				return const_iterator(_begin);
			};

			iterator end(){

				return iterator(_end);
			};

			const_iterator end() const{

				return const_iterator(_end);
			};
			// points after last List element

			reverse_iterator rbegin() {

				if (_end->getPrev())
					return (reverse_iterator(_end->getPrev()));
				return (reverse_iterator(_end));
			};

			const_reverse_iterator rbegin() const {

				if (_end->getPrev())
					return (const_reverse_iterator(_end->getPrev()));
				return (const_reverse_iterator(_end));
			};
			// point to last element, incrementing actually decrements

			reverse_iterator rend() {

				return (reverse_iterator(_begin->getPrev()));
			};

			const_reverse_iterator rend() const {

				return (const_reverse_iterator(_begin->getPrev()));
			};
			// point to hypothetical element BEFORE first element


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/CAPACITY/*\*/*\*//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			bool empty() const {

				if (_size == 0)
					return true;
				return false;
			}

			size_type size() const {

				return _size;
			};

			size_type max_size() const {
				
				size_type maxDiff = std::numeric_limits<difference_type>::max();
				size_type maxVal = std::numeric_limits<size_type>::max() / (sizeof(node_type));
				
				if (maxDiff < maxVal)
					return maxDiff;
				return maxVal;
			};
			//returns max nb of elements List can hold, due to system or library limitations


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/ELEMENT ACCESS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			reference front() {

				return _begin->getValue();
			};

			const_reference front() const{

				return _begin->getValue();
			};
			//same as begin() but returns a reference

			reference back() {

				if (size())
					return _end->getPrev()->getValue();
				return _end->getValue();
			};

			const_reference back() const{

				if (size())
					return _end->getPrev()->getValue();
				return _end->getValue();
			};
			//returns a reference to the last List element(not after it)


			//----------------------------------------------//
			

					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/MODIFIERS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			// >>> range
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last) {

				this->clear();

  				while (first != last) {
		 			this->push_back(*first);
		 			first++;
		 		}
				_begin = _end->getBegin();
				_end->setEnd();
  			};

			// >>> fill
			void assign (size_type n, const value_type& val) {

				this->clear();

				while (_size < n) {
					push_back(val);
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//Assigns new contents to the List container, replacing its current contents, and modifying its size accordingly.

			void push_front (const value_type& val) {

				_begin->addPrev(val);
				_begin = _end->getBegin();
				_size++;
				
				_end->setEnd();
			};
			//insert elem at the beginning. 

			void pop_front() {

				if (_size) {
					_begin->delNode();
					_size--;
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//remove & destroy first element.

			void push_back (const value_type& val) { 

				_end->addPrev(val);
				_size++;
				
				_begin = _end->getBegin();
				_end->setEnd();
			};
			//Adding elements to a list = adding nodes before end. 

			void pop_back() {

				if (_size == 1) { //case 1 = Node1 endNode 
					_begin->delNode();//last node = Node1
					_size--;
				}
				else if (_size > 1) { //case 2 = Node1 Node2 Node3 endNode
					_end->getPrev()->delNode();//delete Node3
					_size--;
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//remove & destroy last element

			iterator insert (iterator position, const value_type& val) {

				position.getNode()->addPrev(val);
				_size++;

				_begin = _end->getBegin();
				_end->setEnd();

				return iterator(position.getNode()->getPrev());

			}; 
			//remove 1 element
    		
			// >>> fill
			void insert (iterator position, size_type n, const value_type& val) {

				for (size_type i = 0; i < n; i++)
					position = insert(position, val);

				_begin = _end->getBegin();
				_end->setEnd();
			};
			
			// >>> range
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last) {

				while (first != last) {
					insert(position, *first);
					first++;
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
    		//Extend the container by inserting new elements before the element at the specified position

			iterator erase (iterator position) {
				
				iterator ret = iterator(position.getNode()->getNext());
				
				position.getNode()->delNode();
				_size--;

				_begin = _end->getBegin();
				_end->setEnd();
				return ret;
			};
			
			iterator erase (iterator first, iterator last) {

				iterator ret = iterator(last.getNode()->getNext());

				if (last.getNode() == _end)
					ret = this->end();

				while (first != last)
					erase(first++);

				_begin = _end->getBegin();
				_end->setEnd();
				return ret;
			};
			// remove & destroy either 1 element or a range of elements. 

			void swap (List& x) {

				node_type *tmp;
				int sz = _size;

				tmp = _begin;
				_begin = x._begin;
				x._begin = tmp;

				tmp = _end;
				_end = x._end;
				x._end = tmp;

				_size = x._size;
				x._size = sz;
			};
			//exchange content with container of the same type

			void resize (size_type n, value_type val = value_type()) {

				node_type *tmp = _begin;
				node_type *next;
				size_type i = 0;

				if (_size > n) {
					while (i++ < n)
						tmp = tmp->getNext();
					while (i++ <= _size) {
						next = tmp->getNext();
						tmp->delNode();
						tmp = next;
					}
				}
				else if (_size < n) {
					iterator it = this->end();
					i = _size;
					while (i++ < n)
						it = insert(it, val);
				}
				_size = n;

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//either removes elements beyond n elements or add elements until container size is n 

			void clear() {

				node_type *tmp;

				while (_begin != _end) {
					tmp = _begin->getNext();
					delete _begin;
					_begin = tmp;
				}
				_size = 0;
				_end->resetNode();
				
				_begin = _end;
				_end->setEnd();
			};
			//removes all elements (size == 0)
			

			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/OPERATIONS/*\*/*//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			void splice (iterator position, List& other) {

				iterator srcIt = other.begin();
				iterator srcEnd = other.end();
				iterator otherNext = srcIt;
				
				node_type *cur = position.getNode();;

				while (srcIt != srcEnd) {
					otherNext++;
					cur->addPrevNode(srcIt.getNode());
					srcIt = otherNext;
				}
				
				_begin = _end->getBegin();
				_end->setEnd();

				other._end->resetNode();
				other._begin = other._end;
				other._end->setEnd();
			}; 
			//entire list
			
			void splice (iterator position, List& other, iterator it) {

				node_type *cur;

				it.getNode()->forgetNode();

				cur = position.getNode();
				cur->addPrevNode(it.getNode());

				_begin = _end->getBegin();
				_end->setEnd();				

				other._begin = other._end->getBegin();
				other._end->setEnd();		
			}; 
			// just 1 element

			// >>> range
			void splice (iterator position, List& other, iterator first, iterator last) {

				iterator next;

				while (first != last) {
					next = first;
					next++;
					splice(position, other, first);
					first = next;
				}

				_begin = _end->getBegin();
				_end->setEnd();	
			}; 
			// Transfer of elements from other into the container

			void remove (const value_type& val) {

				iterator it = this->begin();
				iterator ite = this->end();
				iterator tmp;

				while(it != ite) {
					if (*it == val) {
						tmp = iterator(it.getNode()->getNext());
						it.getNode()->delNode();
						_begin = tmp.getNode()->getBegin();

						if (tmp.getNode() == _end)
							break ;
						it = begin();
					}
					else
						it++;
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//remove elements with specific value

			template <class Predicate>
  			void remove_if (Predicate pred) {

				iterator it = this->begin();
				iterator ite = this->end();
				iterator tmp;

				int index = -1;

				while(it != ite) {
					index++;
					if (pred(*it)) {
						tmp = iterator(it.getNode()->getNext());
						it.getNode()->delNode();
						_begin = _end->getBegin();
						
						if (tmp.getNode() == _end)
							break ;
						it = begin();
						index = -1;
					}
					else
						it++;
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			// pred is a function returning a bool. Check if p(val) is true for each element

			void unique() {

				iterator it = this->begin();
				iterator tmp = it;
				iterator ite = this->end();

				for (it = this->begin(); it != ite; it++) {
					if (it.getNode()->getPrev() && it.getNode()->getPrev()->getValue() == *it) {
						tmp = iterator(it.getNode()->getPrev());
						it.getNode()->delNode();
						it = tmp;
					}
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//remove all but the first element from every consecutive group of equal elements in the container
			
			template <class BinaryPredicate>
  			void unique (BinaryPredicate binary_pred) {

				iterator it = this->begin();
				iterator tmp = it;
				iterator ite = this->end();

				for (it = this->begin(); it != ite; it++) {
					if (it.getNode()->getPrev() && binary_pred(it.getNode()->getPrev()->getValue(), *it)) {
						tmp = iterator(it.getNode()->getPrev());
						it.getNode()->delNode();
						it = tmp;
					}
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//can take any "comparison" function

			void merge (List& other) {

				if (other == *this)
					return ;

				iterator thisIt = this->begin();
				iterator thisIte = this->end();
				
				iterator otherIt = other.begin();
				iterator otherIte = other.end();
				iterator otherNext = otherIt;

				while (thisIt != thisIte) {
					if (otherIt != otherIte && *otherIt < *thisIt) {
						otherNext = otherIt;
						otherNext++;
						splice(thisIt, other, otherIt);
						otherIt = otherNext;
					}
					else
						thisIt++;
				}
				if (otherIt != otherIte)
					splice(thisIt, other, otherIt, otherIte);

				_begin = _end->getBegin();
				_end->setEnd();
			};

			template <class Compare>
  			void merge (List& other, Compare comp) {
			
				if (other == *this)
					return ;
				
				iterator thisIt = this->begin();
				iterator thisIte = this->end();

				iterator otherIt = other.begin();
				iterator otherIte = other.end();
				iterator otherNext = otherIt;

				while (thisIt != thisIte) {
					if (otherIt != otherIte && comp(*otherIt, *thisIt)) {
						otherNext = otherIt;
						otherNext++;
						splice(thisIt, other, otherIt);
						otherIt = otherNext;
					}
					else
						thisIt++;
				}
				if (otherIt != otherIte)
					splice(thisIt, other, otherIt, otherIte);

				_begin = _end->getBegin();
				_end->setEnd();
			};
  			//remove elements from x and insert them in container in orderly fashion
			
			void sort() {

				iterator it = this->begin();
				iterator ite = this->end();
				
				for (it = this->begin(); it != ite; ++it) {
					if (it.getNode()->getPrev() && *it < it.getNode()->getPrev()->getValue()) {
						it.getNode()->swapNodes(it.getNode()->getPrev(), it.getNode());
						_begin = it.getNode()->getBegin();
						it = begin();
					}			
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};
			//use < for comparison
			
			template <class Compare>
  			void sort (Compare comp) {
			
				iterator it = this->begin();
				iterator ite = this->end();
				
				for (it = this->begin(); it != ite; ++it) {
					if (it.getNode()->getPrev() && comp(*it, it.getNode()->getPrev()->getValue())) {
						it.getNode()->swapNodes(it.getNode()->getPrev(), it.getNode());
						_begin = it.getNode()->getBegin();
						it = begin();
					}			
				}

				_begin = _end->getBegin();
				_end->setEnd();
			};

  			void reverse() {

				iterator it = this->begin();
				reverse_iterator rit = this->rbegin();

				value_type tmp;
				
				int i = -1;
				while (++i != _size / 2) {
					tmp = *it;
					*it = *rit;
					*rit = tmp;
					it++;
					rit++;
				}

				_begin = _end->getBegin();
				_end->setEnd();

			};
			//reverse the order of elements

		private:

			node_type 			*_begin;
			node_type 			*_end;
			size_type 			_size;
			
	};
	
	
	//----------------------------------------------//		


			//*\*/*\/*\*/*\/*\*/*\/*\*///
			///*\*/*\NON-MEMBERS/*\*/*\//
			//*\*/*\/*\*/*\/*\*/*\/*\*///

	template < class T, class Alloc>
	bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
	
		if (lhs.size() != rhs.size())
			return false;

		ListIterator< const T, const ListNode<T> > lhsIt = lhs.begin();
		ListIterator< const T, const ListNode<T> > rhsIt = rhs.begin();
		
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
	bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {

		if (rhs == lhs)
			return false;

		return true;
	};

	template <class T, class Alloc>
	bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {

		if (lhs.size() > rhs.size())
		 	return false;

		ListIterator< const T, const ListNode<T> > lhsIt = lhs.begin();
		ListIterator< const T, const ListNode<T> > rhsIt = rhs.begin();
	
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
	bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {

		if (lhs == rhs)
			return true;

		return (lhs < rhs);
	};

	template <class T, class Alloc>
	bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {
	
		if (lhs.size() < rhs.size())
			return false;

		ListIterator< const T, const ListNode<T> > lhsIt = lhs.begin();
		ListIterator< const T, const ListNode<T> > rhsIt = rhs.begin();
	
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
	bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs) {

		if (lhs == rhs)
			return true;

		return (lhs > rhs);
	};

	template <class T, class Alloc>
  	void swap (List<T,Alloc>& x, List<T,Alloc>& y) {

		  x.swap(y);
	};

};

#endif