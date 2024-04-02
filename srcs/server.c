/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:00:23 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/31 17:08:55 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*addchar(char *str, char chr, int *str_len)
{
	char	*out;

	out = malloc(*str_len + 2);
	if (!out)
	{
		ft_printf("server | Memory allocation failed.\n");
		exit(1);
	}
	ft_memcpy(out, str, *str_len);
	out[(*str_len)++] = chr;
	out[*str_len] = '\0';
	if (str)
		free(str);
	return (out);
}

void	handle_sig_server(int sig, siginfo_t *info, void *uctx)
{
	static char	*str = NULL;
	static int	str_len = 0;
	static char	byte = 0b00000000;
	static int	shift = 7;

	(void) uctx;
	byte |= (sig - SIGUSR1) << shift--;
	if (shift == -1)
	{
		if (byte != 0)
			str = addchar(str, byte, &str_len);
		else
		{
			str = addchar(str, '\n', &str_len);
			write(1, str, str_len);
			free(str);
			str = NULL;
			str_len = 0;
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_printf("server | Failed to send to the client.\n");
		}
		byte = 0b00000000;
		shift = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server | PID: %d\n", getpid());
	sa.sa_sigaction = handle_sig_server;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		return (ft_printf("server | Failed adding signal handler.\n"));
	if (sigaction(SIGUSR2, &sa, NULL) < 0)
		return (ft_printf("server | Failed adding signal handler.\n"));
	while (1)
		pause();
}
