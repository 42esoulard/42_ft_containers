/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:44:45 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/06 15:53:12 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H

#include <iomanip>
#include <string>

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

	int step = 40;
	int adjustedStep = 40 - (type.size() + 1);
	
	o << std::setw(53) << "------------------------------------" << std::endl;

	o << std::setw(step) << "- SIZE -" << std::endl;
	o << "ft_" << type << ": " << ft_size << std::setw(adjustedStep - 5) << " ";
	o <<  std::setw(adjustedStep - 5) << "std_" << type << ": " << std_size << std::endl;

	o << std::endl << std::setw(41) << "- CONTENT -" << std::endl;
	o <<  "ft_" << type << std::setw(adjustedStep - 6) << " | ";
	o << std::setw(adjustedStep) << "std_" << type << std::endl;

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
			o << *ft_it << std::setw(adjustedStep) << " | ";
			ft_it++;
		}
		else
			o << std::setw(adjustedStep + 1) << " | ";
		if (std_it != std_ite) {
			o << std::setw(adjustedStep) << *std_it << std::endl;
			std_it++;
		}
		else
			o << std::setw(adjustedStep + 1) << std::endl;
	}

	o << std::setw(53) << "------------------------------------" << std::endl;
};

template <class ft_class, class std_class>
void handle_error(ft_class ft_container, std_class std_container, std::string const &type, std::string const &func, 
	std::string const &errorTheme, std::ostream &o) {
			std::cerr << ">---FAIL--->>>  ON TEST: " << func << std::endl;
			output_containers(ft_container, std_container, type, std::cerr);
			throw customException("ft_container " + errorTheme + " doesn't match std::container's!");
};

template <class ft_class, class std_class>
int chk_result(ft_class ft_container, std_class std_container, std::string const &type, std::string const &func) {

	if (ft_container.size() != std_container.size())
		handle_error(ft_container, std_container, type, func, "SIZE", std::cerr);

	typename ft_class::iterator ft_it = ft_container.begin();
	typename ft_class::iterator ft_ite = ft_container.end();
	
	typename std_class::iterator std_it = std_container.begin();
	typename std_class::iterator std_ite = std_container.end();

	for (ft_it = ft_container.begin(); ft_it != ft_ite; ft_it++) {
		if (*ft_it != *std_it) 
			handle_error(ft_container, std_container, type, func, "CONTENT", std::cerr);
		std_it++;
	}

	return 0;
};






typedef int (*testsPtr)();

/*----------LIST TESTS----------*/
/*     [in List_tests.cpp]      */

int test_list_pushBack_iterate();
int test_list_front_back();
int test_list_fillConstr();
int test_list_rangeConstr();
int test_list_copyConstr();
int test_list_opEqual();
int test_list_pushFront();
int test_list_popFront();
int test_list_popBack();
int test_list_insert();
int test_list_erase();
int test_list_swap();
int test_list_resize();
int test_list_clear();
int test_list_splice();
int test_list_remove();
int test_list_removeIf();
int test_list_unique();
int test_list_merge();
int test_list_sort();
int test_list_nonMembers();

// testsPtr listTests[21] = {&test_pushBack_iterate, &test_front_back, &test_fillConstr, &test_rangeConstr, &test_copyConstr,
//                         &test_opEqual, &test_pushFront, &test_popFront, &test_popBack, &test_insert,
//                         &test_erase, &test_swap, &test_resize, &test_clear, &test_splice, 
//                         &test_remove, &test_removeIf, &test_unique, &test_merge, &test_sort,
//                         &test_nonMembers};


/*----------VECTOR TESTS----------*/
/*     [in Vector_tests.cpp]      */

/*----------MAP TESTS----------*/
/*     [in Map_tests.cpp]      */

/*----------STACK TESTS----------*/
/*     [in Stack_tests.cpp]      */

/*----------QUEUE TESTS----------*/
/*     [in Queue_tests.cpp]      */

#endif