/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:08:32 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/18 17:32:13 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:

    public:
        typedef typename std::deque<T>::iterator iterator;

        MutantStack(void): std::stack<T>() {}

        MutantStack(const MutantStack<T> &origin) : std::stack<T>(origin)
        {
            if (this != &origin) 
            {
                this->std::stack<T>::operator=(origin);
            }
        }

        ~MutantStack(void) {};

        MutantStack &operator=(const MutantStack<T> &origin)
        {
            this->std::stack<T>::operator=(origin);
            return (*this);
        }

        iterator begin(void)
        {
            return (this->c.begin());
        }

        iterator end(void)
        {
            return (this->c.end());
        }

};
#endif