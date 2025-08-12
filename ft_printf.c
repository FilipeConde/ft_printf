/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/12 19:50:27 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	write_char(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count += write(1, *s, 1);
		s++;
	}
	return (count);
}

char	*ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	
	va_end(args);
	return (s);
}