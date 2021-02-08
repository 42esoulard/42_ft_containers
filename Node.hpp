/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:37:03 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/08 15:22:12 by esoulard         ###   ########.fr       */
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
			
			Node 		*getNext() {
				return _next;
			};

			Node 		*getPrev() {
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

		private :
			value_type 		_value;
			node_type 		*_prev;
			node_type 		*_next;

	};
};

#endif