#include <list>
#include <vector>
// #include "includes/containers/List.hpp"
#include <iostream>

int main() {

    std::vector<int> vectorEmpty;
    vectorEmpty.reserve(2);

    int i = 0;
    while (i < 100) {
        std::cout << "Size:" << vectorEmpty.size() << " // Capacity: " << vectorEmpty.capacity() << std::endl;
        vectorEmpty.reserve(12);
        vectorEmpty.push_back(1);
        i++;
    }




    // std::list<char> test(5, 'a');
    // test.push_back('!');

    // std::list<char>::iterator it = test.begin();
    // int i = 0;
    // while (i++ < 20) {
    //     std::cout << *it << std::endl;
    //     it++;
    // }
    // std::cout << "-------ite------" << std::endl;
    // std::cout << *(test.end()) << std::endl;

    // ft::List<char> ft_test(5, 'a');
    // ft_test.push_back('!');

    // std::cout << "---------------FT--------------" << std::endl;

    // ft::List<char>::iterator ft_it = ft_test.begin();
    // i = 0;
    // while (i++ < 20) {
    //     std::cout << *ft_it << std::endl;
    //     ft_it++;
    // }
    // std::cout << "-------ft_ite------" << std::endl;
    // std::cout << *(ft_test.end()) << std::endl;


    // std::list<char> testa;

    // std::list<char>::iterator ita = testa.begin();
    // i = 0;
    // while (i++ < 20) {
    //     std::cout << *ita << std::endl;
    //     ita++;
    // }
    // std::cout << "-------ite------" << std::endl;
    // std::cout << *(testa.end()) << std::endl;

    return 0;
}