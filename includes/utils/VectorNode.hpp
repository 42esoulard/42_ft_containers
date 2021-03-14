/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorNode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/12 13:19:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORNODE_HPP
#define VECTORNODE_HPP

namespace ft {

	template <class T>
	class VectorNode {

		public:
			typedef T 						value_type;
			typedef VectorNode<value_type> 	node_type;

			VectorNode() 							: _value() {};
			VectorNode(value_type const &value) 	: _value(value) {};
			VectorNode(VectorNode const &src) 		: _value(src._value) {};
			~VectorNode() {}

			VectorNode &operator=(VectorNode const &src) {

				this->_value = src._value;
				return (*this);
			}

			value_type &getValue() {

				return _value;
			};

			value_type const &getValue() const {

				return _value;
			};
			
			VectorNode 		*getNext() {

				VectorNode *next = this;

				next++;
				return next;
			};

			VectorNode const 	*getNext() const {

				VectorNode *next = this;
				
				next++;
				return next;
			};

			VectorNode	*getPrev() {

				VectorNode *next = this;
				
				next--;
				return next;
			};

			VectorNode const	*getPrev() const {

				VectorNode *next = this;
				
				next--;
				return next;
			};

			void resetNode() {

				_value = value_type();
			};

			// VectorNode 		*getBegin() {

			// 	VectorNode *begin = this;

			// 	while(begin->_prev)
			// 		begin = begin->_prev;

			// 	return begin;
			// };

			// void 	setEnd() {

			// 	VectorNode *begin = this;

			// 	while(begin && begin->_prev)
			// 		begin = begin->_prev;
			// 	this->_next = begin;
			// };

			void 	addNext(value_type const &value) {

				VectorNode *newNode = new VectorNode(value);

				if (this->_next)
					newNode->_next = this->_next;
				this->_next = newNode;
				newNode->_prev = this;
			};

			void 	addPrev(value_type const &value) {

				VectorNode *newNode = new VectorNode(value);

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
				
				VectorNode *prevNode = this->_prev; 
				VectorNode *nextNode = this->_next; 

				if (prevNode)
					prevNode->_next = nextNode;
				if (nextNode)
					nextNode->_prev = prevNode;
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
		
				VectorNode *stock = two->_next;

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
			
	};
};

#endif