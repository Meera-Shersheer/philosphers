/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshershe <mshershe@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:59:28 by mshershe          #+#    #+#             */
/*   Updated: 2025/07/28 20:16:06 by mshershe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
		n++;
	return (n);
}

long long	ft_atol(const char *nptr)
{
	long long	num;
	int	pn;
	int	sign;

	pn = 1;
	num = 0;
	sign = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == '-')
			pn = -1;
		sign++;
		nptr++;
		if (sign > 1)
			return (-1);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * pn);
}
