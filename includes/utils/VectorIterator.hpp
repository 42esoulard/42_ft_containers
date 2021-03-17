/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:25:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/17 15:05:15 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>

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


template < class value_type >
class VectorIterator {

	public:

		// typedef T 					value_type;
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

// MAKE VECTORREVERSE_ITERATOR CLASS ?? IS THAT NECESSARY ?
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

#endif