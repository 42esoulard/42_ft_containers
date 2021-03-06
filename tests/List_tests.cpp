/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/06 13:56:19 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.h"
#include "tests.hpp"
#include <iomanip>
#include <list>
#include <string>

class customException;

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
	o <<  "ft_" << type << std::setw(adjustedStep - 5) << " | ";
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
			o << std::setw(adjustedStep) << " | ";
		if (std_it != std_ite) {
			o << std::setw(adjustedStep) << *std_it << std::endl;
			std_it++;
		}
		else
			o << std::setw(adjustedStep) << std::endl;
	}

	o << std::setw(53) << "------------------------------------" << std::endl;
};

template <class ft_class, class std_class>
int chk_result(ft_class ft_container, std_class std_container, std::string const &type, std::string const &func) {

	if (ft_container.size() != std_container.size()) {
		std::cerr << ">---FAIL--->>>  ON TEST: " << func << std::endl;
		output_containers(ft_container, std_container, type, std::cerr);
		throw customException("ft_container SIZE doesn't match std::container's!");
	};

	typename ft_class::iterator ft_it = ft_container.begin();
	typename ft_class::iterator ft_ite = ft_container.end();
	
	typename std_class::iterator std_it = std_container.begin();
	typename std_class::iterator std_ite = std_container.end();

	for (ft_it = ft_container.begin(); ft_it != ft_ite; ft_it++) {
		if (*ft_it != *std_it) {
			std::cerr << ">---FAIL--->>>  ON TEST: " << func << std::endl;
			output_containers(ft_container, std_container, type, std::cerr);
			throw customException("ft_container CONTENT doesn't match std::container's!");
		}
		std_it++;
	}

	return 0;
};

int test_pushBack_iterate() {
    // BASIC INSTANCE + PUSH_BACK
	//std::cout << "-----BASIC INSTANCE + PUSH_BACK-----" << std::endl;
	ft::List<int> ft_list;
	std::list<int> list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	list.push_back(10);
	list.push_back(12);
	list.push_back(18);

	chk_result(ft_list, list, "list", "BASIC INSTANCE + PUSH_BACK");

    return 0;
};

//compare each function result with actual official list output, if comp not perfect: throw exception 

int test_front_back() {return 0;};
int test_fillConstr(){return 0;};
int test_rangeConstr(){return 0;};
int test_copyConstr(){return 0;};
int test_opEqual(){return 0;};
int test_pushFront(){return 0;};
int test_popFront(){return 0;};
int test_popBack(){return 0;};
int test_insert(){return 0;};
int test_erase(){return 0;};
int test_swap(){return 0;};
int test_resize(){return 0;};
int test_clear(){return 0;};
int test_splice(){return 0;};
int test_remove(){return 0;};
int test_removeIf(){return 0;};
int test_unique(){return 0;};
int test_merge(){return 0;};
int test_sort(){return 0;};
int test_nonMembers(){return 0;};
