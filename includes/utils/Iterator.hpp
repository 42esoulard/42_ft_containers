/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stella <stella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:25:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/10 18:57:11 by stella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "Node.hpp"

//EXAMPLE OF ITERATOR IMPLEMENTATION, cplusplus.com
//https://www.cplusplus.com/reference/Iterator/Iterator/

// class MyIterator : public std::Iterator<std::input_Iterator_tag, int>
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


template < class value_type, class node_type >
class Iterator {

	public:

		// typedef T 					value_type;
		Iterator() {node_type *tmp; p = tmp;};
		Iterator(node_type *x) :p(x) {};
		Iterator(const Iterator& mit) : p(mit.p) {};

		Iterator& operator++() {p = p->getNext();return *this;};
		Iterator operator++(int) {Iterator tmp(*this); operator++(); return tmp;};
		Iterator const operator++(int) const {Iterator tmp(*this); operator++(); return tmp;};

		node_type *getNode() {return p;};

		bool operator==(const Iterator& rhs) const {return p==rhs.p;};
		bool operator!=(const Iterator& rhs) const {return p!=rhs.p;};
		value_type &operator*() const {return p->getValue();};

	private:

		node_type* p;
};

// MAKE REVERSE_ITERATOR CLASS ?? IS THAT NECESSARY ?
template < class value_type, class node_type >
class Reverse_Iterator : public Iterator<value_type,node_type > {

	public:
		Reverse_Iterator() {node_type *tmp; p = tmp;};
		Reverse_Iterator(node_type *x) :p(x) {};
		Reverse_Iterator(const Reverse_Iterator& mit) : p(mit.p) {};

		Reverse_Iterator<value_type,node_type >& operator++() {p = p->getPrev();return *this;};
		Reverse_Iterator<value_type,node_type > operator++(int) {Reverse_Iterator<value_type,node_type > tmp(*this); operator++(); return tmp;};
		bool operator==(const Reverse_Iterator<value_type,node_type >& rhs) const {return p==rhs.p;}
		bool operator!=(const Reverse_Iterator<value_type,node_type >& rhs) const {return p!=rhs.p;}
		value_type &operator*() const {return p->getValue();};

	private:

		node_type* p;
};

#endif