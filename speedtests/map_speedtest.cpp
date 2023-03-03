/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_speedtest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:00:43 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 12:17:58 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef IS_STD
# define IS_STD 0
#endif

#if IS_STD == 1
	#include <map>
	namespace ft = std;
#else
	#include "../include/Containers/map.hpp"
#endif

int main( void )
{
	ft::map<int, char>				testedMap;
	ft::map<int, char>::iterator	it, ite;

	size_t				numberOfPushes = 200;

	for (size_t i = 0; i < numberOfPushes; i++)
		testedMap.insert(ft::make_pair(i, 'a'));
	it = testedMap.begin();
	ite = testedMap.end();
	while (it != ite)
	{
		it++;
	}
	testedMap.clear();
	return 0;
}