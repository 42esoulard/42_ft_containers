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

			MapNode() 							: _value(), _up(NULL), _left(NULL), _right(NULL) {};
			MapNode(value_type const &value) 	: _value(value), _up(NULL), _left(NULL), _right(NULL) {};
			MapNode(node_type const &src) 		: _value(src._value), _up(src._up), _left(src._left), _right(src._right) {};
			~MapNode() {}

			MapNode &operator=(MapNode const &src) {

				this->_value = src._value;
				this->_up = src._up;
				this->_left = src._left;
				this->_right = src._right;

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

				this->_value = value_type();
				this->_up = NULL;
				this->_left = NULL;
				this->_right = NULL;
			};


			MapNode 		*getBegin() {

				node_type *begin = this;

				while(begin->_up)
					begin = begin->_up;

				return begin;
			};

			// void 	setEnd() {

			// 	MapNode *begin = this;

			// 	while(begin->_prev)
			// 		begin = begin->_prev;
			// 	this->_next = begin;
			// };

			/*
				less returns bool x<y
				so if less(key, cur->value), go left
				if !left go right
			*/

			node_type *findKey(node_type *cur, key_type const &key) {
				
				if (comp(key, cur->value.first) && cur->_left)
					findKey(cur->_left, key);
				if (comp(cur->value.first, key) && cur->_right)
					findKey(cur->_right, key);

				if (!comp(cur->value.first, key) && !comp(cur->value.first, key))
					return cur;

				if (comp(key, cur->value.first) && !cur->_left) {
					cur->_left = node_type(key, mapped_type());
					cur->_left->_up = cur;
					return cur->_left;
				}
				if (comp(cur->value.first, key) && !cur->_right) {
					cur->_right = node_type(key, mapped_type());
					cur->_right->_up = cur;
					return cur->_right;
				}

				return NULL; //shouldn't happen
			}

			node_type *addPair(node_type *cur, value_type const &pair) {

				if (comp(pair.first, cur->value.first) && cur->_left)
					addPair(cur->_left, pair);
				if (comp(cur->value.first, pair) && cur->_right)
					addPair(cur->_right, pair);

				if (!comp(cur->value.first, pair) && !comp(cur->value.first, pair))
					return cur;
					
				if (comp(pair, cur->value.first) && !cur->_left) {
					cur->_left = node_type(pair, mapped_type());
					cur->_left->_up = cur;
					return cur->_left;
				}
				if (comp(cur->value.first, pair) && !cur->_right) {
					cur->_right = node_type(pair, mapped_type());
					cur->_right->_up = cur;
					return cur->_right;
				}

				return NULL; //shouldn't happen
			}

			node_type 	&addNode(key_type const &key) {
				node_type *parent = findParent(this, key);
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
			
			key_compare 	_comp;
			
	};
};

#endif