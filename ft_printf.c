/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/16 20:51:48 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	char	c_var;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		while (*s)
		{
			if (*s == '%')
			{
				// code to handle format specifier cspdiuxX%
				s++;
				if (*s == 'c')
				{
					c_var = (char)va_arg(args, int);
					count += ft_putchar_fd(c_var, 1);
				}
			}
			else
				count += write(1, s, 1);
			s++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char	c_var;

// 	c_var = 'F';
// 	ft_printf("TESTE02: %c", c_var);
// 	return (0);
// }