/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:10:01 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/30 22:56:06 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	record_meal_time(t_philos *philo)
{
	pthread_mutex_lock(&(philo->meal_mutex));
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&(philo->meal_mutex));
	return (0);
}

int	eaten_enough_meals(t_philos *philo)
{
	int	all_have_eaten;

	all_have_eaten = 1;
	pthread_mutex_lock(&(philo->meal_mutex));
	if (philo->prog->num_meals_must_eat == -1)
	{
		pthread_mutex_unlock(&(philo->meal_mutex));
		return (-1);
	}
	if (philo->meals_eaten < philo->prog->num_meals_must_eat)
		all_have_eaten = 0;
	if (all_have_eaten == 1)
	{
		pthread_mutex_unlock(&(philo->meal_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(philo->meal_mutex));
	return (0);
}

void	update_philo_state(t_philos *philo, int state)
{
	if (state == 0)
	{
		pthread_mutex_lock(&(philo->meal_mutex));
		philo->is_eating = 1;
		philo->last_meal_time = get_time();
		pthread_mutex_unlock(&(philo->meal_mutex));
	}
	else
	{
		pthread_mutex_lock(&(philo->meal_mutex));
		philo->is_eating = 0;
		philo->meals_eaten++;
		pthread_mutex_unlock(&(philo->meal_mutex));
	}
}

void	setup_forks(t_philos *philo, t_forks **first, t_forks **second)
{
	if (!first || !second)
		return ;
	if (philo->index % 2 == 0)
	{
		*first = philo->r_fork;
		*second = philo->l_fork;
	}
	else
	{
		*first = philo->l_fork;
		*second = philo->r_fork;
	}
}

int	eat(t_philos *philo)
{
	t_forks	*first;
	t_forks	*second;

	setup_forks(philo, &first, &second);
	if (should_stop(philo->prog) == 1)
		return (1);
	if (take_fork(philo, first, second) == 1)
		return (1);
	update_philo_state(philo, 0);
	print_actions(philo, 1, get_time() - philo->prog->start_time);
	if (intrept_waiting(philo->prog->time_to_eat, philo->prog) == 1)
	{
		update_philo_state(philo, 1);
		release_forks(first, second);
		return (1);
	}
	update_philo_state(philo, 1);
	release_forks(first, second);
	return (0);
}
