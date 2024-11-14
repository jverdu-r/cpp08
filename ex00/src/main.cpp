/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:36:10 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/14 18:45:30 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "../inc/easyfind.hpp"

int main() 
{
    try 
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator vecIt = easyfind(vec, 3);
        std::cout << "Found in vector: " << *vecIt << std::endl;

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::list<int>::iterator lstIt = easyfind(lst, 20);
        std::cout << "Found in list: " << *lstIt << std::endl;

        easyfind(vec, 42);
    }
    catch (const std::exception& e)
    {
        std::cerr << "\033[31m" << "Exception: " << e.what() << "\033[0m" << std::endl;
    }
    return 0;
}