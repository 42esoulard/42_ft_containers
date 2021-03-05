/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/05 15:59:24 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.h"

int test_pushBack_iterate() {
    // BASIC INSTANCE + PUSH_BACK
	std::cout << "-----BASIC INSTANCE + PUSH_BACK-----" << std::endl;
	ft::List<int> ft_list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

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
