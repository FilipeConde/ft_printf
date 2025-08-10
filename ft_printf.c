/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fconde-p <fconde-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:34:01 by fconde-p          #+#    #+#             */
/*   Updated: 2025/08/10 16:32:01 by fconde-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdlib.h>

char	*ft_printf(const char *c)
{
	char	*ptr;

	ptr = malloc((strlen(c) + 1) * sizeof(char));

	strcpy(ptr, c);
	return (ptr);
}