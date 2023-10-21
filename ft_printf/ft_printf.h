/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 01:40:14 by jikarunw          #+#    #+#             */
/*   Updated: 2023/10/21 01:24:34 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_printf_char(int c);
int		ft_printf_hex(unsigned int n, int x_sw);
int		ft_printf_string(char *str);
size_t	ft_printf_nbr(long int num);

#endif
