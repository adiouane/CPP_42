/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:46:25 by adiouane          #+#    #+#             */
/*   Updated: 2023/04/03 02:26:05 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>  // for std::cout, std::endl
#include <string>    // for std::string
#include <vector>    // for std::vector
#include <fstream>   // for std::ifstream
#include <algorithm> // for std::lower_bound
#include <deque>     // for std::deque
#include <time.h>    // for clock_t, clock, CLOCKS_PER_SEC

void ProgramMe_vector(std::vector<int> &v);
void ProgramMe_deque(std::deque<int> &v);

#endif
