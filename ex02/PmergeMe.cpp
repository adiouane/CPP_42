/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:46:23 by adiouane          #+#    #+#             */
/*   Updated: 2023/04/03 02:26:26 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void ProgramMe_vector(std::vector<int> &v)
{
    if (v.size() > 1)
    {
        std::vector<int> left;
        std::vector<int> right;

        int mid = v.size() / 2;
        for (int i = 0; i < mid; i++)
            left.push_back(v[i]);

        for (size_t i = mid; i < v.size(); i++)
            right.push_back(v[i]);

        for (size_t i = 1; i < left.size(); i++)
        {
            int j = i;
            while (j > 0 && left[j] < left[j - 1])
            {
                std::swap(left[j], left[j - 1]);
                j--;
            }
        }

        for (size_t i = 0; i < right.size(); i++)
        {
            std::vector<int>::iterator it = std::lower_bound(left.begin(), left.end(), right[i]);
            left.insert(it, right[i]);
        }

        for (size_t i = 0; i < v.size(); i++)
            v[i] = left[i];
    }
}

void ProgramMe_deque(std::deque<int> &d)
{
    if (d.size() > 1)
    {
        std::deque<int> left;
        std::deque<int> right;

        int mid = d.size() / 2;
        for (int i = 0; i < mid; i++)
            left.push_back(d[i]);

        for (size_t i = mid; i < d.size(); i++)
            right.push_back(d[i]);

        for (size_t i = 1; i < left.size(); i++)
        {
            int j = i;
            while (j > 0 && left[j] < left[j - 1])
            {
                std::swap(left[j], left[j - 1]);
                j--;
            }
        }

        for (size_t i = 0; i < right.size(); i++)
        {
            std::deque<int>::iterator it = std::lower_bound(left.begin(), left.end(), right[i]);
            left.insert(it, right[i]);
        }

        for (size_t i = 0; i < d.size(); i++)
            d[i] = left[i];
    }
}
