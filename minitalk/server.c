/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:50:44 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/03 14:58:28 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_getbit(int signal)
{
	static char	c = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		ft_printf("pid %d\n", getpid());
		signal(SIGUSR1, ft_getbit);
		signal(SIGUSR2, ft_getbit);
		while (1)
		{
			pause();
		}
	}
	return (0);
}
