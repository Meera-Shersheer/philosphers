/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:34:38 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/29 21:42:32 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
	prog->is_stopped = 0;
	return (0);
}

int ft_mutex_init(t_program *prog)
{
	if (pthread_mutex_init(&(prog->print) , NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&(prog->state) , NULL) != 0)
	{
		pthread_mutex_destroy(&(prog->print));
		return (-1);
	}
	 return (0);
}

int forks_init(t_program *prog)
{
	t_forks	*forks_list;
	int i;

	i = 0;
	forks_list = malloc (sizeof(t_forks) * (prog->num_philos + 1));
	if (forks_list == NULL)
		return (-1);
	memset(forks_list, 0, sizeof(t_forks) * (prog->num_philos + 1));
	while (i < prog->num_philos)
	{
		forks_list[i].fork_id = i;
		if (pthread_mutex_init(&(forks_list[i].fork_mutex) , NULL) != 0)
		{
			while (--i >= 0)
			{
				pthread_mutex_destroy(&(forks_list[i].fork_mutex));
			}
			pthread_mutex_destroy(&(prog->state));
			pthread_mutex_destroy(&(prog->print));
			return (-1);
		}
		i++;
	}
	prog->forks = forks_list;
	return (0);
}

int philos_init(t_program *prog)
{
	t_philos	*philos_list;
	int i;
	
	i = 0;
	philos_list = malloc (sizeof(t_philos) * (prog->num_philos + 1));
	if (philos_list  == NULL)
		return (-1);
	memset(philos_list , 0, sizeof(t_forks) * (prog->num_philos + 1));
	while (i < prog->num_philos)
	{
		philos_list[i].index = i + 1;
		if (pthread_mutex_init(&(philos_list[i].meal_mutex) , NULL) != 0)//DESTROY THE OTHER MUTEXES IF IT'S FAIL!!
		{
			destroy_intrupted_philos(i, philos_list, prog);
			return (-1);
		}
		philos_list[i].r_fork = &((prog->forks)[i]);
		philos_list[i].l_fork = &((prog->forks)[(i + 1) % prog->num_philos]);
		philos_list[i].prog = prog;
		i++;
	}
	prog->philos = philos_list;
	return (0);
}

int threads_init(t_program *prog)
{
	t_philos	*philos_list;
	int i;

	i = 0;
	philos_list = prog->philos;
	prog->start_time = get_time();
	while (i < prog->num_philos)
	{
		if (pthread_create(&(philos_list[i].thread_id), NULL, routine, &philos_list[i]) != 0)
			return (-1);
		if (record_meal_time(&(philos_list[i])) == -1)
			return (-1);
		i++;
	}
	pthread_mutex_lock(&(prog->state));
	prog->philos_ready = 1;
	pthread_mutex_unlock(&(prog->state));

	// if (pthread_create(&monitor_th, NULL, monitor, prog) != 0)
	// 		return (-1);
	return (wait_philos(prog));
}

