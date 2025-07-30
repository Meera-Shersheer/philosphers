/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 21:13:58 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 19:33:43 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int take_fork(t_philos *philo, t_forks *first, t_forks *second)
{
	pthread_mutex_lock(&(first)->fork_mutex);
	if(should_stop(philo->prog))
	{
		pthread_mutex_unlock(&(first)->fork_mutex);
		return (1);
	}
	print_actions(philo, 0, get_time() - philo->prog->start_time);
	if (philo->prog->num_philos <= 1)
	{
		pthread_mutex_unlock(&(first)->fork_mutex);
		intrept_waiting(philo->prog->time_to_die, philo->prog);
		return (1);
	}
	if(should_stop(philo->prog) == 1)
	{
		pthread_mutex_unlock(&(first)->fork_mutex);
		return (1);
	}
	pthread_mutex_lock(&(second)->fork_mutex);
	if(should_stop(philo->prog))
	{
		release_forks(first, second);
		return (1);
	}
	print_actions(philo, 0, get_time() - philo->prog->start_time);
	return (0);	
}

void release_forks(t_forks *first, t_forks *secound)
{
	pthread_mutex_unlock(&(first)->fork_mutex);
	pthread_mutex_unlock(&(secound)->fork_mutex);
}

int all_ate(t_program *prog)
{
	t_philos *philos;
	int i;
	
	i = 0;
	philos = prog->philos;
	while (i < prog->num_philos)
	{
		if (eaten_enough_meals(&(philos[i])) == 0)
			return (0);		
		i++;
	}
	return (1);
}