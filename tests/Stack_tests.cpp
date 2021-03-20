/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/20 12:28:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <iomanip>
#include <string>

#include <list>
#include <vector>
#include <stack>

class customException;

            //-------------------------------------------//
           
           
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
                    //*\*/*\CONSTRUCTORS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
					
int test_stack_constr_size() {
	std::string title = "[CONSTRUCTOR + SIZE]";
	std::cout << title;
	
	size_t sz = 3;
	ft::List<int> ft_list (sz,100);
	std::list<int> std_list (sz,100);
	sz = 2;
	ft::Vector<int> ft_vector (sz,200); 
	std::vector<int> std_vector (sz,200); 

	ft::Stack<int> ft_firstStack;  
	std::stack<int,std::list<int> > std_firstStack;
	/* I set my Stack default container as List cuz I didn't do deque 
	but u might have made another choice and THAT'S OK <3 */

	if (ft_firstStack.size() != std_firstStack.size())
		handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "", "SIZE");
	// if ((ft_firstStack.top() && std_firstStack.top()) && ft_firstStack.top() != std_firstStack.top())
	// 	handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "", "BACK");

	ft::Stack<int> ft_secondStack(ft_list); 
	std::stack<int,std::list<int> > std_secondStack(std_list); 

	if (ft_secondStack.size() != std_secondStack.size())
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "", "SIZE");
	if ((ft_secondStack.top() && std_secondStack.top()) && ft_secondStack.top() != std_secondStack.top()) 
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "", "BACK");

	ft::Stack<int,ft::Vector<int> > ft_thirdStack;
	std::stack<int,std::vector<int> > std_thirdStack;

	if (ft_thirdStack.size() != std_thirdStack.size())
		handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "", "SIZE");
	// if ((ft_thirdStack.top() && std_thirdStack.top()) && ft_thirdStack.top() != std_thirdStack.top())
	// 	handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "", "BACK");
	
	ft::Stack<int,ft::Vector<int> > ft_fourthStack (ft_vector);
	std::stack<int,std::vector<int> > std_fourthStack (std_vector);

	if (ft_fourthStack.size() != std_fourthStack.size())
		handle_stack_error(ft_fourthStack, std_fourthStack, "stack", title, "", "SIZE");
	if ((ft_fourthStack.top() && std_fourthStack.top()) && ft_fourthStack.top() != std_fourthStack.top())
		handle_stack_error(ft_fourthStack, std_fourthStack, "stack", title, "", "BACK");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

            //----------------------------------------------//


                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
                    //*\*/*\MEMBER FUNCTIONS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///

int test_stack_empty() {
	std::string title = "[EMPTY]";
	std::cout << title;
	
	size_t sz = 3;
	ft::List<int> ft_list (sz,100);
	std::list<int> std_list (sz,100);
	sz = 2;
	ft::Vector<int> ft_vector (sz,200); 
	std::vector<int> std_vector (sz,200); 

	ft::Stack<int> ft_firstStack;  
	std::stack<int,std::list<int> > std_firstStack;
	/* I set my Stack default container as List cuz I didn't do deque 
	but u might have made another choice and THAT'S OK <3 */

	if (ft_firstStack.empty() != std_firstStack.empty())
		handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "", "empty");

	ft::Stack<int> ft_secondStack(ft_list); 
	std::stack<int,std::list<int> > std_secondStack(std_list); 

	if (ft_secondStack.empty() != std_secondStack.empty())
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "", "empty");

	ft::Stack<int,ft::Vector<int> > ft_thirdStack;
	std::stack<int,std::vector<int> > std_thirdStack;

	if (ft_thirdStack.empty() != std_thirdStack.empty())
		handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "", "empty");
	
	ft::Stack<int,ft::Vector<int> > ft_fourthStack (ft_vector);
	std::stack<int,std::vector<int> > std_fourthStack (std_vector);

	if (ft_fourthStack.empty() != std_fourthStack.empty())
		handle_stack_error(ft_fourthStack, std_fourthStack, "stack", title, "", "empty");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_stack_top_push_pop() {
	std::string title = "[TOP/PUSH/POP]";
	std::cout << title;

	size_t sz = 3;
	ft::List<int> ft_list (sz,100);
	std::list<int> std_list (sz,100);
	sz = 2;
	ft::Vector<int> ft_vector (sz,200); 
	std::vector<int> std_vector (sz,200); 

	ft::Stack<int> ft_firstStack(ft_list); 
	std::stack<int,std::list<int> > std_firstStack(std_list); 

	if (ft_firstStack.top() != std_firstStack.top())
		handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "list stack after constr", "");

	ft_firstStack.push(42);
	std_firstStack.push(42);

	if (ft_firstStack.top() != std_firstStack.top())
		handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "list stack after push", "");

	ft_firstStack.push(6);
	std_firstStack.push(6);

	if (ft_firstStack.top() != std_firstStack.top())
		handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "list stack after push", "");

	ft_firstStack.push(1337);
	std_firstStack.push(1337);

	if (ft_firstStack.top() != std_firstStack.top())
		handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "list stack after push", "");

	for (size_t i = 0; i < std_firstStack.size(); i++) {
		ft_firstStack.pop();
		std_firstStack.pop();

		if (ft_firstStack.top() != std_firstStack.top())
			handle_stack_error(ft_firstStack, std_firstStack, "stack", title, "list stack after pop", "");
	}
	ft_firstStack.pop();
	std_firstStack.pop();
	//UNDEFINED
	// ft_firstStack.pop();
	// std_firstStack.pop();
	// ft_firstStack.pop();
	// std_firstStack.pop();
	
	ft::Stack<int,ft::Vector<int> > ft_secondStack (ft_vector);
	std::stack<int,std::vector<int> > std_secondStack (std_vector);

	if (ft_secondStack.top() != std_secondStack.top())
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "vector stack after constr", "");

	ft_secondStack.push(42);
	std_secondStack.push(42);

	if (ft_secondStack.top() != std_secondStack.top())
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "vector stack after push", "");

	ft_secondStack.push(6);
	std_secondStack.push(6);

	if (ft_secondStack.top() != std_secondStack.top())
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "vector stack after push", "");

	ft_secondStack.push(1337);
	std_secondStack.push(1337);

	if (ft_secondStack.top() != std_secondStack.top())
		handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "vector stack after push", "");

	for (size_t i = 0; i < std_secondStack.size(); i++) {
		ft_secondStack.pop();
		std_secondStack.pop();

		if (ft_secondStack.top() != std_secondStack.top())
			handle_stack_error(ft_secondStack, std_secondStack, "stack", title, "vector stack after pop", "");
	}
	ft_firstStack.pop();
	std_firstStack.pop();

	ft::Stack<int,ft::Vector<int> > ft_thirdStack;
	std::stack<int,std::vector<int> > std_thirdStack;

	ft_thirdStack.push(1337);
	std_thirdStack.push(1337);

	if (ft_thirdStack.size() != std_thirdStack.size())
		handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "empty vector stack after push", "SIZE");
	if (ft_thirdStack.top() != std_thirdStack.top())
		handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "empty vector stack after push", "");

	ft_thirdStack.push(42);
	std_thirdStack.push(42);
	ft_thirdStack.push(42);
	std_thirdStack.push(42);
	ft_thirdStack.push(42);
	std_thirdStack.push(42);
	ft_thirdStack.push(443);
	std_thirdStack.push(443);

	if (ft_thirdStack.size() != std_thirdStack.size())
		handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "empty vector stack after push", "SIZE");
	if (ft_thirdStack.top() != std_thirdStack.top())
		handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "empty vector stack after push", "");

	for (size_t i = 0; i < std_thirdStack.size(); i++) {
		ft_thirdStack.pop();
		std_thirdStack.pop();

		if (ft_thirdStack.top() != std_thirdStack.top())
			handle_stack_error(ft_thirdStack, std_thirdStack, "stack", title, "vector stack after pop", "");
	}
	ft_firstStack.pop();
	std_firstStack.pop();

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};


            //----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\NON-MEMBERS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_stack_nonMembers() {
	std::string title = "----[NON-MEMBER OPERATORS]----";
	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
	title = "[OPERATOR==]";
	std::cout << title;

	ft::Stack<int,ft::Vector<int> > ft_stackA;
	std::stack<int,std::vector<int> > std_stackA;
	ft_stackA.push(0);
	ft_stackA.push(2145678);
	ft_stackA.push(-70);
	ft_stackA.push(42);
	std_stackA.push(0);
	std_stackA.push(2145678);
	std_stackA.push(-70);
	std_stackA.push(42);
	ft::Stack<int,ft::Vector<int> > ft_stackB;
	std::stack<int,std::vector<int> > std_stackB;
	ft_stackB.push(0);
	ft_stackB.push(2145678);
	ft_stackB.push(-70);
	ft_stackB.push(42);
	std_stackB.push(0);
	std_stackB.push(2145678);
	std_stackB.push(-70);
	std_stackB.push(42);

	bool ft_bool = (ft_stackA == ft_stackB);
	bool std_bool = (std_stackA == std_stackB);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft::Stack<int,ft::Vector<int> > ft_stackC;
	std::stack<int,std::vector<int> > std_stackC;
	ft_stackC.push(0);
	ft_stackC.push(666);
	ft_stackC.push(-70);
	ft_stackC.push(42);
	std_stackC.push(0);
	std_stackC.push(666);
	std_stackC.push(-70);
	std_stackC.push(42);

	ft_bool = (ft_stackA == ft_stackC);
	std_bool = (std_stackA == std_stackC);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR!=]";
	std::cout << title;

	ft_bool = (ft_stackA != ft_stackB);
	std_bool = (std_stackA != std_stackB);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA != ft_stackC);
	std_bool = (std_stackA != std_stackC);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<]";
	std::cout << title;

	ft_bool = (ft_stackC < ft_stackA);
	std_bool = (std_stackC < std_stackA);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA < ft_stackC);
	std_bool = (std_stackA < std_stackC);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA < ft_stackB);
	std_bool = (std_stackA < std_stackB);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<=]";
	std::cout << title;

	ft_bool = (ft_stackC <= ft_stackA);
	std_bool = (std_stackC <= std_stackA);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA <= ft_stackC);
	std_bool = (std_stackA <= std_stackC);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA <= ft_stackB);
	std_bool = (std_stackA <= std_stackB);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>]";
	std::cout << title;

	ft_bool = (ft_stackC > ft_stackA);
	std_bool = (std_stackC > std_stackA);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA > ft_stackC);
	std_bool = (std_stackA > std_stackC);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA > ft_stackB);
	std_bool = (std_stackA > std_stackB);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>=]";
	std::cout << title;

	ft_bool = (ft_stackC >= ft_stackA);
	std_bool = (std_stackC >= std_stackA);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA >= ft_stackC);
	std_bool = (std_stackA >= std_stackC);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_stackA >= ft_stackB);
	std_bool = (std_stackA >= std_stackB);
	if (ft_bool != std_bool) {
		handle_stack_error(ft_stackA, std_stackA, "stack", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

