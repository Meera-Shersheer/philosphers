/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:59:48 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/29 21:51:02 by mshershe         ###   ########.fr       */
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

typedef struct s_philos t_philos;
typedef struct s_forks t_forks;
typedef struct s_program
{
	int num_philos;
	int philos_ready;
	int is_stopped;
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
	t_program *prog;
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


//main
long long get_time();
void print_actions(t_philos *philo, int action,long long time);

//parsing
int check_args(int argc, char **argv);
int check_range(char *s);
int check_is_num(char *s);

//utils
size_t	ft_strlen(const char *s);
long long	ft_atol(const char *nptr);

//philo_init
int fill_program_data(int argc, char **argv, t_program *prog);
int ft_mutex_init(t_program *prog);
int forks_init(t_program *prog);
int philos_init(t_program *prog);
int threads_init(t_program *prog);

//monitor
void *routine(void *arg);
int should_stop(t_program *prog);
//void *monitor(t_program *prog);

//wait
int	wait_philos(t_program *prog);
int	ft_wait(t_program *prog);
int	intrept_waiting(long long time, t_program *prog);

//destroy
int destroy_intrupted_philos(int i, t_philos *philos_list, t_program *prog);
int destroy_mutexes(t_program *prog);

//routine
int ft_sleep(t_philos *philo);
int think(t_philos *philo);

//eat
int	eaten_enough_meals(t_philos *philo);
void update_philo_state(t_philos *philo, int state);
void setup_forks(t_philos *philo, t_forks **first, t_forks **second);
int	record_meal_time(t_philos *philo);
int eat(t_philos *philo);

//eat2
void release_forks(t_forks *first, t_forks *secound);
int take_fork(t_philos *philo, t_forks *first, t_forks *second);




#endif