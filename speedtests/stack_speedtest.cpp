/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_speedtest.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:00:46 by estarck           #+#    #+#             */
/*   Updated: 2023/03/02 12:18:01 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <cstdlib>

#ifndef IS_STD
# define IS_STD 0
#endif

#if IS_STD == 1
	#include <stack>
	namespace ft = std;
#else
	#include "../include/Containers/stack.hpp"
#endif

int	main( void )
{
	ft::stack<int>	testedStack;
	int				numberOfPushes = 1000;

	for (int i = 0; i < numberOfPushes; i++)
		testedStack.push(i);
	for (int i = 0; i < numberOfPushes; i++)
		testedStack.pop();
	return 0;
}
