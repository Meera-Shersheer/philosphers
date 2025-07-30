/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:50:43 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/31 00:39:25 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_program	prog;

	if (check_args(argc, argv) == -1)
		return (1);
	memset(&prog, 0, sizeof(t_program));
	if (fill_program_data(argc, argv, &prog) == -1)
		return (1);
	if (ft_mutex_init(&prog) == -1)
		return (1);
	if (forks_init(&prog) == -1)
		return (1);
	if (philos_init(&prog) == -1)
	{
		free(prog.forks);
		return (1);
	}
	if (threads_init(&prog) == -1)
		return (1);
	destroy_mutexes(&prog);
	return (0);
}

long long	get_time(void)
{
	struct timeval	tv;
	long long		current_time_milli;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	current_time_milli = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (current_time_milli);
}

void	print_actions(t_philos *philo, int action, long long time)
{
	if (pthread_mutex_lock(&(philo->prog->print)))
		return ;
	if (action == 0)
		printf("%lld %d has taken a fork\n", time, philo->index);
	else if (action == 1)
		printf("%lld %d is eating\n", time, philo->index);
	else if (action == 2)
		printf("%lld %d is sleeping\n", time, philo->index);
	else if (action == 3)
		printf("%lld %d is thinking\n", time, philo->index);
	else if (action == 4)
		printf("%lld %d died\n", time, philo->index);
	if (pthread_mutex_unlock(&(philo->prog->print)))
		return ;
}
