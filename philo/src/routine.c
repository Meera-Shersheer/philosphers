/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:06:05 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/29 21:18:51 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int sleep(t_program *prog)
{
	if (should_stop(prog) == 1)
		return (-2);
	else
	{
		print_actions(prog, 2, get_time() - prog->start_time);
		intrept_waiting(prog->time_to_sleep, prog);
	}
	return (0);
}

int think(t_program *prog)
{
	if (should_stop(prog) == 1)
		return (-2);
	else
	{
		print_actions(prog, 3, get_time() - prog->start_time);
		intrept_waiting(1, prog);
	}
	return (0);
}
