/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:09:27 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/20 12:36:38 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <limits>
#include <iostream>
#include "ft_containers.h"

namespace ft {

    template <class T, class Container = ft::List<T> > 
    class Stack {
      
      public:
            typedef T 									value_type;
            typedef Container 							container_type;
            typedef size_t  							size_type;
           
           
            //----------------------------------------------//
           
           
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
                    //*\*/*\CONSTRUCTORS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*///

            explicit Stack (const container_type& ctnr = container_type()) : _container(ctnr) {
            };


            //----------------------------------------------//


                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
                    //*\*/*\MEMBER FUNCTIONS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///

            bool empty() const {

                return _container.empty();
            };

            size_type size() const {

                return _container.size();
            };

            value_type& top() {

                return _container.back();
            };
            
            const value_type& top() const {

                return _container.back();
            };

            void push(const value_type& val) {

                _container.push_back(val);
            };

            void pop() {
                
                _container.pop_back();
            };

        private:
            container_type _container;

			template <class A, class B>
			friend bool	operator==(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator!=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator<(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator<=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);

			template <class A, class B>
			friend bool	operator>(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
            
			template <class A, class B>
			friend bool	operator>=(const Stack<A, B> &lhs, const Stack<A, B> &rhs);
    };

	
	//----------------------------------------------//


            //*\*/*\/*\*/*\/*\*/*\/*\*///
            ///*\*/*\NON-MEMBERS/*\*/*\//
            //*\*/*\/*\*/*\/*\*/*\/*\*///

    template <class T, class Container>
    bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {

        return lhs._container == rhs._container;
    };

    template <class T, class Container>
    bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {
        
        return lhs._container != rhs._container;
    };

    template <class T, class Container>
    bool operator<  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {

         return lhs._container < rhs._container;
     };

    template <class T, class Container>
    bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {

        return lhs._container <= rhs._container;
    };

    template <class T, class Container>
    bool operator>  (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {

        return lhs._container > rhs._container;
    };

    template <class T, class Container>
    bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs) {

        return lhs._container >= rhs._container;
    };

};

#endif 