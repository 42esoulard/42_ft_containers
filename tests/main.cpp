/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stella <stella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:48:43 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/11 15:19:12 by stella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.h"
#include "tests.hpp"

#include <iostream>

int main(void) {

	testsPtr listTests[24] = {&test_list_pushBack_iterate, &test_list_front_back, &test_list_fillConstr, &test_list_rangeConstr, &test_list_copyConstr,
                        	&test_list_opEqual, &test_list_pushFront, &test_list_popFront, &test_list_popBack, &test_list_insert,
                        	&test_list_erase, &test_list_swap, &test_list_resize, &test_list_clear, &test_list_splice, 
                       	 	&test_list_remove, &test_list_removeIf, &test_list_unique, &test_list_merge, &test_list_sort,
                        	&test_list_empty, &test_list_reverse, &test_list_nonMembers, &test_list_assign, };

	try {

		for (int i = 0; i < (sizeof(listTests) / sizeof(*(listTests))); i++) {
			(*listTests[i])();
		}
		std::cout << ">>>>>>>>> Lists tests: SUCCESS! <<<<<<<<<" << std::endl;
	}
	catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	//system("leaks ft_containers"); //MUST REMOVE fsanitize from Makefile

	// try {

	// 	for (int i = 0; i < (sizeof(vectorTests) / sizeof(*(vectorTests))); i++) {
	// 		(*vectorTests[i])();
	// 	}
	// 	std::cout << ">>>>>>>>> Vectors tests: SUCCESS! <<<<<<<<<" << std::endl;
	// }
	// catch(std::exception &e) {
	// 	std::cerr << "ERROR: " << e.what() << std::endl;
	// }

	// try {

	// 	for (int i = 0; i < (sizeof(mapTests) / sizeof(*(mapTests))); i++) {
	// 		(*mapTests[i])();
	// 	}
	// 	std::cout << ">>>>>>>>> Maps tests: SUCCESS! <<<<<<<<<" << std::endl;
	// }
	// catch(std::exception &e) {
	// 	std::cerr << "ERROR: " << e.what() << std::endl;
	// }

	// try {

	// 	for (int i = 0; i < (sizeof(stackTests) / sizeof(*(stackTests))); i++) {
	// 		(*stackTests[i])();
	// 	}
	// 	std::cout << ">>>>>>>>> Stacks tests: SUCCESS! <<<<<<<<<" << std::endl;
	// }
	// catch(std::exception &e) {
	// 	std::cerr << "ERROR: " << e.what() << std::endl;
	// }

	// try {

	// 	for (int i = 0; i < (sizeof(queueTests) / sizeof(*(queueTests))); i++) {
	// 		(*queueTests[i])();
	// 	}
	// 	std::cout << ">>>>>>>>> Queues tests: SUCCESS! <<<<<<<<<" << std::endl;
	// }
	// catch(std::exception &e) {
	// 	std::cerr << "ERROR: " << e.what() << std::endl;
	// }


	return 0;
}
