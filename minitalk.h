/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:30 by jikarunw          #+#    #+#             */
/*   Updated: 2023/11/09 00:24:56 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

// ? ANSI escape codes for text color
# define RED_TEXT	"\x1b[31m"
# define GREEN_TEXT	"\x1b[32m"
# define RESET_TEXT	"\x1b[0m"

int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);

#endif
