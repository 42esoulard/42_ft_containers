/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/19 17:13:41 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <iomanip>
#include <string>

#include <stack>

class customException;

            //----------------------------------------------//
           
           
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
                    //*\*/*\CONSTRUCTORS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
					
// int test_stack_constr() {
// 	std::string title = "[FILL CONSTRUCTOR]";
// 	std::cout << title;

// 	ft::List<char> ft_list(5, 'a');
// 	std::list<char> list(5, 'a');

// 	chk_result(ft_list, list, "list", title);

// 	ft::List<char> ft_listEmpty(0, 'a');
// 	std::list<char> listEmpty(0, 'a');

// 	chk_result(ft_list, list, "list", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_list_rangeConstr() {
// 	std::string title = "[RANGE CONSTRUCTOR]";
// 	std::cout << title;

// 	std::list<char> src(10, '!');
// 	src.push_back('@');
// 	src.push_front('&');
// 	ft::List<char> ft_list(src.begin(), src.end());
// 	std::list<char> list(src.begin(), src.end());

// 	chk_result(ft_list, list, "list", title);

// 	ft::List<char> ft_listEmpty(src.end(), src.end());
// 	std::list<char> listEmpty(src.end(), src.end());

// 	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };

// int test_list_copyConstr() {
// 	std::string title = "[COPY CONSTR]";
// 	std::cout << title;

// 	ft::List<char> ft_src(10, '!');
// 	ft_src.push_back('@');
// 	ft_src.push_front('&');

// 	std::list<char> src(10, '!');
// 	src.push_back('@');
// 	src.push_front('&');

// 	ft::List<char> ft_list(ft_src);
// 	std::list<char> list(src);

// 	chk_result(ft_list, list, "list", title);

// 	ft::List<char> ft_srcB(0, '!');
// 	std::list<char> srcB(0, '!');
// 	ft::List<char> ft_listEmpty(ft_srcB);
// 	std::list<char> listEmpty(srcB);

// 	chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

// 	//INVALID SRC = UNDEFINED BEHAVIOR
// 	// ft::List<char> *ft_nullSrc = nullptr;
// 	// ft::List<char> ft_listNull(*ft_nullSrc);
// 	// ft::List<char> *nullSrc = nullptr;
// 	// ft::List<char> listNull(*nullSrc)
// 	//	chk_result(ft_listNull, listNull, "list", "COPY CONSTRUCTOR [NULL SRC]");
	
// 	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
// 	return 0;
// };


            //----------------------------------------------//


                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
                    //*\*/*\MEMBER FUNCTIONS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///

int test_stack_empty() {
	// std::string title = "[EMPTY]";
	// std::cout << title;

	// ft::List<char> ft_list(5, '!');
	// std::list<char> list(5, '!');
	// ft::List<char>::iterator ft_it = ft_list.begin();
	// std::list<char>::iterator it = list.begin();
	// ft_it++;
	// it++;

	// ft_list.push_back('a');
	// ft_list.insert(ft_it, 'a');
	// ft_list.insert(ft_it, 'b');
	// list.push_back('a');
	// list.insert(it, 'a');
	// list.insert(it, 'b');
	// bool ft_empty = ft_list.empty();
	// bool std_empty = list.empty();
	// if (ft_empty != std_empty) {
	// 	std::cerr << "*ft_list.empty() = [" << *ft_it << "] | list.empty() = [" << *it << "]" << std::endl;
	// 	handle_error(ft_list, list, "list", title, "[FULL]", "CONTENT");
	// }
	
	// ft::List<char> ft_listEmpty;
	// std::list<char> listEmpty;
	// ft_listEmpty.empty();
	// listEmpty.empty();
	// ft_empty = ft_list.empty();
	// std_empty = list.empty();
	// if (ft_empty != std_empty) {
	// 	std::cerr << "*ft_list.empty() = [" << *ft_it << "] | list.empty() = [" << *it << "]" << std::endl;
	// 	handle_error(ft_list, list, "list", title, "[EMPTY]", "CONTENT");
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_stack_back() {
	// std::string title = "[BACK]";
	// std::cout << title;

	// ft::List<int> ft_list;
	// std::list<int> list;

	// ft_list.push_back(10);
	// ft_list.push_back(12);
	// ft_list.push_back(18);

	// list.push_back(10);
	// list.push_back(12);
	// list.push_back(18);

	// if (ft_list.front() != list.front() || ft_list.back() != list.back()) {
	// 	std::cerr << "ft_list.front() = [" << ft_list.front() << "] | list.front() = [" << list.front() << "]" << std::endl;
	// 	std::cerr << "ft_list.back() = [" << ft_list.back() << "] | list.back() = [" << list.back() << "]" << std::endl;
	// 	handle_error(ft_list, list, "list", title, "", "CONTENT");
	// }

	// ft::List<int> ft_listEmpty;
	// std::list<int> listEmpty;

	// if (ft_listEmpty.front() != listEmpty.front() || ft_listEmpty.back() != listEmpty.back()) {
	// 	std::cerr << "ft_listEmpty.front() = [" << ft_listEmpty.front() << "] | listEmpty.front() = [" << listEmpty.front() << "]" << std::endl;
	// 	std::cerr << "ft_listEmpty.back() = [" << ft_listEmpty.back() << "] | listEmpty.back() = [" << listEmpty.back() << "]" << std::endl;
	// 	handle_error(ft_listEmpty, listEmpty, "list", title, "[EMPTY]", "CONTENT");
	// }
	
	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	// title = "[FRONT/BACK CONST OVERLOAD]";
	// std::cout << title;

	// ft::List<int> const ft_constList;
	// std::list<int> const constList;

	// if (ft_constList.front() != constList.front() || ft_constList.back() != constList.back()) {
	// 	std::cerr << "ft_constList.front() = [" << ft_constList.front() << "] | constList.front() = [" << constList.front() << "]" << std::endl;
	// 	std::cerr << "ft_constList.back() = [" << ft_constList.back() << "] | constList.back() = [" << constList.back() << "]" << std::endl;
	// 	handle_error(ft_constList, constList, "list", title, "[CONST]", "CONTENT");
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_stack_pushBack() {
	// std::string title = "[BASIC INSTANCE + PUSH_BACK]";
	// std::cout << title;

	// ft::List<int> ft_list;
	// std::list<int> list;

	// ft_list.push_back(10);
	// ft_list.push_back(12);
	// ft_list.push_back(18);

	// list.push_back(10);
	// list.push_back(12);
	// list.push_back(18);

	// chk_result(ft_list, list, "list", title);

	// ft::List<char> ft_listEmpty;
	// ft_list.push_back('&');
	// std::list<char> listEmpty;
	// list.push_back('&');

	// chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");
	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	// title = "[BASIC ITERATING + DEREFERENCING]";
	// std::cout << title;

	// int tmp;
	// ft::List<int>::iterator it = ft_list.begin();
	// while (it != ft_list.end()) {
	// 	//std::cout << *it << std::endl; //commented to keep test output clean
	// 	tmp = *it;
	// 	it++;
	// }
	// chk_result(ft_list, list, "list", title);

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;

	// title = "[BASIC REVERSE ITERATING + DEREFERENCING]";
	// std::cout << title;

	// ft::List<int>::reverse_iterator rit = ft_list.rbegin();
	// while (rit != ft_list.rend()) {
	// 	//std::cout << *it << std::endl; //commented to keep test output clean
	// 	tmp = *rit;
	// 	rit++;
	// }
	// chk_result(ft_list, list, "list", title);

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
    return 0;
};


int test_stack_popBack() {
	// std::string title = "[POP_BACK]";
	// std::cout << title;

	// ft::List<char> ft_list(10, '!');
	// ft_list.push_back('@');
	// ft_list.push_back('&');
	// ft_list.push_front('z');

	// std::list<char> list(10, '!');
	// list.push_back('@');
	// list.push_back('&');
	// list.push_front('z');

	// ft_list.pop_back();
	// list.pop_back();
	// chk_result(ft_list, list, "list", title);

	// ft::List<char> ft_listEmpty;
	// ft_list.pop_back();
	// std::list<char> listEmpty;
	// list.pop_back();

	// chk_result(ft_listEmpty, listEmpty, "list", title, "[EMPTY]");

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

//*\*/*\/*\*/*\/*\*/*\/*\*///
///*\*/*\NON-MEMBERS/*\*/*\//
//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_stack_nonMembers() {
	// std::string title = "----[NON-MEMBER OPERATORS]----";
	// std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
	// title = "[OPERATOR==]";
	// std::cout << title;

	// ft::List<int> ft_listA;
	// std::list<int> listA;
	// ft_listA.push_back(0);
	// ft_listA.push_back(2145678);
	// ft_listA.push_back(-70);
	// ft_listA.push_back(42);
	// listA.push_back(0);
	// listA.push_back(2145678);
	// listA.push_back(-70);
	// listA.push_back(42);
	// ft::List<int> ft_listB;
	// std::list<int> listB;
	// ft_listB.push_back(0);
	// ft_listB.push_back(2145678);
	// ft_listB.push_back(-70);
	// ft_listB.push_back(42);
	// listB.push_back(0);
	// listB.push_back(2145678);
	// listB.push_back(-70);
	// listB.push_back(42);

	// bool ft_bool = (ft_listA == ft_listB);
	// bool std_bool = (listA == listB);
	// if (ft_bool != std_bool) {
	// 	handle_error(ft_listA, ft_listB, "list", title, "[EQUAL]", "CONTENT");
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// }

	// ft::List<int> ft_listC;
	// std::list<int> listC;
	// ft_listC.push_back(0);
	// ft_listC.push_back(666);
	// //ft_listC.push_back(-70);
	// ft_listC.push_back(42);
	// listC.push_back(0);
	// listC.push_back(666);
	// //listC.push_back(-70);
	// listC.push_back(42);

	// ft_bool = (ft_listA == ft_listC);
	// std_bool = (listA == listC);
	// if (ft_bool != std_bool) {
	// 	handle_error(ft_listA, ft_listC, "list", title, "[DIFF]", "CONTENT");
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	// //------------------------------------------------------------------------

	// title = "[OPERATOR!=]";
	// std::cout << title;

	// ft_bool = (ft_listA != ft_listB);
	// std_bool = (listA != listB);
	// if (ft_bool != std_bool) {
	// 	handle_error(ft_listA, ft_listB, "list", title, "[EQUAL]", "CONTENT");
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// }

	// ft_bool = (ft_listA != ft_listC);
	// std_bool = (listA != listC);
	// if (ft_bool != std_bool) {
	// 	handle_error(ft_listA, ft_listC, "list", title, "[DIFF]", "CONTENT");
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	// //------------------------------------------------------------------------

	// title = "[OPERATOR<]";
	// std::cout << title;

	// ft_bool = (ft_listC < ft_listA);
	// std_bool = (listC < listA);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA < ft_listC);
	// std_bool = (listA < listC);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA < ft_listB);
	// std_bool = (listA < listB);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	// }
	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	// //------------------------------------------------------------------------

	// title = "[OPERATOR<=]";
	// std::cout << title;

	// ft_bool = (ft_listC <= ft_listA);
	// std_bool = (listC <= listA);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA <= ft_listC);
	// std_bool = (listA <= listC);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA <= ft_listB);
	// std_bool = (listA <= listB);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	// //------------------------------------------------------------------------

	// title = "[OPERATOR>]";
	// std::cout << title;

	// ft_bool = (ft_listC > ft_listA);
	// std_bool = (listC > listA);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA > ft_listC);
	// std_bool = (listA > listC);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA > ft_listB);
	// std_bool = (listA > listB);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	// //------------------------------------------------------------------------

	// title = "[OPERATOR>=]";
	// std::cout << title;

	// ft_bool = (ft_listC >= ft_listA);
	// std_bool = (listC >= listA);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listC, ft_listA, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA >= ft_listC);
	// std_bool = (listA >= listC);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listC, "list", title, "", "CONTENT");
	// }

	// ft_bool = (ft_listA >= ft_listB);
	// std_bool = (listA >= listB);
	// if (ft_bool != std_bool) {
	// 	std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	// 	handle_error(ft_listA, ft_listB, "list", title, "", "CONTENT");
	// }

	// std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

