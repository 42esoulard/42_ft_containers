/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stella <stella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/02 14:30:43 by stella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

	template <class T>
	class Node {

		public:
			typedef T 					value_type;
			typedef Node<value_type> 	node_type;

			Node() : _value(), _prev(nullptr), _next(nullptr) {};
			Node(value_type const &value) : _value(value),  _prev(nullptr), _next(nullptr) {};
			Node(Node const &src) : _value(src._value), _prev(src._prev), _next(src._next) {};
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

			void 	addPrevNode(node_type const &newNode) {
			
				if (this->_prev) {
					newNode->_prev = this->_prev;
					this->_prev->_next = newNode;
				}
				this->_prev = newNode;
				newNode->_next = this;
			};
							//	begin       		end
			void 	delNode() {//node0 node1 node2 endNode
				//case: pop_front = gotta rm node0
				
				Node *prevNode = this->_prev; //nullptr
				Node *nextNode = this->_next; //node1

				if (prevNode)//si size != 0
					prevNode->_next = nextNode;
				if (nextNode)
					nextNode->_prev = prevNode;
				delete(this);
			};

		private :
			value_type 		_value;
			node_type 		*_prev;
			node_type 		*_next;

	};
};

#endif