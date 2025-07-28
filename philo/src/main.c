/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:50:43 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/28 17:25:07 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//The philosophers take turns eating, thinking, and sleeping.
//args : number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat}
/*
◦ timestamp_in_ms X has taken a fork 
◦ timestamp_in_ms X is eating ◦ 
timestamp_in_ms X is sleeping ◦ 
timestamp_in_ms X is thinking ◦ 
timestamp_in_ms X died
*/

int main(int argc, char **argv)
{
	t_program prog;
	
	if (argc < 5 || argc > 6)
		write(2,"philo arguments: num_of_philos time_to_die time_to_eat \
			time_to_sleep [num_of_must_eaten_meals]\n", ft_strlen("philo \
				arguments: num_of_philos time_to_die time_to_eat \
			time_to_sleep [num_of_must_eaten_meals]\n"));
	else
	{
		if (check_args(argc, argv) == -1)
			return (1);
		memset(&prog, 0, sizeof(t_philos));	
		if (fill_program_data(argc, argv, &prog) == -1)
			return (1);
		if (ft_mutex_init(&prog) == -1)
			return (1);
		if (forks_init(&prog) == -1)
			return (1);
		
	}
	return (0);
}


long long get_time()
{
	struct timeval tv;
	long long current_time_milli;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	current_time_milli = tv.tv_sec * 1000 + tv.tv_usec / 1000; 
	return (current_time_milli);
}