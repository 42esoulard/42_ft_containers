/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/18 12:15:04 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <iomanip>
#include <string>

#include <vector>

class customException;

//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/*\CONSTRUCTORS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_vector_fillConstr() {
	std::string title = "[FILL CONSTRUCTOR]";
	std::cout << title;

	ft::Vector<char> ft_vector(5, 'a');
	std::vector<char> vector(5, 'a');

	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_vectorEmpty(0, 'a');
	std::vector<char> vectorEmpty(0, 'a');

	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "0");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_rangeConstr() {
	std::string title = "[RANGE CONSTRUCTOR]";
	std::cout << title;

	std::vector<char> src(10, '!');
	src.push_back('@');
	ft::Vector<char> ft_vector(src.begin(), src.end());
	std::vector<char> vector(src.begin(), src.end());

	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_vectorEmpty(src.end(), src.end());
	std::vector<char> vectorEmpty(src.end(), src.end());

	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_copyConstr() {
	std::string title = "[COPY CONSTR]";
	std::cout << title;

	ft::Vector<char> ft_src(10, '!');
	ft_src.push_back('@');

	std::vector<char> src(10, '!');
	src.push_back('@');

	ft::Vector<char> ft_vector(ft_src);
	std::vector<char> vector(src);

	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_srcB(0, '!');
	std::vector<char> srcB(0, '!');
	ft::Vector<char> ft_vectorEmpty(ft_srcB);
	std::vector<char> vectorEmpty(srcB);

	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

	//INVALID SRC = UNDEFINED BEHAVIOR
	// ft::Vector<char> *ft_nullSrc = nullptr;
	// ft::Vector<char> ft_vectorNull(*ft_nullSrc);
	// ft::Vector<char> *nullSrc = nullptr;
	// ft::Vector<char> vectorNull(*nullSrc)
	//	chk_result(ft_vectorNull, vectorNull, "vector", "COPY CONSTRUCTOR [NULL SRC]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_opEqual() {
	std::string title = "[OPERATOR=]";
	std::cout << title;

	ft::Vector<char> ft_src(10, '!');
	ft_src.push_back('@');

	std::vector<char> src(10, '!');
	src.push_back('@');

	ft::Vector<char> ft_vector = ft_src;
	std::vector<char> vector = src;

	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_srcB(0, '!');
	std::vector<char> srcB(0, '!');
	ft::Vector<char> ft_vectorEmpty = ft_srcB;
	std::vector<char> vectorEmpty = srcB;

	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

	ft_vector = ft_srcB;
	vector = srcB;

	chk_result(ft_vector, vector, "vector", title, "[FULL = EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};


//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/*\*/ITERATORS/*\*/*\*//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_vector_pushBack_iterate() {
	std::string title = "[BASIC INSTANCE + PUSH_BACK]";
	std::cout << title;

	ft::Vector<int> ft_vector;
	std::vector<int> vector;

	ft_vector.push_back(10);
	ft_vector.push_back(12);
	ft_vector.push_back(18);

	vector.push_back(10);
	vector.push_back(12);
	vector.push_back(18);

	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_vectorEmpty;
	ft_vector.push_back('&');
	std::vector<char> vectorEmpty;
	vector.push_back('&');

	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[BASIC ITERATING + DEREFERENCING]";
	std::cout << title;

	int tmp;
	ft::Vector<int>::iterator it = ft_vector.begin();
	while (it != ft_vector.end()) {
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = *it;
		it++;
	}
	chk_result(ft_vector, vector, "vector", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[BASIC REVERSE ITERATING + DEREFERENCING]";
	std::cout << title;

	ft::Vector<int>::reverse_iterator rit = ft_vector.rbegin();
	while (rit != ft_vector.rend()) {
		//std::cout << *it << std::endl; //commented to keep test output clean
		tmp = *rit;
		rit++;
	}
	chk_result(ft_vector, vector, "vector", title);

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
    return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/CAPACITY/*\*/*\*//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_vector_maxSize() {
	std::string title = "[MAX_SIZE]";
	std::cout << title;

	ft::Vector<int> ft_vectorint;
	std::vector<int> vectorint;

	ft::Vector<char> ft_vectorchar;
	std::vector<char> vectorchar;

	ft::Vector<double> ft_vectordouble;
	std::vector<double> vectordouble;

	ft::Vector<std::string> ft_vectorstring;
	std::vector<std::string> vectorstring;

	size_t ft_max = ft_vectorint.max_size();
	size_t max = vectorint.max_size();

	if (max != ft_max) {
		std::cerr << "int ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_vectorint, vectorint, "vector", title, "int vector", "MAX_SIZE");
	}

	ft_max = ft_vectorchar.max_size();
	max = vectorchar.max_size();

	if (max != ft_max) {
		std::cerr << "char ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_vectorchar, vectorchar, "vector", title, "char vector", "MAX_SIZE");
	}

	ft_max = ft_vectordouble.max_size();
	max = vectordouble.max_size();

	if (max != ft_max) {
		std::cerr << "double ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_vectordouble, vectordouble, "vector", title, "double vector", "MAX_SIZE");
	}

	ft_max = ft_vectorstring.max_size();
	max = vectorstring.max_size();

	if (max != ft_max) {
		std::cerr << "string ft_max = [" << ft_max << "] | std_max = [" << max << "]" << std::endl;
		handle_error(ft_vectorstring, vectorstring, "vector", title, "std::string vector", "MAX_SIZE");
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}

int test_vector_capacity() {
	std::string title = "[CAPACITY]";
	std::cout << title;

	ft::Vector<char> ft_vector(5, '!');
	std::vector<char> vector(5, '!');
	ft::Vector<char>::iterator ft_it = ft_vector.begin();
	std::vector<char>::iterator it = vector.begin();
	ft_it++;
	it++;

	ft_vector.push_back('a');
	ft_vector.insert(ft_vector.begin(), 'a');
	ft_vector.insert(ft_vector.begin(), 'b');
	vector.push_back('a');
	vector.insert(vector.begin(), 'a');
	vector.insert(vector.begin(), 'b');
	size_t ft_capacity = ft_vector.capacity();
	size_t std_capacity = vector.capacity();
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[FULL]", "CONTENT");
	}
	
	ft::Vector<char> ft_vectorEmpty;
	std::vector<char> vectorEmpty;
	ft_capacity = ft_vectorEmpty.empty();
	std_capacity = vectorEmpty.empty();
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[EMPTY]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_resize() {
	std::string title = "[RESIZE]";
	std::cout << title;

	ft::Vector<char> ft_vector(5, '!');
	std::vector<char> vector(5, '!');

	ft_vector.resize(2);
	vector.resize(2);
	chk_result(ft_vector, vector, "vector", title, "[5 TO 2]");

	ft_vector.resize(0);
	vector.resize(0);
	chk_result(ft_vector, vector, "vector", title, "[2 TO 0]");

	ft_vector.resize(0);
	vector.resize(0);
	chk_result(ft_vector, vector, "vector", title, "[0 TO 0]");

	ft_vector.resize(5);
	vector.resize(5);
	chk_result(ft_vector, vector, "vector", title, "[0 TO 5]");
	
	ft_vector.resize(100);
	vector.resize(100);
	chk_result(ft_vector, vector, "vector", title, "[5 TO 100]");

	ft_vector.resize(100);
	vector.resize(100);
	chk_result(ft_vector, vector, "vector", title, "[100 TO 100]");

	//UNDEFINED BEHAVIOUR
	//ft_vector.resize(-50);
	//vector.resize(-50);
	//chk_result(ft_vector, vector, "vector", "RESIZE [100 TO -50]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_empty() {
	std::string title = "[EMPTY]";
	std::cout << title;

	ft::Vector<char> ft_vector(5, '!');
	std::vector<char> vector(5, '!');
	ft::Vector<char>::iterator ft_it = ft_vector.begin();
	std::vector<char>::iterator it = vector.begin();
	ft_it++;
	it++;

	ft_vector.push_back('a');
	ft_vector.insert(ft_vector.begin(), 'a');
	ft_vector.insert(ft_vector.begin(), 'b');
	vector.push_back('a');
	vector.insert(vector.begin(), 'a');
	vector.insert(vector.begin(), 'b');
	bool ft_empty = ft_vector.empty();
	bool std_empty = vector.empty();
	if (ft_empty != std_empty) {
		std::cerr << "ft_vector.empty() = [" << ft_empty << "] | vector.empty() = [" << std_empty << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[FULL]", "CONTENT");
	}
	
	ft::Vector<char> ft_vectorEmpty;
	std::vector<char> vectorEmpty;
	ft_empty = ft_vectorEmpty.empty();
	std_empty = vectorEmpty.empty();
	if (ft_empty != std_empty) {
		std::cerr << "ft_vector.empty() = [" << ft_empty << "] | vector.empty() = [" << std_empty << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[EMPTY]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// //*\*/ELEMENT ACCESS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_vector_front_back() {
// 	std::string title = "[FRONT/BACK]";
// 	std::cout << title;

// 	ft::Vector<int> ft_vector;
// 	std::vector<int> vector;

// 	ft_vector.push_back(10);
// 	ft_vector.push_back(12);
// 	ft_vector.push_back(18);

// 	vector.push_back(10);
// 	vector.push_back(12);
// 	vector.push_back(18);

// 	if (ft_vector.front() != vector.front() || ft_vector.back() != vector.back()) {
// 		std::cerr << "ft_vector.front() = [" << ft_vector.front() << "] | vector.front() = [" << vector.front() << "]" << std::endl;
// 		std::cerr << "ft_vector.back() = [" << ft_vector.back() << "] | vector.back() = [" << vector.back() << "]" << std::endl;
// 		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
// 	}

// 	ft::Vector<int> ft_vectorEmpty;
// 	std::vector<int> vectorEmpty;

// 	if (ft_vectorEmpty.front() != vectorEmpty.front() || ft_vectorEmpty.back() != vectorEmpty.back()) {
// 		std::cerr << "ft_vectorEmpty.front() = [" << ft_vectorEmpty.front() << "] | vectorEmpty.front() = [" << vectorEmpty.front() << "]" << std::endl;
// 		std::cerr << "ft_vectorEmpty.back() = [" << ft_vectorEmpty.back() << "] | vectorEmpty.back() = [" << vectorEmpty.back() << "]" << std::endl;
// 		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "CONTENT");
// 	}
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

// 	title = "[FRONT/BACK CONST OVERLOAD]";
// 	std::cout << title;

// 	ft::Vector<int> const ft_constVector;
// 	std::vector<int> const constVector;

// 	if (ft_constVector.front() != constVector.front() || ft_constVector.back() != constVector.back()) {
// 		std::cerr << "ft_constVector.front() = [" << ft_constVector.front() << "] | constVector.front() = [" << constVector.front() << "]" << std::endl;
// 		std::cerr << "ft_constVector.back() = [" << ft_constVector.back() << "] | constVector.back() = [" << constVector.back() << "]" << std::endl;
// 		handle_error(ft_constVector, constVector, "vector", title, "[CONST]", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// ///*\*/*\*/MODIFIERS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_vector_assign() {
// 	std::string title = "[ASSIGN(1)]";
// 	std::cout << title;

// 	ft::Vector<char> ft_src(8, 'k');
// 	std::vector<char> src(8, 'k');
// 	ft::Vector<char> ft_vector;
// 	std::vector<char> vector;

// 	ft_vector.assign(ft_src.begin(), ft_src.end());
// 	vector.assign(src.begin(), src.end());
// 	chk_result(ft_vector, vector, "vector", title, "[FULL to EMPTY][1/2]");
// 	chk_result(ft_src, src, "vector", title, "[FULL to EMPTY][2/2]");

// 	ft_src.assign(ft_vector.begin(), ft_vector.end());
// 	src.assign(vector.begin(), vector.end());
// 	chk_result(ft_vector, vector, "vector", title, "[FULL to FULL][1/2]");
// 	chk_result(ft_src, src, "vector", title, "[FULL to EMPTY][2/2]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

// 	//------------------------------------------------------------------------
// 	title = "[ASSIGN(2)]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vectorA;
// 	std::vector<char> vectorA;

// 	ft_vectorA.assign(12, 'W');
// 	vectorA.assign(12, 'W');
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[to EMPTY]");
	
// 	ft_vectorA.assign(4, '8');
// 	vectorA.assign(4, '8');
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[to FULL]");

// 	ft_vectorA.assign(24, 'U');
// 	vectorA.assign(24, 'U');
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[to FULL]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// }

// int test_vector_pushFront() {
// 	std::string title = "[PUSH_FRONT]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_front('&');

// 	std::vector<char> vector(10, '!');
// 	vector.push_back('@');
// 	vector.push_front('&');

// 	chk_result(ft_vector, vector, "vector", title);

// 	ft::Vector<char> ft_vectorEmpty;
// 	ft_vector.push_front('&');
// 	std::vector<char> vectorEmpty;
// 	vector.push_front('&');

// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_popFront() {
// 	std::string title = "[POP_FRONT]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_front('&');
// 	ft_vector.push_front('z');

// 	std::vector<char> vector(10, '!');
// 	vector.push_back('@');
// 	vector.push_front('&');
// 	vector.push_front('z');

// 	ft_vector.pop_front();
// 	vector.pop_front();
// 	chk_result(ft_vector, vector, "vector", title);

// 	ft::Vector<char> ft_vectorEmpty;
// 	ft_vector.pop_front();
// 	std::vector<char> vectorEmpty;
// 	vector.pop_front();

// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_popBack() {
// 	std::string title = "[POP_BACK]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_back('&');
// 	ft_vector.push_front('z');

// 	std::vector<char> vector(10, '!');
// 	vector.push_back('@');
// 	vector.push_back('&');
// 	vector.push_front('z');

// 	ft_vector.pop_back();
// 	vector.pop_back();
// 	chk_result(ft_vector, vector, "vector", title);

// 	ft::Vector<char> ft_vectorEmpty;
// 	ft_vector.pop_back();
// 	std::vector<char> vectorEmpty;
// 	vector.pop_back();

// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_insert() {
// 	//------------------------------------------------------------------------
// 	std::string title = "[INSERT(1)]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_back('&');
// 	ft_vector.push_front('z');
// 	ft::Vector<char>::iterator ft_it = ft_vector.begin();
// 	ft_it = ft_vector.insert(ft_it, 'a');
// 	ft_it = ft_vector.insert(ft_it, 'b');
// 	ft_it = ft_vector.insert(ft_it, 'c');

// 	std::vector<char> vector(10, '!');
// 	vector.push_back('@');
// 	vector.push_back('&');
// 	vector.push_front('z');
// 	std::vector<char>::iterator it = vector.begin();
// 	it = vector.insert(it, 'a');
// 	it = vector.insert(it, 'b');
// 	it = vector.insert(it, 'c');

// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
// 	}
// 	chk_result(ft_vector, vector, "vector", title);
	

// 	ft::Vector<char> ft_vectorEmpty;
// 	ft_it = ft_vectorEmpty.begin();
// 	ft_it = ft_vectorEmpty.insert(ft_it, 'a');
// 	std::vector<char> vectorEmpty;
// 	it = vectorEmpty.begin();
// 	it = vectorEmpty.insert(it, 'a');

// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "CONTENT");
// 	}
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[INSERT(2)[FILL]]";
// 	std::cout << title;

// 	size_t size = 3;
// 	ft_it = ft_vector.begin();
// 	ft_it++;
// 	ft_vector.insert(ft_it, size, 6);

// 	it = vector.begin();
// 	it++;
// 	vector.insert(it, size, 6);
	
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(2) = [" << *ft_it << "] | *it after insert(2) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "", "CONTENT");
// 	}
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title);
	
// 	ft::Vector<char> ft_vectorEmptyB;
// 	ft_it = ft_vectorEmptyB.begin();
// 	ft_vectorEmptyB.insert(ft_it, size, '6');
// 	std::vector<char> vectorEmptyB;
// 	it = vectorEmptyB.begin();
// 	vectorEmptyB.insert(it, size, '6');

// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY to FULL]");

// 	size = 0;
// 	ft::Vector<char> ft_vectorEmptyC;
// 	ft_it = ft_vectorEmptyC.begin();
// 	ft_vectorEmptyC.insert(ft_it, size, '6');
// 	std::vector<char> vectorEmptyC;
// 	it = vectorEmptyC.begin();
// 	vectorEmptyC.insert(it, size, '6');

// 	chk_result(ft_vectorEmptyC, vectorEmptyC, "vector", title, "[EMPTY to EMPTY]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[INSERT(3)[RANGE]]";
// 	std::cout << title;

// 	ft::Vector<char> ft_src(10, '!');
// 	ft_src.push_back('@');
// 	ft_src.push_front('&');

// 	ft_it = ft_vector.begin();
// 	ft_it++;
// 	ft_vector.insert(ft_it, ft_src.begin(), ft_src.end());

// 	std::vector<char> src(10, '!');
// 	src.push_back('@');
// 	src.push_front('&');

// 	it = vector.begin();
// 	it++;
// 	vector.insert(it, src.begin(), src.end());

// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after insert(3) = [" << *ft_it << "] | *it after insert(3) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
// 	}
// 	chk_result(ft_vector, vector, "vector", title);

// 	ft::Vector<char> ft_vectorEmptyD;
// 	ft_it = ft_vectorEmptyC.begin();
// 	ft_vectorEmptyC.insert(ft_it, ft_vectorEmptyD.begin(), ft_vectorEmptyD.end());
// 	std::vector<char> vectorEmptyD;
// 	it = vectorEmptyC.begin();
// 	vectorEmptyC.insert(it, vectorEmptyD.begin(), vectorEmptyD.end());
// 	chk_result(ft_vectorEmptyC, vectorEmptyC, "vector", title, "[EMPTY to EMPTY]");
	
// 	ft_it = ft_vector.begin();
// 	ft_vector.insert(ft_it, ft_vectorEmptyD.begin(), ft_vectorEmptyD.end());
// 	it = vector.begin();
// 	vector.insert(it, vectorEmptyD.begin(), vectorEmptyD.end());
// 	chk_result(ft_vector, vector, "vector", title, "[EMPTY to FULL]");
	
// 	ft_it = ft_vectorEmptyD.begin();
// 	ft_vectorEmptyD.insert(ft_it, ft_vector.begin(), ft_vector.end());
// 	it = vectorEmptyD.begin();
// 	vectorEmptyD.insert(it, vector.begin(), vector.end());
// 	chk_result(ft_vectorEmptyD, vectorEmptyD, "vector", title, "[FULL TO EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_erase() {
// 	std::string title = "[ERASE(1)]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_back('&');
// 	ft_vector.push_front('z');
	
// 	std::vector<char> vector(10, '!');
// 	vector.push_back('@');
// 	vector.push_back('&');
// 	vector.push_front('z');

// 	ft::Vector<char>::iterator ft_it = ft_vector.begin();
// 	std::vector<char>::iterator it = vector.begin();

// 	ft_it = ft_vector.erase(ft_it);
// 	it = vector.erase(it);
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vector, vector, "vector", title, "[begin]", "CONTENT");
// 	}
// 	chk_result(ft_vector, vector, "vector", title, "[begin]");

// 	ft_it = ft_vector.erase(ft_it);
// 	it = vector.erase(it);
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vector, vector, "vector", title, "[begin]", "CONTENT");
// 	}
// 	chk_result(ft_vector, vector, "vector", title, "[begin]");

// 	//INVALID POSITION = UNDEFINED BEHAVIOR
// 	// ft_it = ft_vector.end();
// 	// it = vector.end();
// 	// ft_it = ft_vector.erase(ft_it);
// 	// it = vector.erase(it);
// 	// chk_result(ft_vector, vector, "vector", "ERASE(1) [end]");

// 	while (ft_it != ft_vector.end())
// 		ft_it = ft_vector.erase(ft_it);
// 	while (it != vector.end())
// 		it = vector.erase(it);
// 	chk_result(ft_vector, vector, "vector", title, "[all]");

// 	//ERASE EMPTY BEGIN = UNDEFINED BEHAVIOUR
// 	//ft::Vector<char> ft_vectorEmpty;
// 	//std::vector<char> vectorEmpty;
// 	//ft_vectorEmpty.erase(ft_vectorEmpty.begin());
// 	//vectorEmpty.erase(vectorEmpty.begin());
// 	//chk_result(ft_vectorEmpty, vectorEmpty, "vector", "ERASE(1) [EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[ERASE(2)[RANGE]]";
// 	std::cout << title;

// 	ft_vector.erase(ft_vector.begin(), ft_vector.end());
// 	vector.erase(vector.begin(), vector.end());
// 	chk_result(ft_vector, vector, "vector", title, "[EMPTY]");
	
// 	ft_vector.insert(ft_vector.begin(), 10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_back('&');
// 	ft_vector.push_front('z');
// 	ft_it = ft_vector.begin();
// 	ft_it++;
// 	ft_it++;

// 	vector.insert(vector.begin(), 10, '!');
// 	vector.push_back('@');
// 	vector.push_back('&');
// 	vector.push_front('z');
// 	it = vector.begin();
// 	it++;
// 	it++;

// 	ft::Vector<char>::iterator ft_last = ft_it;
// 	std::vector<char>::iterator last = it;
// 	ft_last++;
// 	last++;
// 	ft_it = ft_vector.erase(ft_it, ft_last);
// 	it = vector.erase(it, last);
// 	if (*it != *ft_it) {
// 		std::cerr << "*ft_it after erase(2) = [" << *ft_it << "] | *it after erase(2) = [" << *it << "]" << std::endl;
// 		handle_error(ft_vector, vector, "vector", title, "[PARTIAL]", "CONTENT");
// 	}
// 	chk_result(ft_vector, vector, "vector", title, "[PARTIAL]");
	
// 	ft_it = ft_vector.erase(ft_vector.begin(), ft_vector.end());
// 	it = vector.erase(vector.begin(), vector.end());
// 	chk_result(ft_vector, vector, "vector", title, "[TOTAL]");
// 	//not comparing return pointers because they point after end() in this case

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_swap() {
// 	std::string title = "[SWAP]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(10, '!');
// 	ft_vector.push_back('@');
// 	ft_vector.push_back('&');
// 	ft_vector.push_front('z');
	
// 	std::vector<char> vector(10, '!');
// 	vector.push_back('@');
// 	vector.push_back('&');
// 	vector.push_front('z');

// 	ft::Vector<char> ft_vectorEmpty;
// 	std::vector<char> vectorEmpty;
// 	ft_vectorEmpty.swap(ft_vector);
// 	vectorEmpty.swap(vector);

// 	chk_result(ft_vector, vector, "vector", title, "[Full vs Empty][1/2]");
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[Full vs Empty][2/2]");
	
// 	ft_vectorEmpty.swap(ft_vector);
// 	vectorEmpty.swap(vector);
// 	chk_result(ft_vector, vector, "vector", title, "[Empty vs Full][1/2]");
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[Empty vs Full][2/2]");

// 	ft_vectorEmpty.insert(ft_vectorEmpty.begin(), 56, 'v');
// 	vectorEmpty.insert(vectorEmpty.begin(), 56, 'v');
// 	ft_vectorEmpty.swap(ft_vector);
// 	vectorEmpty.swap(vector);
// 	chk_result(ft_vector, vector, "vector", title, "[Full vs Full][1/2]");
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[Full vs Full][2/2]");

// 	ft::Vector<char> ft_vectorEmptyA;
// 	std::vector<char> vectorEmptyA;
// 	ft::Vector<char> ft_vectorEmptyB;
// 	std::vector<char> vectorEmptyB;
// 	ft_vectorEmptyA.swap(ft_vectorEmptyB);
// 	vectorEmptyA.swap(vectorEmptyB);
// 	chk_result(ft_vectorEmptyA, vectorEmptyA, "vector", title, "[Empty vs Empty][1/2]");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[Empty vs Empty][2/2]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_clear() {
// 	std::string title = "[CLEAR]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(5, '!');
// 	std::vector<char> vector(5, '!');

// 	ft_vector.clear();
// 	vector.clear();
// 	chk_result(ft_vector, vector, "vector", title, "[FULL Vector]");

// 	ft_vector.clear();
// 	vector.clear();
// 	chk_result(ft_vector, vector, "vector", title, "[EMPTY Vector]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// //*\*/*\/*\*/*\/*\*/*\/*\*///
// ///*\*/*\*OPERATIONS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_vector_splice() {
// 	std::string title = "[SPLICE(1)]";
// 	std::cout << title;

// 	size_t size = 6;
// 	ft::Vector<int> ft_vectorA(size, 1);
// 	ft_vectorA.push_back(3);
// 	ft_vectorA.push_back(6);
// 	ft::Vector<int> ft_vectorB(size, 2);
// 	ft_vectorB.push_back(4);
// 	ft_vectorB.push_back(5);
// 	ft_vectorB.push_back(8);
// 	std::vector<int> vectorA(size, 1);
// 	vectorA.push_back(3);
// 	vectorA.push_back(6);
// 	std::vector<int> vectorB(size, 2);
// 	vectorB.push_back(4);
// 	vectorB.push_back(5);
// 	vectorB.push_back(8);

// 	ft_vectorA.splice(ft_vectorA.begin(), ft_vectorB);
// 	vectorA.splice(vectorA.begin(), vectorB);
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[FULL ORDERED vs FULL ORDERED] 1/2");
// 	chk_result(ft_vectorB, vectorB, "vector", title, "[FULL ORDERED vs FULL ORDERED] 2/2");
	
// 	ft::Vector<int> ft_vectorEmptyA;
// 	std::vector<int> vectorEmptyA;
// 	ft::Vector<int> ft_vectorEmptyB;
// 	std::vector<int> vectorEmptyB;
// 	ft_vectorEmptyA.splice(ft_vectorEmptyA.begin(), ft_vectorEmptyB);
// 	vectorEmptyA.splice(vectorEmptyA.begin(), vectorEmptyB);
// 	chk_result(ft_vectorEmptyA, vectorEmptyA, "vector", title, "[EMPTY vs EMPTY] 1/2");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY vs EMPTY] 2/2");

// 	ft_vectorA.splice(ft_vectorA.begin(), ft_vectorEmptyB);
// 	vectorA.splice(vectorA.begin(), vectorEmptyB);
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[FULL vs EMPTY] 1/2");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[FULL vs EMPTY] 2/2");

// 	ft_vectorEmptyB.splice(ft_vectorEmptyB.begin(), ft_vectorA);
// 	vectorEmptyB.splice(vectorEmptyB.begin(), vectorA);
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY vs FULL] 1/2");
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[EMPTY vs FULL] 2/2");
 
// 	ft::Vector<int> ft_vectorC(size, 2);
// 	ft_vectorC.push_back(4);
// 	ft_vectorC.push_back(5);
// 	ft_vectorC.push_back(8);
// 	ft::Vector<int> ft_vectorD(size, 2);
// 	ft_vectorD.push_back(9);
// 	ft_vectorD.push_back(1);
// 	ft_vectorD.push_back(1);
// 	std::vector<int> vectorC(size, 2);
// 	vectorC.push_back(4);
// 	vectorC.push_back(5);
// 	vectorC.push_back(8);
// 	std::vector<int> vectorD(size, 2);
// 	vectorD.push_back(9);
// 	vectorD.push_back(1);
// 	vectorD.push_back(1);
	
// 	ft_vectorC.splice(ft_vectorC.begin(), ft_vectorD);
// 	vectorC.splice(vectorC.begin(), vectorD);
// 	chk_result(ft_vectorC, vectorC, "vector", title, "[FULL DISORDERED vs FULL DISORDERED] 1/2");
// 	chk_result(ft_vectorD, vectorD, "vector", title, "[FULL DISORDERED vs FULL DISORDERED] 2/2");

// 	ft::Vector<int> ft_vectorE(size, 1);
// 	ft_vectorE.push_back(1);
// 	ft_vectorE.push_back(2);
// 	ft_vectorE.push_back(3);
// 	std::vector<int> vectorE(size, 1);
// 	vectorE.push_back(1);
// 	vectorE.push_back(2);
// 	vectorE.push_back(3);
// 	ft::Vector<int> ft_vectorF(size, 1);
// 	ft_vectorF.push_back(5);
// 	ft_vectorF.push_back(1);
// 	ft_vectorF.push_back(3);
// 	std::vector<int> vectorF(size, 1);
// 	vectorF.push_back(5);
// 	vectorF.push_back(1);
// 	vectorF.push_back(3);

// 	ft_vectorE.splice(ft_vectorE.begin(), ft_vectorF);
// 	vectorE.splice(vectorE.begin(), vectorF);
// 	chk_result(ft_vectorE, vectorE, "vector", title, "[FULL ORDERED vs FULL DISORDERED] 1/2");
// 	chk_result(ft_vectorF, vectorF, "vector", title, "[FULL ORDERED vs FULL DISORDERED] 2/2");

// 	ft::Vector<int> ft_vectorG(size, 1);
// 	ft_vectorG.push_back(1);
// 	ft_vectorG.push_back(2);
// 	ft_vectorG.push_back(3);
// 	std::vector<int> vectorG(size, 1);
// 	vectorG.push_back(1);
// 	vectorG.push_back(2);
// 	vectorG.push_back(3);
// 	ft::Vector<int> ft_vectorH(size, 1);
// 	ft_vectorH.push_back(5);
// 	ft_vectorH.push_back(1);
// 	ft_vectorH.push_back(3);
// 	std::vector<int> vectorH(size, 1);
// 	vectorH.push_back(5);
// 	vectorH.push_back(1);
// 	vectorH.push_back(3);

// 	ft_vectorH.splice(ft_vectorH.begin(), ft_vectorG);
// 	vectorH.splice(vectorH.begin(), vectorG);
// 	chk_result(ft_vectorH, vectorH, "vector", title, "[FULL DISORDERED vs FULL ORDERED] 1/2");
// 	chk_result(ft_vectorG, vectorG, "vector", title, "[FULL DISORDERED vs FULL ORDERED] 2/2");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[SPLICE(2)]";
// 	std::cout << title;

// 	size = 6;
// 	ft::Vector<int> ft_vectorI(size, 1);
// 	ft_vectorI.push_back(3);
// 	ft_vectorI.push_back(6);
// 	ft::Vector<int> ft_vectorJ(size, 2);
// 	ft_vectorJ.push_back(4);
// 	ft_vectorJ.push_back(5);
// 	ft_vectorJ.push_back(8);
// 	std::vector<int> vectorI(size, 1);
// 	vectorI.push_back(3);
// 	vectorI.push_back(6);
// 	std::vector<int> vectorJ(size, 2);
// 	vectorJ.push_back(4);
// 	vectorJ.push_back(5);
// 	vectorJ.push_back(8);

// 	ft::Vector<int>::iterator ft_it = ft_vectorJ.begin();
// 	std::vector<int>::iterator it = vectorJ.begin();

// 	ft_vectorI.splice(ft_vectorI.begin(), ft_vectorJ, ft_it);
// 	vectorI.splice(vectorI.begin(), vectorJ, it);
// 	chk_result(ft_vectorI, vectorI, "vector", title, "[BEGIN] 1/2");
// 	chk_result(ft_vectorJ, vectorJ, "vector", title, "[BEGIN] 2/2");

// 	ft_it = ft_vectorJ.begin();
// 	ft_it++;
// 	it = vectorJ.begin();
// 	it++;

// 	ft_vectorI.splice(ft_vectorI.begin(), ft_vectorJ, ft_it);
// 	vectorI.splice(vectorI.begin(), vectorJ, it);
// 	chk_result(ft_vectorI, vectorI, "vector", title, "[MIDDLE] 1/2");
// 	chk_result(ft_vectorJ, vectorJ, "vector", title, "[MIDDLE] 2/2");

// 	//END = UNDEFINED BEHAVIOUR
// 	// ft_vectorI.splice(ft_vectorI.begin(), ft_vectorJ, ft_vectorJ.end());
// 	// vectorI.splice(vectorI.begin(), vectorJ, vectorJ.end());
// 	// chk_result(ft_vectorI, vectorI, "vector", "SPLICE(2) [END] 1/2");
// 	// chk_result(ft_vectorJ, vectorJ, "vector", "SPLICE(2) [END] 2/2");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[SPLICE(3)]";
// 	std::cout << title;

// 	size = 6;
// 	ft::Vector<int> ft_vectorK(size, 1);
// 	ft_vectorK.push_back(3);
// 	ft_vectorK.push_back(6);
// 	ft::Vector<int> ft_vectorL(size, 10);
// 	ft_vectorL.push_back(4);
// 	ft_vectorL.push_back(5);
// 	ft_vectorL.push_back(8);
// 	std::vector<int> vectorK(size, 1);
// 	vectorK.push_back(3);
// 	vectorK.push_back(6);
// 	std::vector<int> vectorL(size, 10);
// 	vectorL.push_back(4);
// 	vectorL.push_back(5);
// 	vectorL.push_back(8);

// 	ft::Vector<int>::iterator ft_itFirst = ft_vectorL.begin();
// 	std::vector<int>::iterator itFirst = vectorL.begin();
// 	ft::Vector<int>::iterator ft_itLast = ft_itFirst;
// 	ft_itLast++;
// 	std::vector<int>::iterator itLast = itFirst;
// 	itLast++;

// 	ft_vectorK.splice(ft_vectorK.begin(), ft_vectorL, ft_itFirst, ft_itLast);
// 	vectorK.splice(vectorK.begin(), vectorL, itFirst, itLast);
// 	chk_result(ft_vectorK, vectorK, "vector", title, "[BEGIN] 1/2");
// 	chk_result(ft_vectorL, vectorL, "vector", title, "[BEGIN] 2/2");

// 	ft_itFirst = ft_vectorL.begin();
// 	ft_itFirst++;
// 	ft_itLast = ft_itFirst;
// 	ft_itLast++;
// 	ft_itLast++;
// 	itFirst = vectorL.begin();
// 	itFirst++;
// 	itLast = itFirst;
// 	itLast++;
// 	itLast++;

// 	ft_vectorK.splice(ft_vectorK.begin(), ft_vectorL, ft_itFirst, ft_itLast);
// 	vectorK.splice(vectorK.begin(), vectorL, itFirst, itLast);
// 	chk_result(ft_vectorI, vectorI, "vector", title, "[MIDDLE] 1/2");
// 	chk_result(ft_vectorJ, vectorJ, "vector", title, "[MIDDLE] 2/2");
	
// 	ft_itFirst = ft_vectorL.begin();
// 	ft_itLast = ft_vectorL.end();
// 	itFirst = vectorL.begin();
// 	ft_itLast = ft_vectorL.end();

// 	ft_vectorK.splice(ft_vectorK.begin(), ft_vectorL, ft_itFirst, ft_itLast);
// 	vectorK.splice(vectorK.begin(), vectorL, itFirst, itLast);
// 	chk_result(ft_vectorI, vectorI, "vector", title, "[END] 1/2");
// 	chk_result(ft_vectorJ, vectorJ, "vector", title, "[END] 2/2");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_remove() {

// 	std::string title = "[REMOVE]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(5, '!');
// 	std::vector<char> vector(5, '!');

// 	ft::Vector<char>::iterator ft_it = ft_vector.begin();
// 	std::vector<char>::iterator it = vector.begin();
// 	ft_it++;
// 	it++;
// 	ft_vector.push_back('a');
// 	ft_vector.insert(ft_it, 'a');
// 	ft_vector.insert(ft_it, 'b');
// 	vector.push_back('a');
// 	vector.insert(it, 'a');
// 	vector.insert(it, 'b');

// 	ft_vector.remove('a');
// 	vector.remove('a');
// 	chk_result(ft_vector, vector, "vector", title, "[WITH DOUBLES]");

// 	ft_vector.remove('!');
// 	vector.remove('!');
// 	chk_result(ft_vector, vector, "vector", title, "[WITH BEGIN]");

// 	ft_vector.remove('b');
// 	vector.remove('b');
// 	chk_result(ft_vector, vector, "vector", title, "[WITH ALL]");

// 	ft::Vector<char> ft_vectorEmpty;
// 	std::vector<char> vectorEmpty;
// 	ft_vectorEmpty.remove('a');
// 	vectorEmpty.remove('a');
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY Vector]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// struct is_odd {
//   bool operator() (const int& value) { return (value%2)==1; }
// };
// struct is_even {
//   bool operator() (const int& value) { return (value%2)==0; }
// };

// int test_vector_removeIf() {
// 	std::string title = "[REMOVE_IF]";
// 	std::cout << title;

// 	size_t size = 5;
// 	ft::Vector<int> ft_vector(size, 4);
// 	std::vector<int> vector(size, 4);

// 	ft::Vector<int>::iterator ft_it = ft_vector.begin();
// 	std::vector<int>::iterator it = vector.begin();
// 	ft_it++;
// 	it++;
// 	ft_vector.push_back(3);
// 	ft_vector.insert(ft_it, 3);
// 	ft_vector.insert(ft_it, 2);
// 	vector.push_back(3);
// 	vector.insert(it, 3);
// 	vector.insert(it, 2);

// 	ft_vector.remove_if(is_odd());
// 	vector.remove_if(is_odd());
// 	chk_result(ft_vector, vector, "vector", title, "[MIDDLE AND END]");

// 	ft_vector.remove_if(is_even());
// 	vector.remove_if(is_even());
// 	chk_result(ft_vector, vector, "vector", title, "[ALL WITH BEGIN]");

// 	ft_vector.remove_if(is_even());
// 	vector.remove_if(is_even());
// 	chk_result(ft_vector, vector, "vector", title, "[EMPTY Vector]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// struct is_near {
//   bool operator() (char first, char second)
//   { return (second - first <= 1 || first - second <= 1); }
// };

// int test_vector_unique() {
// 	std::string title = "[UNIQUE(1)]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(5, '!');
// 	std::vector<char> vector(5, '!');

// 	ft::Vector<char>::iterator ft_it = ft_vector.begin();
// 	std::vector<char>::iterator it = vector.begin();
// 	ft_it++;
// 	it++;
// 	ft_vector.push_back('a');
// 	ft_vector.insert(ft_it, 'a');
// 	ft_vector.insert(ft_it, 'b');
// 	vector.push_back('a');
// 	vector.insert(it, 'a');
// 	vector.insert(it, 'b');

// 	ft_vector.unique();
// 	vector.unique();
// 	chk_result(ft_vector, vector, "vector", title, "[WITH DOUBLES]");

// 	ft_vector.unique();
// 	vector.unique();
// 	chk_result(ft_vector, vector, "vector", title, "[NO DOUBLES]");

// 	ft::Vector<char> ft_vectorEmpty;
// 	std::vector<char> vectorEmpty;
// 	ft_vectorEmpty.unique();
// 	vectorEmpty.unique();
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY Vector]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[UNIQUE(2)[binary_pred]]";
// 	std::cout << title;

// 	ft_vector.push_back('a');
// 	ft_vector.insert(ft_it, 'a');
// 	ft_vector.insert(ft_it, 'b');
// 	vector.push_back('a');
// 	vector.insert(it, 'a');
// 	vector.insert(it, 'b');

// 	ft_vector.unique(is_near());
// 	vector.unique(is_near());
// 	chk_result(ft_vector, vector, "vector", title, "[WITH DOUBLES]");

// 	ft_vector.unique(is_near());
// 	vector.unique(is_near());
// 	chk_result(ft_vector, vector, "vector", title, "[NO DOUBLES]");

// 	ft_vectorEmpty.unique(is_near());
// 	vectorEmpty.unique(is_near());
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY Vector]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_mergeComp();

// int test_vector_merge() {
// 	std::string title = "[MERGE(1)]";
// 	std::cout << title;

// 	size_t size = 6;
// 	ft::Vector<int> ft_vectorA(size, 1);
// 	ft_vectorA.push_back(3);
// 	ft_vectorA.push_back(6);
// 	ft::Vector<int> ft_vectorB(size, 2);
// 	ft_vectorB.push_back(4);
// 	ft_vectorB.push_back(5);
// 	ft_vectorB.push_back(8);
// 	std::vector<int> vectorA(size, 1);
// 	vectorA.push_back(3);
// 	vectorA.push_back(6);
// 	std::vector<int> vectorB(size, 2);
// 	vectorB.push_back(4);
// 	vectorB.push_back(5);
// 	vectorB.push_back(8);

// 	ft_vectorA.merge(ft_vectorB);
// 	vectorA.merge(vectorB);
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[FULL ORDERED vs FULL ORDERED] 1/2");
// 	chk_result(ft_vectorB, vectorB, "vector", title, "[FULL ORDERED vs FULL ORDERED] 2/2");
	
// 	ft::Vector<int> ft_vectorEmptyA;
// 	std::vector<int> vectorEmptyA;
// 	ft::Vector<int> ft_vectorEmptyB;
// 	std::vector<int> vectorEmptyB;
// 	ft_vectorEmptyA.merge(ft_vectorEmptyB);
// 	vectorEmptyA.merge(vectorEmptyB);
// 	chk_result(ft_vectorEmptyA, vectorEmptyA, "vector", title, "[EMPTY vs EMPTY] 1/2");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY vs EMPTY] 2/2");

// 	ft_vectorA.merge(ft_vectorEmptyB);
// 	vectorA.merge(vectorEmptyB);
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[FULL vs EMPTY] 1/2");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[FULL vs EMPTY] 2/2");

// 	ft_vectorEmptyB.merge(ft_vectorA);
// 	vectorEmptyB.merge(vectorA);
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY vs FULL] 1/2");
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[EMPTY vs FULL] 2/2");
 
// 	ft::Vector<int> ft_vectorC(size, 2);
// 	ft_vectorC.push_back(4);
// 	ft_vectorC.push_back(5);
// 	ft_vectorC.push_back(8);
// 	ft::Vector<int> ft_vectorD(size, 2);
// 	ft_vectorD.push_back(9);
// 	ft_vectorD.push_back(1);
// 	ft_vectorD.push_back(1);
// 	std::vector<int> vectorC(size, 2);
// 	vectorC.push_back(4);
// 	vectorC.push_back(5);
// 	vectorC.push_back(8);
// 	std::vector<int> vectorD(size, 2);
// 	vectorD.push_back(9);
// 	vectorD.push_back(1);
// 	vectorD.push_back(1);
	
// 	ft_vectorC.merge(ft_vectorD);
// 	vectorC.merge(vectorD);
// 	chk_result(ft_vectorC, vectorC, "vector", title, "[FULL DISORDERED vs FULL DISORDERED] 1/2");
// 	chk_result(ft_vectorD, vectorD, "vector", title, "[FULL DISORDERED vs FULL DISORDERED] 2/2");

// 	ft::Vector<int> ft_vectorE(size, 1);
// 	ft_vectorE.push_back(1);
// 	ft_vectorE.push_back(2);
// 	ft_vectorE.push_back(3);
// 	std::vector<int> vectorE(size, 1);
// 	vectorE.push_back(1);
// 	vectorE.push_back(2);
// 	vectorE.push_back(3);
// 	ft::Vector<int> ft_vectorF(size, 1);
// 	ft_vectorF.push_back(5);
// 	ft_vectorF.push_back(1);
// 	ft_vectorF.push_back(3);
// 	std::vector<int> vectorF(size, 1);
// 	vectorF.push_back(5);
// 	vectorF.push_back(1);
// 	vectorF.push_back(3);

// 	ft_vectorE.merge(ft_vectorF);
// 	vectorE.merge(vectorF);
// 	chk_result(ft_vectorE, vectorE, "vector", title, "[FULL ORDERED vs FULL DISORDERED] 1/2");
// 	chk_result(ft_vectorF, vectorF, "vector", title, "[FULL ORDERED vs FULL DISORDERED] 2/2");

// 	ft::Vector<int> ft_vectorG(size, 1);
// 	ft_vectorG.push_back(1);
// 	ft_vectorG.push_back(2);
// 	ft_vectorG.push_back(3);
// 	std::vector<int> vectorG(size, 1);
// 	vectorG.push_back(1);
// 	vectorG.push_back(2);
// 	vectorG.push_back(3);
// 	ft::Vector<int> ft_vectorH(size, 1);
// 	ft_vectorH.push_back(5);
// 	ft_vectorH.push_back(1);
// 	ft_vectorH.push_back(3);
// 	std::vector<int> vectorH(size, 1);
// 	vectorH.push_back(5);
// 	vectorH.push_back(1);
// 	vectorH.push_back(3);

// 	ft_vectorH.merge(ft_vectorG);
// 	vectorH.merge(vectorG);
// 	chk_result(ft_vectorH, vectorH, "vector", title, "[FULL DISORDERED vs FULL ORDERED] 1/2");
// 	chk_result(ft_vectorG, vectorG, "vector", title, "[FULL DISORDERED vs FULL ORDERED] 2/2");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return test_vector_mergeComp();
// };

// struct is_bigger {
//   bool operator() (int first, int second)
//   { return (first > second); }
// };

// int test_vector_mergeComp() {
// 	std::string title = "[MERGE(2) [COMP]]";
// 	std::cout << title;

// 	size_t size = 6;
// 	ft::Vector<int> ft_vectorA(size, 1);
// 	ft_vectorA.push_back(3);
// 	ft_vectorA.push_back(6);
// 	ft::Vector<int> ft_vectorB(size, 2);
// 	ft_vectorB.push_back(4);
// 	ft_vectorB.push_back(5);
// 	ft_vectorB.push_back(8);
// 	std::vector<int> vectorA(size, 1);
// 	vectorA.push_back(3);
// 	vectorA.push_back(6);
// 	std::vector<int> vectorB(size, 2);
// 	vectorB.push_back(4);
// 	vectorB.push_back(5);
// 	vectorB.push_back(8);

// 	ft_vectorA.merge(ft_vectorB, is_bigger());
// 	vectorA.merge(vectorB, is_bigger());
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[FULL ORDERED vs FULL ORDERED] 1/2");
// 	chk_result(ft_vectorB, vectorB, "vector", title, "[FULL ORDERED vs FULL ORDERED] 2/2");
	
// 	ft::Vector<int> ft_vectorEmptyA;
// 	std::vector<int> vectorEmptyA;
// 	ft::Vector<int> ft_vectorEmptyB;
// 	std::vector<int> vectorEmptyB;
// 	ft_vectorEmptyA.merge(ft_vectorEmptyB, is_bigger());
// 	vectorEmptyA.merge(vectorEmptyB, is_bigger());
// 	chk_result(ft_vectorEmptyA, vectorEmptyA, "vector", title, "[EMPTY vs EMPTY] 1/2");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY vs EMPTY] 2/2");

// 	ft_vectorA.merge(ft_vectorEmptyB, is_bigger());
// 	vectorA.merge(vectorEmptyB, is_bigger());
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[FULL vs EMPTY] 1/2");
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[FULL vs EMPTY] 2/2");

// 	ft_vectorEmptyB.merge(ft_vectorA, is_bigger());
// 	vectorEmptyB.merge(vectorA, is_bigger());
// 	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY vs FULL] 1/2");
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[EMPTY vs FULL] 2/2");
 
// 	ft::Vector<int> ft_vectorC(size, 2);
// 	ft_vectorC.push_back(4);
// 	ft_vectorC.push_back(5);
// 	ft_vectorC.push_back(8);
// 	ft::Vector<int> ft_vectorD(size, 2);
// 	ft_vectorD.push_back(9);
// 	ft_vectorD.push_back(1);
// 	ft_vectorD.push_back(1);
// 	std::vector<int> vectorC(size, 2);
// 	vectorC.push_back(4);
// 	vectorC.push_back(5);
// 	vectorC.push_back(8);
// 	std::vector<int> vectorD(size, 2);
// 	vectorD.push_back(9);
// 	vectorD.push_back(1);
// 	vectorD.push_back(1);
	
// 	ft_vectorC.merge(ft_vectorD, is_bigger());
// 	vectorC.merge(vectorD, is_bigger());
// 	chk_result(ft_vectorC, vectorC, "vector", title, "[FULL DISORDERED vs FULL DISORDERED] 1/2");
// 	chk_result(ft_vectorD, vectorD, "vector", title, "[FULL DISORDERED vs FULL DISORDERED] 2/2");

// 	ft::Vector<int> ft_vectorE(size, 1);
// 	ft_vectorE.push_back(1);
// 	ft_vectorE.push_back(2);
// 	ft_vectorE.push_back(3);
// 	std::vector<int> vectorE(size, 1);
// 	vectorE.push_back(1);
// 	vectorE.push_back(2);
// 	vectorE.push_back(3);
// 	ft::Vector<int> ft_vectorF(size, 1);
// 	ft_vectorF.push_back(5);
// 	ft_vectorF.push_back(1);
// 	ft_vectorF.push_back(3);
// 	std::vector<int> vectorF(size, 1);
// 	vectorF.push_back(5);
// 	vectorF.push_back(1);
// 	vectorF.push_back(3);

// 	ft_vectorE.merge(ft_vectorF, is_bigger());
// 	vectorE.merge(vectorF, is_bigger());
// 	chk_result(ft_vectorE, vectorE, "vector", title, "[FULL ORDERED vs FULL DISORDERED] 1/2");
// 	chk_result(ft_vectorF, vectorF, "vector", title, "[FULL ORDERED vs FULL DISORDERED] 2/2");

// 	ft::Vector<int> ft_vectorG(size, 1);
// 	ft_vectorG.push_back(1);
// 	ft_vectorG.push_back(2);
// 	ft_vectorG.push_back(3);
// 	std::vector<int> vectorG(size, 1);
// 	vectorG.push_back(1);
// 	vectorG.push_back(2);
// 	vectorG.push_back(3);
// 	ft::Vector<int> ft_vectorH(size, 1);
// 	ft_vectorH.push_back(5);
// 	ft_vectorH.push_back(1);
// 	ft_vectorH.push_back(3);
// 	std::vector<int> vectorH(size, 1);
// 	vectorH.push_back(5);
// 	vectorH.push_back(1);
// 	vectorH.push_back(3);

// 	ft_vectorH.merge(ft_vectorG, is_bigger());
// 	vectorH.merge(vectorG, is_bigger());
// 	chk_result(ft_vectorH, vectorH, "vector", title, "[FULL DISORDERED vs FULL ORDERED] 1/2");
// 	chk_result(ft_vectorG, vectorG, "vector", title, "[FULL DISORDERED vs FULL ORDERED] 2/2");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_sort() {
// 	std::string title = "[SORT(1)]";
// 	std::cout << title;

// 	ft::Vector<int> ft_vector;
// 	std::vector<int> vector;
// 	ft_vector.push_back(0);
// 	ft_vector.push_back(2145678);
// 	ft_vector.push_back(-70);
// 	ft_vector.push_back(42);
// 	vector.push_back(0);
// 	vector.push_back(2145678);
// 	vector.push_back(-70);
// 	vector.push_back(42);

// 	ft_vector.sort();
// 	vector.sort();
// 	chk_result(ft_vector, vector, "vector", title);

// 	ft::Vector<int> ft_vectorEmpty;
// 	std::vector<int> vectorEmpty;
// 	ft_vectorEmpty.sort();
// 	vectorEmpty.sort();
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//----------------------------------------------------------

// 	title = "[SORT(2)]";
// 	std::cout << title;
	
// 	ft_vector.sort(is_bigger());
// 	vector.sort(is_bigger());
// 	chk_result(ft_vector, vector, "vector", title);

// 	ft_vectorEmpty.sort(is_bigger());
// 	vectorEmpty.sort(is_bigger());
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_vector_reverse() {
// 	std::string title = "[REVERSE]";
// 	std::cout << title;

// 	ft::Vector<char> ft_vector(5, '!');
// 	std::vector<char> vector(5, '!');

// 	ft::Vector<char>::iterator ft_it = ft_vector.begin();
// 	std::vector<char>::iterator it = vector.begin();
// 	ft_it++;
// 	it++;
// 	ft_vector.push_back('8');
// 	ft_vector.push_front('1');
// 	ft_vector.insert(ft_it, 'a');
// 	ft_vector.insert(ft_it, 'b');
// 	vector.push_back('8');
// 	vector.push_front('1');
// 	vector.insert(it, 'a');
// 	vector.insert(it, 'b');

// 	ft_vector.reverse();
// 	vector.reverse();
// 	chk_result(ft_vector, vector, "vector", title, "[FULL, EVEN NODES]");
// 	ft_vector.pop_front();
// 	vector.pop_front();
// 	chk_result(ft_vector, vector, "vector", title, "[FULL, ODD NODES]");

// 	ft::Vector<char> ft_vectorEmpty;
// 	std::vector<char> vectorEmpty;
// 	ft_vectorEmpty.reverse();
// 	vectorEmpty.reverse();
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY Vector]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// }


// //*\*/*\/*\*/*\/*\*/*\/*\*///
// ///*\*/*\NON-MEMBERS/*\*/*\//
// //*\*/*\/*\*/*\/*\*/*\/*\*///

// int test_vector_nonMembers() {
// 	std::string title = "----[NON-MEMBER OPERATORS]----";
// 	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
// 	title = "[OPERATOR==]";
// 	std::cout << title;

// 	ft::Vector<int> ft_vectorA;
// 	std::vector<int> vectorA;
// 	ft_vectorA.push_back(0);
// 	ft_vectorA.push_back(2145678);
// 	ft_vectorA.push_back(-70);
// 	ft_vectorA.push_back(42);
// 	vectorA.push_back(0);
// 	vectorA.push_back(2145678);
// 	vectorA.push_back(-70);
// 	vectorA.push_back(42);
// 	ft::Vector<int> ft_vectorB;
// 	std::vector<int> vectorB;
// 	ft_vectorB.push_back(0);
// 	ft_vectorB.push_back(2145678);
// 	ft_vectorB.push_back(-70);
// 	ft_vectorB.push_back(42);
// 	vectorB.push_back(0);
// 	vectorB.push_back(2145678);
// 	vectorB.push_back(-70);
// 	vectorB.push_back(42);

// 	bool ft_bool = (ft_vectorA == ft_vectorB);
// 	bool std_bool = (vectorA == vectorB);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_vectorA, ft_vectorB, "vector", title, "[EQUAL]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	ft::Vector<int> ft_vectorC;
// 	std::vector<int> vectorC;
// 	ft_vectorC.push_back(0);
// 	ft_vectorC.push_back(666);
// 	//ft_vectorC.push_back(-70);
// 	ft_vectorC.push_back(42);
// 	vectorC.push_back(0);
// 	vectorC.push_back(666);
// 	//vectorC.push_back(-70);
// 	vectorC.push_back(42);

// 	ft_bool = (ft_vectorA == ft_vectorC);
// 	std_bool = (vectorA == vectorC);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_vectorA, ft_vectorC, "vector", title, "[DIFF]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR!=]";
// 	std::cout << title;

// 	ft_bool = (ft_vectorA != ft_vectorB);
// 	std_bool = (vectorA != vectorB);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_vectorA, ft_vectorB, "vector", title, "[EQUAL]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	ft_bool = (ft_vectorA != ft_vectorC);
// 	std_bool = (vectorA != vectorC);
// 	if (ft_bool != std_bool) {
// 		handle_error(ft_vectorA, ft_vectorC, "vector", title, "[DIFF]", "CONTENT");
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR<]";
// 	std::cout << title;

// 	ft_bool = (ft_vectorC < ft_vectorA);
// 	std_bool = (vectorC < vectorA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA < ft_vectorC);
// 	std_bool = (vectorA < vectorC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA < ft_vectorB);
// 	std_bool = (vectorA < vectorB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
// 	}
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR<=]";
// 	std::cout << title;

// 	ft_bool = (ft_vectorC <= ft_vectorA);
// 	std_bool = (vectorC <= vectorA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA <= ft_vectorC);
// 	std_bool = (vectorA <= vectorC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA <= ft_vectorB);
// 	std_bool = (vectorA <= vectorB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR>]";
// 	std::cout << title;

// 	ft_bool = (ft_vectorC > ft_vectorA);
// 	std_bool = (vectorC > vectorA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA > ft_vectorC);
// 	std_bool = (vectorA > vectorC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA > ft_vectorB);
// 	std_bool = (vectorA > vectorB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[OPERATOR>=]";
// 	std::cout << title;

// 	ft_bool = (ft_vectorC >= ft_vectorA);
// 	std_bool = (vectorC >= vectorA);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA >= ft_vectorC);
// 	std_bool = (vectorA >= vectorC);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
// 	}

// 	ft_bool = (ft_vectorA >= ft_vectorB);
// 	std_bool = (vectorA >= vectorB);
// 	if (ft_bool != std_bool) {
// 		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
// 		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
// 	}

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	//------------------------------------------------------------------------

// 	title = "[SWAP (non-member)]";
// 	std::cout << title;

// 	swap(ft_vectorA, ft_vectorC);
// 	swap(vectorA, vectorC);
// 	chk_result(ft_vectorA, vectorA, "vector", title, "[1/2]");
// 	chk_result(ft_vectorC, vectorC, "vector", title, "[2/2]");

// 	ft::Vector<int> ft_vectorEmpty;
// 	std::vector<int> vectorEmpty;
// 	swap(ft_vectorEmpty, ft_vectorC);
// 	swap(vectorEmpty, vectorC);
// 	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY vs FULL] [1/2]");
// 	chk_result(ft_vectorC, vectorC, "vector", title, "[EMPTY vs FULL] [2/2]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

