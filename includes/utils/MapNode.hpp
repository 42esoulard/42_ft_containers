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
			Pair() : first(), second() {};
			Pair(Pair<Key, T> const &other) : first(other.first), second(other.second) {};
			Pair(Key const &key, T const &content) : first(key), second(content) {};
			virtual ~Pair() {};
			
			Pair &operator=(Pair const &other) {

				first = other.first; 
				second = other.second;
				return (*this);
			}
			Pair &operator=(T const &other) {

				// std::cout << "fuckfuckfuckfuck" << std::endl;
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
			typedef std::pair<const key_type, mapped_type> 				value_type;
			typedef Compare 											key_compare;
			typedef MapNode<Key, T, Compare> 							node_type;

			MapNode() 							: _value(), _up(NULL), _left(NULL), _right(NULL) {};
			MapNode(value_type const &value) 	: _value(value), _up(NULL), _left(NULL), _right(NULL) {};
			MapNode(node_type const &src) 		: _value(src._value), _up(src._up), _left(src._left), _right(src._right) {};
			~MapNode() {}

			MapNode &operator=(MapNode const &src) {

				//std::cout << "AAAAAAAAAAAAAAAAA" << std::endl;
				this->_value = src._value;
				this->_up = src._up;
				this->_left = src._left;
				this->_right = src._right;

				return (*this);
			}

			MapNode &operator=(mapped_type const &src) {

				this->_value.second = src;
				// std::cout << "op= value" << std::endl;
				// this->_up = src._up;
				// this->_left = src._left;
				// this->_right = src._right;

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

				node_type *ret = cur;

				if (ret->_left) {
					ret = ret->_left;
					while (ret->_right)
						ret = ret->_right;
					return ret;
				}
				else if (ret->_up) {
					node_type *prev = ret;
					ret = ret->_up;
					while (_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type 	const *getPrev(node_type *cur) const {

				node_type *ret = cur;

				if (ret->_left) {
					ret = ret->_left;
					while (ret->_right)
						ret = ret->_right;
					return ret;
				}
				else if (ret->_up) {
					node_type *prev = ret;
					ret = ret->_up;
					while (_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type const		*getNext(node_type const *cur) const {

				node_type const *ret = cur;

				if (ret->_right) {
					ret = ret->_right;
					while (ret->_left)
						ret = ret->_left;
					return ret;
				}
				else if (ret->_up) {
					node_type const *prev = ret;
					ret = ret->_up;
					while (!_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type 		*getNext(node_type *cur) {

				node_type *ret = cur;

				if (ret->_right) {
					ret = ret->_right;
					while (ret->_left)
						ret = ret->_left;
					return ret;
				}
				else if (ret->_up) {
					node_type *prev = ret;
					ret = ret->_up;
					while (!_comp(prev->_value.first, ret->_value.first)) {
						prev = ret;
						if (!ret->_up)
							return NULL;
						ret = ret->_up;
					}
					return ret;
				}
				return NULL;
			};

			node_type 		*getLast(node_type *cur, node_type *end) {

				node_type *last = cur;
				if (last->_right && last->_right != end)
					last = last->_right;
			//	std::cout << "curLast index["<< last->_value.first<< "] mapped value [" << last->_value.second << "]" << std::endl;
				return last;
			};

			node_type const 	*getLast(node_type *cur, node_type *end) const {

				node_type *last = cur;
				if (last->_right && last->_right != end)
					last = last->_right;
			//	std::cout << "curLast index["<< last->_value.first<< "] mapped value [" << last->_value.second << "]" << std::endl;
				return last;
			};

			node_type 	*getBegin(node_type *cur) {
				
				node_type *beg = cur;
				while (beg->_left)
					beg = beg->_left;
				
			//	std::cout << ">>>getBegin index["<< cur->_value.first<< "] mapped value [" << cur->_value.second << "]" << std::endl;
				return beg;
			};

			node_type const 	*getBegin(node_type *cur) const {

				if (cur->_left)
					getBegin(cur->_left);
				
				return cur;
			};

			node_type 	*getParent() {

				return _up;
			};

			node_type const 	*getParent() const {

				return _up;
			};

			void 	setEnd(node_type *cur) {

				node_type *last = getLast(cur, this);
			//	std::cout << "IN SETEND AFTER GET LAST" << std::endl;
				last->_right = this;
				this->_up = last; 
			};

			/*
				less returns bool x<y
				so if less(key, cur->value), go left
				if !left go right
			*/

				
			

			node_type *nextExtremity(node_type *cur, node_type *end) {

				if ((!(cur->_right) || cur->_right == end) && !(cur->_left))
					return cur ;
				if (cur->_left)
					nextExtremity(cur->_left, end);
				if (cur->_right && cur->_right != end)
					nextExtremity(cur->_right, end);
				return cur;
			};

			void	ditchParent(node_type *cur) {

				cur->_up = NULL;
			};

			void	ditchKids(node_type *cur) {

				cur->_left = NULL;
				cur->_right = NULL;
			};

			void	ditchKid(node_type *kid) {

				if (this->_left == kid)
					this->_left = NULL;
				else if (this->_right == kid)
					this->_right = NULL;
			};

			void	ditchAll(node_type *cur) {

				ditchKids(cur);
				ditchParent(cur);
			};


			node_type *addNode(node_type *cur, node_type *node, node_type *end) {

				if (_comp(node->_value.first, cur->_value.first) && cur->_left)
					addNode(cur->_left, node, end);
				if (_comp(cur->_value.first, node->_value.first) && cur->_right != end)
					addNode(cur->_right, node, end);

				if (!_comp(cur->_value.first, node->_value.first) && !_comp(cur->_value.first, node->_value.first))
					return cur;
				
				if (_comp(node->_value.first, cur->_value.first) && !cur->_left) {
			//		cur->_left = node;
			//		cur->_left->_up = cur;
					return cur->_left;
				}
				if (_comp(cur->_value.first, node->_value.first) && (!cur->_right || cur->_right == end)) {
				//	cur->_right = node;
				//	cur->_right->_up = cur;
					return cur->_right;
				}

				return NULL; //shouldn't get there, i think all cases are covered above
			}

			node_type *findSpot(node_type *cur, key_type k, node_type *beg, node_type *end) {
				
			//	std::cout << "findSpot cur key " << cur->_value.first << " k " << k << std::endl;
			//	std::cout << "beg key " << beg->_value.first << " k " << k << std::endl;
				if (!_comp(cur->_value.first, k) && (!cur->_left || cur == beg)) {
			//		cur->_left = node;
			//		cur->_left->_up = cur;
			//		std::cout << "left returning cur " << cur->_value.first << std::endl;
					return cur;
				}
				if (_comp(cur->_value.first, k) && (!cur->_right || cur->_right == end)) {
				//	cur->_right = node;
				//	cur->_right->_up = cur;
				//	std::cout << "right returning cur " << cur->_value.first << std::endl;
					return cur;
				}

			//	std::cout << "findSpot cur key " << cur->_value.first << " k " << k << std::endl;

				if (_comp(k, cur->_value.first) && cur->_left && cur != beg)
					return findSpot(cur->_left, k, beg, end);
				if (_comp(cur->_value.first, k) && cur->_right && cur->_right != end)
					return findSpot(cur->_right, k, beg, end);

				

				return NULL;
			};

		
			void adopt(node_type *kid, node_type *end) {
				// std::cout << "adopt beg" << std::endl;
				if (_comp(kid->_value.first, this->_value.first))
					this->_left = kid;
				else {
					if (this->_right == end) {
						kid->_right = end;
						end->_up = kid;
						// std::cout << "end transfer OKOK" << std::endl;
					}
					this->_right = kid;
				}
				kid->_up = this;
				// std::cout << "adopt end" << std::endl;
			};

			void initRoot(node_type *begin, node_type *end) {

				// node_type *end = root;
				// root = new node_type(pair);
			//	root->_value = pair;
			//	std::cout << "IN INIT ROOT index" << _value.first << "content" << _value.second << std::endl;
				this->_left = NULL;
				begin = this;
				this->_right = end;
				end->_up = this;

			}

			// node_type *addPair(node_type *cur, value_type const &pair, node_type *end) {

			// 	if (_comp(pair.first, cur->_value.first) && cur->_left)
			// 		addPair(cur->_left, pair, end);
			// 	if (_comp(cur->_value.first, pair.first) && cur->_right != end)
			// 		addPair(cur->_right, pair, end);

			// 	if (!_comp(cur->_value.first, pair.first) && !_comp(cur->_value.first, pair.first))
			// 		return cur;
				
			// 	if (_comp(pair.first, cur->_value.first) && !cur->_left) {
			// 		//cur->_left = new node_type(pair);
			// 		std::cout << "add pair in left" << std::endl;
			// 	//	cur->_left->_value = pair;
			// 		//cur->_left->_up = cur;
			// 		return cur->_left;
			// 	}
			// 	if (_comp(cur->_value.first, pair.first) && (!cur->_right || cur->_right == end)) {
			// 		//cur->_right = new node_type(pair);
			// 		//std::cout << "add pair in right" << std::endl;
			// 		//cur->_right->_value = pair;
			// 		//cur->_right->_up = cur;
			// 		return cur->_right;
			// 	}

			// 	return NULL; //shouldn't get there, i think all cases are covered above
			// }

			node_type *findKey(node_type *cur, key_type const &key, node_type *end) {

				if (cur == end)
					return NULL;
								
			//	std::cout << "before sgv key " << key << " cur key " << cur->_value.first << std::endl;
				if (!_comp(cur->_value.first, key) && !_comp(key, cur->_value.first)) {
			//		std::cout << "GOT A MATCH!!" << std::endl;
					return cur;
				}

				if (_comp(key, cur->_value.first) && cur->_left && cur->_left != end)
					return findKey(cur->_left, key, end);
				if (_comp(cur->_value.first, key) && cur->_right && cur->_right != end)
					return findKey(cur->_right, key, end);
				// std::cout << "before sgv key " << key << " cur key " << cur->_value.first << std::endl;
				// if (!_comp(cur->_value.first, key) && !_comp(key, cur->_value.first))
				// 	return cur;
			//	std::cout << "before sgv no match key " << key << " cur key " << cur->_value.first << std::endl;
				return NULL;
			}

			void deleteAll(node_type *cur, node_type *end) {

				if (!cur || cur == end)
					return ;
				deleteAll(cur->_left, end);
				deleteAll(cur->_right, end);
				delete cur;
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