/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/17 14:16:45 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

	template <class T>
	class Node {

		public:
			typedef T 						value_type;
			typedef Node<value_type> 		node_type;

			Node() 							: _value(), _prev(NULL), _next(NULL) {};
			Node(value_type const &value) 	: _value(value),  _prev(NULL), _next(NULL) {};
			Node(Node const &src) 		: _value(src._value), _prev(src._prev), _next(src._next) {};
			~Node() {}

			Node &operator=(Node const &src) {
				this->_value = src._value;
				this->_prev = src._prev;
				this->_next = src._next;

				return (*this);
			}

			value_type &getValue() {

				return _value;
			};

			value_type const &getValue() const {

				return _value;
			};
			
			Node 		*getNext() {

				return _next;
			};

			Node const 	*getNext() const {

				return _next;
			};

			Node	*getPrev() {

				return _prev;
			};

			Node const	*getPrev() const {

				return _prev;
			};

			void resetNode() {

				_next = NULL;
				_prev = NULL;
			};

			Node 		*getBegin() {

				Node *begin = this;

				while(begin->_prev)
					begin = begin->_prev;

				return begin;
			};

			// Node 		*getEnd() {

			// 	Node *end = this;

			// 	while(end->_next)
			// 		end = end->_next;

			// 	return end;
			// };

			void 	setEnd() {

				Node *begin = this;

				while(begin->_prev)
					begin = begin->_prev;
				this->_next = begin;
			};

			void 	addNext(value_type const &value) {

				Node *newNode = new Node(value);

				if (this->_next)
					newNode->_next = this->_next;
				this->_next = newNode;
				newNode->_prev = this;
			};

			void 	addPrev(value_type const &value) {

				Node *newNode = new Node(value);

				if (this->_prev) {
					newNode->_prev = this->_prev;
					this->_prev->_next = newNode;
				}
				this->_prev = newNode;
				newNode->_next = this;
			};

			void 	addPrevNode(node_type *newNode) {
		
				newNode->_prev = this->_prev;
				if (this->_prev) 
					this->_prev->_next = newNode;
			
				this->_prev = newNode;
				newNode->_next = this;
			};

			void 	forgetNode() {
				
				Node *prevNode = this->_prev; 
				Node *nextNode = this->_next; 

				if (prevNode)
					prevNode->_next = nextNode;
				if (nextNode)
					nextNode->_prev = prevNode;
			};

			void 	forgetValue() {
				
				_value = 0;
			};

			void 	setValue(value_type const &a) {
				
				_value = a;
			};

			void 	delNode() {
				
				forgetNode();
				delete(this);
			};

			void 	linkNodes(node_type first, node_type second) {
			
				if (first)
					first->_next = second;
				if (second)
					second->_prev = first;
			};
                                                      
			void 	swapNodes(node_type *one, node_type *two) {
		
				Node *stock = two->_next;

				one->_next = two->_next;
				two->_next = one;

				if (one->_prev)
					one->_prev->_next = two;
				if (stock)
					stock->_prev = one;

				stock = one->_prev;
				one->_prev = two;
				two->_prev = stock;
			};
			
		private :

			value_type 		_value;
			node_type 		*_prev;
			node_type 		*_next;
			
	};
};

#endif