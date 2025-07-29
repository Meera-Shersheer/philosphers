/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:04:21 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/28 21:05:18 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int destroy_intrupted_philos(int i, t_philos *philos_list, t_program *prog)
{
	int j;

	j = 0;
	pthread_mutex_destroy(&(prog->print));
	pthread_mutex_destroy(&(prog->state));
	while (&((prog->forks)[j]) != 0)
	{
			pthread_mutex_destroy(&((prog->forks)[j].fork_mutex));
			j++;
	}
	while(--i >= 0)
	{
		pthread_mutex_destroy(&(philos_list[i].meal_mutex));
	}
	return (0);
}

int destroy_mutexes(t_program *prog)
{
	int i;

	i = 0;
	pthread_mutex_destroy(&(prog->print));
	pthread_mutex_destroy(&(prog->state));
	while (&((prog->forks)[i]) != 0)
	{
			pthread_mutex_destroy(&((prog->forks)[i].fork_mutex));
			i++;
	}
	i = 0;
	while (&((prog->philos)[i]) != 0)
	{
			pthread_mutex_destroy(&((prog->philos)[i].meal_mutex));
			i++;
	}
	return (0);
}