/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:15:54 by adiouane          #+#    #+#             */
/*   Updated: 2023/04/02 04:31:21 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN(char *str[])
{
    std::stack<int> stack;
    int i = 0;

    if (str[1][0] == '\0')
    {
        std::cerr << "Error: empty expression" << std::endl;
        return;
    }
    while (str[1][i] != '\0')
    {
        if (isdigit(str[1][i]) && str[1][i + 1] != '\0')
            stack.push(str[1][i] - '0');
        else if (str[1][i] == '+')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: insufficient operands for '+'" << std::endl;
                return;
            }
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            stack.push(num1 + num2);
        }
        else if (str[1][i] == '-')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: insufficient operands for '-'" << std::endl;
                return;
            }
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            stack.push(num1 - num2);
        }
        else if (str[1][i] == '*')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: insufficient operands for '*'" << std::endl;
                return;
            }
            int num2 = stack.top();
            stack.pop();
            int num1 = stack.top();
            stack.pop();
            stack.push(num1 * num2);
        }
        else if (str[1][i] == '/')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: insufficient operands for '/'" << std::endl;
                return;
            }
            int num2 = stack.top();
            stack.pop();
            if (num2 == 0)
            {
                std::cerr << "Error: division by zero" << std::endl;
                return;
            }
            int num1 = stack.top();
            stack.pop();
            stack.push(num1 / num2);
        }
        else if (str[1][i] == '%')
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: insufficient operands for '%'" << std::endl;
                return;
            }
            int num2 = stack.top();
            stack.pop();
            if (num2 == 0)
            {
                std::cerr << "Error: modulo by zero" << std::endl;
                return;
            }
            int num1 = stack.top();
            stack.pop();
            stack.push(num1 % num2);
        }
        else if (str[1][i] == ' ')
            ;
        else if (isdigit(str[1][i]) && str[1][i + 1] == '\0')
            stack.push(str[1][i] - '0');
        else
        {
            std::cerr << "Error: invalid token '" << str[1][i] << "'" << std::endl;
            return;
        }
        i++;
    }
    if (stack.size() > 1)
    {
        std::cerr << "Error: insufficient operators" << std::endl;
        return;
    }
    std::cout << stack.top() << std::endl;
}