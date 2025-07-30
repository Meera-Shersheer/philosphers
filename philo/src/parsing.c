/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:57:10 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 20:26:41 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(2, "philo args: num_philos die_T eat_T sleep_T [meals_to_eat]\n", \
ft_strlen("philo args: num_philos die_T eat_T sleep_T [meals_to_eat]\n")\
);
		return (-1);
	}
	else
	{
		while (i < argc)
		{
			if (check_is_num(argv[i]) == -1)
				return (-1);
			if (check_range(argv[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}

int	check_range(char *s)
{
	long long	num;

	num = ft_atol(s);
	if (num < 0)
	{
		write(2, "Negative values and multiple signs are not allowed\n", \
ft_strlen("Negative values and multiple signs are not allowed\n"));
		return (-1);
	}
	return (0);
}

int	check_is_num(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if ((s[i] != '-' && s[i] != '+') && (s[i] < '0' || s[i] > '9'))
		{
			write(2, "Arguments contains a letter or a special char\n", \
ft_strlen("Arguments contains a letter or a special char\n"));
			return (-1);
		}
		i++;
	}
	return (0);
}
