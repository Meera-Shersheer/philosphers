/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:57:47 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/28 18:58:32 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*to be put in the monitor*/
int	wait_philos(t_program *prog)
{
	t_philos	*philos_list;
	int i;

	i = 0;
	philos_list = prog->philos;
	while (i < prog->num_philos)
	{
		if (pthread_join(philos_list[i].thread_id, NULL) != 0)
			return (-1);			
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
	while(prog->philos_ready != 1)
		usleep(100);
	return (0);
}

int	record_meal_time(t_philos *philo)
{
	if (pthread_mutex_lock(&(philo->meal_mutex)))
		return (-1);
	philo->last_meal_time = get_time();
	if (pthread_mutex_unlock(&(philo->meal_mutex)))
		return (-1);
	return (0);
}

void *routine(void *philo)
{
    //printf("Thread running with arg = %s\n", (char *)arg);
    return (NULL);
}
void *monitor(void *proggram)
{
   //printf("Thread running with arg = %s\n", (char *)arg);
    return (NULL);
}