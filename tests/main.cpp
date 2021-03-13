/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:48:43 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/13 11:59:39 by esoulard         ###   ########.fr       */
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

	// testsPtr vectorTests[1] = { &test_vector_fillConstr, };

	/* &test_vector_rangeConstr, &test_vector_copyConstr, &test_vector_opEqual, &test_vector_pushBack_iterate, 
							&test_vector_empty, &test_vector_maxSize, &test_vector_front_back,  &test_vector_assign, &test_vector_pushFront, 
                        	&test_vector_popFront, &test_vector_popBack, &test_vector_insert, &test_vector_erase, &test_vector_swap, 
                       	 	&test_vector_resize, &test_vector_clear, &test_vector_splice, &test_vector_remove, &test_vector_removeIf, 
                        	&test_vector_unique, &test_vector_merge, &test_vector_sort, &test_vector_reverse, &test_vector_nonMembers, */

	// try {
	// 	output_title("- VECTOR TESTS -");
	// 	for (unsigned int i = 0; i < (sizeof(vectorTests) / sizeof(*(vectorTests))); i++)
	// 		(*vectorTests[i])();
	// 	output_title(">>>>>>>>> Vector tests: SUCCESS! <<<<<<<<<");
	// }
	// catch(std::exception &e) {
	// 	std::cerr << "ERROR: " << e.what() << std::endl;
	// 	output_title(">>>>>>>>> Vector tests: FAIL :( <<<<<<<<<");
	// }



	//system("leaks ft_containers"); //MUST REMOVE fsanitize from Makefile



	return 0;
}
