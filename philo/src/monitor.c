/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:57:47 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 18:40:24 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *monitor(t_program *prog)
{
	t_philos *philos;
	int all_philos_meals_eaten;
	int i;

	i = 0;
	all_philos_meals_eaten = 1;
	philos = prog->philos;
	if (wait_philos(prog) == -1)
		return (NULL);
	while (i < prog->num_philos && prog->num_meals_must_eat != -1 )
	{
		if (eaten_enough_meals(&(philos[i])) == 0)
			all_philos_meals_eaten = 0;		
		i++;
	}
	if (all_philos_meals_eaten == 1)
	{
		if (pthread_mutex_lock(&(prog->state)))
			return (-1);
		prog->is_stopped = 1;
		if (pthread_mutex_unlock(&(prog->state)))
			return (-1);
	}
    return (NULL);
}

int check_death_philos(t_program *prog)
{
	int dead_philo;
	int i;

	i = 0;
	dead_philo = 0;
	if (wait_philos(prog) == -1)
		return (-1);
	while (i < prog->num_philos)
	{
		if (check_death(&((prog->philos)[i])) == 1)
		{
			dead_philo = 1;
			return (1);
		}
		i++;
	}
    return (0);
}

int check_death(t_philos *philo)
{
	if	(get_time() - philo->last_meal_time >= philo->prog->time_to_die)
	{
		if (pthread_mutex_lock(&(philo->prog->state)))
			return (-1);
		philo->prog->is_stopped = 1;
		if (pthread_mutex_unlock(&(philo->prog->state)))
			return (-1);
		return (1);
	}
	return (0);
}

int should_stop(t_program *prog)
{
	if (pthread_mutex_lock(&(prog->state)))
		return (-1);
	if (prog->is_stopped == 1)
	{
		if (pthread_mutex_unlock(&(prog->state)))
			return (-1);
		return (1);
	}
	if (pthread_mutex_unlock(&(prog->state)))
		return (-1);
	return (0);
}