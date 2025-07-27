/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:50:43 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/27 21:18:14 by mshershe         ###   ########.fr       */
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

		
	}
	return (0);
}

int fill_program_data(int argc, char **argv, t_program *prog)
{
	if (!prog)
		return (-1);
	prog->num_philos = ft_atol(argv[1]);
	prog->time_to_die = ft_atol(argv[2]);
	prog->time_to_eat = ft_atol(argv[3]);
	prog->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		prog->num_meals_must_eat = ft_atol(argv[5]);
	else
		prog->num_meals_must_eat = -1;
	return (0);
}
