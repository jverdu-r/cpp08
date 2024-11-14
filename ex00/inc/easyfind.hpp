/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jverdu-r <jverdu-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:31:28 by jverdu-r          #+#    #+#             */
/*   Updated: 2024/11/14 18:39:51 by jverdu-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    for(typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return (it);
    }
    throw std::runtime_error("value not found in the container");
}
#endif