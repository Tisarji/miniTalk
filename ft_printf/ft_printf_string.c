/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:35:44 by jikarunw          #+#    #+#             */
/*   Updated: 2023/10/21 21:02:31 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(char *str)
{
	unsigned int	count;

	if (!str)
		return (ft_printf_string("(null)"));
	while (*str)
	{
		count += ft_printf_char(*str);
		str++;
	}
	return (count);
}
