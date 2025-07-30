/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:57:47 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 22:07:14 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*monitor(void *arg)
{
	t_program	*prog;

	prog = (t_program *) arg;
	ft_wait(prog);
	while (1)
	{
		if (prog->num_meals_must_eat != -1)
		{
			if (all_ate(prog) == 1)
			{
				pthread_mutex_lock(&(prog->state));
				prog->is_stopped = 1;
				pthread_mutex_unlock(&(prog->state));
				break ;
			}
		}
		if (check_death_philos(prog) == 1)
			break ;
		usleep(100);
	}
	return (NULL);
}

int	check_death_philos(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->num_philos)
	{
		if (check_death(&((prog->philos)[i])) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_death(t_philos *philo)
{
	pthread_mutex_lock(&(philo->meal_mutex));
	if ((get_time() - philo->last_meal_time >= philo->prog->time_to_die) && \
philo->is_eating == 0)
	{
		pthread_mutex_unlock(&(philo->meal_mutex));
		pthread_mutex_lock(&(philo->prog->state));
		philo->prog->is_stopped = 1;
		print_actions(philo, 4, get_time() - philo->prog->start_time);
		pthread_mutex_unlock(&(philo->prog->state));
		return (1);
	}
	else
		pthread_mutex_unlock(&(philo->meal_mutex));
	return (0);
}

int	should_stop(t_program *prog)
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
