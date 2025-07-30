/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:06:05 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 18:03:17 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


void *routine(void *arg)
{
	t_philos *philo;

	philo = (t_philos *) arg;
	ft_wait(philo->prog);
	if(philo->index % 2 == 0)
		usleep(1000);
	if (record_meal_time(philo) == -1)
		return (NULL);
	while (should_stop(philo->prog) != 1)
	{
		if (eaten_enough_meals(philo) == 1)
			break;
    	if (eat (philo) == 1)
	 		break;
		if (ft_sleep(philo) == 1)
			break;
		if (think(philo) == 1)
			break;
	}
    return (NULL);
}


int ft_sleep(t_philos *philo)
{
	if (should_stop(philo->prog) == 1)
		return (1);
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
		return (1);
	else
	{
		print_actions(philo, 3, get_time() - philo->prog->start_time);
		intrept_waiting(0.5, philo->prog);
	}
	return (0);
}
