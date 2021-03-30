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

int test_map_constr() {

	std::string title = "[DEFAULT CONSTR]";
	std::cout << title;

	std::map<char, int> src;
	ft::Map<char, int> ft_src;

	chk_mapResult(ft_src, src, "map", title);
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[OPERATOR[] ASSIGNING]";
	std::cout << title;

	src['f']=30;
	src['a']=10;
 	src['c']=50;
	src['d']=70;
	src['a']=10;
	src['b']=42;
	src['y']=120354467;
	src['r']=68;
	src['e']=8;
	src['z']=4;

	ft_src['f']=30;
	ft_src['a']=10;
	ft_src['c']=50;
	ft_src['d']=70;
	ft_src['a']=10;
	ft_src['b']=42;
	ft_src['y']=120354467;
	ft_src['r']=68;
	ft_src['e']=8;
	ft_src['z']=4;

	chk_mapResult(ft_src, src, "map", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[RANGE CONSTR]";
	std::cout << title;

	ft::Map<char, int> ft_mapA(ft_src.begin(), ft_src.end());
	std::map<char, int> mapA(src.begin(), src.end());

	chk_mapResult(ft_mapA, mapA, "map", title, "from full list");

	ft::Map<char, int> ft_mapEmpty(ft_src.end(), ft_src.end());
	std::map<char, int> mapEmpty(src.end(), src.end());

	chk_mapResult(ft_mapEmpty, mapEmpty, "map", title, "from end to end aka empty list");
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[COPY CONSTR]";
	std::cout << title;

	ft::Map<char, int> ft_mapB(ft_mapA);
	std::map<char, int> mapB(mapA);
	chk_mapResult(ft_mapB, mapB, "map", title, "from full list");

	ft::Map<char, int> ft_mapEmptyBis(ft_mapEmpty.begin(), ft_mapEmpty.end());
	std::map<char, int> mapEmptyBis(mapEmpty.begin(), mapEmpty.end());

	chk_mapResult(ft_mapEmptyBis, mapEmptyBis, "map", title, "from empty list");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	title = "[OPERATOR=]";
	std::cout << title;

	ft::Map<char, int> ft_mapC = ft_mapA;
	std::map<char, int> mapC = mapA;
	chk_mapResult(ft_mapC, mapC, "map", title, "from full list");

	ft::Map<char, int> ft_mapEmptyTer = ft_mapEmpty;
	std::map<char, int> mapEmptyTer = mapEmpty;
	chk_mapResult(ft_mapEmptyTer, mapEmptyTer, "map", title, "from empty list");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// //*\*/*\*/ITERATORS/*\*/*\*//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

int test_map_iterate() {
	std::string title = "[BASIC ITERATING + DEREFERENCING]";
	std::cout << title;

	ft::Map<int, int> ft_map;
	std::map<int, int> map;

	ft_map[3] = 10;
	ft_map[12] = 42;
	ft_map[1] = 20;
	ft_map[17] = 26;

	map[3] = 10;
	map[12] = 42;
	map[1] = 20;
	map[17] = 26;

	

	int tmp;
	ft::Map<int, int>::iterator it = ft_map.begin();
	while (it != ft_map.end()) {
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = (*it).first;
		tmp = (*it).second;
		it++;
	}
	chk_mapResult(ft_map, map, "map", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[BASIC REVERSE ITERATING + DEREFERENCING]";
	std::cout << title;

	ft::Map<int, int>::reverse_iterator rit = ft_map.rbegin();
	while (rit != ft_map.rend()) {
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = (*rit).first;
		tmp = (*rit).second;
		rit++;
	}
	chk_mapResult(ft_map, map, "map", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
    return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/CAPACITY/*\*/*\*//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_map_empty() {
	std::string title = "[EMPTY]";
	std::cout << title;

	ft::Map<char, char> ft_map;
	std::map<char, char> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['y']=55;
	map['r']=68;
	map['e']=8;
	map['z']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['y']=55;
	ft_map['r']=68;
	ft_map['e']=8;
	ft_map['z']=4;

	bool ft_empty = ft_map.empty();
	bool std_empty = map.empty();

	if (ft_empty != std_empty) {
		std::cerr << "ft_map.empty() = [" << ft_empty << "] | map.empty() = [" << std_empty << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "[FULL]", "CONTENT");
	}

	ft_map.clear();
	map.clear();

	ft_empty = ft_map.empty();
	std_empty = map.empty();

	if (ft_empty != std_empty) {
		std::cerr << "ft_map.empty() = [" << ft_empty << "] | map.empty() = [" << std_empty << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "[EMPTIED BY CLEAR]", "CONTENT");
	}
	
	ft::Map<char, char> ft_mapEmpty;
	std::map<char, char> mapEmpty;
	ft_empty = ft_mapEmpty.empty();
	std_empty = mapEmpty.empty();
	if (ft_empty != std_empty) {
		std::cerr << "ft_map.empty() = [" << ft_empty << "] | map.empty() = [" << std_empty << "]" << std::endl;
		handle_mapError(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_map_maxSize() {
	std::string title = "[MAX_SIZE]";
	std::cout << title;

	ft::Map<int, int> ft_mapint;
	std::map<int, int> mapint;

	ft::Map<double, double> ft_mapdouble;
	std::map<double, double> mapdouble;

	ft::Map<std::string, std::string> ft_mapstring;
	std::map<std::string, std::string> mapstring;

	size_t ft_max = ft_mapint.max_size();
	size_t max = mapint.max_size();

	if (max != ft_max) {
		std::cerr << "int ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_mapError(ft_mapint, mapint, "map", title, "int map", "MAX_SIZE");
	}

	ft_max = ft_mapdouble.max_size();
	max = mapdouble.max_size();

	if (max != ft_max) {
		std::cerr << "double ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_mapError(ft_mapdouble, mapdouble, "map", title, "double map", "MAX_SIZE");
	}

	ft_max = ft_mapstring.max_size();
	max = mapstring.max_size();

	if (max != ft_max) {
		std::cerr << "string ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_mapError(ft_mapstring, mapstring, "map", title, "std::string map", "MAX_SIZE");
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// //*\*/ELEMENT ACCESS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

int test_map_oparray() {
	std::string title = "[OPERATOR[]]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;
	
	char a = 'a';
	for (size_t i = 0; i < ft_map.size(); i++) {
		if (ft_map[a] != map[a]) {
			std::cerr << "ft_map[" << a << "] = [" << ft_map[a] << "] | map[" << a << "] = [" << map[i] << std::endl;
			handle_mapError(ft_map, map, "map", title, "[COMPARE]", "");
		}
		a++;
	}

	a = 'z';
	if (ft_map[a] != map[a]) {
			std::cerr << "ft_map[" << a << "] = [" << ft_map[a] << "] | map[" << a << "] = [" << map[a] << std::endl;
			handle_mapError(ft_map, map, "map", title, "[COMPARE]", "new elem");
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/MODIFIERS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_map_insert() {
	//------------------------------------------------------------------------
	std::string title = "[INSERT(1)]";
	std::cout << title;

	ft::Map<char, char> ft_map;
	ft_map['a']='@';
	ft_map['b']='&';
	std::pair<ft::Map<char, char>::iterator, bool> ft_res;
	ft::Map<char, char>::iterator ft_it;
	bool ft_bool;
	ft_res = ft_map.insert(std::pair<char, char>('c', '!'));
	ft_it = ft_res.first;
	ft_bool = ft_res.second;

	std::map<char, char> map;
	map['a']='@';
	map['b']='&';
	std::pair<std::map<char, char>::iterator, bool> std_res;
	std::map<char, char>::iterator std_it;
	bool std_bool;
	std_res = map.insert(std::pair<char, char>('c', '!'));
	std_it = std_res.first;
	std_bool = std_res.second;

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second) || (ft_bool != std_bool)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] bool[" << ft_bool << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "] bool[" << ft_bool << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title);

	ft_res = ft_map.insert(std::pair<char, char>('r', 'R'));
	ft_it = ft_res.first;
	ft_bool = ft_res.second;
	std_res = map.insert(std::pair<char, char>('r', 'R'));
	std_it = std_res.first;
	std_bool = std_res.second;

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second) || (ft_bool != std_bool)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] bool[" << ft_bool << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "] bool[" << ft_bool << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title);

	ft_res = ft_map.insert(std::pair<char, char>('b', 'B'));
	ft_it = ft_res.first;
	ft_bool = ft_res.second;
	std_res = map.insert(std::pair<char, char>('b', 'B'));
	std_it = std_res.first;
	std_bool = std_res.second;

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second) || (ft_bool != std_bool)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] bool[" << ft_bool << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "] bool[" << ft_bool << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title);

	ft::Map<char, char> ft_mapEmpty;
	std::map<char, char> mapEmpty;

	ft_res = ft_mapEmpty.insert(std::pair<char, char>('b', 'B'));
	ft_it = ft_res.first;
	ft_bool = ft_res.second;
	std_res = mapEmpty.insert(std::pair<char, char>('b', 'B'));
	std_it = std_res.first;
	std_bool = std_res.second;

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second) || (ft_bool != std_bool)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] bool[" << ft_bool << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "] bool[" << ft_bool << "]" << std::endl;
		handle_mapError(ft_mapEmpty, mapEmpty, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_mapEmpty, mapEmpty, "map", title, "empty");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[INSERT(2)[HINT]]";
	std::cout << title;

	ft::Map<char, char> ft_mapI;
	ft_mapI['a']='@';
	ft_mapI['b']='&';
	ft_it = ft_mapI.insert(ft_mapI.begin(), std::pair<char, char>('c', '!'));

	std::map<char, char> mapI;
	mapI['a']='@';
	mapI['b']='&';
	std_it = mapI.insert(mapI.begin(), std::pair<char, char>('c', '!'));

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_mapI, mapI, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_mapI, mapI, "map", title);

	ft_it = ft_mapI.insert(ft_mapI.begin(), std::pair<char, char>('r', 'R'));
	std_it = mapI.insert(mapI.begin(), std::pair<char, char>('r', 'R'));

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_mapI, mapI, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_mapI, mapI, "map", title);

	ft_it = ft_mapI.insert(ft_mapI.begin(), std::pair<char, char>('b', 'B'));
	std_it = mapI.insert(mapI.begin(), std::pair<char, char>('b', 'B'));

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_mapI, mapI, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_mapI, mapI, "map", title);

	ft::Map<char, char> ft_mapEmptyI;
	std::map<char, char> mapEmptyI;

	ft_it = ft_mapEmptyI.insert(ft_mapEmptyI.begin(), std::pair<char, char>('b', 'B'));
	std_it = mapEmptyI.insert(mapEmptyI.begin(), std::pair<char, char>('b', 'B'));

	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second)) {
		std::cerr << "(*ft_it) after insert(1) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after insert(1) = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_mapEmptyI, mapEmptyI, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_mapEmptyI, mapEmptyI, "map", title, "empty");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[INSERT(3)[RANGE]]";
	std::cout << title;
	
	ft::Map<char, char> ft_src;
	ft_src['y']='&';
	ft_src['a']='@';
	ft_src['b']='&';
	ft_src['c']='f';

	std::map<char, char> src;
	src['y']='&';
	src['a']='@';
	src['b']='&';
	src['c']='f';

	ft_it = ft_src.begin();
	ft_it++;
	ft_it++;
	ft_map.insert(ft_it, ft_src.end());

	std_it = src.begin();
	std_it++;
	std_it++;
	map.insert(std_it, src.end());

	chk_mapResult(ft_map, map, "map", title);
	chk_mapResult(ft_src, src, "map", title);

	ft::Map<char, char> ft_mapEmptyC;
	ft::Map<char, char> ft_mapEmptyD;
	ft_mapEmptyC.insert(ft_mapEmptyD.begin(), ft_mapEmptyD.end());
	std::map<char, char> mapEmptyC;
	std::map<char, char> mapEmptyD;
	mapEmptyC.insert(mapEmptyD.begin(), mapEmptyD.end());
	chk_mapResult(ft_mapEmptyC, mapEmptyC, "map", title, "[EMPTY to EMPTY]");
	chk_mapResult(ft_mapEmptyD, mapEmptyD, "map", title, "[EMPTY to EMPTY]");

	ft_map.insert(ft_mapEmptyD.begin(), ft_mapEmptyD.end());
	map.insert(mapEmptyD.begin(), mapEmptyD.end());
	ft_it = ft_map.begin();
	std_it = map.begin();
	if (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second)) {
		std::cerr << "(*ft_it) after insert(3) = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after insert(3) = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[EMPTY to FULL]");
	chk_mapResult(ft_mapEmptyD, mapEmptyD, "map", title, "[EMPTY to FULL]");
	
	ft_mapEmptyD.insert(ft_map.begin(), ft_map.end());
	mapEmptyD.insert(map.begin(), map.end());
	chk_mapResult(ft_mapEmptyD, mapEmptyD, "map", title, "[FULL TO EMPTY]");
	chk_mapResult(ft_map, map, "map", title, "[FULL TO EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_map_erase() {
	std::string title = "[ERASE(1)][POSITION]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft::Map<char, int>::iterator ft_it = ft_map.begin();
	std::map<char, int>::iterator std_it = map.begin();

	ft_map.erase(ft_it);
	map.erase(std_it);
	chk_mapResult(ft_map, map, "map", title, "[begin]");

	ft_it = ft_map.begin();
	std_it = map.begin();

	ft_map.erase(ft_it);
	map.erase(std_it);
	chk_mapResult(ft_map, map, "map", title, "[begin]");

	// //INVALID POSITION = UNDEFINED BEHAVIOR
	// // ft_it = ft_map.end();
	// // it = map.end();
	// // ft_it = ft_map.erase(ft_it);
	// // it = map.erase(it);
	// // chk_mapResult(ft_map, map, "map", "ERASE(1) [end]");

	ft_it = ft_map.begin();
	std_it = map.begin();
	while (ft_it != ft_map.end()) {
		ft_map.erase(ft_it);
		ft_it = ft_map.begin();
	}
	while (std_it != map.end()) {
		map.erase(std_it);
		std_it = map.begin();
	}
	chk_mapResult(ft_map, map, "map", title, "[all]");

	//ERASE EMPTY BEGIN = UNDEFINED BEHAVIOUR
	//ft::Map<char> ft_mapEmpty;
	//std::map<char> mapEmpty;
	//ft_mapEmpty.erase(ft_mapEmpty.begin());
	//mapEmpty.erase(mapEmpty.begin());
	//chk_mapResult(ft_mapEmpty, mapEmpty, "map", "ERASE(1) [EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[ERASE(2)][KEY]";
	std::cout << title;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft_map.erase('a');
	map.erase('a');
	chk_mapResult(ft_map, map, "map", title, "[existing key]");

	ft_map.erase('f');
	map.erase('f');
	chk_mapResult(ft_map, map, "map", title, "[root key]");

	ft_map.erase('a');
	map.erase('a');
	chk_mapResult(ft_map, map, "map", title, "[already erased key]");

	ft_map.erase('Z');
	map.erase('Z');
	chk_mapResult(ft_map, map, "map", title, "[key that's never been there]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[ERASE(3)][RANGE]";
	std::cout << title;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft_map.erase(ft_map.begin(), ft_map.begin());
	map.erase(map.begin(), map.begin());
	chk_mapResult(ft_map, map, "map", title, "[begin]");

	ft_map.erase(ft_map.end(), ft_map.end());
	map.erase(map.end(), map.end());
	chk_mapResult(ft_map, map, "map", title, "[end]");

	ft_map.erase(ft_map.begin(), ft_map.end());
	map.erase(map.begin(), map.end());
	chk_mapResult(ft_map, map, "map", title, "[all]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_map_swap() {
	std::string title = "[SWAP]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft::Map<char, int> ft_mapEmpty;
	std::map<char, int> mapEmpty;

	ft_map.swap(ft_mapEmpty);
	map.swap(mapEmpty);


	chk_mapResult(ft_map, map, "map", title, "[Full vs Empty][1/2]");
	chk_mapResult(ft_mapEmpty, mapEmpty, "map", title, "[Full vs Empty][2/2]");
	
	ft_map.swap(ft_mapEmpty);
	map.swap(mapEmpty);
	chk_mapResult(ft_map, map, "map", title, "[Empty vs Full][1/2]");
	chk_mapResult(ft_mapEmpty, mapEmpty, "map", title, "[Empty vs Full][2/2]");

	ft_mapEmpty['U'] = 592;
	mapEmpty['U'] = 592;
	ft_mapEmpty['Y'] = 1337;
	mapEmpty['Y'] = 1337;
	ft_mapEmpty.swap(ft_map);
	mapEmpty.swap(map);
	chk_mapResult(ft_map, map, "map", title, "[Full vs Full][1/2]");
	chk_mapResult(ft_mapEmpty, mapEmpty, "map", title, "[Full vs Full][2/2]");

	ft::Map<char, int> ft_mapEmptyA;
	std::map<char, int> mapEmptyA;
	ft::Map<char, int> ft_mapEmptyB;
	std::map<char, int> mapEmptyB;
	chk_mapResult(ft_mapEmptyA, mapEmptyA, "map", title, "[Empty vs Empty][1/2]");
	chk_mapResult(ft_mapEmptyB, mapEmptyB, "map", title, "[Empty vs Empty][2/2]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_map_clear() {
	std::string title = "[CLEAR]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft_map.clear();
	map.clear();
	chk_mapResult(ft_map, map, "map", title, "[FULL Map]");

	ft_map.clear();
	map.clear();
	chk_mapResult(ft_map, map, "map", title, "[EMPTY Map]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/OPERATIONS/*\*/*//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_map_find() {
	std::string title = "[FIND]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;


	ft::Map<char, int>::iterator ft_it;
	std::map<char, int>::iterator std_it;

	ft_it = ft_map.find('d');
	std_it = map.find('d');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after find = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after find = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find present key]");

	ft_it = ft_map.find('f');
	std_it = map.find('f');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after find = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after find = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find root key]");

	ft_it = ft_map.find('X');
	std_it = map.find('X');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after find = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after find = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find non present key]");

	ft_map.clear();
	map.clear();
	ft_it = ft_map.find('f');
	std_it = map.find('f');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after find = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after find = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[EMPTY Map]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};


int test_map_count() {
	std::string title = "[COUNT]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['a']=10;
 	map['c']=50;
	map['d']=70;
	map['a']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['a']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['a']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;


	size_t ft_sz;
	size_t std_sz;

	ft_sz = ft_map.count('d');
	std_sz = map.count('d');
	if (ft_sz != std_sz) {
		std::cerr << "ft_sz after count = [" << ft_sz << "] | std_sz after count= [" << std_sz << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "RETURN");
	}
	chk_mapResult(ft_map, map, "map", title, "[find present key]");

	ft_sz = ft_map.count('f');
	std_sz = map.count('f');
	if (ft_sz != std_sz) {
		std::cerr << "ft_sz after count = [" << ft_sz << "] | std_sz after count= [" << std_sz << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "RETURN");
	}
	chk_mapResult(ft_map, map, "map", title, "[find root key]");

	ft_sz = ft_map.count('X');
	std_sz = map.count('X');
	if (ft_sz != std_sz) {
		std::cerr << "ft_sz after count = [" << ft_sz << "] | std_sz after count= [" << std_sz << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "RETURN");
	}
	chk_mapResult(ft_map, map, "map", title, "[find non present key]");

	ft_map.clear();
	map.clear();
	ft_sz = ft_map.count('f');
	std_sz = map.count('f');
	if (ft_sz != std_sz) {
		std::cerr << "ft_sz after count = [" << ft_sz << "] | std_sz after count= [" << std_sz << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "RETURN");
	}
	chk_mapResult(ft_map, map, "map", title, "[EMPTY Map]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}


int test_map_lowerBound() {
	std::string title = "[LOWER BOUND]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['q']=10;
 	map['c']=50;
	map['d']=70;
	map['q']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['q']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['q']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft::Map<char, int>::iterator ft_it;
	std::map<char, int>::iterator std_it;

	ft_it = ft_map.lower_bound('d');
	std_it = map.lower_bound('d');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after lower bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after lower bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find present key]");

	ft_it = ft_map.lower_bound('f');
	std_it = map.lower_bound('f');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after lower bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after lower bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find root key]");

	ft_it = ft_map.lower_bound('b');
	std_it = map.lower_bound('b');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after lower bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after lower bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find from lowest]");

	ft_it = ft_map.lower_bound('a');
	std_it = map.lower_bound('a');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after lower bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after lower bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find from absent lowest]");

	ft_it = ft_map.lower_bound('X');
	std_it = map.lower_bound('X');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after lower bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after lower bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find non present key]");

	ft_map.clear();
	map.clear();
	ft_it = ft_map.lower_bound('f');
	std_it = map.lower_bound('f');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after lower bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after lower bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[EMPTY Map]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	return 0;
}



int test_map_upperBound() {
	std::string title = "[UPPER BOUND]";
	std::cout << title;

	ft::Map<char, int> ft_map;
	std::map<char, int> map;

	map['f']=30;
	map['q']=10;
 	map['c']=50;
	map['d']=70;
	map['q']=10;
	map['b']=42;
	map['i']=55;
	map['g']=68;
	map['e']=8;
	map['h']=4;

	ft_map['f']=30;
	ft_map['q']=10;
	ft_map['c']=50;
	ft_map['d']=70;
	ft_map['q']=10;
	ft_map['b']=42;
	ft_map['i']=55;
	ft_map['g']=68;
	ft_map['e']=8;
	ft_map['h']=4;

	ft::Map<char, int>::iterator ft_it;
	std::map<char, int>::iterator std_it;

	ft_it = ft_map.upper_bound('d');
	std_it = map.upper_bound('d');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after upper bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after upper bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find present key]");

	ft_it = ft_map.upper_bound('f');
	std_it = map.upper_bound('f');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after upper bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after upper bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find root key]");

	ft_it = ft_map.upper_bound('b');
	std_it = map.upper_bound('b');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after upper bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after upper bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find from lowest]");

	ft_it = ft_map.upper_bound('a');
	std_it = map.upper_bound('a');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after upper bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after upper bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find from absent lowest]");

	ft_it = ft_map.upper_bound('X');
	std_it = map.upper_bound('X');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after upper bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after upper bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[find non present key]");

	ft_map.clear();
	map.clear();
	ft_it = ft_map.upper_bound('f');
	std_it = map.upper_bound('f');
	if (ft_it != ft_map.end() && std_it != map.end() && (((*ft_it).first != (*std_it).first) || ((*ft_it).second != (*std_it).second))) {
		std::cerr << "(*ft_it) after upper bound = [" << (*ft_it).first << "]["<< (*ft_it).second << "] | (*std_it).first) after upper bound = [" << (*std_it).first << "][" << (*std_it).second << "]" << std::endl;
		handle_mapError(ft_map, map, "map", title, "", "CONTENT");
	}
	chk_mapResult(ft_map, map, "map", title, "[EMPTY Map]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	return 0;
}

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
// 		handle_mapError(ft_mapA, ft_mapB, "map", title, "[EQUAL]", "CONTENT");
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
// 		handle_mapError(ft_mapA, ft_mapC, "map", title, "[DIFF]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR!=]";
// 	std::cout << title;

// 	ft_bool = (ft_mapA != ft_mapB);
// 	std_bool = (mapA != mapB);
// 	if (ft_bool != std_bool) {
// 		handle_mapError(ft_mapA, ft_mapB, "map", title, "[EQUAL]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	ft_bool = (ft_mapA != ft_mapC);
// 	std_bool = (mapA != mapC);
// 	if (ft_bool != std_bool) {
// 		handle_mapError(ft_mapA, ft_mapC, "map", title, "[DIFF]", "CONTENT");
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
// 		handle_mapError(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA < ft_mapC);
// 	std_bool = (mapA < mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA < ft_mapB);
// 	std_bool = (mapA < mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR<=]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC <= ft_mapA);
// 	std_bool = (mapC <= mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA <= ft_mapC);
// 	std_bool = (mapA <= mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA <= ft_mapB);
// 	std_bool = (mapA <= mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR>]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC > ft_mapA);
// 	std_bool = (mapC > mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA > ft_mapC);
// 	std_bool = (mapA > mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA > ft_mapB);
// 	std_bool = (mapA > mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR>=]";
// 	std::cout << title;

// 	ft_bool = (ft_mapC >= ft_mapA);
// 	std_bool = (mapC >= mapA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapC, ft_mapA, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA >= ft_mapC);
// 	std_bool = (mapA >= mapC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapC, "map", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_mapA >= ft_mapB);
// 	std_bool = (mapA >= mapB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_mapError(ft_mapA, ft_mapB, "map", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[SWAP (non-member)]";
// 	std::cout << title;

// 	swap(ft_mapA, ft_mapC);
// 	swap(mapA, mapC);
// 	chk_mapResult(ft_mapA, mapA, "map", title, "[1/2]");
// 	chk_mapResult(ft_mapC, mapC, "map", title, "[2/2]");

// 	ft::Map<int> ft_mapEmpty;
// 	std::map<int> mapEmpty;
// 	swap(ft_mapEmpty, ft_mapC);
// 	swap(mapEmpty, mapC);
// 	chk_mapResult(ft_mapEmpty, mapEmpty, "map", title, "[EMPTY vs FULL] [1/2]");
// 	chk_mapResult(ft_mapC, mapC, "map", title, "[EMPTY vs FULL] [2/2]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };
