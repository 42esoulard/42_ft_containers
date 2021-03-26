/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:57:18 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/21 11:39:19 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <limits>
#include <iostream>
#include "MapNode.hpp"

namespace ft {

	template < class value_type, class node_type >
	class MapIterator {

		public:

			MapIterator() {node_type tmp = node_type(); p = &tmp;};
			MapIterator(node_type *x) :p(x) {};
			MapIterator(const MapIterator& mit) : p(mit.p) {};

			MapIterator& operator++() {
				p = p->getNext(p);
				
				return *this;
			};

			MapIterator& operator--() {
				p = p->getPrev(p);
				
				return *this;
			};

			MapIterator operator++(int) {MapIterator tmp(*this); operator++(); return tmp;};
			MapIterator const operator++(int) const {MapIterator tmp(*this); operator++(); return tmp;};
			MapIterator operator--(int) {MapIterator tmp(*this); operator--(); return tmp;};
			MapIterator const operator--(int) const {MapIterator tmp(*this); operator--(); return tmp;};

			node_type *getNode() {return p;};

			bool operator==(const MapIterator& rhs) const {return p==rhs.p;};
			bool operator!=(const MapIterator& rhs) const {return p!=rhs.p;};
			value_type &operator*() const {return p->getValue();};

		private:

			node_type* p;
	};

	template < class value_type, class node_type >
	class MapReverse_Iterator : public MapIterator<value_type,node_type > {

		public:
			MapReverse_Iterator() {node_type *tmp; p = tmp;};
			MapReverse_Iterator(node_type *x) :p(x) {};
			MapReverse_Iterator(const MapReverse_Iterator& mit) : p(mit.p) {};

			MapReverse_Iterator<value_type,node_type >& operator++() {p = p->getPrev();return *this;};
			MapReverse_Iterator<value_type,node_type > operator++(int) {MapReverse_Iterator<value_type,node_type > tmp(*this); operator++(); return tmp;};
			bool operator==(const MapReverse_Iterator<value_type,node_type >& rhs) const {return p==rhs.p;}
			bool operator!=(const MapReverse_Iterator<value_type,node_type >& rhs) const {return p!=rhs.p;}
			value_type &operator*() const {return p->getValue();};

		private:

			node_type* p;
	};

	//************************************************************************************************

	template < class Key, class T, class Compare = std::less<Key> >
	class Map {

		public:

			// ALIASES:

			
			typedef Key 												key_type;
			typedef T 													mapped_type;
			typedef ft::Pair<const key_type, mapped_type> 				value_type;
			typedef Compare 											key_compare;
			typedef MapNode<key_type, mapped_type, key_compare>			node_type;
			typedef typename std::allocator<node_type> 					allocator_type;
			typedef value_type											&reference;
			typedef value_type const	 								&const_reference;
			typedef value_type 											*pointer;
			typedef value_type const	 								*const_pointer;
			typedef MapIterator<value_type, node_type> 					iterator;
			typedef MapIterator<value_type const, node_type const> 		const_iterator;
			typedef MapReverse_Iterator<value_type, node_type> 			reverse_iterator;
			typedef MapReverse_Iterator<value_type const, node_type const> const_reverse_iterator;
			typedef std::ptrdiff_t 										difference_type;
			typedef size_t 		  										size_type;
			
			//template <class Key, class T, class Compare, class Alloc>
			class value_compare {
				friend class Map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
					
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
					}
			};
			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/*\CONSTRUCTORS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			// >>> default
			explicit Map (const key_compare& comp = key_compare()) :
				_k_compare(comp), _v_compare(comp) {
				
				_root = new node_type();
				_begin = _root;
				_end = _begin;
				_size = 0;

			};

			// >>> range
			template <class InputIterator> Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare()) :
				_k_compare(comp), _v_compare(comp) {

		 		_root = new node_type();
				_begin = _root;
				_end = _begin;
				_size = 0;
		
				insert(first, last);
		 	};	
			
			// >>> copy 
			Map (const Map& x) :
				_k_compare(x._k_compare), _v_compare(x._v_compare) {

				_root = new node_type();
				_begin = _root;
				_end = _begin;
				_size = 0;
				std::cout << "IN CONSTR CPY other size" << x._size << std::endl;
		 		insert(x.begin(), x.end());
				std::cout << "IN CONSTR CPY size:" << _size << std::endl;
			}; 

			Map& operator= (const Map& x) {

				clear();
				insert(x.begin(), x.end());

				return *this;
			}; //destroy all content then copy


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/*\DESTRUCTORS/*\*/*\///
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			~Map() { 

				clear(); 
				delete _end; 
			};


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/*\*/ITERATORS/*\*/*\*//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			iterator 		begin() {

				return iterator(_begin);
			};

			const_iterator 	begin() const {

				return const_iterator(_begin);
			};

			iterator end() {

				return iterator(_end);
			};

			const_iterator end() const {

				return const_iterator(_end);
			};
			// points after last Map element

			// reverse_iterator rbegin() {

			// 	// if (_end->getPrev())
			// 	// 	return (reverse_iterator(_end->getPrev()));
			// 	// return (reverse_iterator(_end));
			// };

			// const_reverse_iterator rbegin() const {

			// 	// if (_end->getPrev())
			// 	// 	return (const_reverse_iterator(_end->getPrev()));
			// 	// return (const_reverse_iterator(_end));
			// };
			// // point to last element, incrementing actually decrements

			// reverse_iterator rend() {

			// 	// return (reverse_iterator(_begin->getPrev()));
			// };

			// const_reverse_iterator rend() const {

			// 	// return (const_reverse_iterator(_begin->getPrev()));
			// };
			// point to hypothetical element BEFORE first element


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/CAPACITY/*\*/*\*//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			bool empty() const {

				if (_size == 0)
					return true;
				return false;
			}

			size_type size() const {

				return _size;
			};

			size_type max_size() const {
				
				size_type maxDiff = std::numeric_limits<difference_type>::max();
				size_type maxVal = std::numeric_limits<size_type>::max() / (sizeof(node_type));
				
				if (maxDiff < maxVal)
					return maxDiff;
				return maxVal;
			};
			//returns max nb of elements Map can hold, due to system or library limitations


			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					//*\*/ELEMENT ACCESS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			mapped_type& operator[] (const key_type& k) {

				node_type *cur;
				if (_size) {
					cur = findKey(_root, k, _end);
					if (!cur) {
						cur = addPair(_root, value_type(k, mapped_type()), _end);
						_end->setEnd(_root);
						_begin = getBegin(_root);
						_size++;
					}
				}
				else {
					_root = node_type(value_type(k, mapped_type()));
					cur = _root;
					_end->setEnd(_root);
					_begin = _root;
					_size++;
				}

				return cur->_value.second;
			};
				//search for key , return ref to its mapped_value (content)
				//if key k not found:
					//insert new elem with key k and default mapped_value mapped_value()
					//_size++
					//return ref to its defaulted mapped_value
			


			//----------------------------------------------//
			

					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/MODIFIERS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			// >>> single element
			std::pair<iterator,bool> insert (const value_type& val) {

				node_type *newNode;
				if (_size) {
					if ((newNode = _root->findKey(_root, val.first, _end)))
						return std::pair<iterator,bool>(iterator(newNode), false);
					newNode = _root->addPair(_root, val, _end);
					std::cout << "insert: pair added" << std::endl;
					_begin = _root->getBegin(_root);
				}
				else {
					newNode = _root->initRoot(_root, val);
					_begin = _root;
					std::cout << "insert: initiating root" << std::endl;
				}			
				_size++;
				std::cout << "insert: new size = " << _size << "begin index " << (*begin()).first << "content" << (*begin()).second << std::endl;
				std::cout << "insert: new size = " << _size << "root index " << (*iterator(_root)).first << "content" << (*iterator(_root)).second << std::endl;
				_end->setEnd(_root);
				
				return std::pair<iterator,bool>(iterator(newNode), true);

			};
			//return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key 

			// >>> with hint
			iterator insert (iterator position, const value_type& val) {

				std::cout << "INSERT POS VAL" << std::endl;
				node_type *newNode;
				if (_size) {
					//newNode = _root->findKey(position, val.first, _end);
					if ((newNode = _root->findKey(position, val.first, _end)) || (newNode = _root->findKey(_root, val.first, _end)))
						return std::pair<iterator,bool>(iterator(newNode), false);
					newNode = addPair(_root, val, _end);
					_begin = getBegin(_root);
				}
				else {
					newNode = _root->initRoot(_root, val);
					_begin = _root;
				}
				_size++;
				_end->setEnd(_root);
				
				return iterator(newNode);
			}; 
			//return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.
    		
			// >>> range
			template <class InputIterator>
    		void insert (InputIterator first, InputIterator last) {

				std::cout << "INSERT RANGE" << std::endl;
				while (first != last) {
					std::cout << "INSERT RANGE in loop" << std::endl;
					this->insert(*first);
					first++;
				}
				std::cout << "IN insert it aft" << _size << std::endl;
			};
    		//Extend the container by inserting new elements before the element at the specified position

			void erase (iterator position) {
				
				if (!_size)
					return;

				node_type *toDel = position.getNode();

				node_type *parent = getParent(toDel);
				if (!parent) {
					parent = getPrev(toDel);
					if (!parent)
						parent = getNext(toDel);
					if (!parent) {
						delete(toDel);
						_root = _end;
						_begin = _end;
						_size = 0;
						return;
					}
					_root = parent;
				}
				parent->ditchKids();

				iterator first = _root->getBegin(position.getNode());
				iterator last = _root->getLast(position.getNode());
				iterator next = first;
				while (first != last) {
					next++;
					if (first.getNode() != parent && first.getNode() != toDel) {
						first.getNode()->ditchAll();
						addNode(_root, first.getNode(), _end);
					}
					first = next;
				}
				delete(toDel);
				_end->setEnd(_root);
				_begin = getBegin(_root);
				_size--;
			};

			size_type erase (const key_type &k) {
				
				size_type ret = 0;

				if (!_size)
					return ret;

				node_type *toDel = _root->findKey(_root, k, _end);
				if (toDel) {
					ret = 1;
					erase(iterator(toDel));
				}
				return ret;
			};
			//returns the nb of elements removed
			
			void erase (iterator first, iterator last) {
				
				iterator next = first;

				while (first != last) {
					next++;
					erase(first);
					first = next;
				}
			};
			// remove & destroy a range of elements. 

			void swap (Map& x) {

				node_type *tmp;
				int sz = _size;

				tmp = _begin;
				_begin = x._begin;
				x._begin = tmp;

				// tmp = _end;
				// _end = x._end;
				// x._end = tmp;

				_size = x._size;
				x._size = sz;
			};
			//exchange content with container of the same type

			void clear() {
				
				if (!_size)
					return ;
				
				iterator first = _root->getBegin(_root);
				iterator last = end(); 
				
				iterator next = first;

				while (first != last) {
					next++;
					delete(first.getNode());
					first = next;
				}
				_root = _end;
				_begin = _end;
				_size = 0;
			};
			//removes all elements (size == 0)
			

			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/OBSERVERS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			key_compare key_comp() const {
				return _k_compare;
			};
			//my key_compare member, if I got that right

			value_compare value_comp() const {
				return _v_compare;
			};

			//----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\*/OPERATIONS/*\*/*//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

			iterator find (const key_type& k) {

				node_type *node = _root->findKey(_root, k, _end);

				if (node)
					return (iterator(node));

				return (iterator(_end));
			};
			// return it to matching element if found, else iterator to end 

			const_iterator find (const key_type& k) const {

				node_type *node = findKey(_root, k, _end);

				if (node)
					return (const_iterator(node));

				return (const_iterator(_end));
			};
			// return it to matching element if found, else iterator to end 

			size_type count (const key_type& k) const {

				node_type *node = findKey(_root, k, _end);

				size_type ret = 0;
				if (node)
					ret = 1;

				return ret;
			};
			// return 1 if element is found, else 0

			iterator lower_bound (const key_type& k) {

				iterator first = getBegin(_root);
				iterator last = getLast(_root);

				while (first != last) {
					if (!_k_compare((*first).first, k))
						return first;
				}
				return iterator(_end);
			};
			// return an iterator to the first element for which key_comp(element_key,k) would return false

			const_iterator lower_bound (const key_type& k) const {
				
				iterator first = getBegin(_root);
				iterator last = getLast(_root);

				while (first != last) {
					if (!_k_compare((*first).first, k))
						return const_iterator(first->getNode());
				}
				return const_iterator(_end);
			};
			// return an iterator to the first element for which key_comp(element_key,k) would return false

			iterator upper_bound (const key_type& k) {

				iterator first = getBegin(_root);
				iterator last = getLast(_root);

				while (first != last) {
					if (_k_compare((*first).first, k))
						return first;
				}
				return iterator(_end);
			};
			// return an iterator to the first element for which key_comp(element_key,k) would return true

			const_iterator upper_bound (const key_type& k) const {

				iterator first = getBegin(_root);
				iterator last = getLast(_root);

				while (first != last) {
					if (_k_compare((*first).first, k))
						return const_iterator(first->getNode());
				}
				return const_iterator(_end);
			};
			// return an iterator to the first element for which key_comp(element_key,k) would return true

			std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
			
				// node_type *node = findKey(_root, k);

				// if (node)
				// 	return pair(const_iterator(node), const_iterator(node));

				// iterator first = getBegin(_root);
				// iterator last = getLast(_root);

				// while (first != last) {
				// 	if (!_k_compare((*first).first), k)
				// 		return pair(const_iterator(first->getNode()), const_iterator(first->getNode()));
				// 	first++;
				// }
				// return (pair(const_iterator(_end), const_iterator(_end));
				return pair(lower_bound(k), upper_bound(k));
			};
			// returns element with k equivalent to k (for which key_comp returns fals whatever order of the elems)
			// If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).

			std::pair<iterator,iterator>             equal_range (const key_type& k) {
				// node_type *node = findKey(_root, k);

				// if (node)
				// 	return pair(const_iterator(node), const_iterator(node));

				// iterator first = getBegin(_root);
				// iterator last = getLast(_root);

				// while (first != last) {
				// 	if (!_k_compare((*first).first), k)
				// 		return pair(iterator(first->getNode()), iterator(first->getNode()));
				// 	first++;
				// }
				// return (pair(iterator(_end), iterator(_end));
				return pair(lower_bound(k), upper_bound(k));
			};
			// returns element with k equivalent to k (for which key_comp returns fals whatever order of the elems)
			// If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element that has a key considered to go after k according to the container's internal comparison object (key_comp).

		private:

			node_type 			*_root;
			node_type 			*_begin;
			node_type 			*_end;
			allocator_type 		_allocator;
			size_type 			_size;
			key_compare 		_k_compare;
			value_compare 		_v_compare;
			
	};
};

#endif