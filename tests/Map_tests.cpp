/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/19 16:18:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <iomanip>
#include <string>

#include <map>

class customException;

//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/*\CONSTRUCTORS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_map_rangeConstr() {
	std::string title = "[RANGE CONSTRUCTOR]";
	std::cout << title;

	std::map<char, int> src;
	src['a']=10;
	src['b']=30;
	// src['c']=50;
//	src['d']=70;

	ft::Map<char, int> ft_src;
	ft_src['b']=30;
	std::cout << "after ft_src['b']=30;" << std::endl;
	ft_src['a']=10;
	std::cout << "after ft_src['a']=10;" << std::endl;
	


	// ft_src['c']=50;
	// std::cout << "after ft_src['c']=50; : ft_src['c'] = [" << ft_src['c'] << "]"  << std::endl;
	//ft_src['d']=70;

		chk_mapResult(ft_src, src, "map", title);

	// ft::Map<char, int> ft_map;
	// std::map<char, int> map;

	// chk_mapResult(ft_map, map, "map", title);

	// ft::Map<char, int> ft_mapA(ft_src.begin(), ft_src.end());
	// std::map<char, int> mapA(src.begin(), src.end());

	// ft::Map<char, int> ft_mapB(ft_mapA);
	// std::map<char, int> mapB(mapA);
	// chk_mapResult(ft_mapB, mapB, "map", title);

	// std::cout << "in main : size " << ft_mapA.size() << std::endl;
	// std::cout << "*****************************" << std::endl;
	// chk_mapResult(ft_mapA, mapA, "map", title);
	// std::cout << "*****************************" << std::endl;

	

	// ft::Map<char, int> ft_mapEmpty(src.end(), src.end());
	// std::map<char, int> mapEmpty(src.end(), src.end());

	// chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

// int test_map_copyConstr() {
// 	std::string title = "[COPY CONSTR]";
// 	std::cout << title;

// 	ft::Map<char> ft_src(10, '!');
// 	ft_src.push_back('@');

// 	std::map<char> src(10, '!');
// 	src.push_back('@');

// 	ft::Map<char> ft_map(ft_src);
// 	std::map<char> map(src);

// 	chk_result(ft_map, map, "map", title);

// 	ft::Map<char> ft_srcB(0, '!');
// 	std::map<char> srcB(0, '!');
// 	ft::Map<char> ft_mapEmpty(ft_srcB);
// 	std::map<char> mapEmpty(srcB);

// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]");

// 	//INVALID SRC = UNDEFINED BEHAVIOR
// 	// ft::Map<char> *ft_nullSrc = nullptr;
// 	// ft::Map<char> ft_mapNull(*ft_nullSrc);
// 	// ft::Map<char> *nullSrc = nullptr;
// 	// ft::Map<char> mapNull(*nullSrc)
// 	//	chk_result(ft_mapNull, mapNull, "map", "COPY CONSTRUCTOR [NULL SRC]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_opEqual() {
// 	std::string title = "[OPERATOR=]";
// 	std::cout << title;

// 	ft::Map<char> ft_src(10, '!');
// 	ft_src.push_back('@');

// 	std::map<char> src(10, '!');
// 	src.push_back('@');

// 	ft::Map<char> ft_map = ft_src;
// 	std::map<char> map = src;

// 	chk_result(ft_map, map, "map", title);

// 	ft::Map<char> ft_srcB(0, '!');
// 	std::map<char> srcB(0, '!');
// 	ft::Map<char> ft_mapEmpty = ft_srcB;
// 	std::map<char> mapEmpty = srcB;

// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]");

// 	ft_map = ft_srcB;
// 	map = srcB;

// 	chk_result(ft_map, map, "map", title, "[FULL = EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };


// //*\*/*\/*\*/*\/*\*/*\/*\*///
// //*\*/*\*/ITERATORS/*\*/*\*//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_map_pushBack_iterate() {
// 	std::string title = "[BASIC INSTANCE + PUSH_BACK]";
// 	std::cout << title;

// 	ft::Map<int> ft_map;
// 	std::map<int> map;

// 	ft_map.push_back(10);
// 	ft_map.push_back(12);
// 	ft_map.push_back(18);

// 	map.push_back(10);
// 	map.push_back(12);
// 	map.push_back(18);

// 	chk_result(ft_map, map, "map", title);

// 	ft::Map<char> ft_mapEmpty;
// 	ft_map.push_back('&');
// 	std::map<char> mapEmpty;
// 	map.push_back('&');

// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]");
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

// 	title = "[BASIC ITERATING + DEREFERENCING]";
// 	std::cout << title;

// 	int tmp;
// 	ft::Map<int>::iterator it = ft_map.begin();
// 	while (it != ft_map.end()) {
// 		//std::cout << *it << std::endl; //commented to keep test output clean
// 		tmp = *it;
// 		it++;
// 	}
// 	chk_result(ft_map, map, "map", title);

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

// 	title = "[BASIC REVERSE ITERATING + DEREFERENCING]";
// 	std::cout << title;

// 	ft::Map<int>::reverse_iterator rit = ft_map.rbegin();
// 	while (rit != ft_map.rend()) {
// 		//std::cout << *it << std::endl; //commented to keep test output clean
// 		tmp = *rit;
// 		rit++;
// 	}
// 	chk_result(ft_map, map, "map", title);

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
//     return 0;
// };

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// ///*\*/*\*/CAPACITY/*\*/*\*//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_map_maxSize() {
// 	std::string title = "[MAX_SIZE]";
// 	std::cout << title;

// 	ft::Map<int> ft_mapint;
// 	std::map<int> mapint;

// 	ft::Map<char> ft_mapchar;
// 	std::map<char> mapchar;

// 	ft::Map<double> ft_mapdouble;
// 	std::map<double> mapdouble;

// 	ft::Map<std::string> ft_mapstring;
// 	std::map<std::string> mapstring;

// 	size_t ft_max = ft_mapint.max_size();
// 	size_t max = mapint.max_size();

// 	if (max != ft_max) {
// 		std::cerr << "int ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
// 		handle_error(ft_mapint, mapint, "map", title, "int map", "MAX_SIZE");
// 	}

// 	ft_max = ft_mapchar.max_size();
// 	max = mapchar.max_size();

// 	if (max != ft_max) {
// 		std::cerr << "char ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
// 		handle_error(ft_mapchar, mapchar, "map", title, "char map", "MAX_SIZE");
// 	}

// 	ft_max = ft_mapdouble.max_size();
// 	max = mapdouble.max_size();

// 	if (max != ft_max) {
// 		std::cerr << "double ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
// 		handle_error(ft_mapdouble, mapdouble, "map", title, "double map", "MAX_SIZE");
// 	}

// 	ft_max = ft_mapstring.max_size();
// 	max = mapstring.max_size();

// 	if (max != ft_max) {
// 		std::cerr << "string ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
// 		handle_error(ft_mapstring, mapstring, "map", title, "std::string map", "MAX_SIZE");
// 	}
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// }

// int test_map_capacity() {
// 	std::string title = "[CAPACITY]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(5, '!');
// 	std::map<char> map(5, '!');
// 	ft::Map<char>::iterator ft_it = ft_map.begin();
// 	std::map<char>::iterator it = map.begin();
// 	ft_it++;
// 	it++;

// 	ft_map.push_back('a');
// 	ft_map.insert(ft_map.begin(), 'a');
// 	ft_map.insert(ft_map.begin(), 'b');
// 	map.push_back('a');
// 	map.insert(map.begin(), 'a');
// 	map.insert(map.begin(), 'b');

// 	size_t ft_capacity = ft_map.capacity();
// 	size_t std_capacity = map.capacity();
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[FULL]", "CONTENT");
// 	}
	
// 	ft::Map<char> ft_mapEmpty;
// 	std::map<char> mapEmpty;
// 	ft_capacity = ft_mapEmpty.capacity();
// 	std_capacity = mapEmpty.capacity();
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[EMPTY]", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_resize() {
// 	std::string title = "[RESIZE]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(5, '!');
// 	std::map<char> map(5, '!');

// 	ft_map.resize(2);
// 	map.resize(2);
// 	chk_result(ft_map, map, "map", title, "[5 TO 2]");

// 	ft_map.resize(0);
// 	map.resize(0);
// 	chk_result(ft_map, map, "map", title, "[2 TO 0]");

// 	ft_map.resize(0);
// 	map.resize(0);
// 	chk_result(ft_map, map, "map", title, "[0 TO 0]");

// 	ft_map.resize(5);
// 	map.resize(5);
// 	chk_result(ft_map, map, "map", title, "[0 TO 5]");
	
// 	ft_map.resize(100);
// 	map.resize(100);
// 	chk_result(ft_map, map, "map", title, "[5 TO 100]");

// 	ft_map.resize(100);
// 	map.resize(100);
// 	chk_result(ft_map, map, "map", title, "[100 TO 100]");

// 	//UNDEFINED BEHAVIOUR
// 	//ft_map.resize(-50);
// 	//map.resize(-50);
// 	//chk_result(ft_map, map, "map", "RESIZE [100 TO -50]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_empty() {
// 	std::string title = "[EMPTY]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(5, '!');
// 	std::map<char> map(5, '!');
// 	ft::Map<char>::iterator ft_it = ft_map.begin();
// 	std::map<char>::iterator it = map.begin();
// 	ft_it++;
// 	it++;

// 	ft_map.push_back('a');
// 	ft_map.insert(ft_map.begin(), 'a');
// 	ft_map.insert(ft_map.begin(), 'b');
// 	map.push_back('a');
// 	map.insert(map.begin(), 'a');
// 	map.insert(map.begin(), 'b');
// 	bool ft_empty = ft_map.empty();
// 	bool std_empty = map.empty();
// 	if (ft_empty != std_empty) {
// 		std::cerr << "ft_map.empty() = [" << ft_empty << "] | map.empty() = [" << std_empty << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[FULL]", "CONTENT");
// 	}
	
// 	ft::Map<char> ft_mapEmpty;
// 	std::map<char> mapEmpty;
// 	ft_empty = ft_mapEmpty.empty();
// 	std_empty = mapEmpty.empty();
// 	if (ft_empty != std_empty) {
// 		std::cerr << "ft_map.empty() = [" << ft_empty << "] | map.empty() = [" << std_empty << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_reserve() {
// 	std::string title = "[RESERVE]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(5, '!');
// 	std::map<char> map(5, '!');

// 	size_t ft_size = ft_map.size();
// 	size_t std_size = map.size();
// 	size_t ft_capacity = ft_map.capacity();
// 	size_t std_capacity = map.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5]", "CAPACITY");
// 	}

// 	ft_map.reserve(2);
// 	map.reserve(2);
// 	ft_size = ft_map.size();
// 	std_size = map.size();
// 	ft_capacity = ft_map.capacity();
// 	std_capacity = map.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5 RESERVE 2]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5 RESERVE 2]", "CAPACITY");
// 	}

// 	ft_map.reserve(6);
// 	map.reserve(6);
// 	ft_size = ft_map.size();
// 	std_size = map.size();
// 	ft_capacity = ft_map.capacity();
// 	std_capacity = map.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5 RESERVE 6]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5 RESERVE 6]", "CAPACITY");
// 	}

// 	ft_map.push_back('a');
// 	ft_map.insert(ft_map.begin(), 'a');
// 	ft_map.insert(ft_map.begin(), 'b');
// 	map.push_back('a');
// 	map.insert(map.begin(), 'a');
// 	map.insert(map.begin(), 'b');

// 	ft_size = ft_map.size();
// 	std_size = map.size();
// 	ft_capacity = ft_map.capacity();
// 	std_capacity = map.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[PUSH BACK AND STUFF AFTER RESERVE]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[PUSH BACK AND STUFF AFTER RESERVE]", "CAPACITY");
// 	}

// 	ft_map.reserve(10000);
// 	map.reserve(10000);
// 	ft_size = ft_map.size();
// 	std_size = map.size();
// 	ft_capacity = ft_map.capacity();
// 	std_capacity = map.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5 RESERVE 10000]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[SIZE 5 RESERVE 10000]", "CAPACITY");
// 	}
	
// 	ft::Map<char> ft_mapEmpty;
// 	std::map<char> mapEmpty;
// 	ft_size = ft_mapEmpty.size();
// 	std_size = mapEmpty.size();
// 	ft_capacity = ft_mapEmpty.capacity();
// 	std_capacity = mapEmpty.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]", "CAPACITY");
// 	}

// 	ft_mapEmpty.reserve(0);
// 	mapEmpty.reserve(0);
// 	ft_size = ft_mapEmpty.size();
// 	std_size = mapEmpty.size();
// 	ft_capacity = ft_mapEmpty.capacity();
// 	std_capacity = mapEmpty.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY RESERVE 0]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY RESERVE 0]", "CAPACITY");
// 	}

// 	ft_mapEmpty.reserve(50000);
// 	mapEmpty.reserve(50000);
// 	ft_size = ft_mapEmpty.size();
// 	std_size = mapEmpty.size();
// 	ft_capacity = ft_mapEmpty.capacity();
// 	std_capacity = mapEmpty.capacity();

// 	if (ft_size != std_size) {
// 		std::cerr << "ft_map.size() = [" << ft_size << "] | map.size() = [" << std_size << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY RESERVE 50000]", "SIZE");
// 	}
// 	if (ft_capacity != std_capacity) {
// 		std::cerr << "ft_map.capacity() = [" << ft_capacity << "] | map.capacity() = [" << std_capacity << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY RESERVE 50000]", "CAPACITY");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// //*\*/ELEMENT ACCESS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_map_oparray() {
// 	std::string title = "[OPERATOR[]]";
// 	std::cout << title;

// 	ft::Map<int> ft_map;
// 	std::map<int> map;

// 	ft_map.push_back(10);
// 	ft_map.push_back(12);
// 	ft_map.push_back(18);
// 	ft_map.insert(ft_map.begin(), 12, 'a');
// 	ft_map.insert(ft_map.begin(), 5, 'b');

// 	map.push_back(10);
// 	map.push_back(12);
// 	map.push_back(18);
// 	map.insert(map.begin(), 12, 'a');
// 	map.insert(map.begin(), 5, 'b');
	
// 	for (size_t i = 0; i < ft_map.size(); i++) {
// 		if (ft_map[i] != map[i]) {
// 			std::cerr << "ft_map[" << i << "] = [" << ft_map[i] << "] | map[" << i << "] = [" << map[i] << std::endl;
// 			handle_error(ft_map, map, "map", title, "[COMPARE]", "");
// 		}
// 	}
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_at() {
// 	std::string title = "[AT]";
// 	std::cout << title;

// 	ft::Map<int> ft_map;
// 	std::map<int> map;

// 	ft_map.push_back(10);
// 	ft_map.push_back(12);
// 	ft_map.push_back(18);
// 	ft_map.insert(ft_map.begin(), 12, 'a');
// 	ft_map.insert(ft_map.begin(), 5, 'b');

// 	map.push_back(10);
// 	map.push_back(12);
// 	map.push_back(18);
// 	map.insert(map.begin(), 12, 'a');
// 	map.insert(map.begin(), 5, 'b');
	
// 	for (size_t i = 0; i < ft_map.size(); i++) {
// 		if (ft_map.at(i) != map.at(i)) {
// 			std::cerr << "ft_map[" << i << "] = [" << ft_map[i] << "] | map[" << i << "] = [" << map[i] << std::endl;
// 			handle_error(ft_map, map, "map", title, "[COMPARE]", "");
// 		}
// 	}
// 	try {
// 		ft_map.at(20);
// 		std::cerr << "ERROR HASN'T BEEN THROWN IN CASE OF OUT OR RANGE MAP ACCESS WITH AT [map size20 accessing idx 20]/!\\" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[COMPARE]", "");
// 	}
// 	catch (std::exception &e) {
// 		try {
// 			map.at(20);
// 		}
// 		catch (std::exception &f) {
// 			if (strcmp(f.what(), e.what())) {
// 				std::cerr << "ft_error[" << e.what() << "] | std_error[" << f.what() << "]" << std::endl;
// 				handle_error(ft_map, map, "map", title, "[COMPARE]", "");
// 			}
// 		}
// 	}
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_front_back() {
// 	std::string title = "[FRONT/BACK]";
// 	std::cout << title;

// 	ft::Map<int> ft_map;
// 	std::map<int> map;

// 	ft_map.push_back(10);
// 	ft_map.push_back(12);
// 	ft_map.push_back(18);

// 	map.push_back(10);
// 	map.push_back(12);
// 	map.push_back(18);

// 	if (ft_map.front() != map.front() || ft_map.back() != map.back()) {
// 		std::cerr << "ft_map.front() = [" << ft_map.front() << "] | map.front() = [" << map.front() << "]" << std::endl;
// 		std::cerr << "ft_map.back() = [" << ft_map.back() << "] | map.back() = [" << map.back() << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "", "CONTENT");
// 	}

// 	//UNDEFINED
// 	// ft::Map<int> ft_mapEmpty;
// 	// std::map<int> mapEmpty;

// 	// if (ft_mapEmpty.front() != mapEmpty.front() || ft_mapEmpty.back() != mapEmpty.back()) {
// 	// 	std::cerr << "ft_mapEmpty.front() = [" << ft_mapEmpty.front() << "] | mapEmpty.front() = [" << mapEmpty.front() << "]" << std::endl;
// 	// 	std::cerr << "ft_mapEmpty.back() = [" << ft_mapEmpty.back() << "] | mapEmpty.back() = [" << mapEmpty.back() << "]" << std::endl;
// 	// 	handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]", "CONTENT");
// 	// }
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

// 	title = "[FRONT/BACK CONST OVERLOAD]";
// 	std::cout << title;

// 	size_t size = 12;
// 	ft::Map<int> const ft_constMap(size, 8);
// 	std::map<int> const constMap(size, 8);

// 	if (ft_constMap.front() != constMap.front() || ft_constMap.back() != constMap.back()) {
// 		std::cerr << "ft_constMap.front() = [" << ft_constMap.front() << "] | constMap.front() = [" << constMap.front() << "]" << std::endl;
// 		std::cerr << "ft_constMap.back() = [" << ft_constMap.back() << "] | constMap.back() = [" << constMap.back() << "]" << std::endl;
// 		handle_error(ft_constMap, constMap, "map", title, "[CONST]", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// ///*\*/*\*/MODIFIERS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_map_assign() {
// 	std::string title = "[ASSIGN(1)]";
// 	std::cout << title;

// 	ft::Map<char> ft_src(8, 'k');
// 	std::map<char> src(8, 'k');
// 	ft::Map<char> ft_map;
// 	std::map<char> map;

// 	ft_map.assign(ft_src.begin(), ft_src.end());
// 	map.assign(src.begin(), src.end());
// 	chk_result(ft_map, map, "map", title, "[FULL to EMPTY][1/2]");
// 	chk_result(ft_src, src, "map", title, "[FULL to EMPTY][2/2]");

// 	ft_src.assign(ft_map.begin(), ft_map.end());
// 	src.assign(map.begin(), map.end());
// 	chk_result(ft_map, map, "map", title, "[FULL to FULL][1/2]");
// 	chk_result(ft_src, src, "map", title, "[FULL to EMPTY][2/2]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

// 	//------------------------------------------------------------------------
// 	title = "[ASSIGN(2)]";
// 	std::cout << title;

// 	ft::Map<char> ft_mapA;
// 	std::map<char> mapA;

// 	ft_mapA.assign(12, 'W');
// 	mapA.assign(12, 'W');
// 	chk_result(ft_mapA, mapA, "map", title, "[to EMPTY]");
	
// 	ft_mapA.assign(4, '8');
// 	mapA.assign(4, '8');
// 	chk_result(ft_mapA, mapA, "map", title, "[to FULL]");

// 	ft_mapA.assign(24, 'U');
// 	mapA.assign(24, 'U');
// 	chk_result(ft_mapA, mapA, "map", title, "[to FULL]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// }

// int test_map_popBack() {
// 	std::string title = "[POP_BACK]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(10, '!');
// 	ft_map.push_back('@');
// 	ft_map.push_back('&');

// 	std::map<char> map(10, '!');
// 	map.push_back('@');
// 	map.push_back('&');

// 	ft_map.pop_back();
// 	map.pop_back();
// 	chk_result(ft_map, map, "map", title);

// 	ft::Map<char> ft_mapEmpty;
// 	ft_map.pop_back();
// 	std::map<char> mapEmpty;
// 	map.pop_back();

// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_insert() {
// 	//------------------------------------------------------------------------
// 	std::string title = "[INSERT(1)]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(10, '!');
// 	ft_map.push_back('@');
// 	ft_map.push_back('&');
// 	ft::Map<char>::iterator ft_it = ft_map.begin();
// 	ft_it = ft_map.insert(ft_it, 'a');
// 	ft_it = ft_map.insert(ft_it, 'b');
// 	ft_it = ft_map.insert(ft_it, 'c');

// 	std::map<char> map(10, '!');
// 	map.push_back('@');
// 	map.push_back('&');
// 	std::map<char>::iterator it = map.begin();
// 	it = map.insert(it, 'a');
// 	it = map.insert(it, 'b');
// 	it = map.insert(it, 'c');

// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title);
	

// 	ft::Map<char> ft_mapEmpty;
// 	ft_it = ft_mapEmpty.begin();
// 	ft_it = ft_mapEmpty.insert(ft_it, 'a');
// 	std::map<char> mapEmpty;
// 	it = mapEmpty.begin();
// 	it = mapEmpty.insert(it, 'a');

// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]", "CONTENT");
// 	}
// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[INSERT(2)[FILL]]";
// 	std::cout << title;

// 	size_t size = 3;
// 	ft_it = ft_map.begin();
// 	ft_it++;
// 	ft_map.insert(ft_it, size, '6');
// 	ft_it = ft_map.begin();

// 	it = map.begin();
// 	it++;
// 	map.insert(it, size, '6');
// 	it = map.begin();
	
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(2) = [" << *ft_it << "] | *it after insert(2) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title);
	
// 	ft::Map<char> ft_mapEmptyB;
// 	ft_it = ft_mapEmptyB.begin();
// 	ft_mapEmptyB.insert(ft_it, size, '6');
// 	std::map<char> mapEmptyB;
// 	it = mapEmptyB.begin();
// 	mapEmptyB.insert(it, size, '6');

// 	chk_result(ft_mapEmptyB, mapEmptyB, "map", title, "[EMPTY to FULL]");

// 	size = 0;
// 	ft::Map<char> ft_mapEmptyC;
// 	ft_it = ft_mapEmptyC.begin();
// 	ft_mapEmptyC.insert(ft_it, size, '6');
// 	std::map<char> mapEmptyC;
// 	it = mapEmptyC.begin();
// 	mapEmptyC.insert(it, size, '6');

// 	chk_result(ft_mapEmptyC, mapEmptyC, "map", title, "[EMPTY to EMPTY]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[INSERT(3)[RANGE]]";
// 	std::cout << title;
// 	chk_result(ft_map, map, "map", title, "askdjhaskjdh");
	
// 	ft::Map<char> ft_src(10, '!');
// 	ft_src.push_back('@');

// 	ft_it = ft_map.begin();
// 	ft_it++;
// 	ft_map.insert(ft_it, ft_src.begin(), ft_src.end());
// 	ft_it = ft_map.begin();

// 	std::map<char> src(10, '!');
// 	src.push_back('@');

// 	it = map.begin();
// 	it++;
// 	map.insert(it, src.begin(), src.end());
// 	it = map.begin();
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(3) = [" << *ft_it << "] | *it after insert(3) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title);

// 	ft::Map<char> ft_mapEmptyD;
// 	ft_it = ft_mapEmptyC.begin();
// 	ft_mapEmptyC.insert(ft_it, ft_mapEmptyD.begin(), ft_mapEmptyD.end());
// 	std::map<char> mapEmptyD;
// 	it = mapEmptyC.begin();
// 	mapEmptyC.insert(it, mapEmptyD.begin(), mapEmptyD.end());
// 	chk_result(ft_mapEmptyC, mapEmptyC, "map", title, "[EMPTY to EMPTY]");

// 	ft_it = ft_map.begin();
// 	ft_map.insert(ft_it, ft_mapEmptyD.begin(), ft_mapEmptyD.end());
// 	it = map.begin();
// 	map.insert(it, mapEmptyD.begin(), mapEmptyD.end());
// 	ft_it = ft_map.begin();
// 	it = map.begin();
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(3) = [" << *ft_it << "] | *it after insert(3) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title, "[EMPTY to FULL]");
	
// 	ft_it = ft_mapEmptyD.begin();
// 	ft_mapEmptyD.insert(ft_it, ft_map.begin(), ft_map.end());
// 	it = mapEmptyD.begin();
// 	mapEmptyD.insert(it, map.begin(), map.end());
// 	chk_result(ft_mapEmptyD, mapEmptyD, "map", title, "[FULL TO EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_erase() {
// 	std::string title = "[ERASE(1)]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(10, '!');
// 	ft_map.push_back('@');
// 	ft_map.push_back('&');
	
// 	std::map<char> map(10, '!');
// 	map.push_back('@');
// 	map.push_back('&');

// 	ft::Map<char>::iterator ft_it = ft_map.begin();
// 	std::map<char>::iterator it = map.begin();

// 	ft_it = ft_map.erase(ft_it);
// 	it = map.erase(it);
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[begin]", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title, "[begin]");

// 	ft_it = ft_map.erase(ft_it);
// 	it = map.erase(it);
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[begin]", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title, "[begin]");

// 	//INVALID POSITION = UNDEFINED BEHAVIOR
// 	// ft_it = ft_map.end();
// 	// it = map.end();
// 	// ft_it = ft_map.erase(ft_it);
// 	// it = map.erase(it);
// 	// chk_result(ft_map, map, "map", "ERASE(1) [end]");

// 	while (ft_it != ft_map.end())
// 		ft_it = ft_map.erase(ft_it);
// 	while (it != map.end())
// 		it = map.erase(it);
// 	chk_result(ft_map, map, "map", title, "[all]");

// 	//ERASE EMPTY BEGIN = UNDEFINED BEHAVIOUR
// 	//ft::Map<char> ft_mapEmpty;
// 	//std::map<char> mapEmpty;
// 	//ft_mapEmpty.erase(ft_mapEmpty.begin());
// 	//mapEmpty.erase(mapEmpty.begin());
// 	//chk_result(ft_mapEmpty, mapEmpty, "map", "ERASE(1) [EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[ERASE(2)[RANGE]]";
// 	std::cout << title;

// 	ft_map.erase(ft_map.begin(), ft_map.end());
// 	map.erase(map.begin(), map.end());
// 	chk_result(ft_map, map, "map", title, "[EMPTY]");
	
// 	ft_map.insert(ft_map.begin(), 10, '!');
// 	ft_map.push_back('@');
// 	ft_map.push_back('&');
// 	ft_it = ft_map.begin();
// 	ft_it++;
// 	ft_it++;

// 	map.insert(map.begin(), 10, '!');
// 	map.push_back('@');
// 	map.push_back('&');
// 	it = map.begin();
// 	it++;
// 	it++;

// 	ft::Map<char>::iterator ft_last = ft_it;
// 	std::map<char>::iterator last = it;
// 	ft_last++;
// 	last++;
		
// 	ft_it = ft_map.erase(ft_it, ft_last);
// 	it = map.erase(it, last);

// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after erase(2) = [" << *ft_it << "] | *it after erase(2) = [" << *it << "]" << std::endl;
// 		handle_error(ft_map, map, "map", title, "[PARTIAL]", "CONTENT");
// 	}
// 	chk_result(ft_map, map, "map", title, "[PARTIAL]");
	
// 	ft_it = ft_map.erase(ft_map.begin(), ft_map.end());
// 	it = map.erase(map.begin(), map.end());
// 	chk_result(ft_map, map, "map", title, "[TOTAL]");
// 	//not comparing return pointers because they point after end() in this case

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_swap() {
// 	std::string title = "[SWAP]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(10, '!');
// 	ft_map.push_back('@');
// 	ft_map.push_back('&');

// 	std::map<char> map(10, '!');
// 	map.push_back('@');
// 	map.push_back('&');

// 	ft::Map<char> ft_mapEmpty;
// 	std::map<char> mapEmpty;
// 	ft_mapEmpty.swap(ft_map);
// 	mapEmpty.swap(map);

// 	chk_result(ft_map, map, "map", title, "[Full vs Empty][1/2]");
// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[Full vs Empty][2/2]");
	
// 	ft_mapEmpty.swap(ft_map);
// 	mapEmpty.swap(map);
// 	chk_result(ft_map, map, "map", title, "[Empty vs Full][1/2]");
// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[Empty vs Full][2/2]");

// 	ft_mapEmpty.insert(ft_mapEmpty.begin(), 56, 'v');
// 	mapEmpty.insert(mapEmpty.begin(), 56, 'v');
// 	ft_mapEmpty.swap(ft_map);
// 	mapEmpty.swap(map);
// 	chk_result(ft_map, map, "map", title, "[Full vs Full][1/2]");
// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[Full vs Full][2/2]");

// 	ft::Map<char> ft_mapEmptyA;
// 	std::map<char> mapEmptyA;
// 	ft::Map<char> ft_mapEmptyB;
// 	std::map<char> mapEmptyB;
// 	ft_mapEmptyA.swap(ft_mapEmptyB);
// 	mapEmptyA.swap(mapEmptyB);
// 	chk_result(ft_mapEmptyA, mapEmptyA, "map", title, "[Empty vs Empty][1/2]");
// 	chk_result(ft_mapEmptyB, mapEmptyB, "map", title, "[Empty vs Empty][2/2]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_map_clear() {
// 	std::string title = "[CLEAR]";
// 	std::cout << title;

// 	ft::Map<char> ft_map(5, '!');
// 	std::map<char> map(5, '!');

// 	ft_map.clear();
// 	map.clear();
// 	chk_result(ft_map, map, "map", title, "[FULL Map]");

// 	ft_map.clear();
// 	map.clear();
// 	chk_result(ft_map, map, "map", title, "[EMPTY Map]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// ///*\*/*\NON-MEMBERS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_map_nonMembers() {
// 	std::string title = "----[NON-MEMBER OPERATORS]----";
// 	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
// 	title = "[OPERATOR==]";
// 	std::cout << title;

// 	ft::Map<int> ft_mapA;
// 	std::map<int> mapA;
// 	ft_mapA.push_back(0);
// 	ft_mapA.push_back(2145678);
// 	ft_mapA.push_back(-70);
// 	ft_mapA.push_back(42);
// 	mapA.push_back(0);
// 	mapA.push_back(2145678);
// 	mapA.push_back(-70);
// 	mapA.push_back(42);
// 	ft::Map<int> ft_mapB;
// 	std::map<int> mapB;
// 	ft_mapB.push_back(0);
// 	ft_mapB.push_back(2145678);
// 	ft_mapB.push_back(-70);
// 	ft_mapB.push_back(42);
// 	mapB.push_back(0);
// 	mapB.push_back(2145678);
// 	mapB.push_back(-70);
// 	mapB.push_back(42);

// 	bool ft_bool = (ft_mapA == ft_mapB);
// 	bool std_bool = (mapA == mapB);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_mapA, ft_mapB, "map", title, "[EQUAL]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	ft::Map<int> ft_mapC;
// 	std::map<int> mapC;
// 	ft_mapC.push_back(0);
// 	ft_mapC.push_back(666);
// 	ft_mapC.push_back(-70);
// 	ft_mapC.push_back(42);
// 	mapC.push_back(0);
// 	mapC.push_back(666);
// 	mapC.push_back(-70);
// 	mapC.push_back(42);

// 	ft_bool = (ft_mapA == ft_mapC);
// 	std_bool = (mapA == mapC);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_mapA, ft_mapC, "map", title, "[DIFF]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR!=]";
// 	std::cout << title;

// 	ft_bool = (ft_mapA != ft_mapB);
// 	std_bool = (mapA != mapB);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_mapA, ft_mapB, "map", title, "[EQUAL]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	ft_bool = (ft_mapA != ft_mapC);
// 	std_bool = (mapA != mapC);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_mapA, ft_mapC, "map", title, "[DIFF]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR<]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC < ft_mapA);
// 	std_bool = (mapC < mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA < ft_mapC);
// 	std_bool = (mapA < mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA < ft_mapB);
// 	std_bool = (mapA < mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR<=]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC <= ft_mapA);
// 	std_bool = (mapC <= mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA <= ft_mapC);
// 	std_bool = (mapA <= mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA <= ft_mapB);
// 	std_bool = (mapA <= mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR>]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC > ft_mapA);
// 	std_bool = (mapC > mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA > ft_mapC);
// 	std_bool = (mapA > mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA > ft_mapB);
// 	std_bool = (mapA > mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR>=]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC >= ft_mapA);
// 	std_bool = (mapC >= mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA >= ft_mapC);
// 	std_bool = (mapA >= mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA >= ft_mapB);
// 	std_bool = (mapA >= mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[SWAP (non-member)]";
// 	std::cout << title;

// 	swap(ft_mapA, ft_mapC);
// 	swap(mapA, mapC);
// 	chk_result(ft_mapA, mapA, "map", title, "[1/2]");
// 	chk_result(ft_mapC, mapC, "map", title, "[2/2]");

// 	ft::Map<int> ft_mapEmpty;
// 	std::map<int> mapEmpty;
// 	swap(ft_mapEmpty, ft_mapC);
// 	swap(mapEmpty, mapC);
// 	chk_result(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY vs FULL] [1/2]");
// 	chk_result(ft_mapC, mapC, "map", title, "[EMPTY vs FULL] [2/2]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };
