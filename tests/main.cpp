/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:48:43 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/28 15:43:55 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.h"
#include "tests.hpp"

#include <iostream>
#include <iomanip>

void output_title(std::string const &title) {
	std::cout << std::string((WIDTH - title.size())/2, ' ') << std::string(title.size(), '-') << std::endl;
	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
	std::cout << std::string((WIDTH - title.size())/2, ' ') << std::string(title.size(), '-') << std::endl;
}

int main(void) { 

							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
							///*\*/*\*/*\LIST TESTS/*\*/*\*//
							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
							/*     [in List_tests.cpp]     */

	testsPtr listTests[25] = { &test_list_fillConstr, &test_list_rangeConstr, &test_list_copyConstr, &test_list_opEqual, &test_list_pushBack_iterate, 
							&test_list_empty, &test_list_maxSize, &test_list_front_back,  &test_list_assign, &test_list_pushFront, 
                        	&test_list_popFront, &test_list_popBack, &test_list_insert, &test_list_erase, &test_list_swap, 
                       	 	&test_list_resize, &test_list_clear, &test_list_splice, &test_list_remove, &test_list_removeIf, 
                        	&test_list_unique, &test_list_merge, &test_list_sort, &test_list_reverse, &test_list_nonMembers, };

	try {
		output_title("- LIST TESTS -");
		for (unsigned int i = 0; i < (sizeof(listTests) / sizeof(*(listTests))); i++)
			(*listTests[i])();
		output_title(">>>>>>>>> List tests: SUCCESS! <<<<<<<<<");
	}
	catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		output_title(">>>>>>>>> List tests: FAIL :( <<<<<<<<<");
	}


							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
							///*\*/*\*/*\VECTOR TESTS/*\*/*//
							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
							/*    [in Vector_tests.cpp]    */

	testsPtr vectorTests[20] = { &test_vector_fillConstr, &test_vector_rangeConstr, &test_vector_copyConstr, &test_vector_opEqual, &test_vector_pushBack_iterate, 
							&test_vector_maxSize, &test_vector_capacity, &test_vector_empty, &test_vector_resize, &test_vector_reserve, &test_vector_oparray, 
							&test_vector_at, &test_vector_front_back, &test_vector_assign, &test_vector_popBack, &test_vector_insert, &test_vector_erase, 
							&test_vector_swap, &test_vector_clear, &test_vector_nonMembers, };

	try {
		output_title("- VECTOR TESTS -");
		for (unsigned int i = 0; i < (sizeof(vectorTests) / sizeof(*(vectorTests))); i++)
			(*vectorTests[i])();
		output_title(">>>>>>>>> Vector tests: SUCCESS! <<<<<<<<<");
	}
	catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		output_title(">>>>>>>>> Vector tests: FAIL :( <<<<<<<<<");
	}


							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*////
							///*\*/*\*/*\STACK TESTS/*\*/*\///
							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*////
							/*     [in Stack_tests.cpp]     */

	testsPtr stackTests[4] = { &test_stack_constr_size, &test_stack_empty, &test_stack_top_push_pop, &test_stack_nonMembers, };

	try {
		output_title("- STACK TESTS -");
		for (unsigned int i = 0; i < (sizeof(stackTests) / sizeof(*(stackTests))); i++)
			(*stackTests[i])();
		output_title(">>>>>>>>> Stack tests: SUCCESS! <<<<<<<<<");
	}
	catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		output_title(">>>>>>>>> Stack tests: FAIL :( <<<<<<<<<");
	}

							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*////
							///*\*/*\*/*\QUEUE TESTS/*\*/*\///
							//*\*/*\/*\*/*\/*\*/*\/*\*/*\*////
							/*     [in Queue_tests.cpp]     */

	testsPtr queueTests[4] = { &test_queue_constr_size, &test_queue_empty, &test_queue_top_push_pop, &test_queue_nonMembers, };

	try {
		output_title("- QUEUE TESTS -");
		for (unsigned int i = 0; i < (sizeof(queueTests) / sizeof(*(queueTests))); i++)
			(*queueTests[i])();
		output_title(">>>>>>>>> Queue tests: SUCCESS! <<<<<<<<<");
	}
	catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		output_title(">>>>>>>>> Queue tests: FAIL :( <<<<<<<<<");
	}

							//*\*/*\/*\*/*\/*\*/*\/*///
							///*\*/*\*MAP TESTS/*\*/*//
							//*\*/*\/*\*/*\/*\*/*\/*///
							/*   [in Map_tests.cpp]  */

	testsPtr mapTests[6] = { &test_map_constr, &test_map_iterate, &test_map_empty, &test_map_maxSize, &test_map_oparray,
							&test_map_insert, };

	


// //MODIFIERS
// int test_map_insert();
// int test_map_erase();
// int test_map_swap();
// int test_map_clear();
// //OBSERVERS
// int test_map_kvComp();
// //OPERATIONS
// int test_map_find();
// int test_map_count();
// int test_map_lowerBound();
// int test_map_upperBound();
// int test_map_equalRange();*/

	try {
		output_title("- MAP TESTS -");
		for (unsigned int i = 0; i < (sizeof(mapTests) / sizeof(*(mapTests))); i++)
			(*mapTests[i])();
		output_title(">>>>>>>>> Map tests: SUCCESS! <<<<<<<<<");
	}
	catch(std::exception &e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		output_title(">>>>>>>>> Map tests: FAIL :( <<<<<<<<<");
	}


	//system("leaks ft_containers"); //MUST REMOVE fsanitize from Makefile



	return 0;
}
