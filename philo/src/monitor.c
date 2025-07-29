/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:57:47 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/29 21:51:19 by mshershe         ###   ########.fr       */
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
    	if (eat (philo) == -2)
	 		break;
		if (ft_sleep(philo) == -2)
			break;
		if (think(philo) == -2)
			break;
	}
    return (NULL);
}





// void *monitor(t_program *prog)
// {
// 	if (wait_philos(prog) == -1)
// 		return (NULL);
// 	check_num_meals(prog);
//    //printf("Thread running with arg = %s\n", (char *)arg);
//     return (NULL);
// }



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