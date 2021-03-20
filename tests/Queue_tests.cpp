/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:47:13 by esoulard          #+#    #+#             */
/*   Updated: 2021/03/20 17:19:01 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <iomanip>
#include <string>

#include <list>
#include <vector>
#include <queue>

class customException;

            //-------------------------------------------//
           
           
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
                    //*\*/*\CONSTRUCTORS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*///
					
int test_queue_constr_size() {
	std::string title = "[CONSTRUCTOR + SIZE]";
	std::cout << title;
	
	size_t sz = 3;
	ft::List<int> ft_list (sz,100);
	std::list<int> std_list (sz,100);
	sz = 2;
	ft::Vector<int> ft_vector (sz,200); 
	std::vector<int> std_vector (sz,200); 

	ft::Queue<int> ft_firstQueue;  
	std::queue<int,std::list<int> > std_firstQueue;
	/* I set my Queue default container as List cuz I didn't do deque 
	but u might have made another choice and THAT'S OK <3 */

	if (ft_firstQueue.size() != std_firstQueue.size())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "", "SIZE");
	// if ((ft_firstQueue.top() && std_firstQueue.top()) && ft_firstQueue.top() != std_firstQueue.top())
	// 	handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "", "BACK");

	ft::Queue<int> ft_secondQueue(ft_list); 
	std::queue<int,std::list<int> > std_secondQueue(std_list); 

	if (ft_secondQueue.size() != std_secondQueue.size())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "", "SIZE");
	if ((ft_secondQueue.front() && std_secondQueue.front()) && ft_secondQueue.front() != std_secondQueue.front()) 
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "", "FRONT");
	if ((ft_secondQueue.back() && std_secondQueue.back()) && ft_secondQueue.back() != std_secondQueue.back()) 
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "", "BACK");

	ft::Queue<int,ft::Vector<int> > ft_thirdQueue;
	std::queue<int,std::vector<int> > std_thirdQueue;

	if (ft_thirdQueue.size() != std_thirdQueue.size())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "", "SIZE");
	// if ((ft_thirdQueue.top() && std_thirdQueue.top()) && ft_thirdQueue.top() != std_thirdQueue.top())
	// 	handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "", "BACK");
	
	ft::Queue<int,ft::Vector<int> > ft_fourthQueue (ft_vector);
	std::queue<int,std::vector<int> > std_fourthQueue (std_vector);

	if (ft_fourthQueue.size() != std_fourthQueue.size())
		handle_queue_error(ft_fourthQueue, std_fourthQueue, "queue", title, "", "SIZE");
	if ((ft_fourthQueue.front() && std_fourthQueue.front()) && ft_fourthQueue.front() != std_fourthQueue.front())
		handle_queue_error(ft_fourthQueue, std_fourthQueue, "queue", title, "", "FRONT");
	if ((ft_fourthQueue.back() && std_fourthQueue.back()) && ft_fourthQueue.back() != std_fourthQueue.back())
		handle_queue_error(ft_fourthQueue, std_fourthQueue, "queue", title, "", "BACK");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

            //----------------------------------------------//


                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///
                    //*\*/*\MEMBER FUNCTIONS/*\*/*\//
                    //*\*/*\/*\*/*\/*\*/*\/*\*/*\*///

int test_queue_empty() {
	std::string title = "[EMPTY]";
	std::cout << title;
	
	size_t sz = 3;
	ft::List<int> ft_list (sz,100);
	std::list<int> std_list (sz,100);
	sz = 2;
	ft::Vector<int> ft_vector (sz,200); 
	std::vector<int> std_vector (sz,200); 

	ft::Queue<int> ft_firstQueue;  
	std::queue<int,std::list<int> > std_firstQueue;
	/* I set my Queue default container as List cuz I didn't do deque 
	but u might have made another choice and THAT'S OK <3 */

	if (ft_firstQueue.empty() != std_firstQueue.empty())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "", "empty");

	ft::Queue<int> ft_secondQueue(ft_list); 
	std::queue<int,std::list<int> > std_secondQueue(std_list); 

	if (ft_secondQueue.empty() != std_secondQueue.empty())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "", "empty");

	ft::Queue<int,ft::Vector<int> > ft_thirdQueue;
	std::queue<int,std::vector<int> > std_thirdQueue;

	if (ft_thirdQueue.empty() != std_thirdQueue.empty())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "", "empty");
	
	ft::Queue<int,ft::Vector<int> > ft_fourthQueue (ft_vector);
	std::queue<int,std::vector<int> > std_fourthQueue (std_vector);

	if (ft_fourthQueue.empty() != std_fourthQueue.empty())
		handle_queue_error(ft_fourthQueue, std_fourthQueue, "queue", title, "", "empty");

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

int test_queue_top_push_pop() {
	std::string title = "[FRONT/BACK/PUSH(back)/POP(front)]";
	std::cout << title;

	size_t sz = 3;
	ft::List<int> ft_list (sz,100);
	std::list<int> std_list (sz,100);
	sz = 2;
	ft::List<int> ft_listA (sz,200); 
	std::list<int> std_listA (sz,200); 

	ft::Queue<int> ft_firstQueue(ft_list); 
	std::queue<int,std::list<int> > std_firstQueue(std_list); 

	if (ft_firstQueue.front() != std_firstQueue.front())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after constr", "front");
	if (ft_firstQueue.back() != std_firstQueue.back())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after constr", "back");

	ft_firstQueue.push(42);
	std_firstQueue.push(42);

	if (ft_firstQueue.front() != std_firstQueue.front())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after push", "front");
	if (ft_firstQueue.back() != std_firstQueue.back())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after push", "back");

	ft_firstQueue.push(6);
	std_firstQueue.push(6);

	if (ft_firstQueue.front() != std_firstQueue.front())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after push", "front");
	if (ft_firstQueue.back() != std_firstQueue.back())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after push", "back");

	ft_firstQueue.push(1337);
	std_firstQueue.push(1337);

	if (ft_firstQueue.front() != std_firstQueue.front())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after push", "front");
	if (ft_firstQueue.back() != std_firstQueue.back())
		handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after push", "back");

	for (size_t i = 0; i < std_firstQueue.size(); i++) {
		ft_firstQueue.pop();
		std_firstQueue.pop();

		if (ft_firstQueue.front() != std_firstQueue.front())
			handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after pop", "front");
		if (ft_firstQueue.back() != std_firstQueue.back())
			handle_queue_error(ft_firstQueue, std_firstQueue, "queue", title, "list queue after pop", "back");
	}
	ft_firstQueue.pop();
	std_firstQueue.pop();
	//UNDEFINED
	// ft_firstQueue.pop();
	// std_firstQueue.pop();
	// ft_firstQueue.pop();
	// std_firstQueue.pop();
	
	ft::Queue<int,ft::List<int> > ft_secondQueue (ft_listA);
	std::queue<int,std::list<int> > std_secondQueue (std_listA);

	if (ft_secondQueue.front() != std_secondQueue.front())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after constr", "front");
	if (ft_secondQueue.back() != std_secondQueue.back())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after constr", "back");

	ft_secondQueue.push(42);
	std_secondQueue.push(42);

	if (ft_secondQueue.front() != std_secondQueue.front())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after push", "front");
	if (ft_secondQueue.back() != std_secondQueue.back())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after push", "back");

	ft_secondQueue.push(6);
	std_secondQueue.push(6);

	if (ft_secondQueue.front() != std_secondQueue.front())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after push", "front");
	if (ft_secondQueue.back() != std_secondQueue.back())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after push", "back");

	ft_secondQueue.push(1337);
	std_secondQueue.push(1337);

	if (ft_secondQueue.front() != std_secondQueue.front())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after push", "front");
	if (ft_secondQueue.back() != std_secondQueue.back())
		handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after push", "back");

	for (size_t i = 0; i < std_secondQueue.size(); i++) {
		// ft_secondQueue.pop();
		// std_secondQueue.pop();

		if (ft_secondQueue.front() != std_secondQueue.front())
			handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after pop", "front");
		if (ft_secondQueue.back() != std_secondQueue.back())
			handle_queue_error(ft_secondQueue, std_secondQueue, "queue", title, "vector queue after pop", "back");

	}
	ft_firstQueue.pop();
	std_firstQueue.pop();

	ft::Queue<int,ft::List<int> > ft_thirdQueue;
	std::queue<int,std::list<int> > std_thirdQueue;

	ft_thirdQueue.push(1337);
	std_thirdQueue.push(1337);

	if (ft_thirdQueue.size() != std_thirdQueue.size())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after push", "SIZE");
	if (ft_thirdQueue.front() != std_thirdQueue.front())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after push", "");
	if (ft_thirdQueue.back() != std_thirdQueue.back())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after push", "back");

	ft_thirdQueue.push(42);
	std_thirdQueue.push(42);
	ft_thirdQueue.push(42);
	std_thirdQueue.push(42);
	ft_thirdQueue.push(42);
	std_thirdQueue.push(42);
	ft_thirdQueue.push(443);
	std_thirdQueue.push(443);

	if (ft_thirdQueue.size() != std_thirdQueue.size())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after push", "SIZE");
	if (ft_thirdQueue.front() != std_thirdQueue.front())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after push", "");
	if (ft_thirdQueue.back() != std_thirdQueue.back())
		handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after push", "back");

	for (size_t i = 0; i < std_thirdQueue.size(); i++) {
		ft_thirdQueue.pop();
		std_thirdQueue.pop();

		if (ft_thirdQueue.front() != std_thirdQueue.front())
			handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after pop", "");
		if (ft_thirdQueue.back() != std_thirdQueue.back())
			handle_queue_error(ft_thirdQueue, std_thirdQueue, "queue", title, "empty vector queue after pop", "back");

	}
	ft_firstQueue.pop();
	std_firstQueue.pop();

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};


            //----------------------------------------------//


					//*\*/*\/*\*/*\/*\*/*\/*\*///
					///*\*/*\NON-MEMBERS/*\*/*\//
					//*\*/*\/*\*/*\/*\*/*\/*\*///

int test_queue_nonMembers() {
	std::string title = "----[NON-MEMBER OPERATORS]----";
	std::cout << std::string((WIDTH - title.size())/2, ' ') << title << std::endl;
	title = "[OPERATOR==]";
	std::cout << title;

	ft::Queue<int,ft::Vector<int> > ft_queueA;
	std::queue<int,std::vector<int> > std_queueA;
	ft_queueA.push(0);
	ft_queueA.push(2145678);
	ft_queueA.push(-70);
	ft_queueA.push(42);
	std_queueA.push(0);
	std_queueA.push(2145678);
	std_queueA.push(-70);
	std_queueA.push(42);
	ft::Queue<int,ft::Vector<int> > ft_queueB;
	std::queue<int,std::vector<int> > std_queueB;
	ft_queueB.push(0);
	ft_queueB.push(2145678);
	ft_queueB.push(-70);
	ft_queueB.push(42);
	std_queueB.push(0);
	std_queueB.push(2145678);
	std_queueB.push(-70);
	std_queueB.push(42);

	bool ft_bool = (ft_queueA == ft_queueB);
	bool std_bool = (std_queueA == std_queueB);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft::Queue<int,ft::Vector<int> > ft_queueC;
	std::queue<int,std::vector<int> > std_queueC;
	ft_queueC.push(0);
	ft_queueC.push(666);
	ft_queueC.push(-70);
	ft_queueC.push(42);
	std_queueC.push(0);
	std_queueC.push(666);
	std_queueC.push(-70);
	std_queueC.push(42);

	ft_bool = (ft_queueA == ft_queueC);
	std_bool = (std_queueA == std_queueC);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR!=]";
	std::cout << title;

	ft_bool = (ft_queueA != ft_queueB);
	std_bool = (std_queueA != std_queueB);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA != ft_queueC);
	std_bool = (std_queueA != std_queueC);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<]";
	std::cout << title;

	ft_bool = (ft_queueC < ft_queueA);
	std_bool = (std_queueC < std_queueA);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA < ft_queueC);
	std_bool = (std_queueA < std_queueC);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA < ft_queueB);
	std_bool = (std_queueA < std_queueB);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR<=]";
	std::cout << title;

	ft_bool = (ft_queueC <= ft_queueA);
	std_bool = (std_queueC <= std_queueA);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA <= ft_queueC);
	std_bool = (std_queueA <= std_queueC);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA <= ft_queueB);
	std_bool = (std_queueA <= std_queueB);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}
	
	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>]";
	std::cout << title;

	ft_bool = (ft_queueC > ft_queueA);
	std_bool = (std_queueC > std_queueA);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA > ft_queueC);
	std_bool = (std_queueA > std_queueC);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA > ft_queueB);
	std_bool = (std_queueA > std_queueB);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	//------------------------------------------------------------------------

	title = "[OPERATOR>=]";
	std::cout << title;

	ft_bool = (ft_queueC >= ft_queueA);
	std_bool = (std_queueC >= std_queueA);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA >= ft_queueC);
	std_bool = (std_queueA >= std_queueC);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	ft_bool = (ft_queueA >= ft_queueB);
	std_bool = (std_queueA >= std_queueB);
	if (ft_bool != std_bool) {
		handle_queue_error(ft_queueA, std_queueA, "queue", title, "bad bool", "");
		std::cerr << "Should return <" << std_bool << "> but returned <" << ft_bool << ">" << std::endl;
	}

	std::cout << std::setfill('.') << std::setw(WIDTH - title.size()) << " ✓" << std::endl;
	return 0;
};

