/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/21 21:01:39 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	write_flag(const char s, va_list args, int *count)
{
	char	*s_var;
	int		i_var;
	
	if (s == '%')
		*count += ft_putchar_fd('%', 1);
	if (s == 'p')
	{
		i_var = (long int)va_arg(args, void *);
		if (!i_var)
			*count += ft_putstr_fd("(nil)", 1);
		else
		{
			*count += ft_putstr_fd("0x", 1);
			*count += ft_puthex(i_var);
		}
	}
	if (s == 'c')
		*count += ft_putchar_fd(va_arg(args, int), 1);
	if (s == 's')
	{
		s_var = va_arg(args, char *);
		if (!s_var)
			*count += ft_putstr_fd("(null)", 1);
		else
			*count += ft_putstr_fd(s_var, 1);
	}
	if (s == 'd' || s == 'i')
		*count+= ft_putnbr_fd(va_arg(args, int), 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	char	c_var;
	char	*s_var;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			// code to handle format specifier cspdiuxX%
			s++;
			write_flag(*s, args, &count);
		}
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
