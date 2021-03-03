/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/03 14:48:30 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "Iterator.hpp"

namespace ft {

	template < class T > 
	class List {

		public:

			// ALIASES:
			typedef T 													value_type;
			typedef Node<value_type> 									node_type;
			typedef typename std::allocator<node_type> 					allocator_type;
			typedef allocator_type 										Alloc;
			typedef value_type											&reference;
			typedef value_type const	 								&const_reference;
			typedef node_type 											*pointer;
			typedef node_type const	 									*const_pointer;
			typedef Iterator<value_type, node_type> 					iterator;
			typedef Iterator<value_type const, node_type const> 		const_iterator;
			typedef Reverse_Iterator<value_type, node_type> 			reverse_iterator;
			typedef Reverse_Iterator<value_type const, node_type const> const_reverse_iterator;
			// typedef typename difference_type Iterator_traits<Iterator>::difference_type;
			typedef size_t 										size_type;
			

			//----------------------------------------------

			// CONSTRUCTORS (as Listed in c++.com):

			// >>> default = a Node with no value, end and begin point to ONE node
			explicit List (const allocator_type& alloc = allocator_type()) {
				_begin = new node_type();
				_end = _begin;
				_size = 0;
			};

			// // >>> fill
			explicit List (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				_begin = new node_type();
				_end = _begin;
				_size = 0;
				assign(n, val);
			};

			// // >>> range
			template <class InputIterator>
		 	List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())  {
		 		_begin = new node_type();
				_end = _begin;
				_size = 0;
		 		assign(first, last);
		 	};	
			
			// // >>> copy 
			List (const List& x) {
				_begin = new node_type();
				_end = _begin;
				_size = 0;
		 		assign(x.begin(), x.end());
			}; 

			List& operator= (const List& x) {
				clear();
				assign(x.begin(), x.end());
			}; //destroy all content then copy

			//----------------------------------------------

			//DESTRUCTOR:

			~List() { clear(); delete _end; }; // get begin, from begin delete all List

			//----------------------------------------------

			//ITERATORS:

			iterator 		begin() {
				return iterator(_begin);
			};

			const_iterator 	begin() const{
				return const_iterator(_begin);
			};
			// point to List first element

			iterator end(){
				return iterator(_end);
			};

			const_iterator end() const{
				return const_iterator(_end);
			};
			// point after last List element (nullptr?)

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
			// point to hypothetical element BEFORE first element (nullptr?)

			//----------------------------------------------

			//SIZE:

			bool empty() const {
				if (_size == 0)
					return true;
				return false;
			}

			size_type size() const {
				return _size;
			};

			//size_type max_size() const;
			//returns max nb of elements List can hold, due to system or library limitations

			//----------------------------------------------

			// ELEMENT ACCESS:

			reference front() {
				std::cout << "front" << std::endl;
				return _begin->getValue();
			};

			const_reference front() const{
				std::cout << "front const" << std::endl;
				return _begin->getValue();
			};
			//same as begin() but returns a reference

			reference back() {
				std::cout << "back" << std::endl;
				return _end->getPrev()->getValue();
			};

			const_reference back() const{
				std::cout << "back const" << std::endl;
				return _end->getPrev()->getValue();
			};
			//returns a reference to the last List element(not after it)

			//----------------------------------------------
			
			// MODIFIERS

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last) {
  				while (first != last) {
		 			this->push_back(*first);
		 			first++;
		 		}
  			};//RANGE

			void assign (size_type n, const value_type& val) {
				while (_size < n) {
					push_back(val);
				}
			};//FILL
			//Assigns new contents to the List container, replacing its current contents, and modifying its size accordingly.

			void push_front (const value_type& val) {
				_begin->addPrev(val);
				_begin = _begin->getPrev();
				_size++;
			};
			//insert elem at the beginning. 

			void pop_front() {

				if (_size) {
					node_type *tmp = _begin->getNext();

					_begin->delNode();
					_begin = tmp;
					_size--;
				}
			};
			//remove & destroy first element.

			//Adding elements to a list = adding nodes before end. 
			void push_back (const value_type& val) { 
				_end->addPrev(val);
				if (empty())
					_begin = _end->getPrev();
				_size++;
			};
			//add element at the end

			void pop_back() {

				if (_size == 1) { //case 1 = Node1 endNode 
					_begin->delNode();//last node = Node1
					_begin = _end;
					_size--;
				}
				else if (_size > 1) { //case 2 = Node1 Node2 Node3 endNode
					_end->getPrev()->delNode();//delete Node3
					_size--;
				}
				std::cout << "popped back " << std::endl;
			};
			//remove & destroy last element

			iterator insert (iterator position, const value_type& val) {
				
				//std::cout << " in insert 1" << std::endl;
				position.getNode()->addPrev(val);
				_size++;
				while (_begin->getPrev())
					_begin = _begin->getPrev();
				std::cout << "in insert1 beg value: " << _begin->getValue() << std::endl;
				return iterator(position.getNode()->getPrev());

			}; //1 ELEMENT
    		
			void insert (iterator position, size_type n, const value_type& val) {

				std::cout << " in insert 3 fill" << std::endl;
				for (int i = 0; i < n; i++) {
					std::cout << "adding " << val << std::endl;
					position = insert(position, val);
					std::cout << "beg value: " << _begin->getValue() << std::endl;
				}
			};//FILL
			
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last) {
				std::cout << "in insert 4 range" << std::endl;
				while (first != last) {
					std::cout << "adding " << *first << std::endl;
					position = insert(*first);
					first++;
					std::cout << "beg value: " << _begin->getValue() << std::endl;
				}
			};//RANGE
    		//Extend the container by inserting new elements before the element at the specified position


			iterator erase (iterator position) {
				
				node_type *tmp;
				iterator ret;

				if (position->getNode() == _end)
					ret = this->end();
				else
					ret = iterator(position->getNode()->getNext());

				if (position->getNode() == _begin)
					tmp = _begin->getNext();
				else
					tmp = _begin;
				position->getNode()->delNode();
				_begin = tmp;
				_size--;

				return ret;
			};
			
			iterator erase (iterator first, iterator last) {

				iterator ret;

				if (last->getNode() == _end)
					ret = this->end();
				else
					ret = iterator(last->getNode()->getNext());

				while (first != last)
					erase(first++);

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
				int i = 0;

				if (_size > n) { //size 3 n 2
					while (i++ < n)
						tmp = tmp->getNext();
					while (i++ < _size) {
						next = tmp->getNext();
						tmp->delNode();
						tmp = next;
					}
					if (n == 0)
						_begin = _end;
				}
				else if (_size < n) {
					iterator it = _end;
					i = _size;
					while (i++ < n)
						_end = insert(_end, val);
				}
				_size = n;
			};
			//either removes elements beyond n elements or add elements until container size is n 

			void clear() {
				node_type *tmp;

				while (_begin != _end) {
					tmp = _begin->getNext();
					delete _begin;
					_begin = tmp;
				}
				_end->resetNode();
				_begin = _end;
				_size = 0;
			};
			//removes all elements (size == 0)
			
			//----------------------------------------------

			//OPERATIONS

			void splice (iterator position, List& other) {
				iterator srcIt = other._begin;
				iterator srcEnd = other._end;
				node_type *cur = position->getNode();;

				while (srcIt != srcEnd) {
					cur->addPrevNode(srcIt->getNode());
					cur = cur->getPrev();
					srcIt++;
				}
				other._end->resetNode();
				other._begin = other._end;

			}; //ENTIRE LIST
			
			void splice (iterator position, List& other, iterator it) {

				node_type *cur;

				it->getNode()->forgetNode();
				
				cur = position->getNode();
				cur->addPrevNode(it->getNode());
		
			}; //1 ELEMENT
			
			void splice (iterator position, List& other, iterator first, iterator last) {

				node_type *cur = position->getNode();;
				iterator next;

				while (first != last) {
					next = first;
					next++;
					cur->addPrevNode(first->getNode());
					cur = cur->getPrev();
					first = next;
				}
				other._end->resetNode();
				other._begin = other._end;
			}; //RANGE
			// Transfer of elements from other into the container

			void remove (const value_type& val) {
				iterator it;
				iterator tmp;
				iterator ite = this->end();

				for (it = this->begin(); it != ite; it++) {
					if (*it == val) {
						tmp = iterator(it->getNode()->getNext());
						it->getNode()->delNode();
						it = tmp;
					}
				}
			};
			//remove elements with specific value

			template <class Predicate>
  			void remove_if (Predicate pred) {
				iterator it;
				iterator tmp;
				iterator ite = this->end();

				for (it = this->begin(); it != ite; it++) {
					if (pred(*it)) {
						tmp = iterator(it->getNode()->getNext());
						it->getNode()->delNode();
						it = tmp;
					}
				}
		 	};
			// pred is a function returning a bool. Check if p(val) is true for each element

			void unique() {
				iterator it;
				iterator tmp;
				iterator ite = this->end();

				for (it = this->begin(); it != ite; it++) {
					if (it->getNode()->getPrev() && it->getNode()->getPrev() == it->getNode()) {
						tmp = iterator(it->getNode()->getNext());
						it->getNode()->delNode();
						it = tmp;
					}
				}
			};
			//remove all but the first element from every consecutive group of equal elements in the container
			template <class BinaryPredicate>
  			void unique (BinaryPredicate binary_pred) {
				iterator it;
				iterator tmp;
				iterator ite = this->end();

				for (it = this->begin(); it != ite; it++) {
					if (binary_pred(it->getNode()->getPrev(), it->getNode())) {
						tmp = iterator(it->getNode()->getNext());
						it->getNode()->delNode();
						it = tmp;
					}
				}
			};
			//can take any "comparison" function

			void merge (List& other) {

				if (other == *this)
					return ;
					
				iterator otherIt = other.begin();
				iterator otherIte = other.end();
				iterator otherNext;
				iterator thisIt;
				iterator thisIte = this->end();

				for (thisIt = this->begin(); thisIt != thisIte; ++thisIt) {
					if (*otherIt < *thisIt) {
						otherNext = otherIt;
						otherNext++;
						splice(thisIt, other, otherIt);
						otherIt = otherNext;
					}
				}
			};

			template <class Compare>
  			void merge (List& other, Compare comp) {
				  if (other == *this)
					return ;
					
				iterator otherIt = other.begin();
				iterator otherIte = other.end();
				iterator otherNext;
				iterator thisIt;
				iterator thisIte = this->end();

				for (thisIt = this->begin(); thisIt != thisIte; ++thisIt) {
					if (comp(*otherIt, *thisIt)) {
						otherNext = otherIt;
						otherNext++;
						splice(thisIt, other, otherIt);
						otherIt = otherNext;
					}
				}
			};
  			//remove elements from x and insert them in container in orderly fashion
			
			//void sort();//use < for comparison
			//template <class Compare>
  			//void sort (Compare comp);//uses.. i'm not sure what yet

  			//void reverse();
			//reverse the order of elements

			//----------------------------------------------
			
			//NON MEMBER FUNCTION OVERLOADS

	// 			template <class T, class Alloc>
	//   bool operator== (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator!= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator<  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator<= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator>  (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator>= (const List<T,Alloc>& lhs, const List<T,Alloc>& rhs);

			//lord have mercy

	//template <class T, class Alloc>
  	//void swap (List<T,Alloc>& x, List<T,Alloc>& y);
			//NOT SURE I SHOULD EVEN IMPLEMENT THIS
			//----------------------------------------------
			//----------------------------------------------
			//----------------------------------------------


		private:

			node_type 			*_begin;
			node_type 			*_end;
			size_type 			_size;
			

	};
};

#endif