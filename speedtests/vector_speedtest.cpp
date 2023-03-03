/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_speedtest.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:00:48 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 12:18:06 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <cstdlib>
#include <iostream>

#ifndef IS_STD
# define IS_STD 0
#endif

#if IS_STD == 1
	#include <vector>
	namespace ft = std;
#else
	#include "../include/Containers/vector.hpp"
#endif

int	main( void )
{
	ft::vector<int>	testedVector;
	size_t			numberOfPushes = 1000;

	for (size_t i = 0; i < numberOfPushes; i++)
		testedVector.insert(testedVector.begin(), i);
	testedVector.clear();
	return 0;
}