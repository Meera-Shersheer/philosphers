/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:16:23 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 20:33:53 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	wait_philos(t_program *prog)
{
	t_philos	*philos_list;
	int			i;

	i = 0;
	philos_list = prog->philos;
	while (i < prog->num_philos)
	{
		pthread_join(philos_list[i].thread_id, NULL);
		return (-1);
		i++;
	}
	if (pthread_mutex_lock(&(prog->state)))
		return (-1);
	prog->philos_ready = 1;
	if (pthread_mutex_unlock(&(prog->state)))
		return (-1);
	return (0);
}

int	ft_wait(t_program *prog)
{
	pthread_mutex_lock(&(prog->state));
	while (prog->philos_ready != 1)
	{
		pthread_mutex_unlock(&(prog->state));
		usleep(100);
		pthread_mutex_lock(&(prog->state));
	}
	pthread_mutex_unlock(&(prog->state));
	return (0);
}

int	intrept_waiting(long long time, t_program *prog)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		pthread_mutex_lock(&(prog->state));
		if (prog->is_stopped == 1)
		{
			pthread_mutex_unlock(&(prog->state));
			return (1);
		}
		pthread_mutex_unlock(&(prog->state));
		usleep(100);
	}
	return (0);
}
