/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akizilto <akizilto@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:50:14 by akizilto          #+#    #+#             */
/*   Updated: 2024/04/03 14:52:55 by akizilto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	result;

	a = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			a = -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * a);
}

void	ft_sendbit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	char	*s;
	int		pid;
	int		i;

	if (ac != 3)
	{
		ft_printf("Error !\n");
		return (1);
	}
	i = 0;
	s = av[2];
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		while (s[i])
		{
			ft_sendbit(pid, s[i]);
			i++;
		}
	}
	return (0);
}
