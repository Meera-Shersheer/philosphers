/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:59:48 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/27 21:13:39 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H



# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_program
{
	int num_philos;
	long long time_to_die;
	long long time_to_eat;
	long long time_to_sleep;
	long long start_time;
	long long num_meals_must_eat;
	t_philos *philos;
	t_forks *forks;
	pthread_mutex_t state;
	pthread_mutex_t print;
}	t_program;

typedef struct s_philos 
{
	int index;
	long long meals_eaten;
	int is_eating;
	long long last_meal_time;
	pthread_t thread_id;
	t_forks *r_fork;
	t_forks *l_fork;
	pthread_mutex_t meal_mutex;
}	t_philos ;

typedef struct s_forks 
{
	int	fork_id;
	pthread_mutex_t fork_mutex;
}	t_forks;

//parsing
int check_args(int argc, char **argv);
int check_range(char *s);
int check_is_num(char *s);

//utils
size_t	ft_strlen(const char *s);
long long	ft_atol(const char *nptr);

#endif