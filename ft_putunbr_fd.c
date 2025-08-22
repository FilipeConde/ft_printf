/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:12:48 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/21 21:55:20 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunbr_fd(n / 10, fd);
	}
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}
