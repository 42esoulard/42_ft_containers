/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/06 17:19:46 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_containers.h"
#include "tests.hpp"

#include <list>
#include <string>

class customException;

int test_list_pushBack_iterate() {
	std::cout << "[BASIC INSTANCE + PUSH_BACK]" << std::endl;
	ft::List<int> ft_list;
	std::list<int> list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	list.push_back(10);
	list.push_back(12);
	list.push_back(18);

	std::cout << "[BASIC ITERATING + DEREFERENCING]" << std::endl;
	int tmp;
	ft::List<int>::iterator it = ft_list.begin();
	while (it != ft_list.end()) {
		//std::cout << *it << std::endl;
		tmp = *it;
		it++;
	}

	chk_result(ft_list, list, "list", "BASIC INSTANCE + PUSH_BACK + BASIC ITERATING + DEREFERENCING");

	ft::List<char> ft_emptyList;
	ft_list.push_back('&');
	std::list<char> emptyList;
	list.push_back('&');

	chk_result(ft_emptyList, emptyList, "list", "PUSH_BACK [EMPTY]");

    return 0;
};

int test_list_front_back() {
	std::cout << "[FRONT/BACK]" << std::endl;
	ft::List<int> ft_list;
	std::list<int> list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	list.push_back(10);
	list.push_back(12);
	list.push_back(18);

	if (ft_list.front() != list.front() || ft_list.back() != list.back()) {
		std::cerr << "ft_list.front() = [" << ft_list.front() << "] | list.front() = [" << list.front() << "]" << std::endl;
		std::cerr << "ft_list.back() = [" << ft_list.back() << "] | list.back() = [" << list.back() << "]" << std::endl;
		handle_error(ft_list, list, "list", "FRONT + BACK", "CONTENT", std::cerr);
	}

	ft::List<int> ft_emptyList;
	std::list<int> emptyList;

	if (ft_emptyList.front() != emptyList.front() || ft_emptyList.back() != emptyList.back()) {
		std::cerr << "ft_emptyList.front() = [" << ft_emptyList.front() << "] | emptyList.front() = [" << emptyList.front() << "]" << std::endl;
		std::cerr << "ft_emptyList.back() = [" << ft_emptyList.back() << "] | emptyList.back() = [" << emptyList.back() << "]" << std::endl;
		handle_error(ft_emptyList, emptyList, "list", "FRONT + BACK [EMPTY]", "CONTENT", std::cerr);
	}
	
	std::cout << "[FRONT/BACK CONST OVERLOAD]" << std::endl;
	ft::List<int> const ft_constList;
	std::list<int> const constList;

	if (ft_constList.front() != constList.front() || ft_constList.back() != constList.back()) {
		std::cerr << "ft_constList.front() = [" << ft_constList.front() << "] | constList.front() = [" << constList.front() << "]" << std::endl;
		std::cerr << "ft_constList.back() = [" << ft_constList.back() << "] | constList.back() = [" << constList.back() << "]" << std::endl;
		handle_error(ft_constList, constList, "list", "FRONT + BACK [CONST]", "CONTENT", std::cerr);
	}

	return 0;
};

int test_list_fillConstr() {
	
	std::cout << "[FILL CONSTRUCTOR]" << std::endl;
	ft::List<char> ft_list(5, 'a');
	std::list<char> list(5, 'a');

	chk_result(ft_list, list, "list", "FILL CONSTRUCTOR");

	ft::List<char> ft_emptyList(0, 'a');
	std::list<char> emptyList(0, 'a');

	chk_result(ft_list, list, "list", "FILL CONSTRUCTOR [EMPTY]");

	return 0;
};

int test_list_rangeConstr() {

	std::cout << "[RANGE CONSTRUCTOR]" << std::endl;
	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');
	ft::List<char> ft_list(src.begin(), src.end());
	std::list<char> list(src.begin(), src.end());

	chk_result(ft_list, list, "list", "RANGE CONSTRUCTOR");

	ft::List<char> ft_emptyList(src.end(), src.end());
	std::list<char> emptyList(src.end(), src.end());

	chk_result(ft_emptyList, emptyList, "list", "RANGE CONSTRUCTOR [EMPTY]");

	return 0;
};

int test_list_copyConstr() {
	std::cout << "[COPY CONSTR]" << std::endl;
	ft::List<char> ft_src(10, '!');
	ft_src.push_back('@');
	ft_src.push_front('&');

	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');

	ft::List<char> ft_list(ft_src);
	std::list<char> list(src);

	chk_result(ft_list, list, "list", "COPY CONSTRUCTOR");

	ft::List<char> ft_srcB(0, '!');
	std::list<char> srcB(0, '!');
	ft::List<char> ft_emptyList(ft_srcB);
	std::list<char> emptyList(srcB);

	chk_result(ft_emptyList, emptyList, "list", "COPY CONSTRUCTOR [EMPTY]");

	//src = nullptr ?
	
	return 0;
};

int test_list_opEqual() {
	std::cout << "[OPERATOR=]" << std::endl;
	ft::List<char> ft_src(10, '!');
	ft_src.push_back('@');
	ft_src.push_front('&');

	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');

	ft::List<char> ft_list = ft_src;
	std::list<char> list = src;

	chk_result(ft_list, list, "list", "OPERATOR=");

	ft::List<char> ft_srcB(0, '!');
	std::list<char> srcB(0, '!');
	ft::List<char> ft_emptyList = ft_srcB;
	std::list<char> emptyList = srcB;

	chk_result(ft_emptyList, emptyList, "list", "OPERATOR= [EMPTY]");

	ft_list = ft_srcB;
	list = srcB;

	chk_result(ft_list, list, "list", "OPERATOR= [FULL = EMPTY]");

	return 0;
};

int test_list_pushFront() {
	std::cout << "[PUSH_FRONT]" << std::endl;
	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_front('&');

	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_front('&');

	chk_result(ft_list, list, "list", "PUSH_FRONT");

	ft::List<char> ft_emptyList;
	ft_list.push_front('&');
	std::list<char> emptyList;
	list.push_front('&');

	chk_result(ft_emptyList, emptyList, "list", "PUSH_FRONT [EMPTY]");

	return 0;
};

int test_list_popFront() {
	std::cout << "[POP_FRONT]" << std::endl;
	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_front('&');
	ft_list.push_front('z');

	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_front('&');
	list.push_front('z');

	ft_list.pop_front();
	list.pop_front();
	chk_result(ft_list, list, "list", "POP_FRONT");

	ft::List<char> ft_emptyList;
	ft_list.pop_front();
	std::list<char> emptyList;
	list.pop_front();

	chk_result(ft_emptyList, emptyList, "list", "POP_FRONT [EMPTY]");
	return 0;
};

int test_list_popBack() {
	std::cout << "[POP_BACK]" << std::endl;
	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_back('&');
	ft_list.push_front('z');

	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_back('&');
	list.push_front('z');

	ft_list.pop_back();
	list.pop_back();
	chk_result(ft_list, list, "list", "POP_BACK");

	ft::List<char> ft_emptyList;
	ft_list.pop_back();
	std::list<char> emptyList;
	list.pop_back();

	chk_result(ft_emptyList, emptyList, "list", "POP_BACK [EMPTY]");
	return 0;
};

int test_list_insert() {
	//------------------------------------------------------------------------

	std::cout << "[INSERT(1)]" << std::endl;
	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_back('&');
	ft_list.push_front('z');
	ft::List<char>::iterator ft_it = ft_list.begin();
	ft_it = ft_list.insert(ft_it, 'a');
	ft_it = ft_list.insert(ft_it, 'b');
	ft_it = ft_list.insert(ft_it, 'c');

	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_back('&');
	list.push_front('z');
	std::list<char>::iterator it = list.begin();
	it = list.insert(it, 'a');
	it = list.insert(it, 'b');
	it = list.insert(it, 'c');

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", "INSERT(1)", "CONTENT", std::cerr);
	}
	chk_result(ft_list, list, "list", "INSERT(1)");

	ft::List<char> ft_emptyList;
	ft_it = ft_emptyList.begin();
	ft_it = ft_emptyList.insert(ft_it, 'a');
	std::list<char> emptyList;
	it = emptyList.begin();
	it = emptyList.insert(it, 'a');

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
		handle_error(ft_emptyList, emptyList, "list", "INSERT(1) [EMPTY]", "CONTENT", std::cerr);
	}
	chk_result(ft_emptyList, emptyList, "list", "INSERT(1)  [EMPTY]");

	//------------------------------------------------------------------------

	std::cout << "[INSERT(2)[FILL]]" << std::endl;
	size_t size = 3;
	ft_it = ft_list.begin();
	ft_it++;
	ft_list.insert(ft_it, size, 6);

	it = list.begin();
	it++;
	list.insert(it, size, 6);

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(2) = [" << *ft_it << "] | *it after insert(2) = [" << *it << "]" << std::endl;
		handle_error(ft_emptyList, emptyList, "list", "INSERT(2)", "CONTENT", std::cerr);
	}
	chk_result(ft_emptyList, emptyList, "list", "INSERT(2)");

	ft::List<char> ft_emptyListB;
	ft_it = ft_emptyListB.begin();
	ft_emptyListB.insert(ft_it, size, '6');
	std::list<char> emptyListB;
	it = emptyListB.begin();
	emptyListB.insert(it, size, '6');

	chk_result(ft_emptyListB, emptyListB, "list", "INSERT(2)[FILL] [EMPTY to FULL]");

	size = 0;
	ft::List<char> ft_emptyListC;
	ft_it = ft_emptyListC.begin();
	ft_emptyListC.insert(ft_it, size, '6');
	std::list<char> emptyListC;
	it = emptyListC.begin();
	emptyListC.insert(it, size, '6');

	chk_result(ft_emptyListC, emptyListC, "list", "INSERT(2)[FILL] [EMPTY to EMPTY]");
	
	//------------------------------------------------------------------------

	std::cout << "[INSERT(3)[RANGE]]" << std::endl;
	ft::List<char> ft_src(10, '!');
	ft_src.push_back('@');
	ft_src.push_front('&');

	ft_it = ft_list.begin();
	ft_it++;
	ft_list.insert(ft_it, ft_src.begin(), ft_src.end());

	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');

	it = list.begin();
	it++;
	list.insert(it, src.begin(), src.end());

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(3) = [" << *ft_it << "] | *it after insert(3) = [" << *it << "]" << std::endl;
		handle_error(ft_emptyList, emptyList, "list", "INSERT(3)[RANGE]", "CONTENT", std::cerr);
	}
	chk_result(ft_emptyList, emptyList, "list", "INSERT(3)[RANGE]");

	//add empty to empty
	//add empty to full
	return 0;
};

// 	//test SWAP, ERASE1 + 2, RESIZE, REVERSE_ITERATORS + CONST_REVERSE_ITERATORS
// 	//SPLICE1/2/3, REMOVE, REMOVE_IF, UNIQUE1/2, 

//empty, size, max_size
//asign
//clear
//sort
//reverse


int test_list_erase() {
	std::cout << "[ERASE(1)]" << std::endl;
	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_back('&');
	ft_list.push_front('z');
	
	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_back('&');
	list.push_front('z');

	ft::List<char>::iterator ft_it = ft_list.begin();
	std::list<char>::iterator it = list.begin();

	ft_it = ft_list.erase(ft_it);
	it = list.erase(it);
	chk_result(ft_list, list, "list", "ERASE(1) [begin]");

	ft_it = ft_list.erase(ft_it);
	it = list.erase(it);
	chk_result(ft_list, list, "list", "ERASE(1) [begin]");

	//INVALID POSITION = UNDEFINED BEHAVIOR
	// ft_it = ft_list.end();
	// it = list.end();
	// ft_it = ft_list.erase(ft_it);
	// it = list.erase(it);
	// chk_result(ft_list, list, "list", "ERASE(1) [end]");

	while (ft_it != ft_list.end())
		ft_it = ft_list.erase(ft_it);
	while (it != list.end())
		it = list.erase(it);
	chk_result(ft_list, list, "list", "ERASE(1) [all]");

	//erase empty (begin())

	//------------------------------------------------------------------------

	std::cout << "[ERASE(2)]" << std::endl;

	// ft::List<char> ft_list(10, '!');
	// ft_list.push_back('@');
	// ft_list.push_back('&');
	// ft_list.push_front('z');
	
	// std::list<char> list(10, '!');
	// list.push_back('@');
	// list.push_back('&');
	// list.push_front('z');

	// ft::List<char>::iterator ft_it = ft_list.begin();
	// std::list<char>::iterator it = list.begin();

	// ft_it = ft_list.erase(ft_it);
	// it = list.erase(it);
	// chk_result(ft_list, list, "list", "ERASE(1) [begin]");

	// ft_it = ft_list.erase(ft_it);
	// it = list.erase(it);
	// chk_result(ft_list, list, "list", "ERASE(1) [begin]");

	//------------------------------------------------------------------------

	//erase range begin to end
	//erase range begin to end on empty

	return 0;
};

int test_list_swap() {
	//full vs empty
	//empty vs full
	//full vs full
	//empty vs empty
	//full vs nullptr
	//empty vs nullptr
	//nullptr vs full
	//nullptr vs empty
	
	return 0;
};

int test_list_resize() {
	//size 5 resize to 1
	//size 5 resize to 0
	//size 5 resize to 10
	//size 0 resize to 10
	//size 0 resize to 0
	//size 5 resize to 5
	return 0;
};

int test_list_clear() {
	//full list
	//empty list
	return 0;
};

int test_list_splice() {
	//full ordered vs empty
	//empty vs full ordered 
	//full ordered vs full ordered 
	//empty vs empty
	//full ordered vs full disordered
	//full disordered vs full ordered
	//full disordered vs full disordered
	//full ordered vs nullptr
	//nullptr vs full ordered
	return 0;
};

int test_list_remove() {
	return 0;
};

int test_list_removeIf() {
	return 0;
};

int test_list_unique() {
	return 0;
};

int test_list_merge() {
	return 0;
};

int test_list_sort() {
	return 0;
};

int test_list_nonMembers() {
	//relational operators
	//non member swap
	return 0;
};

