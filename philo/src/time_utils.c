/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:01:47 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:48:13 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	gettime_in_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		log_fd(STDERR_FILENO, GETTIMEOFDAY_E);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	accurate_msleep(time_t ms)
{
	time_t	start_timestamp;

	start_timestamp = gettime_in_ms();
	while (gettime_in_ms() - start_timestamp < ms)
	{
		if (usleep(500) == -1)
			return (-1);
	}
	return (0);
}
