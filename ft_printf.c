/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/25 19:37:27 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	write_flag(const char s, va_list args, int *count)
{
	char	*s_var;
	unsigned long		i_var;

	if (s == '%')
		*count += ft_putchar_fd('%', 1);
	if (s == 'p')
	{
		i_var = va_arg(args, unsigned long);
		if (!i_var)
			*count += ft_putstr_fd("(nil)", 1);
		else
		{
			*count += ft_putstr_fd("0x", 1);
			*count += ft_putulhex(i_var, 'x');
		}
	}
	if (s == 'x' || s == 'X')
		*count += ft_puthex(va_arg(args, unsigned int), s);
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
		*count += ft_putnbr_fd(va_arg(args, int), 1);
	if (s == 'u')
		*count += ft_putunbr_fd(va_arg(args, unsigned int), 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			write_flag(*s, args, &count);
		}
		else if (*s == '%' && !*(s + 1))
			return (count);
		// count += write(1, s, 1);
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (count);
}
