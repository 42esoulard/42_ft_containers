/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:09:27 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/20 17:02:32 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <limits>
#include <iostream>
#include "ft_containers.h"

namespace ft {

    template <class T, class Container = ft::List<T> > 
    class Queue {
      
      public:
            typedef T 									value_type;
            typedef Container 							container_type;
            typedef size_t  							size_type;
           
           
            //----------------------------------------------//
           
           
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
                    //*\*/*\CONSTRUCTORS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*///

            explicit Queue (const container_type& ctnr = container_type()) : _container(ctnr) {
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

            value_type& front() {

                return _container.front();
            };

            const value_type& front() const {

                return _container.front();
            };

            value_type& back() {

                return _container.back();
            };
            
            const value_type& back() const {

                return _container.back();
            };

            void push(const value_type& val) {

                _container.push_back(val);
            };

            void pop() {
                
                _container.pop_front();
            };

        private:
            container_type _container;

			template <class A, class B>
			friend bool	operator==(const Queue<A, B> &lhs, const Queue<A, B> &rhs);

			template <class A, class B>
			friend bool	operator!=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);

			template <class A, class B>
			friend bool	operator<(const Queue<A, B> &lhs, const Queue<A, B> &rhs);

			template <class A, class B>
			friend bool	operator<=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);

			template <class A, class B>
			friend bool	operator>(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
            
			template <class A, class B>
			friend bool	operator>=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
    };

	
	//----------------------------------------------//


            //*\*/*\/*\*/*\/*\*/*\/*\*///
            ///*\*/*\NON-MEMBERS/*\*/*\//
            //*\*/*\/*\*/*\/*\*/*\/*\*///

    template <class T, class Container>
    bool operator== (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

        return lhs._container == rhs._container;
    };

    template <class T, class Container>
    bool operator!= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {
        
        return lhs._container != rhs._container;
    };

    template <class T, class Container>
    bool operator<  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

         return lhs._container < rhs._container;
     };

    template <class T, class Container>
    bool operator<= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

        return lhs._container <= rhs._container;
    };

    template <class T, class Container>
    bool operator>  (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

        return lhs._container > rhs._container;
    };

    template <class T, class Container>
    bool operator>= (const Queue<T,Container>& lhs, const Queue<T,Container>& rhs) {

        return lhs._container >= rhs._container;
    };

};

#endif 