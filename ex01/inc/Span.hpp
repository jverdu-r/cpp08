/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:04:37 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/18 15:32:55 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int> _vector;
        const unsigned int _size;
        Span(void);
        Span &operator=(const Span &origin);
        
    public:
        Span(unsigned int size);
        Span(const Span &origin);
        ~Span(void);
        int shortestSpan(void) const;
        int longestSpan(void) const;
        void addNumber(int n);

        template<typename T>
        void addNumbers(T init, T end)
        {
            while(init < end)
            {
                this->addNumber(*init);
                init++;
            }
        };

        class BadSpanSize : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Span has only 0 or 1 elements");
            };
        };
        class FullSpan : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Span is actually full");
            };
        };
};
#endif