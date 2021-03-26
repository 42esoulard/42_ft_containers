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

	template < class Key, class T >
	class Pair {
		public:
			Pair() : first(Key()), second(T()) {};
			Pair(Pair &other) : first(other.first), second(other.second) {};
			
			Pair &operator=(Pair &other) {
				first = other.first; 
				second = other.second;
				return (*this);
			}

			Key first;
			T second;
	};

	template < class Key, class T, class Compare = std::less<Key> >
	class MapNode {

		public:
			typedef Key 												key_type;
			typedef T 													mapped_type;
			typedef ft::Pair<const key_type, mapped_type> 				value_type;
			typedef Compare 											key_compare;
			typedef MapNode<Key, T, Compare> 							node_type;

			MapNode() 							: _value(), _up(NULL), _left(NULL), _right(NULL) {};
			//MapNode(value_type const &value) 	: _value(value), _up(NULL), _left(NULL), _right(NULL) { std::cout << "----------------MAPNODE COPIED-------------" << std::endl;};
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


			// MapNode 		*getBegin() {

			// 	node_type *begin = this;

			// 	while(begin->_up)
			// 		begin = begin->_up;

			// 	return begin;
			// };

			node_type 		*getPrev(node_type *cur) {

				if (cur->_left) {
					cur = cur->_left;
					while (cur->_right)
						cur = cur->_right;
					return cur;
				}
				else if (cur->_up) {
					node_type *prev = cur;
					cur = cur->_up;
					while (_comp(prev->_value.first, cur->_value.first)) {
						prev = cur;
						if (!cur->_up)
							return NULL;
						cur = cur->_up;
					}
					return cur;
				}
				return NULL;
			};

			node_type 	const *getPrev(node_type *cur) const {

				if (cur->_left) {
					cur = cur->_left;
					while (cur->_right)
						cur = cur->_right;
					return cur;
				}
				else if (cur->_up) {
					node_type *prev = cur;
					cur = cur->_up;
					while (_comp(prev->_value.first, cur->_value.first)) {
						prev = cur;
						if (!cur->_up)
							return NULL;
						cur = cur->_up;
					}
					return cur;
				}
				return NULL;
			};

			node_type const		*getNext(node_type const *cur) const {

				if (cur->_right) {
					cur = cur->_right;
					while (cur->_left)
						cur = cur->_left;
					return cur;
				}
				else if (cur->_up) {
					node_type const *prev = cur;
					cur = cur->_up;
					while (!_comp(prev->_value.first, cur->_value.first)) {
						prev = cur;
						if (!cur->_up)
							return NULL;
						cur = cur->_up;
					}
					return cur;
				}
				return NULL;
			};

			node_type 		*getNext(node_type *cur) {

				if (cur->_right) {
					cur = cur->_right;
					while (cur->_left)
						cur = cur->_left;
					return cur;
				}
				else if (cur->_up) {
					node_type *prev = cur;
					cur = cur->_up;
					while (!_comp(prev->_value.first, cur->_value.first)) {
						prev = cur;
						if (!cur->_up)
							return NULL;
						cur = cur->_up;
					}
					return cur;
				}
				return NULL;
			};

			node_type 		*getLast(node_type *cur) {

				if (cur->_right)
					getLast(cur->_right);

				return cur;
			};

			node_type const 	*getLast(node_type *cur) const {

				if (cur->_right)
					getLast(cur->_right);

				return cur;
			};

			node_type 	*getBegin(node_type *cur) {

				if (cur->_left)
					getBegin(cur->_left);
				
				return cur;
			};

			node_type const 	*getBegin(node_type *cur) const {

				if (cur->_left)
					getBegin(cur->_left);
				
				return cur;
			};

			node_type 	*getParent(node_type *cur) {

				return cur->_up;
			};

			node_type const 	*getParent(node_type *cur) const {

				return cur->_up;
			};

			void 	setEnd(node_type *cur) {

				cur = getLast(cur);
				cur->_right = this;
				this->_up = cur; 
			};

			/*
				less returns bool x<y
				so if less(key, cur->value), go left
				if !left go right
			*/

			void	ditchParent(node_type *cur) {

				cur->_up = NULL;
			};

			void	ditchKids(node_type *cur) {

				cur->_left = NULL;
				cur->_right = NULL;
			};

			void	ditchAll(node_type *cur) {

				ditchKids(cur);
				ditchParent(cur);
			};


			node_type *addNode(node_type *cur, node_type const &node, node_type *end) {

				if (comp(node->_value.first, cur->value.first) && cur->_left)
					addPair(cur->_left, node, end);
				if (comp(cur->value.first, node->_value.first) && cur->_right != end)
					addPair(cur->_right, node, end);

				if (!comp(cur->value.first, node->_value.first) && !comp(cur->value.first, node->_value.first))
					return cur;
				
				if (comp(node->_value.first, cur->value.first) && !cur->_left) {
					cur->_left = node;
					cur->_left->_up = cur;
					return cur->_left;
				}
				if (comp(cur->value.first, node->_value.first) && (!cur->_right || cur->_right == end)) {
					cur->_right = node;
					cur->_right->_up = cur;
					return cur->_right;
				}

				return NULL; //shouldn't get there, i think all cases are covered above
			}

			node_type *initRoot(node_type *root, value_type const &pair) {

				node_type *end = root;
				root = new node_type();
				root->_value = pair;
				std::cout << "IN INIT ROOT index" << _value.first << "content" << _value.second << std::endl;
				root->_right = end;
				end->_up = root;

				return root;
			}

			node_type *addPair(node_type *cur, value_type const &pair, node_type *end) {

				if (_comp(pair.first, cur->_value.first) && cur->_left)
					addPair(cur->_left, pair, end);
				if (_comp(cur->_value.first, pair.first) && cur->_right != end)
					addPair(cur->_right, pair, end);

				if (!_comp(cur->_value.first, pair.first) && !_comp(cur->_value.first, pair.first))
					return cur;
				
				if (_comp(pair.first, cur->_value.first) && !cur->_left) {
					cur->_left = new node_type();
					cur->_left->_value = pair;
					cur->_left->_up = cur;
					return cur->_left;
				}
				if (_comp(cur->_value.first, pair.first) && (!cur->_right || cur->_right == end)) {
					cur->_right = new node_type();
					cur->_right->_value = pair;
					cur->_right->_up = cur;
					return cur->_right;
				}

				return NULL; //shouldn't get there, i think all cases are covered above
			}

			node_type *findKey(node_type *cur, key_type const &key, node_type *end) {

				if (cur == end)
					return NULL;			

				if (_comp(key, cur->_value.first) && cur->_left)
					findKey(cur->_left, key, end);
				if (_comp(cur->_value.first, key) && cur->_right)
					findKey(cur->_right, key, end);

				if (!_comp(cur->_value.first, key) && !_comp(cur->_value.first, key))
					return cur;
					
				return NULL;
			}

			// void 	addNext(value_type const &value) {

			// 	MapNode *newNode = new MapNode(value);

			// 	if (this->_next)
			// 		newNode->_next = this->_next;
			// 	this->_next = newNode;
			// 	newNode->_prev = this;
			// };

			// void 	addPrev(value_type const &value) {

			// 	MapNode *newNode = new MapNode(value);

			// 	if (this->_prev) {
			// 		newNode->_prev = this->_prev;
			// 		this->_prev->_next = newNode;
			// 	}
			// 	this->_prev = newNode;
			// 	newNode->_next = this;
			// };

			// void 	addPrevNode(node_type *newNode) {
		
			// 	newNode->_prev = this->_prev;
			// 	if (this->_prev) 
			// 		this->_prev->_next = newNode;
			
			// 	this->_prev = newNode;
			// 	newNode->_next = this;
			// };

			// void 	forgetNode() {
				
			// 	MapNode *prevNode = this->_prev; 
			// 	MapNode *nextNode = this->_next; 

			// 	if (prevNode)
			// 		prevNode->_next = nextNode;
			// 	if (nextNode)
			// 		nextNode->_prev = prevNode;
			// };

			// void 	delNode() {
				
			// 	forgetNode();
			// 	delete(this);
			// };

			// void 	linkNodes(node_type first, node_type second) {
			
			// 	if (first)
			// 		first->_next = second;
			// 	if (second)
			// 		second->_prev = first;
			// };
                                                      
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