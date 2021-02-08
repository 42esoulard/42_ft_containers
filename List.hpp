/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/08 15:33:57 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "Iterator.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> > 
	class List {

		public:

			// ALIASES:
			typedef T 											value_type;
			typedef Node<value_type> 							node_type;
			typedef typename std::allocator<node_type> 			allocator_type;
			typedef allocator_type								&reference;
			typedef allocator_type const 						&const_reference;
			typedef allocator_type 								*pointer;
			typedef allocator_type const 						*const_pointer;
			typedef Iterator<value_type, node_type> 			iterator;
			typedef Iterator<value_type const, node_type const> const_iterator;
			// typedef typename reverse_Iterator<Iterator>;
			// typedef typename const_reverse_Iterator<const_Iterator>;
			// typedef typename difference_type Iterator_traits<Iterator>::difference_type;
			typedef size_t 										size_type;
			

			//----------------------------------------------

			// CONSTRUCTORS (as Listed in c++.com):

			// >>> default
			explicit List (const allocator_type& alloc = allocator_type()) {
				_begin = new node_type();
				_end = _begin;
				_size = 0;
			};

			// // >>> fill
			// explicit List (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			// 	prev = nullptr;
			// 	next = nullptr;
			// };

			// // >>> range
			// template <class InputIterator>
		 	// List (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());	
			
			// // >>> copy
			// List (const List& x); use operator=
			// List& operator= (const List& x); //destroy all content then copy

			//----------------------------------------------

			//DESTRUCTOR:

			~List() { clear(); }; // get begin, from begin delete all List

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

			//reverse_Iterator rbegin();
			//const_reverse_Iterator rbegin() const;
			// point to last element, incrementing actually decrements

			//reverse_Iterator rend();
			//const_reverse_Iterator rend() const;
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

			//reference front();
			//const_reference front() const;
			//same as begin() but returns a reference

			//reference back();
			//const_reference back() const;
			//returns a reference to the last List element(not after it)

			//----------------------------------------------
			
			// MODIFIERS

			//template <class InputIterator>
  			//void assign (InputIterator first, InputIterator last);//RANGE
			//void assign (size_type n, const value_type& val);//FILL
			//Assigns new contents to the List container, replacing its current contents, and modifying its size accordingly.

			//void push_front (const value_type& val);
			//insert elem at the beginning. 

			//void pop_front();
			//remove & destroy first element.

			void push_back (const value_type& val) {
				this->_end->addPrev(val);
				if (empty())
					this->_begin = this->_end->getPrev();
				this->_size++;
			};
			//add element at the end

			//void pop_back();
			//remove & destroy last element

			//Iterator insert (Iterator position, const value_type& val); //1 ELEMENT
    		//void insert (Iterator position, size_type n, const value_type& val);//FILL
			//template <class InputIterator>
    		//void insert (Iterator position, InputIterator first, InputIterator last);//RANGE
    		//Extend the container by inserting new elements before the element at the specified position

			//Iterator erase (Iterator position);
			//Iterator erase (Iterator first, Iterator last);
			// remove & destroy either 1 element or a range of elements. 

			//void swap (List& x);
			//exchange content with container of the same type

			//void resize (size_type n, value_type val = value_type());
			//either removes elements beyond n elements or add elements until container size is n 

			void clear() {
				node_type *tmp;

				while (_begin != _end) {
					tmp = _begin->getNext();
					delete _begin;
					_begin = tmp;
				}
				delete _end;
				_size = 0;
			};
			//removes all elements (size == 0)
			
			//----------------------------------------------

			//OPERATIONS

			//void splice (Iterator position, List& x); //ENTIRE LIST
			//void splice (Iterator position, List& x, Iterator i); //1 ELEMENT
			//void splice (Iterator position, List& x, Iterator first, Iterator last); //RANGE
			// Transfer of elements from x into the container

			//void remove (const value_type& val);
			//remove elements with specific value

			//template <class Predicate>
  			//void remove_if (Predicate pred);
			// ?!? i have no idea what the heck is going on

			//void unique();
			//remove all but the first element from every consecutive group of equal elements in the container
			//template <class BinaryPredicate>
  			//void unique (BinaryPredicate binary_pred);
			//can take any "comparison" function

			//void merge (List& x);
			//template <class Compare>
  			//void merge (List& x, Compare comp);
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
			// T 		elem;
			// List<T> *prev;
			// List<T> *next;
			

	};
};

#endif