/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/13 20:37:22 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	
	va_end(args);
	return ((char *)s);
}