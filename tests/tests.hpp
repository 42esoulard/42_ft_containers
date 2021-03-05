/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:44:45 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/05 15:48:51 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H

#include <string>

class customException : public std::exception {
			
	public:
		customException(std::string const &str) : _err(str) {};
		virtual char const *what() const _NOEXCEPT {return _err.c_str();};
        virtual ~customException() _NOEXCEPT;
	
	protected:
		std::string const _err;	
};



typedef int (*testsPtr)();

/*----------LIST TESTS----------*/
/*     [in List_tests.cpp]      */

int test_pushBack_iterate();
int test_front_back();
int test_fillConstr();
int test_rangeConstr();
int test_copyConstr();
int test_opEqual();
int test_pushFront();
int test_popFront();
int test_popBack();
int test_insert();
int test_erase();
int test_swap();
int test_resize();
int test_clear();
int test_splice();
int test_remove();
int test_removeIf();
int test_unique();
int test_merge();
int test_sort();
int test_nonMembers();

testsPtr listTests[21] = {&test_pushBack_iterate, &test_front_back, &test_fillConstr, &test_rangeConstr, &test_copyConstr,
                        &test_opEqual, &test_pushFront, &test_popFront, &test_popBack, &test_insert,
                        &test_erase, &test_swap, &test_resize, &test_clear, &test_splice, 
                        &test_remove, &test_removeIf, &test_unique, &test_merge, &test_sort,
                        &test_nonMembers};


/*----------VECTOR TESTS----------*/
/*     [in Vector_tests.cpp]      */

/*----------MAP TESTS----------*/
/*     [in Map_tests.cpp]      */

/*----------STACK TESTS----------*/
/*     [in Stack_tests.cpp]      */

/*----------QUEUE TESTS----------*/
/*     [in Queue_tests.cpp]      */

#endif