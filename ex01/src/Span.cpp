/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:31:25 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/18 16:10:56 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(void): _size(0){};

Span& Span::operator=(const Span &origin)
{
    this->_vector = origin._vector;
    return (*this);
}

Span::Span(unsigned int size): _size(size) {};

Span::Span(const Span &origin): _size(origin._size)
{
    *this = origin;
}

Span::~Span(void) {};

int Span::shortestSpan(void) const
{
    if (this->_vector.size() <= 1)
        throw(BadSpanSize());
    int ret;
    std::vector<int> aux;

    ret = abs(this->_vector[0] - this->_vector[1]);
    aux = this->_vector;
    std::sort(aux.begin(), aux.end());
    for (std::vector<int>::const_iterator it = ++(aux.begin()); it < aux.end(); it++)
    {
        ret = std::min(ret, abs(*it - *(it -1)));
    }
    return (ret);
}

static int vectorMax(std::vector<int> v)
{
    if (v.size() == 0)
        throw;
    int max = v[0];
     for (std::vector<int>::const_iterator it = ++(v.begin()); it < v.end(); it++)
     {
        max = std::max(max, *it);
     }
     return(max);
}

static int vectorMin(std::vector<int> v)
{
    if (v.size() == 0)
        throw;
    int min = v[0];
     for (std::vector<int>::const_iterator it = ++(v.begin()); it < v.end(); it++)
     {
        min = std::min(min, *it);
     }
     return(min);
}

int Span::longestSpan(void) const
{
    if (this->_vector.size() <= 1)
        throw(BadSpanSize());
    return (vectorMax(this->_vector) - vectorMin(this->_vector));
}
void Span::addNumber(int n)
{
    if (this->_vector.size() == this->_size)
        throw (FullSpan());
    this->_vector.push_back(n);
}