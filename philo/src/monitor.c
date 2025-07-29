/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:57:47 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/28 20:16:36 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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