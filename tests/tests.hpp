/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:44:45 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/18 10:53:03 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H

#if defined(__linux__)
	#define _NOEXCEPT _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
#endif

# define WIDTH 60

#include "ft_containers.h"

#include <iomanip>
#include <string>
#include <sstream>

class customException : public std::exception {
			
	public:
		customException(std::string const &str) : _err(str) {};
		virtual char const *what() const _NOEXCEPT {return _err.c_str();};
       	virtual ~customException() _NOEXCEPT {};

	protected:
		std::string const _err;	
};


template <class ft_class, class std_class>
void output_containers(ft_class ft_container, std_class std_container, std::string const &type, std::ostream &o) {

	int ft_size = ft_container.size();
	int std_size = std_container.size();

	std::string tmp;
	std::string a;
	std::stringstream conv;
	std::setfill(' ');

	tmp = "------------------------------------";
	int nb = (WIDTH - tmp.size()) / 2;
	o << std::endl << std::string( nb, ' ' ) << tmp << std::endl;

	tmp = "- SIZE -";
	nb = (WIDTH - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;

	conv << ft_size;
	tmp = "ft_" + type + ": <" + conv.str() + ">";
	conv.str(std::string());
	nb = (WIDTH - tmp.size()) / 2;
	o << tmp << std::string( nb, ' ' );

	conv << std_size;
	tmp = "std_" + type + ": <" + conv.str() + ">";
	conv.str(std::string());
	nb = (WIDTH - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;
	//o << std::setw(step) << "std_" << type << ": " << std_size << std::endl;

	tmp =  "- CONTENT -";
	nb = (WIDTH - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;

	tmp = "ft_" + type + ": ";
	nb = (WIDTH - tmp.size()) / 2;
	o << tmp << std::string( nb, ' ' );

	tmp = "std_" + type + ": ";
	nb = (WIDTH - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;

	typename ft_class::iterator ft_it = ft_container.begin();
	typename ft_class::iterator ft_ite = ft_container.end();
	
	typename std_class::iterator std_it = std_container.begin();
	typename std_class::iterator std_ite = std_container.end();

	int i = -1;
	int max = std_size;

	if (ft_size > std_size)
		max = ft_size;
	while (++i < max) {
		if (ft_it != ft_ite) {
			conv << *ft_it;
			nb = (WIDTH - conv.str().size()) / 2;
			o << "[" << conv.str() << "]" << std::string( nb, ' ' );
			conv.str(std::string());
			ft_it++;
		}
		else
			o << std::string(WIDTH/2 + 2, ' ' );
		if (std_it != std_ite) {
			conv << *std_it;
			nb = (WIDTH - conv.str().size()) / 2;
			o << std::string( nb, ' ' ) << "[" << conv.str() << "]" << std::endl;
			conv.str(std::string());
			std_it++;
		}
		else
			o << std::string(WIDTH/2, ' ' ) << std::endl;
	}

	tmp = "------------------------------------";
	nb = (WIDTH - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;
};

template <class ft_class, class std_class>
void handle_error(ft_class ft_container, std_class std_container, std::string const &type, std::string const &func, 
	std::string const &testInfo, std::string const &errorTheme) {
			std::cout << std::setfill('.') << std::setw(WIDTH - func.size()) << " ✘" << std::endl;
			std::cerr << ">---FAIL--->>>  ON FUNCTION: " << func << std::endl;
			if (testInfo.size())
				std::cerr << std::string(15, ' ') << " Test info: " << testInfo << std::endl;
			output_containers(ft_container, std_container, type, std::cerr);
			throw customException("ft_container " + errorTheme + " doesn't match std::container's!");
};

template <class ft_class, class std_class>
int chk_result(ft_class ft_container, std_class std_container, std::string const &type, std::string const &func, std::string const &testInfo = "") {

	if (ft_container.size() != std_container.size())
		handle_error(ft_container, std_container, type, func, testInfo, "SIZE");

	typename ft_class::iterator ft_it = ft_container.begin();
	typename ft_class::iterator ft_ite = ft_container.end();
	
	typename std_class::iterator std_it = std_container.begin();

	
	for (ft_it = ft_container.begin(); ft_it != ft_ite; ft_it++) {
		if (*ft_it != *std_it)
			handle_error(ft_container, std_container, type, func, testInfo, "CONTENT");
		std_it++;
	}
	

	return 0;
};

// template <class ft_class, class std_class>
// void handle_errorVector(ft_class ft_container, std_class std_container, size_t std_capac, std::string const &type, std::string const &func, 
// 	std::string const &testInfo, std::string const &errorTheme) {
// 			std::cout << std::setfill('.') << std::setw(WIDTH - func.size()) << " ✘" << std::endl;
// 			std::cerr << ">---FAIL--->>>  ON FUNCTION: " << func << std::endl;
// 			if (testInfo.size())
// 				std::cerr << std::string(15, ' ') << " Test info: " << testInfo << std::endl;
			
// 			std::string tmp = "- CAPACITY -";
// 			int nb = (WIDTH - tmp.size()) / 2;
// 			std::cerr << std::string( nb, ' ' ) << tmp << std::endl;

// 			std::stringstream conv;
// 			conv << ft_container.capacity();
// 			tmp = "ft_" + type + ": <" + conv.str() + ">";
// 			conv.str(std::string());
// 			nb = (WIDTH - tmp.size()) / 2;
// 			std::cerr << tmp << std::string( nb, ' ' );

// 			conv << std_capac;
// 			tmp = "std_" + type + ": <" + conv.str() + ">";
// 			conv.str(std::string());
// 			nb = (WIDTH - tmp.size()) / 2;
// 			std::cerr << std::string( nb, ' ' ) << tmp << std::endl;

// 			output_containers(ft_container, std_container, type, std::cerr);
// 			throw customException("ft_container " + errorTheme + " doesn't match std::container's!");
// };

// template <class ft_class, class std_class>
// int chk_resultVector(ft_class ft_container, std_class std_container, size_t std_capac, std::string const &type, std::string const &func, std::string const &testInfo = "") {
		
// 	std::cout << std_capac << " vs cont capac " << std_container.capacity() << std::endl;
// 	if (ft_container.capacity() != std_capac)
// 		handle_errorVector(ft_container, std_container, std_capac, type, func, testInfo, "CAPACITY");


// 	chk_result(ft_container, std_container, type, func, testInfo);
// 	return 0;
// };

typedef int (*testsPtr)();


//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
///*\*/*\*/*\LIST TESTS/*\*/*\*//
//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
/*     [in List_tests.cpp]     */

//CONSTRUCTORS
int test_list_fillConstr();
int test_list_rangeConstr();
int test_list_copyConstr();
int test_list_opEqual();
//ITERATORS
int test_list_pushBack_iterate();
//CAPACITY
int test_list_empty();
int test_list_maxSize();
//ELEMENT ACCESS
int test_list_front_back();
//MODIFIERS
int test_list_assign();
int test_list_pushFront();
int test_list_popFront();
int test_list_popBack();
int test_list_insert();
int test_list_erase();
int test_list_swap();
int test_list_resize();
int test_list_clear();
//OPERATIONS
int test_list_splice();
int test_list_remove();
int test_list_removeIf();
int test_list_unique();
int test_list_merge();
int test_list_sort();
int test_list_reverse();
//NON-MEMBER FUNCTION OVERLOADS
int test_list_nonMembers();


//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
///*\*/*\*/*\VECTOR TESTS/*\*/*//
//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
/*     [in Vector_tests.cpp]     */

//CONSTRUCTORS
int test_vector_fillConstr();
int test_vector_rangeConstr();
int test_vector_copyConstr();
int test_vector_opEqual();
//ITERATORS
int test_vector_pushBack_iterate();
// //CAPACITY
int test_vector_maxSize();
// int test_vector_resize();
// int test_vector_capacity();
int test_vector_empty();
// int test_vector_reserve();
// //ELEMENT ACCESS
// int test_vector_oparray();
// int test_vector_at();
// int test_vector_front_back();
// //MODIFIERS
// int test_vector_assign();
// int test_vector_popBack();
// int test_vector_insert();
// int test_vector_erase();
// int test_vector_swap();
// int test_vector_clear();
// //NON-MEMBER FUNCTION OVERLOADS
// int test_vector_nonMembers();

/*----------MAP TESTS----------*/
/*     [in Map_tests.cpp]      */

/*----------STACK TESTS----------*/
/*     [in Stack_tests.cpp]      */

/*----------QUEUE TESTS----------*/
/*     [in Queue_tests.cpp]      */

#endif