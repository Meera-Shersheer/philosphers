/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:06:05 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/29 21:51:50 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int ft_sleep(t_philos *philo)
{
	if (should_stop(philo->prog) == 1)
		return (-2);
	else
	{
		print_actions(philo, 2, get_time() - philo->prog->start_time);
		intrept_waiting(philo->prog->time_to_sleep, philo->prog);
	}
	return (0);
}

int think(t_philos *philo)
{
	if (should_stop(philo->prog) == 1)
		return (-2);
	else
	{
		print_actions(philo, 3, get_time() - philo->prog->start_time);
		intrept_waiting(1, philo->prog);
	}
	return (0);
}
