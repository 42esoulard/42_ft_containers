/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListNode.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/12 13:19:10 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

namespace ft {

	template <class T>
	class ListNode {

		public:
			typedef T 					value_type;
			typedef ListNode<value_type> 	node_type;

			ListNode() : _value(), _prev(NULL), _next(NULL) {};
			ListNode(value_type const &value) : _value(value),  _prev(NULL), _next(NULL) {};
			ListNode(ListNode const &src) : _value(src._value), _prev(src._prev), _next(src._next) {};
			~ListNode() {}

			ListNode &operator=(ListNode const &src) {
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
			
			ListNode 		*getNext() {
				return _next;
			};

			ListNode const 	*getNext() const {
				return _next;
			};

			ListNode	*getPrev() {
				return _prev;
			};

			ListNode const	*getPrev() const {
				return _prev;
			};

			void resetNode() {
				_next = NULL;
				_prev = NULL;
			};

			ListNode 		*getBegin() {
				ListNode *begin = this;

				while(begin->_prev)
					begin = begin->_prev;
				return begin;
			};

			void 	addNext(value_type const &value) {
				ListNode *newNode = new ListNode(value);
				if (this->_next)
					newNode->_next = this->_next;
				this->_next = newNode;
				newNode->_prev = this;
			};

			void 	addPrev(value_type const &value) {
				ListNode *newNode = new ListNode(value);
				if (this->_prev) {
					newNode->_prev = this->_prev;
					this->_prev->_next = newNode;
				}
				this->_prev = newNode;
				newNode->_next = this;
			};

			void 	addPrevNode(node_type *newNode) {
				//<-       ->
				//  newNode this
				newNode->_prev = this->_prev;
				if (this->_prev) 
					this->_prev->_next = newNode;
			
				this->_prev = newNode;
				newNode->_next = this;
			};
							//	begin       		end
			void 	delNode() {//node0 node1 node2 endNode
				//case: pop_front = gotta rm node0
				
				ListNode *prevNode = this->_prev; //NULL
				ListNode *nextNode = this->_next; //node1

				if (prevNode)//si size != 0
					prevNode->_next = nextNode;
				if (nextNode)
					nextNode->_prev = prevNode;
				delete(this);
			};

										//	begin       		end
			void 	forgetNode() {//node0 node1 node2 endNode NO DELETE
				//case: pop_front = gotta rm node0
				
				ListNode *prevNode = this->_prev; //NULL
				ListNode *nextNode = this->_next; //node1

				if (prevNode)//si size != 0
					prevNode->_next = nextNode;
				if (nextNode)
					nextNode->_prev = prevNode;
			};

			void 	linkNodes(node_type first, node_type second) {//node0 node1 node2 endNode NO DELETE
				//case: pop_front = gotta rm node0

				if (first)//si size != 0
					first->_next = second;
				if (second)
					second->_prev = first;
			};
                                                        //   <-  -><-  -><-  -><-  ->
			void 	swapNodes(node_type *one, node_type *two) {//beg node1 node2 end should become beg node2 node1 end

			//	std::cout << "fffffcuk" <<std::endl;
				ListNode *stock = two->_next;

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