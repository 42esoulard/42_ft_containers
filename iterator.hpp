/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:25:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/03 15:36:22 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//EXAMPLE OF ITERATOR IMPLEMENTATION, cplusplus.com
//https://www.cplusplus.com/reference/iterator/iterator/

// class MyIterator : public std::iterator<std::input_iterator_tag, int>
// {
// 		int* p;
// 	public:
// 		MyIterator(int* x) :p(x) {}
// 		MyIterator(const MyIterator& mit) : p(mit.p) {}
// 		MyIterator& operator++() {++p;return *this;}
// 		MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
// 		bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
// 		bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
// 		int& operator*() {return *p;}
// };


template < class T >
class iterator {

		T* p;

	public:

		iterator(T* x) :p(x) {}
		iterator(const iterator& mit) : p(mit.p) {}

		iterator& operator++() {++p;return *this;}
		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
		bool operator==(const iterator& rhs) const {return p==rhs.p;}
		bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
		int& operator*() {return *p;}
};

// MAKE REVERSE_ITERATOR CLASS ?? IS THAT NECESSARY ?
// template < class itType >
// class reverse_iterator : public iterator {

// 		int* p;

// 	public:

// 		iterator(int* x) :p(x) {}
// 		iterator(const iterator& mit) : p(mit.p) {}
		
// 		iterator& operator++() {++p;return *this;}
// 		iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
// 		bool operator==(const iterator& rhs) const {return p==rhs.p;}
// 		bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
// 		int& operator*() {return *p;}
// };