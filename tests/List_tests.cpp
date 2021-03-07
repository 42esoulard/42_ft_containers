/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/07 15:10:13 by esoulard         ###   ########.fr       */
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
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = *it;
		it++;
	}

	chk_result(ft_list, list, "list", "BASIC INSTANCE + PUSH_BACK + BASIC ITERATING + DEREFERENCING");

	ft::List<char> ft_listEmpty;
	ft_list.push_back('&');
	std::list<char> listEmpty;
	list.push_back('&');

	chk_result(ft_listEmpty, listEmpty, "list", "PUSH_BACK [EMPTY]");

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

	ft::List<int> ft_listEmpty;
	std::list<int> listEmpty;

	if (ft_listEmpty.front() != listEmpty.front() || ft_listEmpty.back() != listEmpty.back()) {
		std::cerr << "ft_listEmpty.front() = [" << ft_listEmpty.front() << "] | listEmpty.front() = [" << listEmpty.front() << "]" << std::endl;
		std::cerr << "ft_listEmpty.back() = [" << ft_listEmpty.back() << "] | listEmpty.back() = [" << listEmpty.back() << "]" << std::endl;
		handle_error(ft_listEmpty, listEmpty, "list", "FRONT + BACK [EMPTY]", "CONTENT", std::cerr);
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

	ft::List<char> ft_listEmpty(0, 'a');
	std::list<char> listEmpty(0, 'a');

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

	ft::List<char> ft_listEmpty(src.end(), src.end());
	std::list<char> listEmpty(src.end(), src.end());

	chk_result(ft_listEmpty, listEmpty, "list", "RANGE CONSTRUCTOR [EMPTY]");

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
	ft::List<char> ft_listEmpty(ft_srcB);
	std::list<char> listEmpty(srcB);

	chk_result(ft_listEmpty, listEmpty, "list", "COPY CONSTRUCTOR [EMPTY]");

	//INVALID SRC = UNDEFINED BEHAVIOR
	// ft::List<char> *ft_nullSrc = nullptr;
	// ft::List<char> ft_listNull(*ft_nullSrc);
	// ft::List<char> *nullSrc = nullptr;
	// ft::List<char> listNull(*nullSrc)
	//	chk_result(ft_listNull, listNull, "list", "COPY CONSTRUCTOR [NULL SRC]");
	
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
	ft::List<char> ft_listEmpty = ft_srcB;
	std::list<char> listEmpty = srcB;

	chk_result(ft_listEmpty, listEmpty, "list", "OPERATOR= [EMPTY]");

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

	ft::List<char> ft_listEmpty;
	ft_list.push_front('&');
	std::list<char> listEmpty;
	list.push_front('&');

	chk_result(ft_listEmpty, listEmpty, "list", "PUSH_FRONT [EMPTY]");

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

	ft::List<char> ft_listEmpty;
	ft_list.pop_front();
	std::list<char> listEmpty;
	list.pop_front();

	chk_result(ft_listEmpty, listEmpty, "list", "POP_FRONT [EMPTY]");
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

	ft::List<char> ft_listEmpty;
	ft_list.pop_back();
	std::list<char> listEmpty;
	list.pop_back();

	chk_result(ft_listEmpty, listEmpty, "list", "POP_BACK [EMPTY]");
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
	

	ft::List<char> ft_listEmpty;
	ft_it = ft_listEmpty.begin();
	ft_it = ft_listEmpty.insert(ft_it, 'a');
	std::list<char> listEmpty;
	it = listEmpty.begin();
	it = listEmpty.insert(it, 'a');

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
		handle_error(ft_listEmpty, listEmpty, "list", "INSERT(1) [EMPTY]", "CONTENT", std::cerr);
	}
	chk_result(ft_listEmpty, listEmpty, "list", "INSERT(1)  [EMPTY]");

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
		handle_error(ft_listEmpty, listEmpty, "list", "INSERT(2)", "CONTENT", std::cerr);
	}
	chk_result(ft_listEmpty, listEmpty, "list", "INSERT(2)");
	
	ft::List<char> ft_listEmptyB;
	ft_it = ft_listEmptyB.begin();
	ft_listEmptyB.insert(ft_it, size, '6');
	std::list<char> listEmptyB;
	it = listEmptyB.begin();
	listEmptyB.insert(it, size, '6');

	chk_result(ft_listEmptyB, listEmptyB, "list", "INSERT(2)[FILL] [EMPTY to FULL]");

	size = 0;
	ft::List<char> ft_listEmptyC;
	ft_it = ft_listEmptyC.begin();
	ft_listEmptyC.insert(ft_it, size, '6');
	std::list<char> listEmptyC;
	it = listEmptyC.begin();
	listEmptyC.insert(it, size, '6');

	chk_result(ft_listEmptyC, listEmptyC, "list", "INSERT(2)[FILL] [EMPTY to EMPTY]");
	
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
		handle_error(ft_list, list, "list", "INSERT(3)[RANGE]", "CONTENT", std::cerr);
	}
	chk_result(ft_list, list, "list", "INSERT(3)[RANGE]");

	ft::List<char> ft_listEmptyD;
	ft_it = ft_listEmptyC.begin();
	ft_listEmptyC.insert(ft_it, ft_listEmptyD.begin(), ft_listEmptyD.end());
	std::list<char> listEmptyD;
	it = listEmptyC.begin();
	listEmptyC.insert(it, listEmptyD.begin(), listEmptyD.end());
	chk_result(ft_listEmptyC, listEmptyC, "list", "INSERT(3)[RANGE] [EMPTY to EMPTY]");
	
	ft_it = ft_list.begin();
	ft_list.insert(ft_it, ft_listEmptyD.begin(), ft_listEmptyD.end());
	it = list.begin();
	list.insert(it, listEmptyD.begin(), listEmptyD.end());
	chk_result(ft_list, list, "list", "INSERT(3)[RANGE] [EMPTY to FULL]");
	
	ft_it = ft_listEmptyD.begin();
	ft_listEmptyD.insert(ft_it, ft_list.begin(), ft_list.end());
	it = listEmptyD.begin();
	listEmptyD.insert(it, list.begin(), list.end());
	chk_result(ft_listEmptyD, listEmptyD, "list", "INSERT(3)[RANGE] [FULL TO EMPTY]");
	return 0;
};

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
	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", "ERASE(1) [begin]", "CONTENT", std::cerr);
	}
	chk_result(ft_list, list, "list", "ERASE(1) [begin]");

	ft_it = ft_list.erase(ft_it);
	it = list.erase(it);
	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", "ERASE(1) [begin]", "CONTENT", std::cerr);
	}
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

	//ERASE EMPTY BEGIN = UNDEFINED BEHAVIOUR
	//ft::List<char> ft_listEmpty;
	//std::list<char> listEmpty;
	//ft_listEmpty.erase(ft_listEmpty.begin());
	//listEmpty.erase(listEmpty.begin());
	//chk_result(ft_listEmpty, listEmpty, "list", "ERASE(1) [EMPTY]");

	//------------------------------------------------------------------------

	std::cout << "[ERASE(2)[RANGE]]" << std::endl;

	ft_list.erase(ft_list.begin(), ft_list.end());
	list.erase(list.begin(), list.end());
	chk_result(ft_list, list, "list", "ERASE(2)[RANGE] [EMPTY]");
	
	ft_list.insert(ft_list.begin(), 10, '!');
	ft_list.push_back('@');
	ft_list.push_back('&');
	ft_list.push_front('z');
	ft_it = ft_list.begin();
	ft_it++;
	ft_it++;

	list.insert(list.begin(), 10, '!');
	list.push_back('@');
	list.push_back('&');
	list.push_front('z');
	it = list.begin();
	it++;
	it++;

	ft::List<char>::iterator ft_last = ft_it;
	std::list<char>::iterator last = it;
	ft_last++;
	last++;
	ft_it = ft_list.erase(ft_it, ft_last);
	it = list.erase(it, last);
	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(2) = [" << *ft_it << "] | *it after erase(2) = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", "ERASE(2)[RANGE] [PARTIAL]", "CONTENT", std::cerr);
	}
	chk_result(ft_list, list, "list", "ERASE(2)[RANGE] [PARTIAL]");
	
	ft_it = ft_list.erase(ft_list.begin(), ft_list.end());
	it = list.erase(list.begin(), list.end());
	chk_result(ft_list, list, "list", "ERASE(2)[RANGE] [TOTAL]");
	//not comparing return pointers because they point after end() in this case

	//------------------------------------------------------------------------
	return 0;
};

int test_list_swap() {
	std::cout << "[SWAP]" << std::endl;
	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_back('&');
	ft_list.push_front('z');
	
	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_back('&');
	list.push_front('z');

	ft::List<char> ft_listEmpty;
	std::list<char> listEmpty;
	ft_listEmpty.swap(ft_list);
	listEmpty.swap(list);

	chk_result(ft_list, list, "list", "SWAP [Full vs Empty][1/2]");
	chk_result(ft_listEmpty, listEmpty, "list", "SWAP [Full vs Empty][2/2]");
	
	ft_listEmpty.swap(ft_list);
	listEmpty.swap(list);
	chk_result(ft_list, list, "list", "SWAP [Empty vs Full][1/2]");
	chk_result(ft_listEmpty, listEmpty, "list", "SWAP [Empty vs Full][2/2]");

	ft_listEmpty.insert(ft_listEmpty.begin(), 56, 'v');
	listEmpty.insert(listEmpty.begin(), 56, 'v');
	ft_listEmpty.swap(ft_list);
	listEmpty.swap(list);
	chk_result(ft_list, list, "list", "SWAP [Full vs Full][1/2]");
	chk_result(ft_listEmpty, listEmpty, "list", "SWAP [Full vs Full][2/2]");

	ft::List<char> ft_listEmptyA;
	std::list<char> listEmptyA;
	ft::List<char> ft_listEmptyB;
	std::list<char> listEmptyB;
	ft_listEmptyA.swap(ft_listEmptyB);
	listEmptyA.swap(listEmptyB);
	chk_result(ft_listEmptyA, listEmptyA, "list", "SWAP [Empty vs Empty][1/2]");
	chk_result(ft_listEmptyB, listEmptyB, "list", "SWAP [Empty vs Empty][2/2]");
	
	return 0;
};

int test_list_resize() {
	std::cout << "[RESIZE]" << std::endl;
	ft::List<char> ft_list(5, '!');
	std::list<char> list(5, '!');

	ft_list.resize(2);
	list.resize(2);
	chk_result(ft_list, list, "list", "RESIZE [5 TO 2]");

	ft_list.resize(0);
	list.resize(0);
	chk_result(ft_list, list, "list", "RESIZE [2 TO 0]");

	ft_list.resize(0);
	list.resize(0);
	chk_result(ft_list, list, "list", "RESIZE [0 TO 0]");

	ft_list.resize(5);
	list.resize(5);
	chk_result(ft_list, list, "list", "RESIZE [0 TO 5]");
	
	ft_list.resize(100);
	list.resize(100);
	chk_result(ft_list, list, "list", "RESIZE [5 TO 100]");

	ft_list.resize(100);
	list.resize(100);
	chk_result(ft_list, list, "list", "RESIZE [100 TO 100]");

	//UNDEFINED BEHAVIOUR
	//ft_list.resize(-50);
	//list.resize(-50);
	//chk_result(ft_list, list, "list", "RESIZE [100 TO -50]");
	return 0;
};

int test_list_clear() {
	std::cout << "[CLEAR]" << std::endl;
	ft::List<char> ft_list(5, '!');
	std::list<char> list(5, '!');

	ft_list.clear();
	list.clear();
	chk_result(ft_list, list, "list", "CLEAR [FULL LIST]");

	ft_list.clear();
	list.clear();
	chk_result(ft_list, list, "list", "CLEAR [EMPTY LIST]");
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

struct is_near {
  bool operator() (char first, char second)
  { return (second - first <= 1 || first - second <= 1); }
};

int test_list_unique() {
	std::cout << "[UNIQUE(1)]" << std::endl;
	ft::List<char> ft_list(5, '!');
	std::list<char> list(5, '!');

	ft::List<char>::iterator ft_it = ft_list.begin();
	std::list<char>::iterator it = list.begin();
	ft_it++;
	it++;
	ft_list.push_back('a');
	ft_list.insert(ft_it, 'a');
	ft_list.insert(ft_it, 'b');
	list.push_back('a');
	list.insert(it, 'a');
	list.insert(it, 'b');

	ft_list.unique();
	list.unique();
	chk_result(ft_list, list, "list", "UNIQUE(1) [WITH DOUBLES]");

	ft_list.unique();
	list.unique();
	chk_result(ft_list, list, "list", "UNIQUE(1) [NO DOUBLES]");

	ft::List<char> ft_listEmpty;
	std::list<char> listEmpty;
	ft_listEmpty.unique();
	listEmpty.unique();
	chk_result(ft_listEmpty, listEmpty, "list", "UNIQUE(1) [EMPTY LIST]");

	//------------------------------------------------------------------------

	std::cout << "[UNIQUE(2)[binary_pred]]" << std::endl;
	ft_list.push_back('a');
	ft_list.insert(ft_it, 'a');
	ft_list.insert(ft_it, 'b');
	list.push_back('a');
	list.insert(it, 'a');
	list.insert(it, 'b');

	ft_list.unique(is_near());
	list.unique(is_near());
	chk_result(ft_list, list, "list", "UNIQUE(2) [WITH DOUBLES]");

	ft_list.unique(is_near());
	list.unique(is_near());
	chk_result(ft_list, list, "list", "UNIQUE(2) [NO DOUBLES]");

	ft_listEmpty.unique(is_near());
	listEmpty.unique(is_near());
	chk_result(ft_listEmpty, listEmpty, "list", "UNIQUE(2) [EMPTY LIST]");
	return 0;
};

// 	//test REVERSE_ITERATORS + CONST_REVERSE_ITERATORS
// 	//SPLICE1/2/3, REMOVE, REMOVE_IF

//empty, size, max_size
//asign
//sort
//reverse

int test_list_merge() {
	return 0;
};

int test_list_sort() {
	std::cout << "SORT(1)" << std::endl;
	ft::List<int> ft_list;
	std::list<int> list;
	ft_list.push_back(0);
	ft_list.push_back(2145678);
	ft_list.push_back(-70);
	ft_list.push_back(42);
	list.push_back(0);
	list.push_back(2145678);
	list.push_back(-70);
	list.push_back(42);

	ft_list.sort();
	list.sort();
	chk_result(ft_list, list, "list", "SORT(1)");

	// ft::List<int> ft_listEmpty;
	// std::list<int> listEmpty;
	// ft_listEmpty.sort();
	// listEmpty.sort();
	// chk_result(ft_listEmpty, listEmpty, "list", "SORT(1) [EMPTY]");

//	std::cout << "SORT(2)" << std::endl;
	return 0;
};

int test_list_nonMembers() {
	//relational operators
	//non member swap
	return 0;
};

