/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:27:00 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/21 20:01:03 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(int nbr)
{
	int		div;
	int		mod;
	char	c_nbr;
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= 16)
	{
		div = nbr / 16;
		count += ft_puthex(div);
	}
	mod = nbr % 16;
	c_nbr = base[mod];
	count += write(1, &c_nbr, 1);
	return (count);
}

// int	main(void)
// {
// 	int		num = -19;
// 	char	*empty = "";
// 	char	*binario = "01";
// 	char	*hexadecimal = "0123456789ABCDEF";
// 	ft_putnbr_base(num, binario);
// 	write(1, &"\n", 1);
// 	ft_putnbr_base(num, hexadecimal);
// 	write(1, &"\n", 1);
// 	ft_putnbr_base(num, empty);
// }