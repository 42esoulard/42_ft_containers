/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:48:43 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/08 20:09:06 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.h"
#include <iostream>

int main(void) {

	//-----------------------------
	// LIST TESTS

	// BASIC INSTANCE + PUSH_BACK
	ft::List<int> ft_list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	// BASIC ITERATING + DEREFERENCING
	ft::List<int>::iterator it = ft_list.begin();
	while (it != ft_list.end()) {
		std::cout << *it << std::endl;
		it++;
	}

	// FRONT() AND BACK() + THEIR CONST OVERLOADS
	std::cout << ft_list.front() << std::endl;
	std::cout << ft_list.back() << std::endl;

//!\	//CONST OVERLOAD RETURN DOESNT WORK!!!
	int const tmp = ft_list.front();
	std::cout << tmp << std::endl;
	int const tmpa = ft_list.back();
	std::cout << tmpa << std::endl;

	
	// LIST FILL CONSTRUCTOR
	ft::List<char> ft_listA(5, 'a');

	ft::List<char>::iterator itA = ft_listA.begin();
	while (itA != ft_listA.end()) {
		std::cout << *itA << std::endl;
		itA++;
	}

	// LIST RANGE CONSTRUCTOR
	ft::List<int> ft_listB(ft_list.begin(), ft_list.end());

	ft::List<int>::iterator itB = ft_listB.begin();
	while (itB != ft_listB.end()) {
		std::cout << *itB << std::endl;
		itB++;
	}

	// COPY CONSTRUCTOR
	ft::List<int> ft_listC(ft_listB);

	ft::List<int>::iterator itC = ft_listC.begin();
	while (itC != ft_listC.end()) {
		std::cout << *itC << std::endl;
		itC++;
	}

	//OPERATOR=
	ft::List<int> ft_listD = ft_listC;

	itC = ft_listD.begin();
	while (itC != ft_listD.end()) {
		std::cout << *itC << std::endl;
		itC++;
	}
	return 0;
}
