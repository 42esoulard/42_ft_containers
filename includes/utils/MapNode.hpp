/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapNode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/12 13:19:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPNODE_HPP
#define MAPNODE_HPP

namespace ft {

	template < class Key, class T, class Compare = std::less<Key> >
	class MapNode {

		public:
			typedef Key 												key_type;
			typedef T 													mapped_type;
			typedef std::pair<const key_type, mapped_type> 				value_type;
			typedef Compare 											key_compare;
			typedef MapNode<value_type> 								node_type;

			MapNode() 							: _value(), _left(NULL), _right(NULL) {};
			MapNode(value_type const &value) 	: _value(value),  _left(NULL), _right(NULL) {};
			MapNode(MapNode const &src) 		: _value(src._value), _left(src._left), _right(src._right) {};
			~MapNode() {}

			MapNode &operator=(MapNode const &src) {

				this->_value = src._value;
				this->_prev = src._left;
				this->_next = src._right;

				return (*this);
			}

			value_type &getValue() {

				return _value;
			};

			value_type const &getValue() const {

				return _value;
			};
			
			MapNode 		*getLeft() {

				return _left;
			};

			MapNode const 	*getLeft() const {

				return _left;
			};

			MapNode	*getRight() {

				return _right;
			};

			MapNode const	*getRight() const {

				return _right;
			};

			void resetNode() {

				_left = NULL;
				_right = NULL;
			};

			// MapNode 		*getBegin() {

			// 	MapNode *begin = this;

			// 	while(begin->_prev)
			// 		begin = begin->_prev;

			// 	return begin;
			// };

			// void 	setEnd() {

			// 	MapNode *begin = this;

			// 	while(begin->_prev)
			// 		begin = begin->_prev;
			// 	this->_next = begin;
			// };

			node_type 	&addNode(key_type const &key) {
				if ()
			}

			void 	addNext(value_type const &value) {

				MapNode *newNode = new MapNode(value);

				if (this->_next)
					newNode->_next = this->_next;
				this->_next = newNode;
				newNode->_prev = this;
			};

			void 	addPrev(value_type const &value) {

				MapNode *newNode = new MapNode(value);

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
				
				MapNode *prevNode = this->_prev; 
				MapNode *nextNode = this->_next; 

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
		
				MapNode *stock = two->_next;

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
			
			node_type 		*_up;
			node_type 		*_left;
			node_type 		*_right;
			
			key_compare 	comp;
			
	};
};

#endif