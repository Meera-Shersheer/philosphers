/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:04:21 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/31 00:44:25 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_intrupted_philos(t_philos *philos_list, t_program *prog)
{
	int	j;

	j = 0;
	pthread_mutex_destroy(&(prog->print));
	pthread_mutex_destroy(&(prog->state));
	while (j < prog->num_philos)
	{
		printf ("%d destory fork and meal \n", j);
		pthread_mutex_destroy(&((prog->forks)[j].fork_mutex));
		pthread_mutex_destroy(&(philos_list[j].meal_mutex));
		j++;
	}
	free(prog->philos);
	free(prog->forks);
	return (-1);
}

int	destroy_mutexes(t_program *prog)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(prog->print));
	pthread_mutex_destroy(&(prog->state));
	while (i < prog->num_philos)
	{
		pthread_mutex_destroy(&((prog->forks)[i].fork_mutex));
		pthread_mutex_destroy(&((prog->philos)[i].meal_mutex));
		i++;
	}
	free(prog->philos);
	free(prog->forks);
	return (1);
}
