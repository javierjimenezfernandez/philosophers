/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:59:06 by javjimen          #+#    #+#             */
/*   Updated: 2025/09/28 19:34:10 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	threads_create(
			t_main_data_struct *main_data,
			t_philo *philo_array,
			pthread_mutex_t *fork_array)
{
	pthread_t		the_watcher;
	unsigned int	i;

	if (pthread_create(&the_watcher, NULL, &watcher, (void *)philo_array) != 0)
		return (destroy_all_mutexes(PTHREAD_CREATE_E, main_data, fork_array));
	i = 0;
	while (i < philo_array[0].n_of_philos)
	{
		if (pthread_create(&philo_array[i].thread, NULL, &philo_actions,
				(void *)&philo_array[i]) != 0)
			return (destroy_all_mutexes(PTHREAD_CREATE_E, main_data,
					fork_array));
		i++;
	}
	if (pthread_join(the_watcher, NULL) != 0)
		return (destroy_all_mutexes(PTHREAD_JOIN_E, main_data, fork_array));
	i = 0;
	while (i < philo_array[0].n_of_philos)
	{
		if (pthread_join(philo_array[i].thread, NULL) != 0)
			return (destroy_all_mutexes(PTHREAD_JOIN_E, main_data, fork_array));
		i++;
	}
	return ;
}
