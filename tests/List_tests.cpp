/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List_tests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/13 11:30:08 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <iomanip>
#include <string>

#include <list>

class customException;

//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/*\CONSTRUCTORS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_fillConstr() {
	std::string title = "[FILL CONSTRUCTOR]";
	std::cout << title;

	ft::List<char> ft_list(5, 'a');
	std::list<char> list(5, 'a');

	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmpty(0, 'a');
	std::list<char> listEmpty(0, 'a');

	chk_result(ft_list, list, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_rangeConstr() {
	std::string title = "[RANGE CONSTRUCTOR]";
	std::cout << title;

	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');
	ft::List<char> ft_list(src.begin(), src.end());
	std::list<char> list(src.begin(), src.end());

	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmpty(src.end(), src.end());
	std::list<char> listEmpty(src.end(), src.end());

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_copyConstr() {
	std::string title = "[COPY CONSTR]";
	std::cout << title;

	ft::List<char> ft_src(10, '!');
	ft_src.push_back('@');
	ft_src.push_front('&');

	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');

	ft::List<char> ft_list(ft_src);
	std::list<char> list(src);

	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_srcB(0, '!');
	std::list<char> srcB(0, '!');
	ft::List<char> ft_listEmpty(ft_srcB);
	std::list<char> listEmpty(srcB);

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	//INVALID SRC = UNDEFINED BEHAVIOR
	// ft::List<char> *ft_nullSrc = nullptr;
	// ft::List<char> ft_listNull(*ft_nullSrc);
	// ft::List<char> *nullSrc = nullptr;
	// ft::List<char> listNull(*nullSrc)
	//	chk_result(ft_listNull, listNull, "list", "COPY CONSTRUCTOR [NULL SRC]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_opEqual() {
	std::string title = "[OPERATOR=]";
	std::cout << title;

	ft::List<char> ft_src(10, '!');
	ft_src.push_back('@');
	ft_src.push_front('&');

	std::list<char> src(10, '!');
	src.push_back('@');
	src.push_front('&');

	ft::List<char> ft_list = ft_src;
	std::list<char> list = src;

	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_srcB(0, '!');
	std::list<char> srcB(0, '!');
	ft::List<char> ft_listEmpty = ft_srcB;
	std::list<char> listEmpty = srcB;

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	ft_list = ft_srcB;
	list = srcB;

	chk_result(ft_list, list, "list", title, "[FULL = EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};


//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/*\*/ITERATORS/*\*/*\*//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_pushBack_iterate() {
	std::string title = "[BASIC INSTANCE + PUSH_BACK]";
	std::cout << title;

	ft::List<int> ft_list;
	std::list<int> list;

	ft_list.push_back(10);
	ft_list.push_back(12);
	ft_list.push_back(18);

	list.push_back(10);
	list.push_back(12);
	list.push_back(18);

	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmpty;
	ft_list.push_back('&');
	std::list<char> listEmpty;
	list.push_back('&');

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[BASIC ITERATING + DEREFERENCING]";
	std::cout << title;

	int tmp;
	ft::List<int>::iterator it = ft_list.begin();
	while (it != ft_list.end()) {
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = *it;
		it++;
	}
	chk_result(ft_list, list, "list", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[BASIC REVERSE ITERATING + DEREFERENCING]";
	std::cout << title;

	ft::List<int>::reverse_iterator rit = ft_list.rbegin();
	while (rit != ft_list.rend()) {
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = *rit;
		rit++;
	}
	chk_result(ft_list, list, "list", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
    return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/CAPACITY/*\*/*\*//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_empty() {
	std::string title = "[EMPTY]";
	std::cout << title;

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
	bool ft_empty = ft_list.empty();
	bool std_empty = list.empty();
	if (ft_empty != std_empty) {
		std::cerr << "*ft_list.empty() = [" << *ft_it << "] | list.empty() = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", title, "[FULL]", "CONTENT");
	}
	
	ft::List<char> ft_listEmpty;
	std::list<char> listEmpty;
	ft_listEmpty.empty();
	listEmpty.empty();
	ft_empty = ft_list.empty();
	std_empty = list.empty();
	if (ft_empty != std_empty) {
		std::cerr << "*ft_list.empty() = [" << *ft_it << "] | list.empty() = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", title, "[EMPTY]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_maxSize() {
	std::string title = "[MAX_SIZE]";
	std::cout << title;

	ft::List<int> ft_listint;
	std::list<int> listint;

	ft::List<char> ft_listchar;
	std::list<char> listchar;

	ft::List<double> ft_listdouble;
	std::list<double> listdouble;

	ft::List<std::string> ft_liststring;
	std::list<std::string> liststring;

	size_t ft_max = ft_listint.max_size();
	size_t max = listint.max_size();

	if (max != ft_max) {
		std::cerr << "int ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_listint, listint, "list", title, "int list", "MAX_SIZE");
	}

	ft_max = ft_listchar.max_size();
	max = listchar.max_size();

	if (max != ft_max) {
		std::cerr << "char ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_listchar, listchar, "list", title, "char list", "MAX_SIZE");
	}

	ft_max = ft_listdouble.max_size();
	max = listdouble.max_size();

	if (max != ft_max) {
		std::cerr << "double ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_listdouble, listdouble, "list", title, "double list", "MAX_SIZE");
	}

	ft_max = ft_liststring.max_size();
	max = liststring.max_size();

	if (max != ft_max) {
		std::cerr << "string ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_liststring, liststring, "list", title, "std::string list", "MAX_SIZE");
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}

//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/ELEMENT ACCESS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_front_back() {
	std::string title = "[FRONT/BACK]";
	std::cout << title;

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
		handle_error(ft_list, list, "list", title, "", "CONTENT");
	}

	ft::List<int> ft_listEmpty;
	std::list<int> listEmpty;

	if (ft_listEmpty.front() != listEmpty.front() || ft_listEmpty.back() != listEmpty.back()) {
		std::cerr << "ft_listEmpty.front() = [" << ft_listEmpty.front() << "] | listEmpty.front() = [" << listEmpty.front() << "]" << std::endl;
		std::cerr << "ft_listEmpty.back() = [" << ft_listEmpty.back() << "] | listEmpty.back() = [" << listEmpty.back() << "]" << std::endl;
		handle_error(ft_listEmpty, listEmpty, "list", title, "[EMPTY]", "CONTENT");
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[FRONT/BACK CONST OVERLOAD]";
	std::cout << title;

	ft::List<int> const ft_constList;
	std::list<int> const constList;

	if (ft_constList.front() != constList.front() || ft_constList.back() != constList.back()) {
		std::cerr << "ft_constList.front() = [" << ft_constList.front() << "] | constList.front() = [" << constList.front() << "]" << std::endl;
		std::cerr << "ft_constList.back() = [" << ft_constList.back() << "] | constList.back() = [" << constList.back() << "]" << std::endl;
		handle_error(ft_constList, constList, "list", title, "[CONST]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/MODIFIERS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_assign() {
	std::string title = "[ASSIGN(1)]";
	std::cout << title;

	ft::List<char> ft_src(8, 'k');
	std::list<char> src(8, 'k');
	ft::List<char> ft_list;
	std::list<char> list;

	ft_list.assign(ft_src.begin(), ft_src.end());
	list.assign(src.begin(), src.end());
	chk_result(ft_list, list, "list", title, "[FULL to EMPTY][1/2]");
	chk_result(ft_src, src, "list", title, "[FULL to EMPTY][2/2]");

	ft_src.assign(ft_list.begin(), ft_list.end());
	src.assign(list.begin(), list.end());
	chk_result(ft_list, list, "list", title, "[FULL to FULL][1/2]");
	chk_result(ft_src, src, "list", title, "[FULL to EMPTY][2/2]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	//------------------------------------------------------------------------
	title = "[ASSIGN(2)]";
	std::cout << title;

	ft::List<char> ft_listA;
	std::list<char> listA;

	ft_listA.assign(12, 'W');
	listA.assign(12, 'W');
	chk_result(ft_listA, listA, "list", title, "[to EMPTY]");
	
	ft_listA.assign(4, '8');
	listA.assign(4, '8');
	chk_result(ft_listA, listA, "list", title, "[to FULL]");

	ft_listA.assign(24, 'U');
	listA.assign(24, 'U');
	chk_result(ft_listA, listA, "list", title, "[to FULL]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}

int test_list_pushFront() {
	std::string title = "[PUSH_FRONT]";
	std::cout << title;

	ft::List<char> ft_list(10, '!');
	ft_list.push_back('@');
	ft_list.push_front('&');

	std::list<char> list(10, '!');
	list.push_back('@');
	list.push_front('&');

	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmpty;
	ft_list.push_front('&');
	std::list<char> listEmpty;
	list.push_front('&');

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_popFront() {
	std::string title = "[POP_FRONT]";
	std::cout << title;

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
	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmpty;
	ft_list.pop_front();
	std::list<char> listEmpty;
	list.pop_front();

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_popBack() {
	std::string title = "[POP_BACK]";
	std::cout << title;

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
	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmpty;
	ft_list.pop_back();
	std::list<char> listEmpty;
	list.pop_back();

	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_insert() {
	//------------------------------------------------------------------------
	std::string title = "[INSERT(1)]";
	std::cout << title;

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
		handle_error(ft_list, list, "list", title, "", "CONTENT");
	}
	chk_result(ft_list, list, "list", title);
	

	ft::List<char> ft_listEmpty;
	ft_it = ft_listEmpty.begin();
	ft_it = ft_listEmpty.insert(ft_it, 'a');
	std::list<char> listEmpty;
	it = listEmpty.begin();
	it = listEmpty.insert(it, 'a');

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
		handle_error(ft_listEmpty, listEmpty, "list", title, "[EMPTY]", "CONTENT");
	}
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[INSERT(2)[FILL]]";
	std::cout << title;

	size_t size = 3;
	ft_it = ft_list.begin();
	ft_it++;
	ft_list.insert(ft_it, size, 6);

	it = list.begin();
	it++;
	list.insert(it, size, 6);
	
	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(2) = [" << *ft_it << "] | *it after insert(2) = [" << *it << "]" << std::endl;
		handle_error(ft_listEmpty, listEmpty, "list", title, "", "CONTENT");
	}
	chk_result(ft_listEmpty, listEmpty, "list", title);
	
	ft::List<char> ft_listEmptyB;
	ft_it = ft_listEmptyB.begin();
	ft_listEmptyB.insert(ft_it, size, '6');
	std::list<char> listEmptyB;
	it = listEmptyB.begin();
	listEmptyB.insert(it, size, '6');

	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY to FULL]");

	size = 0;
	ft::List<char> ft_listEmptyC;
	ft_it = ft_listEmptyC.begin();
	ft_listEmptyC.insert(ft_it, size, '6');
	std::list<char> listEmptyC;
	it = listEmptyC.begin();
	listEmptyC.insert(it, size, '6');

	chk_result(ft_listEmptyC, listEmptyC, "list", title, "[EMPTY to EMPTY]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[INSERT(3)[RANGE]]";
	std::cout << title;

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
		handle_error(ft_list, list, "list", title, "", "CONTENT");
	}
	chk_result(ft_list, list, "list", title);

	ft::List<char> ft_listEmptyD;
	ft_it = ft_listEmptyC.begin();
	ft_listEmptyC.insert(ft_it, ft_listEmptyD.begin(), ft_listEmptyD.end());
	std::list<char> listEmptyD;
	it = listEmptyC.begin();
	listEmptyC.insert(it, listEmptyD.begin(), listEmptyD.end());
	chk_result(ft_listEmptyC, listEmptyC, "list", title, "[EMPTY to EMPTY]");
	
	ft_it = ft_list.begin();
	ft_list.insert(ft_it, ft_listEmptyD.begin(), ft_listEmptyD.end());
	it = list.begin();
	list.insert(it, listEmptyD.begin(), listEmptyD.end());
	chk_result(ft_list, list, "list", title, "[EMPTY to FULL]");
	
	ft_it = ft_listEmptyD.begin();
	ft_listEmptyD.insert(ft_it, ft_list.begin(), ft_list.end());
	it = listEmptyD.begin();
	listEmptyD.insert(it, list.begin(), list.end());
	chk_result(ft_listEmptyD, listEmptyD, "list", title, "[FULL TO EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_erase() {
	std::string title = "[ERASE(1)]";
	std::cout << title;

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
		handle_error(ft_list, list, "list", title, "[begin]", "CONTENT");
	}
	chk_result(ft_list, list, "list", title, "[begin]");

	ft_it = ft_list.erase(ft_it);
	it = list.erase(it);
	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
		handle_error(ft_list, list, "list", title, "[begin]", "CONTENT");
	}
	chk_result(ft_list, list, "list", title, "[begin]");

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
	chk_result(ft_list, list, "list", title, "[all]");

	//ERASE EMPTY BEGIN = UNDEFINED BEHAVIOUR
	//ft::List<char> ft_listEmpty;
	//std::list<char> listEmpty;
	//ft_listEmpty.erase(ft_listEmpty.begin());
	//listEmpty.erase(listEmpty.begin());
	//chk_result(ft_listEmpty, listEmpty, "list", "ERASE(1) [EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[ERASE(2)[RANGE]]";
	std::cout << title;

	ft_list.erase(ft_list.begin(), ft_list.end());
	list.erase(list.begin(), list.end());
	chk_result(ft_list, list, "list", title, "[EMPTY]");
	
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
		handle_error(ft_list, list, "list", title, "[PARTIAL]", "CONTENT");
	}
	chk_result(ft_list, list, "list", title, "[PARTIAL]");
	
	ft_it = ft_list.erase(ft_list.begin(), ft_list.end());
	it = list.erase(list.begin(), list.end());
	chk_result(ft_list, list, "list", title, "[TOTAL]");
	//not comparing return pointers because they point after end() in this case

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_swap() {
	std::string title = "[SWAP]";
	std::cout << title;

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

	chk_result(ft_list, list, "list", title, "[Full vs Empty][1/2]");
	chk_result(ft_listEmpty, listEmpty, "list", title, "[Full vs Empty][2/2]");
	
	ft_listEmpty.swap(ft_list);
	listEmpty.swap(list);
	chk_result(ft_list, list, "list", title, "[Empty vs Full][1/2]");
	chk_result(ft_listEmpty, listEmpty, "list", title, "[Empty vs Full][2/2]");

	ft_listEmpty.insert(ft_listEmpty.begin(), 56, 'v');
	listEmpty.insert(listEmpty.begin(), 56, 'v');
	ft_listEmpty.swap(ft_list);
	listEmpty.swap(list);
	chk_result(ft_list, list, "list", title, "[Full vs Full][1/2]");
	chk_result(ft_listEmpty, listEmpty, "list", title, "[Full vs Full][2/2]");

	ft::List<char> ft_listEmptyA;
	std::list<char> listEmptyA;
	ft::List<char> ft_listEmptyB;
	std::list<char> listEmptyB;
	ft_listEmptyA.swap(ft_listEmptyB);
	listEmptyA.swap(listEmptyB);
	chk_result(ft_listEmptyA, listEmptyA, "list", title, "[Empty vs Empty][1/2]");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[Empty vs Empty][2/2]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_resize() {
	std::string title = "[RESIZE]";
	std::cout << title;

	ft::List<char> ft_list(5, '!');
	std::list<char> list(5, '!');

	ft_list.resize(2);
	list.resize(2);
	chk_result(ft_list, list, "list", title, "[5 TO 2]");

	ft_list.resize(0);
	list.resize(0);
	chk_result(ft_list, list, "list", title, "[2 TO 0]");

	ft_list.resize(0);
	list.resize(0);
	chk_result(ft_list, list, "list", title, "[0 TO 0]");

	ft_list.resize(5);
	list.resize(5);
	chk_result(ft_list, list, "list", title, "[0 TO 5]");
	
	ft_list.resize(100);
	list.resize(100);
	chk_result(ft_list, list, "list", title, "[5 TO 100]");

	ft_list.resize(100);
	list.resize(100);
	chk_result(ft_list, list, "list", title, "[100 TO 100]");

	//UNDEFINED BEHAVIOUR
	//ft_list.resize(-50);
	//list.resize(-50);
	//chk_result(ft_list, list, "list", "RESIZE [100 TO -50]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_clear() {
	std::string title = "[CLEAR]";
	std::cout << title;

	ft::List<char> ft_list(5, '!');
	std::list<char> list(5, '!');

	ft_list.clear();
	list.clear();
	chk_result(ft_list, list, "list", title, "[FULL LIST]");

	ft_list.clear();
	list.clear();
	chk_result(ft_list, list, "list", title, "[EMPTY LIST]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*OPERATIONS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_splice() {
	std::string title = "[SPLICE(1)]";
	std::cout << title;

	size_t size = 6;
	ft::List<int> ft_listA(size, 1);
	ft_listA.push_back(3);
	ft_listA.push_back(6);
	ft::List<int> ft_listB(size, 2);
	ft_listB.push_back(4);
	ft_listB.push_back(5);
	ft_listB.push_back(8);
	std::list<int> listA(size, 1);
	listA.push_back(3);
	listA.push_back(6);
	std::list<int> listB(size, 2);
	listB.push_back(4);
	listB.push_back(5);
	listB.push_back(8);

	ft_listA.splice(ft_listA.begin(), ft_listB);
	listA.splice(listA.begin(), listB);
	chk_result(ft_listA, listA, "list", title, "[FULL ORDERED vs FULL ORDERED] 1/2");
	chk_result(ft_listB, listB, "list", title, "[FULL ORDERED vs FULL ORDERED] 2/2");
	
	ft::List<int> ft_listEmptyA;
	std::list<int> listEmptyA;
	ft::List<int> ft_listEmptyB;
	std::list<int> listEmptyB;
	ft_listEmptyA.splice(ft_listEmptyA.begin(), ft_listEmptyB);
	listEmptyA.splice(listEmptyA.begin(), listEmptyB);
	chk_result(ft_listEmptyA, listEmptyA, "list", title, "[EMPTY vs EMPTY] 1/2");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY vs EMPTY] 2/2");

	ft_listA.splice(ft_listA.begin(), ft_listEmptyB);
	listA.splice(listA.begin(), listEmptyB);
	chk_result(ft_listA, listA, "list", title, "[FULL vs EMPTY] 1/2");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[FULL vs EMPTY] 2/2");

	ft_listEmptyB.splice(ft_listEmptyB.begin(), ft_listA);
	listEmptyB.splice(listEmptyB.begin(), listA);
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY vs FULL] 1/2");
	chk_result(ft_listA, listA, "list", title, "[EMPTY vs FULL] 2/2");
 
	ft::List<int> ft_listC(size, 2);
	ft_listC.push_back(4);
	ft_listC.push_back(5);
	ft_listC.push_back(8);
	ft::List<int> ft_listD(size, 2);
	ft_listD.push_back(9);
	ft_listD.push_back(1);
	ft_listD.push_back(1);
	std::list<int> listC(size, 2);
	listC.push_back(4);
	listC.push_back(5);
	listC.push_back(8);
	std::list<int> listD(size, 2);
	listD.push_back(9);
	listD.push_back(1);
	listD.push_back(1);
	
	ft_listC.splice(ft_listC.begin(), ft_listD);
	listC.splice(listC.begin(), listD);
	chk_result(ft_listC, listC, "list", title, "[FULL DISORDERED vs FULL DISORDERED] 1/2");
	chk_result(ft_listD, listD, "list", title, "[FULL DISORDERED vs FULL DISORDERED] 2/2");

	ft::List<int> ft_listE(size, 1);
	ft_listE.push_back(1);
	ft_listE.push_back(2);
	ft_listE.push_back(3);
	std::list<int> listE(size, 1);
	listE.push_back(1);
	listE.push_back(2);
	listE.push_back(3);
	ft::List<int> ft_listF(size, 1);
	ft_listF.push_back(5);
	ft_listF.push_back(1);
	ft_listF.push_back(3);
	std::list<int> listF(size, 1);
	listF.push_back(5);
	listF.push_back(1);
	listF.push_back(3);

	ft_listE.splice(ft_listE.begin(), ft_listF);
	listE.splice(listE.begin(), listF);
	chk_result(ft_listE, listE, "list", title, "[FULL ORDERED vs FULL DISORDERED] 1/2");
	chk_result(ft_listF, listF, "list", title, "[FULL ORDERED vs FULL DISORDERED] 2/2");

	ft::List<int> ft_listG(size, 1);
	ft_listG.push_back(1);
	ft_listG.push_back(2);
	ft_listG.push_back(3);
	std::list<int> listG(size, 1);
	listG.push_back(1);
	listG.push_back(2);
	listG.push_back(3);
	ft::List<int> ft_listH(size, 1);
	ft_listH.push_back(5);
	ft_listH.push_back(1);
	ft_listH.push_back(3);
	std::list<int> listH(size, 1);
	listH.push_back(5);
	listH.push_back(1);
	listH.push_back(3);

	ft_listH.splice(ft_listH.begin(), ft_listG);
	listH.splice(listH.begin(), listG);
	chk_result(ft_listH, listH, "list", title, "[FULL DISORDERED vs FULL ORDERED] 1/2");
	chk_result(ft_listG, listG, "list", title, "[FULL DISORDERED vs FULL ORDERED] 2/2");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[SPLICE(2)]";
	std::cout << title;

	size = 6;
	ft::List<int> ft_listI(size, 1);
	ft_listI.push_back(3);
	ft_listI.push_back(6);
	ft::List<int> ft_listJ(size, 2);
	ft_listJ.push_back(4);
	ft_listJ.push_back(5);
	ft_listJ.push_back(8);
	std::list<int> listI(size, 1);
	listI.push_back(3);
	listI.push_back(6);
	std::list<int> listJ(size, 2);
	listJ.push_back(4);
	listJ.push_back(5);
	listJ.push_back(8);

	ft::List<int>::iterator ft_it = ft_listJ.begin();
	std::list<int>::iterator it = listJ.begin();

	ft_listI.splice(ft_listI.begin(), ft_listJ, ft_it);
	listI.splice(listI.begin(), listJ, it);
	chk_result(ft_listI, listI, "list", title, "[BEGIN] 1/2");
	chk_result(ft_listJ, listJ, "list", title, "[BEGIN] 2/2");

	ft_it = ft_listJ.begin();
	ft_it++;
	it = listJ.begin();
	it++;

	ft_listI.splice(ft_listI.begin(), ft_listJ, ft_it);
	listI.splice(listI.begin(), listJ, it);
	chk_result(ft_listI, listI, "list", title, "[MIDDLE] 1/2");
	chk_result(ft_listJ, listJ, "list", title, "[MIDDLE] 2/2");

	//END = UNDEFINED BEHAVIOUR
	// ft_listI.splice(ft_listI.begin(), ft_listJ, ft_listJ.end());
	// listI.splice(listI.begin(), listJ, listJ.end());
	// chk_result(ft_listI, listI, "list", "SPLICE(2) [END] 1/2");
	// chk_result(ft_listJ, listJ, "list", "SPLICE(2) [END] 2/2");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[SPLICE(3)]";
	std::cout << title;

	size = 6;
	ft::List<int> ft_listK(size, 1);
	ft_listK.push_back(3);
	ft_listK.push_back(6);
	ft::List<int> ft_listL(size, 10);
	ft_listL.push_back(4);
	ft_listL.push_back(5);
	ft_listL.push_back(8);
	std::list<int> listK(size, 1);
	listK.push_back(3);
	listK.push_back(6);
	std::list<int> listL(size, 10);
	listL.push_back(4);
	listL.push_back(5);
	listL.push_back(8);

	ft::List<int>::iterator ft_itFirst = ft_listL.begin();
	std::list<int>::iterator itFirst = listL.begin();
	ft::List<int>::iterator ft_itLast = ft_itFirst;
	ft_itLast++;
	std::list<int>::iterator itLast = itFirst;
	itLast++;

	ft_listK.splice(ft_listK.begin(), ft_listL, ft_itFirst, ft_itLast);
	listK.splice(listK.begin(), listL, itFirst, itLast);
	chk_result(ft_listK, listK, "list", title, "[BEGIN] 1/2");
	chk_result(ft_listL, listL, "list", title, "[BEGIN] 2/2");

	ft_itFirst = ft_listL.begin();
	ft_itFirst++;
	ft_itLast = ft_itFirst;
	ft_itLast++;
	ft_itLast++;
	itFirst = listL.begin();
	itFirst++;
	itLast = itFirst;
	itLast++;
	itLast++;

	ft_listK.splice(ft_listK.begin(), ft_listL, ft_itFirst, ft_itLast);
	listK.splice(listK.begin(), listL, itFirst, itLast);
	chk_result(ft_listI, listI, "list", title, "[MIDDLE] 1/2");
	chk_result(ft_listJ, listJ, "list", title, "[MIDDLE] 2/2");
	
	ft_itFirst = ft_listL.begin();
	ft_itLast = ft_listL.end();
	itFirst = listL.begin();
	ft_itLast = ft_listL.end();

	ft_listK.splice(ft_listK.begin(), ft_listL, ft_itFirst, ft_itLast);
	listK.splice(listK.begin(), listL, itFirst, itLast);
	chk_result(ft_listI, listI, "list", title, "[END] 1/2");
	chk_result(ft_listJ, listJ, "list", title, "[END] 2/2");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_remove() {

	std::string title = "[REMOVE]";
	std::cout << title;

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

	ft_list.remove('a');
	list.remove('a');
	chk_result(ft_list, list, "list", title, "[WITH DOUBLES]");

	ft_list.remove('!');
	list.remove('!');
	chk_result(ft_list, list, "list", title, "[WITH BEGIN]");

	ft_list.remove('b');
	list.remove('b');
	chk_result(ft_list, list, "list", title, "[WITH ALL]");

	ft::List<char> ft_listEmpty;
	std::list<char> listEmpty;
	ft_listEmpty.remove('a');
	listEmpty.remove('a');
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY LIST]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};
struct is_even {
  bool operator() (const int& value) { return (value%2)==0; }
};

int test_list_removeIf() {
	std::string title = "[REMOVE_IF]";
	std::cout << title;

	size_t size = 5;
	ft::List<int> ft_list(size, 4);
	std::list<int> list(size, 4);

	ft::List<int>::iterator ft_it = ft_list.begin();
	std::list<int>::iterator it = list.begin();
	ft_it++;
	it++;
	ft_list.push_back(3);
	ft_list.insert(ft_it, 3);
	ft_list.insert(ft_it, 2);
	list.push_back(3);
	list.insert(it, 3);
	list.insert(it, 2);

	ft_list.remove_if(is_odd());
	list.remove_if(is_odd());
	chk_result(ft_list, list, "list", title, "[MIDDLE AND END]");

	ft_list.remove_if(is_even());
	list.remove_if(is_even());
	chk_result(ft_list, list, "list", title, "[ALL WITH BEGIN]");

	ft_list.remove_if(is_even());
	list.remove_if(is_even());
	chk_result(ft_list, list, "list", title, "[EMPTY LIST]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

struct is_near {
  bool operator() (char first, char second)
  { return (second - first <= 1 || first - second <= 1); }
};

int test_list_unique() {
	std::string title = "[UNIQUE(1)]";
	std::cout << title;

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
	chk_result(ft_list, list, "list", title, "[WITH DOUBLES]");

	ft_list.unique();
	list.unique();
	chk_result(ft_list, list, "list", title, "[NO DOUBLES]");

	ft::List<char> ft_listEmpty;
	std::list<char> listEmpty;
	ft_listEmpty.unique();
	listEmpty.unique();
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY LIST]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[UNIQUE(2)[binary_pred]]";
	std::cout << title;

	ft_list.push_back('a');
	ft_list.insert(ft_it, 'a');
	ft_list.insert(ft_it, 'b');
	list.push_back('a');
	list.insert(it, 'a');
	list.insert(it, 'b');

	ft_list.unique(is_near());
	list.unique(is_near());
	chk_result(ft_list, list, "list", title, "[WITH DOUBLES]");

	ft_list.unique(is_near());
	list.unique(is_near());
	chk_result(ft_list, list, "list", title, "[NO DOUBLES]");

	ft_listEmpty.unique(is_near());
	listEmpty.unique(is_near());
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY LIST]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_mergeComp();

int test_list_merge() {
	std::string title = "[MERGE(1)]";
	std::cout << title;

	size_t size = 6;
	ft::List<int> ft_listA(size, 1);
	ft_listA.push_back(3);
	ft_listA.push_back(6);
	ft::List<int> ft_listB(size, 2);
	ft_listB.push_back(4);
	ft_listB.push_back(5);
	ft_listB.push_back(8);
	std::list<int> listA(size, 1);
	listA.push_back(3);
	listA.push_back(6);
	std::list<int> listB(size, 2);
	listB.push_back(4);
	listB.push_back(5);
	listB.push_back(8);

	ft_listA.merge(ft_listB);
	listA.merge(listB);
	chk_result(ft_listA, listA, "list", title, "[FULL ORDERED vs FULL ORDERED] 1/2");
	chk_result(ft_listB, listB, "list", title, "[FULL ORDERED vs FULL ORDERED] 2/2");
	
	ft::List<int> ft_listEmptyA;
	std::list<int> listEmptyA;
	ft::List<int> ft_listEmptyB;
	std::list<int> listEmptyB;
	ft_listEmptyA.merge(ft_listEmptyB);
	listEmptyA.merge(listEmptyB);
	chk_result(ft_listEmptyA, listEmptyA, "list", title, "[EMPTY vs EMPTY] 1/2");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY vs EMPTY] 2/2");

	ft_listA.merge(ft_listEmptyB);
	listA.merge(listEmptyB);
	chk_result(ft_listA, listA, "list", title, "[FULL vs EMPTY] 1/2");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[FULL vs EMPTY] 2/2");

	ft_listEmptyB.merge(ft_listA);
	listEmptyB.merge(listA);
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY vs FULL] 1/2");
	chk_result(ft_listA, listA, "list", title, "[EMPTY vs FULL] 2/2");
 
	ft::List<int> ft_listC(size, 2);
	ft_listC.push_back(4);
	ft_listC.push_back(5);
	ft_listC.push_back(8);
	ft::List<int> ft_listD(size, 2);
	ft_listD.push_back(9);
	ft_listD.push_back(1);
	ft_listD.push_back(1);
	std::list<int> listC(size, 2);
	listC.push_back(4);
	listC.push_back(5);
	listC.push_back(8);
	std::list<int> listD(size, 2);
	listD.push_back(9);
	listD.push_back(1);
	listD.push_back(1);
	
	ft_listC.merge(ft_listD);
	listC.merge(listD);
	chk_result(ft_listC, listC, "list", title, "[FULL DISORDERED vs FULL DISORDERED] 1/2");
	chk_result(ft_listD, listD, "list", title, "[FULL DISORDERED vs FULL DISORDERED] 2/2");

	ft::List<int> ft_listE(size, 1);
	ft_listE.push_back(1);
	ft_listE.push_back(2);
	ft_listE.push_back(3);
	std::list<int> listE(size, 1);
	listE.push_back(1);
	listE.push_back(2);
	listE.push_back(3);
	ft::List<int> ft_listF(size, 1);
	ft_listF.push_back(5);
	ft_listF.push_back(1);
	ft_listF.push_back(3);
	std::list<int> listF(size, 1);
	listF.push_back(5);
	listF.push_back(1);
	listF.push_back(3);

	ft_listE.merge(ft_listF);
	listE.merge(listF);
	chk_result(ft_listE, listE, "list", title, "[FULL ORDERED vs FULL DISORDERED] 1/2");
	chk_result(ft_listF, listF, "list", title, "[FULL ORDERED vs FULL DISORDERED] 2/2");

	ft::List<int> ft_listG(size, 1);
	ft_listG.push_back(1);
	ft_listG.push_back(2);
	ft_listG.push_back(3);
	std::list<int> listG(size, 1);
	listG.push_back(1);
	listG.push_back(2);
	listG.push_back(3);
	ft::List<int> ft_listH(size, 1);
	ft_listH.push_back(5);
	ft_listH.push_back(1);
	ft_listH.push_back(3);
	std::list<int> listH(size, 1);
	listH.push_back(5);
	listH.push_back(1);
	listH.push_back(3);

	ft_listH.merge(ft_listG);
	listH.merge(listG);
	chk_result(ft_listH, listH, "list", title, "[FULL DISORDERED vs FULL ORDERED] 1/2");
	chk_result(ft_listG, listG, "list", title, "[FULL DISORDERED vs FULL ORDERED] 2/2");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return test_list_mergeComp();
};

struct is_bigger {
  bool operator() (int first, int second)
  { return (first > second); }
};

int test_list_mergeComp() {
	std::string title = "[MERGE(2) [COMP]]";
	std::cout << title;

	size_t size = 6;
	ft::List<int> ft_listA(size, 1);
	ft_listA.push_back(3);
	ft_listA.push_back(6);
	ft::List<int> ft_listB(size, 2);
	ft_listB.push_back(4);
	ft_listB.push_back(5);
	ft_listB.push_back(8);
	std::list<int> listA(size, 1);
	listA.push_back(3);
	listA.push_back(6);
	std::list<int> listB(size, 2);
	listB.push_back(4);
	listB.push_back(5);
	listB.push_back(8);

	ft_listA.merge(ft_listB, is_bigger());
	listA.merge(listB, is_bigger());
	chk_result(ft_listA, listA, "list", title, "[FULL ORDERED vs FULL ORDERED] 1/2");
	chk_result(ft_listB, listB, "list", title, "[FULL ORDERED vs FULL ORDERED] 2/2");
	
	ft::List<int> ft_listEmptyA;
	std::list<int> listEmptyA;
	ft::List<int> ft_listEmptyB;
	std::list<int> listEmptyB;
	ft_listEmptyA.merge(ft_listEmptyB, is_bigger());
	listEmptyA.merge(listEmptyB, is_bigger());
	chk_result(ft_listEmptyA, listEmptyA, "list", title, "[EMPTY vs EMPTY] 1/2");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY vs EMPTY] 2/2");

	ft_listA.merge(ft_listEmptyB, is_bigger());
	listA.merge(listEmptyB, is_bigger());
	chk_result(ft_listA, listA, "list", title, "[FULL vs EMPTY] 1/2");
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[FULL vs EMPTY] 2/2");

	ft_listEmptyB.merge(ft_listA, is_bigger());
	listEmptyB.merge(listA, is_bigger());
	chk_result(ft_listEmptyB, listEmptyB, "list", title, "[EMPTY vs FULL] 1/2");
	chk_result(ft_listA, listA, "list", title, "[EMPTY vs FULL] 2/2");
 
	ft::List<int> ft_listC(size, 2);
	ft_listC.push_back(4);
	ft_listC.push_back(5);
	ft_listC.push_back(8);
	ft::List<int> ft_listD(size, 2);
	ft_listD.push_back(9);
	ft_listD.push_back(1);
	ft_listD.push_back(1);
	std::list<int> listC(size, 2);
	listC.push_back(4);
	listC.push_back(5);
	listC.push_back(8);
	std::list<int> listD(size, 2);
	listD.push_back(9);
	listD.push_back(1);
	listD.push_back(1);
	
	ft_listC.merge(ft_listD, is_bigger());
	listC.merge(listD, is_bigger());
	chk_result(ft_listC, listC, "list", title, "[FULL DISORDERED vs FULL DISORDERED] 1/2");
	chk_result(ft_listD, listD, "list", title, "[FULL DISORDERED vs FULL DISORDERED] 2/2");

	ft::List<int> ft_listE(size, 1);
	ft_listE.push_back(1);
	ft_listE.push_back(2);
	ft_listE.push_back(3);
	std::list<int> listE(size, 1);
	listE.push_back(1);
	listE.push_back(2);
	listE.push_back(3);
	ft::List<int> ft_listF(size, 1);
	ft_listF.push_back(5);
	ft_listF.push_back(1);
	ft_listF.push_back(3);
	std::list<int> listF(size, 1);
	listF.push_back(5);
	listF.push_back(1);
	listF.push_back(3);

	ft_listE.merge(ft_listF, is_bigger());
	listE.merge(listF, is_bigger());
	chk_result(ft_listE, listE, "list", title, "[FULL ORDERED vs FULL DISORDERED] 1/2");
	chk_result(ft_listF, listF, "list", title, "[FULL ORDERED vs FULL DISORDERED] 2/2");

	ft::List<int> ft_listG(size, 1);
	ft_listG.push_back(1);
	ft_listG.push_back(2);
	ft_listG.push_back(3);
	std::list<int> listG(size, 1);
	listG.push_back(1);
	listG.push_back(2);
	listG.push_back(3);
	ft::List<int> ft_listH(size, 1);
	ft_listH.push_back(5);
	ft_listH.push_back(1);
	ft_listH.push_back(3);
	std::list<int> listH(size, 1);
	listH.push_back(5);
	listH.push_back(1);
	listH.push_back(3);

	ft_listH.merge(ft_listG, is_bigger());
	listH.merge(listG, is_bigger());
	chk_result(ft_listH, listH, "list", title, "[FULL DISORDERED vs FULL ORDERED] 1/2");
	chk_result(ft_listG, listG, "list", title, "[FULL DISORDERED vs FULL ORDERED] 2/2");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_sort() {
	std::string title = "[SORT(1)]";
	std::cout << title;

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
	chk_result(ft_list, list, "list", title);

	ft::List<int> ft_listEmpty;
	std::list<int> listEmpty;
	ft_listEmpty.sort();
	listEmpty.sort();
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//----------------------------------------------------------

	title = "[SORT(2)]";
	std::cout << title;
	
	ft_list.sort(is_bigger());
	list.sort(is_bigger());
	chk_result(ft_list, list, "list", title);

	ft_listEmpty.sort(is_bigger());
	listEmpty.sort(is_bigger());
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_list_reverse() {
	std::string title = "[REVERSE]";
	std::cout << title;

	ft::List<char> ft_list(5, '!');
	std::list<char> list(5, '!');

	ft::List<char>::iterator ft_it = ft_list.begin();
	std::list<char>::iterator it = list.begin();
	ft_it++;
	it++;
	ft_list.push_back('8');
	ft_list.push_front('1');
	ft_list.insert(ft_it, 'a');
	ft_list.insert(ft_it, 'b');
	list.push_back('8');
	list.push_front('1');
	list.insert(it, 'a');
	list.insert(it, 'b');

	ft_list.reverse();
	list.reverse();
	chk_result(ft_list, list, "list", title, "[FULL, EVEN NODES]");
	ft_list.pop_front();
	list.pop_front();
	chk_result(ft_list, list, "list", title, "[FULL, ODD NODES]");

	ft::List<char> ft_listEmpty;
	std::list<char> listEmpty;
	ft_listEmpty.reverse();
	listEmpty.reverse();
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY LIST]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}


//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\NON-MEMBERS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_list_nonMembers() {
	std::string title = "----[NON-MEMBER OPERATORS]----";
	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
	title = "[OPERATOR==]";
	std::cout << title;

	ft::List<int> ft_listA;
	std::list<int> listA;
	ft_listA.push_back(0);
	ft_listA.push_back(2145678);
	ft_listA.push_back(-70);
	ft_listA.push_back(42);
	listA.push_back(0);
	listA.push_back(2145678);
	listA.push_back(-70);
	listA.push_back(42);
	ft::List<int> ft_listB;
	std::list<int> listB;
	ft_listB.push_back(0);
	ft_listB.push_back(2145678);
	ft_listB.push_back(-70);
	ft_listB.push_back(42);
	listB.push_back(0);
	listB.push_back(2145678);
	listB.push_back(-70);
	listB.push_back(42);

	bool ft_bool = (ft_listA == ft_listB);
	bool std_bool = (listA == listB);
	if (ft_bool != std_bool) {
		handle_error(ft_listA, ft_listB, "list", title, "[EQUAL]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft::List<int> ft_listC;
	std::list<int> listC;
	ft_listC.push_back(0);
	ft_listC.push_back(666);
	//ft_listC.push_back(-70);
	ft_listC.push_back(42);
	listC.push_back(0);
	listC.push_back(666);
	//listC.push_back(-70);
	listC.push_back(42);

	ft_bool = (ft_listA == ft_listC);
	std_bool = (listA == listC);
	if (ft_bool != std_bool) {
		handle_error(ft_listA, ft_listC, "list", title, "[DIFF]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR!=]";
	std::cout << title;

	ft_bool = (ft_listA != ft_listB);
	std_bool = (listA != listB);
	if (ft_bool != std_bool) {
		handle_error(ft_listA, ft_listB, "list", title, "[EQUAL]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_listA != ft_listC);
	std_bool = (listA != listC);
	if (ft_bool != std_bool) {
		handle_error(ft_listA, ft_listC, "list", title, "[DIFF]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<]";
	std::cout << title;

	ft_bool = (ft_listC < ft_listA);
	std_bool = (listC < listA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA < ft_listC);
	std_bool = (listA < listC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA < ft_listB);
	std_bool = (listA < listB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	}
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<=]";
	std::cout << title;

	ft_bool = (ft_listC <= ft_listA);
	std_bool = (listC <= listA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA <= ft_listC);
	std_bool = (listA <= listC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA <= ft_listB);
	std_bool = (listA <= listB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>]";
	std::cout << title;

	ft_bool = (ft_listC > ft_listA);
	std_bool = (listC > listA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA > ft_listC);
	std_bool = (listA > listC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA > ft_listB);
	std_bool = (listA > listB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>=]";
	std::cout << title;

	ft_bool = (ft_listC >= ft_listA);
	std_bool = (listC >= listA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA >= ft_listC);
	std_bool = (listA >= listC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	}

	ft_bool = (ft_listA >= ft_listB);
	std_bool = (listA >= listB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[SWAP (non-member)]";
	std::cout << title;

	swap(ft_listA, ft_listC);
	swap(listA, listC);
	chk_result(ft_listA, listA, "list", title, "[1/2]");
	chk_result(ft_listC, listC, "list", title, "[2/2]");

	ft::List<int> ft_listEmpty;
	std::list<int> listEmpty;
	swap(ft_listEmpty, ft_listC);
	swap(listEmpty, listC);
	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY vs FULL] [1/2]");
	chk_result(ft_listC, listC, "list", title, "[EMPTY vs FULL] [2/2]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

