/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:34:49 by jikarunw          #+#    #+#             */
/*   Updated: 2023/10/21 01:24:02 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_nbr(long int num)
{
	size_t	out;

	out = 0;
	if (num < 0)
	{
		out += ft_printf_char('-');
		out += ft_printf_nbr(num * -1);
	}
	else if (num > 9)
	{
		out += ft_printf_nbr(num / 10);
		out += ft_printf_nbr(num % 10);
	}
	else
		out += ft_printf_char(num + '0');
	return (out);
}
