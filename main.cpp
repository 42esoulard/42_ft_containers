/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:48:43 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/28 11:55:01 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.h"
#include <iostream>

int main(void) {

	//-----------------------------
	// LIST TESTS

	// BASIC INSTANCE + PUSH_BACK
	std::cout << "-----BASIC INSTANCE + PUSH_BACK-----" << std::endl;
	ft::List<int> ft_list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	// BASIC ITERATING + DEREFERENCING
	std::cout << "-----BASIC ITERATING-----" << std::endl;
	ft::List<int>::iterator it = ft_list.begin();
	while (it != ft_list.end()) {
		std::cout << *it << std::endl;
		it++;
	}

	// FRONT() AND BACK() + THEIR CONST OVERLOADS
	std::cout << "-----FRONT/BACK-----" << std::endl;
	std::cout << ft_list.front() << std::endl;
	std::cout << ft_list.back() << std::endl;

//!\	//CONST OVERLOAD RETURN DOESNT WORK!!!
	std::cout << "-----FRONT/BACK CONST OVERLOAD-----" << std::endl;
	int const tmp = ft_list.front();
	std::cout << tmp << std::endl;
	int const tmpa = ft_list.back();
	std::cout << tmpa << std::endl;

	
	// LIST FILL CONSTRUCTOR
	std::cout << "-----FILL CONSTR-----" << std::endl;
	ft::List<char> ft_listA(5, 'a');

	ft::List<char>::iterator itA = ft_listA.begin();
	while (itA != ft_listA.end()) {
		std::cout << *itA << std::endl;
		itA++;
	}

	// LIST RANGE CONSTRUCTOR
	std::cout << "-----RANGE CONSTR-----" << std::endl;
	ft::List<int> ft_listB(ft_list.begin(), ft_list.end());

	ft::List<int>::iterator itB = ft_listB.begin();
	while (itB != ft_listB.end()) {
		std::cout << *itB << std::endl;
		itB++;
	}

	// COPY CONSTRUCTOR
	std::cout << "-----COPY CONSTR-----" << std::endl;
	ft::List<int> ft_listC(ft_listB);

	ft::List<int>::iterator itC = ft_listC.begin();
	while (itC != ft_listC.end()) {
		std::cout << *itC << std::endl;
		itC++;
	}

	//OPERATOR=
	std::cout << "-----OPERATOR=-----" << std::endl;
	ft::List<int> ft_listD = ft_listC;

	itC = ft_listD.begin();
	while (itC != ft_listD.end()) {
		std::cout << *itC << std::endl;
		itC++;
	}


	//PUSH_FRONT
	std::cout << "-----PUSH_FRONT-----" << std::endl;
	std::cout << ft_list.front() << std::endl;
	ft_list.push_front(4242);
	std::cout << ft_list.front() << std::endl;

	//POP_FRONT
	std::cout << "-----POP_FRONT-----" << std::endl;
	std::cout << ft_list.front() << std::endl;
	ft_list.pop_front();
	std::cout << ft_list.front() << std::endl;

	//POP_BACK
	std::cout << "-----POP_BACK-----" << std::endl;
	std::cout << ft_list.back() << std::endl;
	std::cout << ft_list.size() << std::endl;
	ft_list.pop_back();
	std::cout << ft_list.size() << std::endl;
	std::cout << ft_list.back() << std::endl;

	//INSERT
	std::cout << "-----INSERT(1)-----" << std::endl;
	it = ft_list.begin();
	it = ft_list.insert(it, 75);
	it = ft_list.insert(it, 75);
	it = ft_list.insert(it, 2);
	while (it != ft_list.end()) {
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << ft_list.front() << std::endl;
	std::cout << ft_list.size() << std::endl;

	std::cout << "-----INSERT(3)-----" << std::endl;
	size_t size = 3;
	it = ft_list.begin();
	ft_list.insert(it, size, 6);//GOES INTO INSERT 4 FOR SOME REASON?!
	size_t sz = 1;
	it = ft_list.begin();
	ft_list.insert(it, sz, 1);
	it = ft_list.begin();
	while (it != ft_list.end()) {
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << ft_list.front() << std::endl;
	std::cout << ft_list.size() << std::endl;
	
	std::cout << "-----INSERT(4)-----" << std::endl;

	

	return 0;
}
