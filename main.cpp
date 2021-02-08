/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:48:43 by esoulard          #+#    #+#             */
/*   Updated: 2021/02/08 15:34:29 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.h"
#include <iostream>

int main(void) {

	//-----------------------------
	// LIST TESTS

	ft::List<int> ft_list;
	// ft::List<int>::iterator it;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	ft::List<int>::iterator it = ft_list.begin();
	while (it != ft_list.end()) {
		std::cout << *it << std::endl;
		it++;
	}

	return 0;
}
