/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:46:19 by adiouane          #+#    #+#             */
/*   Updated: 2023/04/02 03:35:55 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    std::vector<int> v;
    std::deque<int> d;

    for (int i = 1; i < argc; i++)
        if (isdigit(argv[i][0]) == 0)
        {
            std::cout << "Error: Invalid argument" << std::endl;
            return (1);
        }

    for (int i = 1; i < argc; i++)
        v.push_back(atoi(argv[i]));

    for (int i = 1; i < argc; i++)
        d.push_back(atoi(argv[i]));

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    clock_t start, end;
    start = clock();
    ProgramMe_vector(v);
    end = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of 5 elements with std::vector " << cpu_time_used << " us" << std::endl;
    start = clock();
    ProgramMe_deque(d);
    end = clock();
    std::cout << "Time to process a range of 5 elements with std::deque: " << cpu_time_used << " us" << std::endl;
    return 0;
}