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

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

namespace ft {

	template <class T>
	class VectorNode {

		public:
			typedef T 					value_type;
			typedef VectorNode<value_type> 	node_type;

			VectorNode() : _value() {};
			VectorNode(value_type const &value) : _value(value) {};
			VectorNode(VectorNode const &src) : _value(src._value) {};
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

			// void resetNode() {
			// 	_next = NULL;
			// 	_prev = NULL;
			// };

			// VectorNode 		*getBegin() {
			// 	VectorNode *begin = this;

			// 	while(begin->_prev)
			// 		begin = begin->_prev;
			// 	return begin;
			// };

			// void 	addNext(value_type const &value) {
			// 	VectorNode *newNode = new VectorNode(value);
			// 	if (this->_next)
			// 		newNode->_next = this->_next;
			// 	this->_next = newNode;
			// 	newNode->_prev = this;
			// };

			// void 	addPrev(value_type const &value) {
			// 	VectorNode *newNode = new VectorNode(value);
			// 	if (this->_prev) {
			// 		newNode->_prev = this->_prev;
			// 		this->_prev->_next = newNode;
			// 	}
			// 	this->_prev = newNode;
			// 	newNode->_next = this;
			// };

			// void 	addPrevNode(node_type *newNode) {
			// 	//<-       ->
			// 	//  newNode this
			// 	newNode->_prev = this->_prev;
			// 	if (this->_prev) 
			// 		this->_prev->_next = newNode;
			
			// 	this->_prev = newNode;
			// 	newNode->_next = this;
			// };
			// 				//	begin       		end
			// void 	delNode() {//node0 node1 node2 endNode
			// 	//case: pop_front = gotta rm node0
				
			// 	VectorNode *prevNode = this->_prev; //NULL
			// 	VectorNode *nextNode = this->_next; //node1

			// 	if (prevNode)//si size != 0
			// 		prevNode->_next = nextNode;
			// 	if (nextNode)
			// 		nextNode->_prev = prevNode;
			// 	delete(this);
			// };

			// 							//	begin       		end
			// void 	forgetNode() {//node0 node1 node2 endNode NO DELETE
			// 	//case: pop_front = gotta rm node0
				
			// 	VectorNode *prevNode = this->_prev; //NULL
			// 	VectorNode *nextNode = this->_next; //node1

			// 	if (prevNode)//si size != 0
			// 		prevNode->_next = nextNode;
			// 	if (nextNode)
			// 		nextNode->_prev = prevNode;
			// };

			// void 	linkNodes(node_type first, node_type second) {//node0 node1 node2 endNode NO DELETE
			// 	//case: pop_front = gotta rm node0

			// 	if (first)//si size != 0
			// 		first->_next = second;
			// 	if (second)
			// 		second->_prev = first;
			// };
            //                                             //   <-  -><-  -><-  -><-  ->
			// void 	swapNodes(node_type *one, node_type *two) {//beg node1 node2 end should become beg node2 node1 end

			// //	std::cout << "fffffcuk" <<std::endl;
			// 	VectorNode *stock = two->_next;

			// 	one->_next = two->_next;
			// 	two->_next = one;
			// 	if (one->_prev)
			// 		one->_prev->_next = two;
			// 	if (stock)
			// 		stock->_prev = one;
			// 	stock = one->_prev;
			// 	one->_prev = two;
			// 	two->_prev = stock;
			// };
			
		private :
			value_type 		_value;
	};
};

#endif