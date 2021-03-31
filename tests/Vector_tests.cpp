/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/31 11:22:27 by esoulard         ###   ########.fr       */
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
	ft_capacity = ft_vectorEmpty.capacity();
	std_capacity = vectorEmpty.capacity();
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
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_reserve() {
	std::string title = "[RESERVE]";
	std::cout << title;

	ft::Vector<char> ft_vector(5, '!');
	std::vector<char> vector(5, '!');

	size_t ft_size = ft_vector.size();
	size_t std_size = vector.size();
	size_t ft_capacity = ft_vector.capacity();
	size_t std_capacity = vector.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5]", "CAPACITY");
	}

	ft_vector.reserve(2);
	vector.reserve(2);
	ft_size = ft_vector.size();
	std_size = vector.size();
	ft_capacity = ft_vector.capacity();
	std_capacity = vector.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5 RESERVE 2]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5 RESERVE 2]", "CAPACITY");
	}

	ft_vector.reserve(6);
	vector.reserve(6);
	ft_size = ft_vector.size();
	std_size = vector.size();
	ft_capacity = ft_vector.capacity();
	std_capacity = vector.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5 RESERVE 6]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5 RESERVE 6]", "CAPACITY");
	}

	ft_vector.push_back('a');
	ft_vector.insert(ft_vector.begin(), 'a');
	ft_vector.insert(ft_vector.begin(), 'b');
	vector.push_back('a');
	vector.insert(vector.begin(), 'a');
	vector.insert(vector.begin(), 'b');

	ft_size = ft_vector.size();
	std_size = vector.size();
	ft_capacity = ft_vector.capacity();
	std_capacity = vector.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[PUSH BACK AND STUFF AFTER RESERVE]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[PUSH BACK AND STUFF AFTER RESERVE]", "CAPACITY");
	}

	ft_vector.reserve(10000);
	vector.reserve(10000);
	ft_size = ft_vector.size();
	std_size = vector.size();
	ft_capacity = ft_vector.capacity();
	std_capacity = vector.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5 RESERVE 10000]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[SIZE 5 RESERVE 10000]", "CAPACITY");
	}
	
	ft::Vector<char> ft_vectorEmpty;
	std::vector<char> vectorEmpty;
	ft_size = ft_vectorEmpty.size();
	std_size = vectorEmpty.size();
	ft_capacity = ft_vectorEmpty.capacity();
	std_capacity = vectorEmpty.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "CAPACITY");
	}

	ft_vectorEmpty.reserve(0);
	vectorEmpty.reserve(0);
	ft_size = ft_vectorEmpty.size();
	std_size = vectorEmpty.size();
	ft_capacity = ft_vectorEmpty.capacity();
	std_capacity = vectorEmpty.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY RESERVE 0]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY RESERVE 0]", "CAPACITY");
	}

	ft_vectorEmpty.reserve(50000);
	vectorEmpty.reserve(50000);
	ft_size = ft_vectorEmpty.size();
	std_size = vectorEmpty.size();
	ft_capacity = ft_vectorEmpty.capacity();
	std_capacity = vectorEmpty.capacity();

	if (ft_size != std_size) {
		std::cerr << "ft_vector.size() = [" << ft_size << "] | vector.size() = [" << std_size << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY RESERVE 50000]", "SIZE");
	}
	if (ft_capacity != std_capacity) {
		std::cerr << "ft_vector.capacity() = [" << ft_capacity << "] | vector.capacity() = [" << std_capacity << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY RESERVE 50000]", "CAPACITY");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
//*\*/ELEMENT ACCESS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_vector_oparray() {
	std::string title = "[OPERATOR[]]";
	std::cout << title;

	ft::Vector<int> ft_vector;
	std::vector<int> vector;

	ft_vector.push_back(10);
	ft_vector.push_back(12);
	ft_vector.push_back(18);
	ft_vector.insert(ft_vector.begin(), 12, 'a');
	ft_vector.insert(ft_vector.begin(), 5, 'b');

	vector.push_back(10);
	vector.push_back(12);
	vector.push_back(18);
	vector.insert(vector.begin(), 12, 'a');
	vector.insert(vector.begin(), 5, 'b');
	
	for (size_t i = 0; i < ft_vector.size(); i++) {
		if (ft_vector[i] != vector[i]) {
			std::cerr << "ft_vector[" << i << "] = [" << ft_vector[i] << "] | vector[" << i << "] = [" << vector[i] << std::endl;
			handle_error(ft_vector, vector, "vector", title, "[COMPARE]", "");
		}
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_at() {
	std::string title = "[AT]";
	std::cout << title;

	ft::Vector<int> ft_vector;
	std::vector<int> vector;

	ft_vector.push_back(10);
	ft_vector.push_back(12);
	ft_vector.push_back(18);
	ft_vector.insert(ft_vector.begin(), 12, 'a');
	ft_vector.insert(ft_vector.begin(), 5, 'b');

	vector.push_back(10);
	vector.push_back(12);
	vector.push_back(18);
	vector.insert(vector.begin(), 12, 'a');
	vector.insert(vector.begin(), 5, 'b');
	
	for (size_t i = 0; i < ft_vector.size(); i++) {
		if (ft_vector.at(i) != vector.at(i)) {
			std::cerr << "ft_vector[" << i << "] = [" << ft_vector[i] << "] | vector[" << i << "] = [" << vector[i] << std::endl;
			handle_error(ft_vector, vector, "vector", title, "[COMPARE]", "");
		}
	}
	try {
		ft_vector.at(20);
		std::cerr << "ERROR HASN'T BEEN THROWN IN CASE OF OUT OR RANGE VECTOR ACCESS WITH AT [vector size20 accessing idx 20]/!\\" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[COMPARE]", "");
	}
	catch (std::exception &e) {
		try {
			vector.at(20);
		}
		catch (std::exception &f) {
			if (strcmp(f.what(), e.what())) {
				std::cerr << "ft_error[" << e.what() << "] | std_error[" << f.what() << "]" << std::endl;
				handle_error(ft_vector, vector, "vector", title, "[COMPARE]", "");
			}
		}
	}
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_front_back() {
	std::string title = "[FRONT/BACK]";
	std::cout << title;

	ft::Vector<int> ft_vector;
	std::vector<int> vector;

	ft_vector.push_back(10);
	ft_vector.push_back(12);
	ft_vector.push_back(18);

	vector.push_back(10);
	vector.push_back(12);
	vector.push_back(18);

	if (ft_vector.front() != vector.front() || ft_vector.back() != vector.back()) {
		std::cerr << "ft_vector.front() = [" << ft_vector.front() << "] | vector.front() = [" << vector.front() << "]" << std::endl;
		std::cerr << "ft_vector.back() = [" << ft_vector.back() << "] | vector.back() = [" << vector.back() << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
	}

	//UNDEFINED
	// ft::Vector<int> ft_vectorEmpty;
	// std::vector<int> vectorEmpty;

	// if (ft_vectorEmpty.front() != vectorEmpty.front() || ft_vectorEmpty.back() != vectorEmpty.back()) {
	// 	std::cerr << "ft_vectorEmpty.front() = [" << ft_vectorEmpty.front() << "] | vectorEmpty.front() = [" << vectorEmpty.front() << "]" << std::endl;
	// 	std::cerr << "ft_vectorEmpty.back() = [" << ft_vectorEmpty.back() << "] | vectorEmpty.back() = [" << vectorEmpty.back() << "]" << std::endl;
	// 	handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "CONTENT");
	// }
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	title = "[FRONT/BACK CONST OVERLOAD]";
	std::cout << title;

	size_t size = 12;
	ft::Vector<int> const ft_constVector(size, 8);
	std::vector<int> const constVector(size, 8);

	if (ft_constVector.front() != constVector.front() || ft_constVector.back() != constVector.back()) {
		std::cerr << "ft_constVector.front() = [" << ft_constVector.front() << "] | constVector.front() = [" << constVector.front() << "]" << std::endl;
		std::cerr << "ft_constVector.back() = [" << ft_constVector.back() << "] | constVector.back() = [" << constVector.back() << "]" << std::endl;
		handle_error(ft_constVector, constVector, "vector", title, "[CONST]", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\*/MODIFIERS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_vector_assign() {
	std::string title = "[ASSIGN(1)]";
	std::cout << title;

	ft::Vector<char> ft_src(8, 'k');
	std::vector<char> src(8, 'k');
	ft::Vector<char> ft_vector;
	std::vector<char> vector;

	ft_vector.assign(ft_src.begin(), ft_src.end());
	vector.assign(src.begin(), src.end());
	chk_result(ft_vector, vector, "vector", title, "[FULL to EMPTY][1/2]");
	chk_result(ft_src, src, "vector", title, "[FULL to EMPTY][2/2]");

	ft_src.assign(ft_vector.begin(), ft_vector.end());
	src.assign(vector.begin(), vector.end());
	chk_result(ft_vector, vector, "vector", title, "[FULL to FULL][1/2]");
	chk_result(ft_src, src, "vector", title, "[FULL to EMPTY][2/2]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	//------------------------------------------------------------------------
	title = "[ASSIGN(2)]";
	std::cout << title;

	ft::Vector<char> ft_vectorA;
	std::vector<char> vectorA;

	ft_vectorA.assign(12, 'W');
	vectorA.assign(12, 'W');
	chk_result(ft_vectorA, vectorA, "vector", title, "[to EMPTY]");
	
	ft_vectorA.assign(4, '8');
	vectorA.assign(4, '8');
	chk_result(ft_vectorA, vectorA, "vector", title, "[to FULL]");

	ft_vectorA.assign(24, 'U');
	vectorA.assign(24, 'U');
	chk_result(ft_vectorA, vectorA, "vector", title, "[to FULL]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
}

int test_vector_popBack() {
	std::string title = "[POP_BACK]";
	std::cout << title;

	ft::Vector<char> ft_vector(10, '!');
	ft_vector.push_back('@');
	ft_vector.push_back('&');

	std::vector<char> vector(10, '!');
	vector.push_back('@');
	vector.push_back('&');

	ft_vector.pop_back();
	vector.pop_back();
	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_vectorEmpty;
	ft_vector.pop_back();
	std::vector<char> vectorEmpty;
	vector.pop_back();

	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_insert() {
	//------------------------------------------------------------------------
	std::string title = "[INSERT(1)]";
	std::cout << title;

	ft::Vector<char> ft_vector(10, '!');
	ft_vector.push_back('@');
	ft_vector.push_back('&');
	ft::Vector<char>::iterator ft_it = ft_vector.begin();
	ft_it = ft_vector.insert(ft_it, 'a');
	ft_it = ft_vector.insert(ft_it, 'b');
	ft_it = ft_vector.insert(ft_it, 'c');

	std::vector<char> vector(10, '!');
	vector.push_back('@');
	vector.push_back('&');
	std::vector<char>::iterator it = vector.begin();
	it = vector.insert(it, 'a');
	it = vector.insert(it, 'b');
	it = vector.insert(it, 'c');

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title);
	

	ft::Vector<char> ft_vectorEmpty;
	ft_it = ft_vectorEmpty.begin();
	ft_it = ft_vectorEmpty.insert(ft_it, 'a');
	std::vector<char> vectorEmpty;
	it = vectorEmpty.begin();
	it = vectorEmpty.insert(it, 'a');

	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(1) = [" << *ft_it << "] | *it after insert(1) = [" << *it << "]" << std::endl;
		handle_error(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]", "CONTENT");
	}
	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[INSERT(2)[FILL]]";
	std::cout << title;

	size_t size = 3;
	ft_it = ft_vector.begin();
	ft_it++;
	ft_vector.insert(ft_it, size, '6');
	ft_it = ft_vector.begin();

	it = vector.begin();
	it++;
	vector.insert(it, size, '6');
	it = vector.begin();
	
	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(2) = [" << *ft_it << "] | *it after insert(2) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title);
	
	ft::Vector<char> ft_vectorEmptyB;
	ft_it = ft_vectorEmptyB.begin();
	ft_vectorEmptyB.insert(ft_it, size, '6');
	std::vector<char> vectorEmptyB;
	it = vectorEmptyB.begin();
	vectorEmptyB.insert(it, size, '6');

	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[EMPTY to FULL]");

	size = 0;
	ft::Vector<char> ft_vectorEmptyC;
	ft_it = ft_vectorEmptyC.begin();
	ft_vectorEmptyC.insert(ft_it, size, '6');
	std::vector<char> vectorEmptyC;
	it = vectorEmptyC.begin();
	vectorEmptyC.insert(it, size, '6');

	chk_result(ft_vectorEmptyC, vectorEmptyC, "vector", title, "[EMPTY to EMPTY]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[INSERT(3)[RANGE]]";
	std::cout << title;
	chk_result(ft_vector, vector, "vector", title, "askdjhaskjdh");
	
	ft::Vector<char> ft_src(10, '!');
	ft_src.push_back('@');

	ft_it = ft_vector.begin();
	ft_it++;
	ft_vector.insert(ft_it, ft_src.begin(), ft_src.end());
	ft_it = ft_vector.begin();

	std::vector<char> src(10, '!');
	src.push_back('@');

	it = vector.begin();
	it++;
	vector.insert(it, src.begin(), src.end());
	it = vector.begin();
	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(3) = [" << *ft_it << "] | *it after insert(3) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title);

	ft::Vector<char> ft_vectorEmptyD;
	ft_it = ft_vectorEmptyC.begin();
	ft_vectorEmptyC.insert(ft_it, ft_vectorEmptyD.begin(), ft_vectorEmptyD.end());
	std::vector<char> vectorEmptyD;
	it = vectorEmptyC.begin();
	vectorEmptyC.insert(it, vectorEmptyD.begin(), vectorEmptyD.end());
	chk_result(ft_vectorEmptyC, vectorEmptyC, "vector", title, "[EMPTY to EMPTY]");

	ft_it = ft_vector.begin();
	ft_vector.insert(ft_it, ft_vectorEmptyD.begin(), ft_vectorEmptyD.end());
	it = vector.begin();
	vector.insert(it, vectorEmptyD.begin(), vectorEmptyD.end());
	ft_it = ft_vector.begin();
	it = vector.begin();
	if (*it != *ft_it) {
		std::cerr << "*ft_it after insert(3) = [" << *ft_it << "] | *it after insert(3) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title, "[EMPTY to FULL]");
	
	ft_it = ft_vectorEmptyD.begin();
	ft_vectorEmptyD.insert(ft_it, ft_vector.begin(), ft_vector.end());
	it = vectorEmptyD.begin();
	vectorEmptyD.insert(it, vector.begin(), vector.end());
	chk_result(ft_vectorEmptyD, vectorEmptyD, "vector", title, "[FULL TO EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_erase() {
	std::string title = "[ERASE(1)]";
	std::cout << title;

	ft::Vector<char> ft_vector(10, '!');
	ft_vector.push_back('@');
	ft_vector.push_back('&');
	
	std::vector<char> vector(10, '!');
	vector.push_back('@');
	vector.push_back('&');

	ft::Vector<char>::iterator ft_it = ft_vector.begin();
	std::vector<char>::iterator it = vector.begin();

	ft_it = ft_vector.erase(ft_it);
	it = vector.erase(it);
	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[begin]", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title, "[begin]");

	ft_it = ft_vector.erase(ft_it);
	it = vector.erase(it);
	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(1) = [" << *ft_it << "] | *it after erase(1) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[begin]", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title, "[begin]");

	//INVALID POSITION = UNDEFINED BEHAVIOR
	// ft_it = ft_vector.end();
	// it = vector.end();
	// ft_it = ft_vector.erase(ft_it);
	// it = vector.erase(it);
	// chk_result(ft_vector, vector, "vector", "ERASE(1) [end]");

	while (ft_it != ft_vector.end())
		ft_it = ft_vector.erase(ft_it);
	while (it != vector.end())
		it = vector.erase(it);
	chk_result(ft_vector, vector, "vector", title, "[all]");

	//ERASE EMPTY BEGIN = UNDEFINED BEHAVIOUR
	//ft::Vector<char> ft_vectorEmpty;
	//std::vector<char> vectorEmpty;
	//ft_vectorEmpty.erase(ft_vectorEmpty.begin());
	//vectorEmpty.erase(vectorEmpty.begin());
	//chk_result(ft_vectorEmpty, vectorEmpty, "vector", "ERASE(1) [EMPTY]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[ERASE(2)[RANGE]]";
	std::cout << title;

	ft_vector.erase(ft_vector.begin(), ft_vector.end());
	vector.erase(vector.begin(), vector.end());
	chk_result(ft_vector, vector, "vector", title, "[EMPTY]");
	
	ft_vector.insert(ft_vector.begin(), 10, '!');
	ft_vector.push_back('@');
	ft_vector.push_back('&');
	ft_it = ft_vector.begin();
	ft_it++;
	ft_it++;

	vector.insert(vector.begin(), 10, '!');
	vector.push_back('@');
	vector.push_back('&');
	it = vector.begin();
	it++;
	it++;

	ft::Vector<char>::iterator ft_last = ft_it;
	std::vector<char>::iterator last = it;
	ft_last++;
	last++;
		
	ft_it = ft_vector.erase(ft_it, ft_last);
	it = vector.erase(it, last);

	if (*it != *ft_it) {
		std::cerr << "*ft_it after erase(2) = [" << *ft_it << "] | *it after erase(2) = [" << *it << "]" << std::endl;
		handle_error(ft_vector, vector, "vector", title, "[PARTIAL]", "CONTENT");
	}
	chk_result(ft_vector, vector, "vector", title, "[PARTIAL]");
	
	ft_it = ft_vector.erase(ft_vector.begin(), ft_vector.end());
	it = vector.erase(vector.begin(), vector.end());
	chk_result(ft_vector, vector, "vector", title, "[TOTAL]");
	//not comparing return pointers because they point after end() in this case

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_swap() {
	std::string title = "[SWAP]";
	std::cout << title;

	ft::Vector<char> ft_vector(10, '!');
	ft_vector.push_back('@');
	ft_vector.push_back('&');

	std::vector<char> vector(10, '!');
	vector.push_back('@');
	vector.push_back('&');

	ft::Vector<char> ft_vectorEmpty;
	std::vector<char> vectorEmpty;
	ft_vectorEmpty.swap(ft_vector);
	vectorEmpty.swap(vector);

	chk_result(ft_vector, vector, "vector", title, "[Full vs Empty][1/2]");
	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[Full vs Empty][2/2]");
	
	ft_vectorEmpty.swap(ft_vector);
	vectorEmpty.swap(vector);
	chk_result(ft_vector, vector, "vector", title, "[Empty vs Full][1/2]");
	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[Empty vs Full][2/2]");

	ft_vectorEmpty.insert(ft_vectorEmpty.begin(), 56, 'v');
	vectorEmpty.insert(vectorEmpty.begin(), 56, 'v');
	ft_vectorEmpty.swap(ft_vector);
	vectorEmpty.swap(vector);
	chk_result(ft_vector, vector, "vector", title, "[Full vs Full][1/2]");
	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[Full vs Full][2/2]");

	ft::Vector<char> ft_vectorEmptyA;
	std::vector<char> vectorEmptyA;
	ft::Vector<char> ft_vectorEmptyB;
	std::vector<char> vectorEmptyB;
	ft_vectorEmptyA.swap(ft_vectorEmptyB);
	vectorEmptyA.swap(vectorEmptyB);
	chk_result(ft_vectorEmptyA, vectorEmptyA, "vector", title, "[Empty vs Empty][1/2]");
	chk_result(ft_vectorEmptyB, vectorEmptyB, "vector", title, "[Empty vs Empty][2/2]");
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_vector_clear() {
	std::string title = "[CLEAR]";
	std::cout << title;

	ft::Vector<char> ft_vector(5, '!');
	std::vector<char> vector(5, '!');

	ft_vector.clear();
	vector.clear();
	chk_result(ft_vector, vector, "vector", title, "[FULL Vector]");

	ft_vector.clear();
	vector.clear();
	chk_result(ft_vector, vector, "vector", title, "[EMPTY Vector]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\NON-MEMBERS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_vector_nonMembers() {
	std::string title = "----[NON-MEMBER OPERATORS]----";
	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
	title = "[OPERATOR==]";
	std::cout << title;

	ft::Vector<int> ft_vectorA;
	std::vector<int> vectorA;
	ft_vectorA.push_back(0);
	ft_vectorA.push_back(2145678);
	ft_vectorA.push_back(-70);
	ft_vectorA.push_back(42);
	vectorA.push_back(0);
	vectorA.push_back(2145678);
	vectorA.push_back(-70);
	vectorA.push_back(42);
	ft::Vector<int> ft_vectorB;
	std::vector<int> vectorB;
	ft_vectorB.push_back(0);
	ft_vectorB.push_back(2145678);
	ft_vectorB.push_back(-70);
	ft_vectorB.push_back(42);
	vectorB.push_back(0);
	vectorB.push_back(2145678);
	vectorB.push_back(-70);
	vectorB.push_back(42);

	bool ft_bool = (ft_vectorA == ft_vectorB);
	bool std_bool = (vectorA == vectorB);
	if (ft_bool != std_bool) {
		handle_error(ft_vectorA, ft_vectorB, "vector", title, "[EQUAL]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft::Vector<int> ft_vectorC;
	std::vector<int> vectorC;
	ft_vectorC.push_back(0);
	ft_vectorC.push_back(666);
	ft_vectorC.push_back(-70);
	ft_vectorC.push_back(42);
	vectorC.push_back(0);
	vectorC.push_back(666);
	vectorC.push_back(-70);
	vectorC.push_back(42);

	ft_bool = (ft_vectorA == ft_vectorC);
	std_bool = (vectorA == vectorC);
	if (ft_bool != std_bool) {
		handle_error(ft_vectorA, ft_vectorC, "vector", title, "[DIFF]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR!=]";
	std::cout << title;

	ft_bool = (ft_vectorA != ft_vectorB);
	std_bool = (vectorA != vectorB);
	if (ft_bool != std_bool) {
		handle_error(ft_vectorA, ft_vectorB, "vector", title, "[EQUAL]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_vectorA != ft_vectorC);
	std_bool = (vectorA != vectorC);
	if (ft_bool != std_bool) {
		handle_error(ft_vectorA, ft_vectorC, "vector", title, "[DIFF]", "CONTENT");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<]";
	std::cout << title;

	ft_bool = (ft_vectorC < ft_vectorA);
	std_bool = (vectorC < vectorA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA < ft_vectorC);
	std_bool = (vectorA < vectorC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA < ft_vectorB);
	std_bool = (vectorA < vectorB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
	}
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<=]";
	std::cout << title;

	ft_bool = (ft_vectorC <= ft_vectorA);
	std_bool = (vectorC <= vectorA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA <= ft_vectorC);
	std_bool = (vectorA <= vectorC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA <= ft_vectorB);
	std_bool = (vectorA <= vectorB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>]";
	std::cout << title;

	ft_bool = (ft_vectorC > ft_vectorA);
	std_bool = (vectorC > vectorA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA > ft_vectorC);
	std_bool = (vectorA > vectorC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA > ft_vectorB);
	std_bool = (vectorA > vectorB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>=]";
	std::cout << title;

	ft_bool = (ft_vectorC >= ft_vectorA);
	std_bool = (vectorC >= vectorA);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorC, ft_vectorA, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA >= ft_vectorC);
	std_bool = (vectorA >= vectorC);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorC, "vector", title, "", "CONTENT");
	}

	ft_bool = (ft_vectorA >= ft_vectorB);
	std_bool = (vectorA >= vectorB);
	if (ft_bool != std_bool) {
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
		handle_error(ft_vectorA, ft_vectorB, "vector", title, "", "CONTENT");
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[SWAP (non-member)]";
	std::cout << title;

	swap(ft_vectorA, ft_vectorC);
	swap(vectorA, vectorC);
	chk_result(ft_vectorA, vectorA, "vector", title, "[1/2]");
	chk_result(ft_vectorC, vectorC, "vector", title, "[2/2]");

	ft::Vector<int> ft_vectorEmpty;
	std::vector<int> vectorEmpty;
	swap(ft_vectorEmpty, ft_vectorC);
	swap(vectorEmpty, vectorC);
	chk_result(ft_vectorEmpty, vectorEmpty, "vector", title, "[EMPTY vs FULL] [1/2]");
	chk_result(ft_vectorC, vectorC, "vector", title, "[EMPTY vs FULL] [2/2]");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};
