/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/03 15:53:24 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

namespace ft {

	template < class T, class Alloc = allocator<T> > 
	class list {

		public:

			// ALIASES:
			typedef typename T 					value_type;
			typedef typename Alloc 				allocator_type;
			typedef typename reference 			allocator_type::reference;
			typedef typename const_reference 	allocator_type::const_reference;
			typedef typename pointer 			allocator_type::pointer;
			typedef typename const_pointer 		allocator_type::const_pointer;
			typedef typename iterator;
			typedef typename const_iterator;
			// typedef typename reverse_iterator<iterator>;
			// typedef typename reverse_iterator<const_iterator>;
			// typedef typename difference_type iterator_traits<iterator>::difference_type;
			typedef typename size_type size_t;

			//----------------------------------------------

			// CONSTRUCTORS (as listed in c++.com):

			// >>> default
			explicit list (const allocator_type& alloc = allocator_type()) {
				prev = nullptr;
				next = nullptr;
			};

			// // >>> fill
			// explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			// 	prev = nullptr;
			// 	next = nullptr;
			// };

			// // >>> range
			// template <class InputIterator>
		 	// list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());	
			
			// // >>> copy
			// list (const list& x); use operator=
			// list& operator= (const list& x); //destroy all content then copy

			//----------------------------------------------

			//DESTRUCTOR:

			~list() {}; // get begin, from begin delete all list

			//----------------------------------------------

			//ITERATORS:

			// iterator 		begin();
			// const_iterator 	begin() const;
			// point to list first element

			//iterator end();
			//const_iterator end() const;
			// point after last list element (nullptr?)

			//reverse_iterator rbegin();
			//const_reverse_iterator rbegin() const;
			// point to last element, incrementing actually decrements

			//reverse_iterator rend();
			//const_reverse_iterator rend() const;
			// point to hypothetical element BEFORE first element (nullptr?)

			//----------------------------------------------

			//SIZE:

			//bool empty() const;
			//checks if size() is 0

			//size_type size() const;
			//returns number of elements in container

			//size_type max_size() const;
			//returns max nb of elements list can hold, due to system or library limitations

			//----------------------------------------------

			// ELEMENT ACCESS:

			//reference front();
			//const_reference front() const;
			//same as begin() but returns a reference

			//reference back();
			//const_reference back() const;
			//returns a reference to the last list element(not after it)

			//----------------------------------------------
			
			// MODIFIERS

			//template <class InputIterator>
  			//void assign (InputIterator first, InputIterator last);//RANGE
			//void assign (size_type n, const value_type& val);//FILL
			//Assigns new contents to the list container, replacing its current contents, and modifying its size accordingly.

			//void push_front (const value_type& val);
			//insert elem at the beginning. 

			//void pop_front();
			//remove & destroy first element.

			//void push_back (const value_type& val);
			//add element at the end

			//void pop_back();
			//remove & destroy last element

			//iterator insert (iterator position, const value_type& val); //1 ELEMENT
    		//void insert (iterator position, size_type n, const value_type& val);//FILL
			//template <class InputIterator>
    		//void insert (iterator position, InputIterator first, InputIterator last);//RANGE
    		//Extend the container by inserting new elements before the element at the specified position

			//iterator erase (iterator position);
			//iterator erase (iterator first, iterator last);
			// remove & destroy either 1 element or a range of elements. 

			//void swap (list& x);
			//exchange content with container of the same type

			//void resize (size_type n, value_type val = value_type());
			//either removes elements beyond n elements or add elements until container size is n 

			//void clear();
			//removes all elements (size == 0)
			
			//----------------------------------------------

			//OPERATIONS

			//void splice (iterator position, list& x); //ENTIRE LIST
			//void splice (iterator position, list& x, iterator i); //1 ELEMENT
			//void splice (iterator position, list& x, iterator first, iterator last); //RANGE
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

			//void merge (list& x);
			//template <class Compare>
  			//void merge (list& x, Compare comp);
  			//remove elements from x and insert them in container in orderly fashion
			
			//void sort();//use < for comparison
			//template <class Compare>
  			//void sort (Compare comp);//uses.. i'm not sure what yet

  			//void reverse();
			//reverse the order of elements

			//----------------------------------------------
			
			//NON MEMBER FUNCTION OVERLOADS

	// 			template <class T, class Alloc>
	//   bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

	// template <class T, class Alloc>
	//   bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);

			//lord have mercy

	//template <class T, class Alloc>
  	//void swap (list<T,Alloc>& x, list<T,Alloc>& y);
			//NOT SURE I SHOULD EVEN IMPLEMENT THIS
			//----------------------------------------------
			//----------------------------------------------
			//----------------------------------------------


		private:

			T 		elem;
			list<T> *prev;
			list<T> *next;
			

}

#endif