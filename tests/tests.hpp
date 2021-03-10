/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stella <stella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:44:45 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/10 12:29:51 by stella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H

#if defined(__linux__)
	#define _NOEXCEPT noexcept
#endif

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

	int w = 60;
	std::string tmp;
	std::string a;
	std::stringstream conv;
	int step = 40;

	tmp = "------------------------------------";
	int nb = (w - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;

	tmp = "- SIZE -";
	nb = (w - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;

	conv << ft_size;
	tmp = "ft_" + type + ": <" + conv.str() + ">";
	conv.str(std::string());
	nb = (w - tmp.size()) / 2;
	o << tmp << std::string( nb, ' ' );

	conv << std_size;
	tmp = "std_" + type + ": <" + conv.str() + ">";
	conv.str(std::string());
	nb = (w - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;
	//o << std::setw(step) << "std_" << type << ": " << std_size << std::endl;

	tmp =  "- CONTENT -";
	nb = (w - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;

	tmp = "ft_" + type + ": ";
	nb = (w - tmp.size()) / 2;
	o << tmp << std::string( nb, ' ' );

	tmp = "std_" + type + ": ";
	nb = (w - tmp.size()) / 2;
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
			nb = (w - conv.str().size()) / 2;
			o << "[" << conv.str() << "]" << std::string( nb, ' ' );
			conv.str(std::string());
			ft_it++;
		}
		else
			o << std::string( w/2, ' ' );
		if (std_it != std_ite) {
			conv << *std_it;
			nb = (w - conv.str().size()) / 2;
			o << std::string( nb, ' ' ) << "[" << conv.str() << "]" << std::endl;
			conv.str(std::string());
			std_it++;
		}
		else
			o << std::string( w/2, ' ' ) << std::endl;
	}

	tmp = "------------------------------------";
	nb = (w - tmp.size()) / 2;
	o << std::string( nb, ' ' ) << tmp << std::endl;
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